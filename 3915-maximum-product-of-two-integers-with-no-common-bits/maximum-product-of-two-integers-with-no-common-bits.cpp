class Solution {
public:
    struct node{
        node* children[2];
        int val;
        node(){
            val=-1;
            children[0]=nullptr;
            children[1]=nullptr;
        }
    };

    void insert(node* root,int val){
        node*temp = root;
        for(int i=20;i>=0;i--){
            int b = (val >> i)&1;
            if(!temp->children[b]){
                temp->children[b]=new node();
            }
                temp = temp->children[b];
            
        }
        temp->val=val;
    }

    int search(node* temp,int num,int bit){
        if(!temp)return -1;
        if(bit<0)return temp->val;
        
            int b=(num>>bit)&1;
            if(b==1){
                return search(temp->children[0],num,bit-1);
            }
            else{
              int res1=search(temp->children[1],num,bit-1);
                if(res1!=-1)return res1;
               return search(temp->children[0],num,bit-1); 
            }     
    }

    
    long long maxProduct(vector<int>& nums) {
        node* root = new node();
        for(int x : nums)insert(root,x);

        long long ans=0;

        for(int x : nums){
            int y = search(root,x,20);
            if(y!=-1 && (x&y)==0){
                ans = max(ans,1LL*x*y);
            }
        }
        return ans;
    }
};