class Solution {
public:
vector<string>ans;
string s;
    void helper(int n, int left_found, int right_found){
        if(right_found==n){
            ans.push_back(s);
            return;
        }
        if(left_found<n){
            left_found++;
            s.push_back('(');
            helper(n,left_found,right_found);
            s.pop_back();
            left_found--;
        }
        if(right_found<left_found and right_found<n){
            right_found++;
            s.push_back(')');
            helper(n,left_found,right_found);
            s.pop_back();
            right_found--;
        }
    }
    vector<string> generateParenthesis(int n) {
        helper(n,0,0);
        return ans;
    }
};