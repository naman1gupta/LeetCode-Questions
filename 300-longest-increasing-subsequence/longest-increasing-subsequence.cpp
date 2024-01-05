class Solution {
public:
    int lengthOfLIS(vector<int>&a) {
    int n1 = a.size();
    const int INF = 1e9;
    vector<int> d(n1+1, INF);
    d[0] = -INF;
    
    for (int i = 0; i < n1; i++) {
        int j = upper_bound(d.begin(), d.end(), a[i]) - d.begin();
        if (d[j-1] < a[i] && a[i] < d[j])
            d[j] = a[i];
    }
    
    int ans = 0;
    
    for (int i = 0; i <= n1; i++) {
        if (d[i] < INF)
            ans = i;
    }
    
    return ans;
    }
};