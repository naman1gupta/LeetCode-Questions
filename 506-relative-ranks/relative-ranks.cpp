class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<score.size();i++){
            pq.push({score[i],i});
        }
        int cnt=0;
        vector<string>vs(score.size());
        while(!pq.empty()){
            cnt++;
            if(cnt==1){
                vs[pq.top().second]=("Gold Medal");
            }
            else if(cnt==2){
                vs[pq.top().second]=("Silver Medal");
            }
            else if(cnt==3){
                vs[pq.top().second]=("Bronze Medal");
            }
            else {
                // string ss=cnt+"0";
                vs[pq.top().second]=(to_string(cnt));
            }
            pq.pop();
        }
        return vs;
    }
};