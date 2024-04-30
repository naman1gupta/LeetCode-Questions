// \U0001f642 please upvote if you like the Solution. \U0001f642

class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> R(n, 0);
        vector<int> C(m, 0);
        long long count =0;
        for(int i = 0; i<n; i++){
            for(int j =0; j<m; j++){
                R[i] += grid[i][j];
                C[j] += grid[i][j];
            }
        }
        for(int i = 0; i<n; i++){
            for(int j =0; j<m; j++){
                if(grid[i][j] == 1){
                    count += (R[i] - 1)*(C[j] - 1);
                }
            }
        }
        return count;
    }
};