double record[10][50][50][20];

class Solution {
public:
    double getProbability(vector<int>& balls) {
        int n = balls.size();
        int m = 0;
        for (int b: balls) m += b;
        m /= 2;
        memset(record, 0.0, sizeof(record));
        record[0][0][0][n] = 1.0;
        
        for (int i = 1; i <= n; i++) {
            for (int lSlot = 0; lSlot <= m; lSlot++) {
                for (int rSlot = 0; rSlot <= m; rSlot++) {
                    for (int det = -n; det <= n; det++) { // left unique - right unique
                        for (int left = 0; left <= balls[i-1]; left++) {
                            int right = balls[i-1] - left;
                            if (left > lSlot || right > rSlot) continue;
                            int prevDet = det + n;
                            if (left == 0) prevDet--;
                            if (right == 0) prevDet++;
                            if (prevDet < 0 || prevDet > 2*n) continue;
                            record[i][lSlot][rSlot][det+n] += record[i-1][lSlot-left][rSlot-right][prevDet] * computeCnk(lSlot, left) * computeCnk(rSlot, right) / computeCnk(lSlot + rSlot, balls[i-1]);
                        }
                    }
                }
            }
        }
        return record[n][m][m][n];
    }
    double computeCnk(int n, int k) {
        double result = 1.0;
        for (int i = 0; i < k; i++) {
            result *= n - i;
            result /= k - i;
        }
        return result;
    }
};