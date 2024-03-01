class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        string ss;int cnt=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1') cnt++;

        }
        for(int i=1;i<=cnt-1;i++){
            ss.push_back('1');
        }
        for(int i=0;i<s.size()-cnt;i++) ss.push_back('0');
        ss.push_back('1');
        return ss;
    }
};