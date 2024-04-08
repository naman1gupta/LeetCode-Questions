class Solution {
public:
    int combinationSum4(vector<int>&nums, int target) {
        int n = nums.size();
        //combination sum.
        //note that here it is important to note that dp[4]=dp[3]+dp[1]+dp[2];
        //i.e the no of combinations when the last added elements were 3,1,2. 
        //Here it is important which was the last added element;
        vector<unsigned long long> dp(target+1,0);
        dp[0]=1;
        for(int i=1;i<=target;i++){
            for(int j=0;j<n;j++){
                if(i-nums[j]>=0){
                    dp[i]=(dp[i]+dp[i-nums[j]]);
                }
            }
        }
        return dp[target];
    }
};