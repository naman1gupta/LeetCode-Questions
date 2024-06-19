class StockSpanner {
public:
    vector<int>v;
    stack<pair<int,int>>s;int i=0;
    StockSpanner() {
        // return NULL;
    }
    int next(int price) {
            if(s.size()==0){
                v.push_back(-1);
            }
            else if(s.size()>0 && s.top().first>price){
                v.push_back(s.top().second);
            }
            else{
                while(s.size()>0 && s.top().first<=price){
                    s.pop();
                }
                if(s.size()==0) v.push_back(-1);
                else v.push_back(s.top().second);
            }
            s.push({price,i});
            v[i]=i-v[i];
            cout<<v[i]<<' '<<i<<"\n";
            return v[i++];
        }    
};
/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */