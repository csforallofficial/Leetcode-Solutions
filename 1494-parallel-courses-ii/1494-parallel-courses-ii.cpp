class Solution {
private:
    unordered_map <int, int> memo;
    void getCombinations(int i, int index, int k, vector <int> &combination, vector <int> &available, vector <vector <int>> &combinations) {
        if(index == k) {
            combinations.push_back(combination);
            return ;
        }
        if(i == available.size())
            return ;
        else {
            combination[index] = available[i];
            getCombinations(i + 1, index + 1, k, combination, available, combinations);

            getCombinations(i + 1,index,  k, combination, available, combinations);
        }

    }
    int dp(int bitmask, int takenCourses, int k, int totalCourses, vector < int > &inDegree, vector <vector <int>> &graph) {
        // if all courses are taken
        if(takenCourses == totalCourses) {
            return 0;
        }

        // look for cache
        if(memo.count(bitmask) != 0)
            return memo[bitmask];
        
        // get courses which are not taken yet, and have 0 inDegree
        vector <int> availableCourses;
        for(int i = 0; i < totalCourses; i++)
            if(inDegree[i] == 0 && (bitmask & (1 << i)) == 0)
                availableCourses.push_back(i);

        int res = INT_MAX / 2;
        vector  <vector <int>> combinations;
        
        // if available courses are less than or equal to k,  then we must take them all
        if(availableCourses.size() <= k) {
            combinations.push_back(availableCourses);
        }
        // if they are more than k available courses, then we will get all combinations of k from available courses
        else {
            vector <int> combination(k, -1);
            getCombinations(0, 0, k, combination, availableCourses, combinations);
        }

        // for every combination
        for(auto combination : combinations) {
            // save bitmask in temporary variable
            int temp = bitmask;

            for(auto course : combination) {
                // take selected courses
                bitmask |= (1 << course);
                // decrease their neighbour indegrees
                for(auto nextCourse : graph[course]) {
                    inDegree[nextCourse]--;
                }                            
            }

            //backtrack
            res = min(res, dp(bitmask, takenCourses + combination.size(), k, totalCourses, inDegree, graph) + 1);

            // restore state
            bitmask = temp;
            for(auto course : combination) {
                for(auto nextCourse : graph[course]) {
                    inDegree[nextCourse]++;
                }                            
            }
        }
        // save result for current state in cache
        memo[bitmask] = res;
        return res;
    }
public:
	int minNumberOfSemesters(int n, vector<vector<int>>& relations, int k) {
		vector < int > inDegree(n, 0);
		vector < vector < int > > graph(n);
		// calculate indegrees
		for(auto course : relations) {
			graph[course[0] - 1].push_back(course[1] - 1);
			inDegree[course[1] - 1]++;
		}
		return dp(0, 0, k, n, inDegree, graph);
	}
};