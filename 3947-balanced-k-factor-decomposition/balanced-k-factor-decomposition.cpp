class Solution {
public:
    vector<int> getdiv(int n) {
        vector<int> ans;
        for (int i = 1; i <= n; i++) {
            if (n % i == 0)
                ans.push_back(i);
        }
        return ans;
    }

    void func(int ind, long long prod, vector<int>& div, vector<int>& ans,
              vector<int>& best, int& diff, int k, int n) {
        if (ans.size() == k) {
            if (prod == n) {
                int max_ele = *max_element(ans.begin(), ans.end());
                int min_ele = *min_element(ans.begin(), ans.end());
                int new_diff = max_ele - min_ele;
                if (new_diff < diff) {
                    diff = new_diff;
                    best = ans;
                }
            }
            return;
        }

        for (int i = ind; i < div.size(); i++) {
            int no = div[i];
            long long newProd = prod * no;
            if (newProd > n)
                break;
            if (n % newProd != 0)
                continue;

            ans.push_back(no);
            func(i, newProd, div, ans, best, diff, k, n);
            ans.pop_back();
        }
    }

    vector<int> minDifference(int n, int k) {
        vector<int> div = getdiv(n);
        vector<int> ans, best;
        int diff = INT_MAX;
        func(0, 1, div, ans, best, diff, k, n);
        return best;
    }
};