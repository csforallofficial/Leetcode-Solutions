class Solution {
public:
    struct Node{
        int num;
        int freq;
        Node(int a, int b){
            num = a;
            freq = b;
        }
    };
    struct compare{
        bool operator()(Node const& a, Node const& b){
            return a.freq < b.freq;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> track;
        for(int i = 0; i < nums.size(); i++)
            track[nums[i]]++;
        priority_queue<Node,vector<Node>,compare> heap;
        for(auto it:track)
            heap.push(Node(it.first,it.second));
        vector<int> ans;
        while(k--){
            Node temp = heap.top();
            heap.pop();
            ans.push_back(temp.num);
        }
        return ans;
    }
};