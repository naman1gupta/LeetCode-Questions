class Solution {
public:
    
    vector<vector<int>> mergeIntervals(vector<vector<int>>& a) {
        sort(a.begin(),a.end());
        
        vector<vector<int>> ans;
        
        int n=a.size();
        
        int s=a[0][0], e=a[0][1];
        for(int i=1;i<n;i++){
            int si=a[i][0], ei=a[i][1];
            
            if(si>e){
                ans.push_back({s,e});
                s=si;
            }
            e=max(e,ei);
        }
        ans.push_back({s,e});
        
        return ans;
    }
    
    int countDays(int days, vector<vector<int>>& meetings) {
        vector<vector<int>> merged_meetings = mergeIntervals(meetings);
        
        int busy_days = 0;
        for(vector<int> d : merged_meetings){
            int start = d[0], end = d[1];
            busy_days += (end - start +1);
        } 
        
        return days - busy_days;
    }
};