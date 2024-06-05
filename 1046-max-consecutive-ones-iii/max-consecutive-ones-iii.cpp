class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int kk=k,mx=0,cnt=0,ii=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                cnt++;
                mx=max(mx,cnt);
                cout<<i+1<<' '<<cnt<<endl;
            }
            else {
                if(kk>0){
                    cnt++;
                    kk--;
                    mx=max(mx,cnt);
                    cout<<i+1<<' '<<cnt<<endl;
                }
                else{
                    while(ii<i){
                        if(nums[ii]==1){
                            cnt--;
                            ii++;
                        }
                        else{
                            kk++;cnt--;ii++;
                            break;
                        }
                    }
                    if(kk>0){
                        cnt++;
                        mx=max(mx,cnt);
                        cout<<i+1<<' '<<cnt<<endl;
                        kk--;
                    }
                    else{
                        ii++;
                    }
                }
            }
        }
        return mx;
    }
};