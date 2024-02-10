class Solution {
public:
    int countSubstrings(string s) {
        int res = 0;
        int len = s.size();
        for (int mid = 0; mid<len; mid++){
            for(int rad = 0; mid-rad>=0 && mid+rad<len && s[mid-rad]==s[mid+rad]; rad++){
                res++;     
            }
        }
        for (int mid = 0; mid<len-1; mid++){
            for(int rad = 0; mid-rad>=0 && mid+1+rad<len && s[mid-rad]==s[mid+1+rad]; rad++){
                res++;
            }
        }
        
        return res;
    }
};