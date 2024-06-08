class Solution {
public:
    int maximumLength(vector<int>& a, int k) {
        int n=a.size();
        vector<vector<int>> dp(k+2, vector<int> (n+2, -1));
        int res = 0;
        unordered_map<int,int> mp;
        for(int i=n-1; i>=0; i--) {
            dp[0][i] = 1;
            if(mp[a[i]]!=0) dp[0][i] = dp[0][mp[a[i]]]+1;
            mp[a[i]] = i;
            res = max(res, dp[0][i]);
        }
        for(int i=1; i<=k; i++) {
            int maxv = 0;
            mp.clear();
            for(int j=n-1; j>=0; j--) {
                if(j<n-1) maxv = max(maxv, dp[i-1][j+1]);
                dp[i][j] = 1+max(maxv, dp[i][mp[a[j]]]);
                mp[a[j]] = j;
                res = max(res, dp[i][j]);
            }
        }
        return res;
    }
};