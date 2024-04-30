
class Solution {
public:
    bool canMakeSquare(vector<vector<char>>& grid) {
        
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 2; j++){
                int w = 0, b = 0;
                if(grid[i][j] == 'B') b++;
                else w++;
                
                if(grid[i][j+1] == 'B') b++;
                else w++;
                
                if(grid[i+1][j+1] == 'B') b++;
                else w++;
                
                if(grid[i+1][j] == 'B') b++;
                else w++;
                
                if(w >=3 or b >=3) return true;
            }
        }
        return false;
    }
};