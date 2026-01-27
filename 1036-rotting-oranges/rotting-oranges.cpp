class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<pair<int,int>,int>>q; //{{row,col},time}
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2) q.push({{i,j},0});
            }
        }

        int delRow[]={-1,0,1,0};
        int delCol[]={0,1,0,-1};

        int minTime=0;

        while(!q.empty()){

            int r=q.front().first.first;
            int c=q.front().first.second;
            int time=q.front().second;

            minTime=max(minTime,time);

            q.pop();


            for(int k=0;k<4;k++){
                int n_r=r+delRow[k];
                int n_c=c+delCol[k];


                if(n_r>=0 && n_r<n && n_c>=0 && n_c<m && grid[n_r][n_c]==1){
                    grid[n_r][n_c]=2;
                    q.push({{n_r,n_c},time+1});
                }
            }

        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) return -1;
            }
        }
        return minTime;
    }
};