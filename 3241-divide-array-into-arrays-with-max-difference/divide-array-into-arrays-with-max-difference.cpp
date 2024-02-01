class Solution {
public:
    std::vector<std::vector<int>> divideArray(std::vector<int>& nums, int k) {
        int l = nums.size();
        if (l % 3 != 0) {
            return std::vector<std::vector<int>>();
        }

        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> result(l / 3, std::vector<int>(3, 0));
        int c = 0;

        for (int i = 0; i < result.size(); ++i) {
            for (int j = 0; j < 3; ++j) {
                if (c < l - 1 && (c + 3) % 3 == 0 && nums[c + 2] - nums[c] > k) {
                    return std::vector<std::vector<int>>();
                }
                result[i][j] = nums[c++];
            }
        }

        return result;
    }
};