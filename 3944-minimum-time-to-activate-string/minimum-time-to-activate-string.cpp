class Solution {
public:
    int minTime(string s, vector<int>& order, int k) {
    set<int> st;
    auto ss = [](long long l, long long r){ return (r - l - 1) * (r - l) / 2; };
    long long invalid = s.size() * (s.size() + 1) / 2, all = invalid;
    if (k > all)
        return -1;
    for (long long i : order) {
        auto it = st.insert(i).first;
        long long l = it == begin(st) ? -1 : *prev(it);
        long long r = next(it) == end(st) ? s.size() : *next(it);
        invalid += ss(l, i) + ss(i, r) - ss(l, r);
        if (all - invalid >= k)
            break;
    }
    return st.size() - 1;
}
};