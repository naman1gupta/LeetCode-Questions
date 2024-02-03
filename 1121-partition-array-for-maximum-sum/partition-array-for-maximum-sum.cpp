class Solution {
public:
    int dp[501];
    int solve(vector<int> &arr, int i, int k) {

        if(i >= arr.size()) {
            return 0;
        }
        if(dp[i] != -1) {
            return dp[i];
        }
        int ans = INT_MIN;
        for(int j = i; j < i + k and j < arr.size(); j++) {
            int maxx = INT_MIN;
            for(int k = i; k < j+1; k++) {
                maxx = max(maxx, arr[k]);
            }
            int temp = maxx * (j-i+1);
            int nextAns = solve(arr, j+1, k);
            ans = max(ans, temp + nextAns);
        }
        return dp[i] = ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        memset(dp, -1, sizeof(dp));
        return solve(arr, 0, k);
    }
};