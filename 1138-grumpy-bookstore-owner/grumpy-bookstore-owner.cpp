class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int sum=0,mx=0,ii=0;
        for(int i=0;i<grumpy.size();i++){
            if(grumpy[i]==0) sum+=customers[i];
        }
        mx=max(mx,sum);
        for(int i=0;i<grumpy.size();i++){
            // if(grumpy[i]==1){
                if(minutes>0){
                    if(grumpy[i]==1) {
                        sum+=customers[i];
                        
                        mx=max(mx,sum);
                    }
                    minutes--;
                }
                else{
                    // while(ii<i){
                        if(grumpy[ii]==1){
                            sum-=customers[ii];
                        }
                        minutes++;
                        ii++;
                            // break;
                        // }
                        // else ii++;
                    // }
                    if(minutes>0){
                        if(grumpy[i]==1) sum+=customers[i];
                        minutes--;
                        mx=max(mx,sum);
                    }
                }
            // }
        }
        return mx;
    }
};