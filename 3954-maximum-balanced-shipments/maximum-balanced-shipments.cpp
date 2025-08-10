class Solution {
public:
    int maxBalancedShipments(vector<int>& a) {
        int n=a.size();
        int cnt=0, prv=0;
        for(int i=0;i<n;i++){
            if(a[i]<prv) cnt++,prv=0;
            else prv=a[i];
        }
        return cnt;
    }
};