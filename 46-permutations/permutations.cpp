class Solution {
public:
vector<vector<int>>ans;
vector<int>v;
set<int>st;
    void helper(vector<int>& nums){
        if(v.size()==nums.size()){
            ans.push_back(v);
            // v.pop_back();
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(st.find(nums[i])==st.end()){
                v.push_back(nums[i]);
                st.insert(nums[i]);
                // indx=i;
                helper(nums);
                v.pop_back();
                st.erase(nums[i]);
            }
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        helper(nums);
        return ans;
    }
};