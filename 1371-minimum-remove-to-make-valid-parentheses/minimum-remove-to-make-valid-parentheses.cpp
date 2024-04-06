class Solution {
public:
    string minRemoveToMakeValid(string s){
        int cnt=0;
        for(char &c: s){
            if(c=='(') cnt++;
            else if(c==')')
                if(cnt==0) c='*';
                else cnt--;
        }
        cnt=0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]==')') cnt++;
            else if(s[i]=='(')
                if(cnt==0) s[i]='*';
                else cnt--;
        }
        s.erase(remove(s.begin(),s.end(),'*'),s.end());
        return s;
    }
};