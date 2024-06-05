class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.length();
        if(n == 0 || n < k) return 0;
        if(k == 1) return n;

        unordered_map<char,int> freq;
        for(char c : s) freq[c]++;

        int i = 0;
        while(i < n && freq[s[i]] >= k) i++;
        if(i == n) return n;

        int left = longestSubstring(s.substr(0,i), k);
        while(i < n && freq[s[i]] < k) i++;
        int right = longestSubstring(s.substr(i), k);

        return max(left,right);
    }
};
//upvote if this solution helps you