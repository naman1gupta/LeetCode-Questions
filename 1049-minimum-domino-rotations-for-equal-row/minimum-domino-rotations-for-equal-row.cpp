class Solution {
public:
    
    int countdiff(vector<int>&tops, vector<int>&bottoms, int num){
        int counttops=0,countbot=0;
        for(int i=0;i<tops.size();i++){
            if(tops[i]!=num && bottoms[i]!=num) return -1;
            if(tops[i]!=num)counttops++;
            if(bottoms[i]!=num)countbot++;
        }
        return min(counttops,countbot);
    }
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int res1 = countdiff(tops,bottoms,tops[0]);
        int res2 = countdiff(tops,bottoms,bottoms[0]);
        return(min(res1,res2)<0)?max(res1,res2):min(res1,res2);
    }
};