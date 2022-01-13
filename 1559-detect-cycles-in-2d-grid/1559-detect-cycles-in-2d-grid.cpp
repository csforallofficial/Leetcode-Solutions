#define UNION_FIND 1
#define BFS 2

#define METHOD UNION_FIND


#if METHOD == UNION_FIND
class Solution {
public:
    int root(int father[], int idx) {
        while (idx != father[idx])
            idx = father[idx] = father[father[idx]];

        return idx;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        int M = grid.size(), N = grid[0].size(), father[M*N];

        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                int r_up = -1, r_left = -2;
                if (i-1 >= 0 && grid[i-1][j] == grid[i][j])
                    r_up = root(father, (i-1)*N+j);

                if (j-1 >= 0 && grid[i][j-1] == grid[i][j])
                    r_left = root(father, i*N+j-1);

                if (r_up == r_left)
                    return true;

                if (r_up < 0 && r_left < 0)
                    father[i*N+j] = i*N+j;
                else if (r_up < 0)
                    father[i*N+j] = r_left;
                else if (r_left < 0)
                    father[i*N+j] = r_up;
                else
                    father[r_left] = father[i*N+j] = father[r_up];
            }
        }
        return false;
    }
};
#endif

#if METHOD == BFS
class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int M = grid.size(), N = grid[0].size(), steps[M][N];
        vector<pair<int,int>> dir = {{0,-1}, {0,1}, {1,0}, {-1,0}};
        queue<pair<int,int>> q;
        memset(steps, 0, sizeof(steps));

        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (steps[i][j] != 0)
                    continue;

                int step = 1;
                steps[i][j] = step;
                q.push({i,j});

                while (q.size()) {
                    int sz = q.size();
                    while (sz--) {
                        auto [x, y] = q.front(); q.pop();
                        for (auto d:dir) {
                            auto [dx, dy] = d;
                            int nx = x+dx, ny = y+dy;

                            if (nx < 0 || nx >= M || ny < 0 || ny >= N || grid[nx][ny] != grid[i][j])
                                continue;

                            if (steps[nx][ny] == step+1)
                                return true;

                            if (steps[nx][ny] == 0) {
                                q.push({nx, ny});
                                steps[nx][ny] = step+1;
                            }
                        }
                    }
                    ++step;
                }
            }
        }
        return false;
    }
};
#endif