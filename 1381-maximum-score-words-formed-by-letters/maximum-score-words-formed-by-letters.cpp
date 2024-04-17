class Solution {
public:
        int calcScore(string &word, vector<int>&mp, vector<int>&score){
        int scre = 0;
        for(char c: word){
            if(mp[c-'a']==0) return INT_MIN;
            mp[c-'a']--;
            scre+=score[c-'a'];
        }
        return scre;
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int res = 0, temp, n = words.size();
        vector<int>mp(26);
        for(char c: letters) mp[c-'a']++;
        for(int mask = 0; mask<(1<<n); mask++){//generating all combinations
            temp = 0;
            vector<int>tmp = mp;//O(26)
            for(int i=0; i<n; i++){
                if(mask & 1<<i){//ith word is chosen
                    temp+=calcScore(words[i], tmp, score);
                    if(temp<0) break;
                }
            }
            res = max(res, temp);
        }
        return res;
    }
};