class Solution {
public:
const int modu=1e9+7;
    int maxSum(vector<int>& nums, int k) {
      int cnt[31];
      memset(cnt,0,sizeof(cnt));
      for(int i=0;i<nums.size();i++){
          for(int j=0;j<31;j++){
              int bit=(nums[i]>>j)&1;
              if(bit==1)
              cnt[j]++;
          }
      }
      vector<long long>v(k,0);
      for(int i=0;i<k;i++){
          for(int j=0;j<31;j++){
              if(cnt[j]>0){
                  cnt[j]--;
                  v[i]|=(1<<j);
              }
          }
      }
      long long sum=0;
      for(int i=0;i<k;i++){
         sum=((sum%modu)+(v[i]%modu*v[i]%modu)%modu)%modu;
      }
      return (int)sum;
    }
};