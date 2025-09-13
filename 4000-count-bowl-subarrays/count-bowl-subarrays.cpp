class Solution {
public:
    long long bowlSubarrays(vector<int>& nums) {
        long long ans = 0;
        stack<int> s;
        for (int i = 0; i < nums.size(); i++) {
            while (!s.empty() && nums[s.top()] < nums[i]) {
                s.pop();
                if (!s.empty()) {
                    ans++;
                }
            }
            s.push(i);
        }

        return ans;
    }
};