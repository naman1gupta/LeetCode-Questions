class Solution {
public:
    map<pair<string, string>, bool> m;
    bool okk(string s1, string s2) {
        int count[26] = {0};
        for (int i = 0; i < s1.length(); i++) {
            count[s1[i] - 'a']++;
            count[s2[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (count[i] != 0) {
                return false;
            }
        }
        return true;
        
    }

    bool isScramble(string s1, string s2) 
    {
        
        if (s1 == s2) {
            return true;
        }
        if (m.count(make_pair(s1, s2))) {
            return m[make_pair(s1, s2)];
        }
        if (!okk(s1, s2)) {
            return false;
        }
        for (int i = 1; i < s1.length(); i++) {
            if ((isScramble(s1.substr(0, i), s2.substr(s2.length() - i)) && isScramble(s1.substr(i), s2.substr(0, s2.length() - i)))
                || (isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i)))) {
                m[make_pair(s1, s2)] = true;
                return true;
            }
        }
        m[make_pair(s1, s2)] = false;
        return false;
    }
    
    
};