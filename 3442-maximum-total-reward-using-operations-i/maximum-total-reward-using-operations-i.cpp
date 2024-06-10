class Solution {
    int dp[2005][4005];
    int f(int i, int r, int n, vector<int>& nums){
        if(i==n) return 0;
        if(dp[i][r] != -1) return dp[i][r];
        int skip = f(i+1,r,n,nums);
        int take = 0;
        if(r < nums[i])
            take = nums[i] + f(i,r+nums[i],n,nums);
        return dp[i][r] = max(skip,take);
    }
public:
    int maxTotalReward(vector<int>& rewardValues) {
        int n = rewardValues.size();
        sort(rewardValues.begin(),rewardValues.end());
        memset(dp,-1,sizeof(dp));
        return f(0,0,n,rewardValues);
    }
};