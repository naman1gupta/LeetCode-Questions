class Solution {
public:
    string makeGood(string s) {
        string t;
        for (auto c : s) {
            if (t.size() && (t.back() ^ (1 << 5)) == c) {
                t.pop_back();
            } else {
                t.push_back(c);
            }
        }
        return t;
    }
};