#define MOD 1000000007
class Solution {
public:
    int valueAfterKSeconds(int n, int k) {
        vector<int> v(n,1);
        
        v[0] = 1;
        for(int i = 0; i<k; i++){
            for(int j = 1; j<n; j++){
                v[j] =(v[j-1] + v[j]) % MOD;
            }
        }
       
        return v[n-1] ;
    }
};