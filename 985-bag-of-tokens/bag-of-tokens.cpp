class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int n = tokens.size();
        int score = 0, mx = 0,l = 0,r = n - 1;
        while (l <= r) {
            if (power >= tokens[l]) {
                power -= tokens[l];
                score += 1;
                l += 1;
                mx = max(mx, score);
            } else if (score > 0) {
                power += tokens[r];
                score -= 1;
                r -= 1;
            } else {
                break;
            }
        }
        
        return mx;
    }
};