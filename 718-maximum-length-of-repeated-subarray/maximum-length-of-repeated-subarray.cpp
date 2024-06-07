class Solution {
public:
// exact similar to longest common substring aditya verma
    int findLength(vector<int>& x, vector<int>& y) {
        int m=x.size(),n=y.size();
        int t[m+1][n+1];
        for(int i=0;i<m+1;i++){
            for(int j=0;j<n+1;j++){
                if(i==0 or j==0){
                    t[i][j]=0;
                }
            }
        }
        for(int i=1;i<m+1;i++){
            for(int j=1;j<n+1;j++){
                if(x[i-1]==y[j-1]) t[i][j]=t[i-1][j-1]+1;
                else t[i][j]=0;
            }
        }
        int mx=0; 
        for(int i=0;i<m+1;i++){
            for(int j=0;j<n+1;j++)
               mx=max(mx,t[i][j]);
        }
        return mx;
    }
};