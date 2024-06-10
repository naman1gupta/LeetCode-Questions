class Solution {
public:
    int maxTotalReward(vector<int>& rewards) {
        int n = rewards.size();
        sort(rewards.begin(), rewards.end());
        bool dp[50000] = {};
        dp[0] = true;
        int maximum_reward = 0;
        for (int i = 0; i < n; i++) {
            if (i == 0 || rewards[i - 1] != rewards[i]) {
                int limit = min(rewards[i], rewards[n - 1] - rewards[i]);
                for (int j = 0; j < limit; j++) {
                    if (dp[j]) {
                        dp[j + rewards[i]] = true;
                        maximum_reward = max(maximum_reward, j + rewards[i]);
                    }
                }
            }
        }
        return maximum_reward + rewards[n - 1];
    }
};