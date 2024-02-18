class Solution {
public:
    string lastNonEmptyString(string s) {
        unordered_map<char,int> ump; 
        int maxi=0; 
        for(auto it:s){
            ump[it]++;
            maxi=max(ump[it],maxi);
        }
        
        string ans="";
        for(int i=s.size()-1;i>=0;i--){
            if(ump[s[i]]==maxi){
                ans.push_back(s[i]);
                ump[s[i]]--;
            }
        }
        reverse(ans.begin(),ans.end());

        // happy coding \U0001f44d\U0001f44d\U0001f44d\U0001f44d\U0001f60a
        return ans;
    }
};