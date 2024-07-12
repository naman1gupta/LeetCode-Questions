class Solution {
public:
vector<vector<int>>ans;
vector<int>v;
    void helper(vector<int>& candidate, int target, int sum, int indx){
        if(sum==target){
            ans.push_back(v);
            return;
        }
        for(int i=indx;i<candidate.size();i++){
            if((target-sum) >= candidate[i]){
                sum+=candidate[i];
                indx=i;
                v.push_back(candidate[i]);
                helper(candidate,target,sum, indx);
                sum-=candidate[i];
                v.pop_back();
            }
        }
    } 
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>candidate=candidates;
        sort(candidate.begin(),candidate.end());
        helper(candidate,target,0, 0);
        return ans;
    }
};