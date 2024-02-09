int n;
unordered_map<int,int> mp;
class Solution {
private:
    bool isPossible(int i, int jump, vector<int>& stones, int dp[][2002]){
        if(i == n-1) return true;
        if(dp[i][jump] != -1) return dp[i][jump];

        for(int nxtJump = jump - 1; nxtJump <= jump + 1; nxtJump++){
            if(nxtJump > 0){
                int next_stone = stones[i] + nxtJump;
                if(mp.find(next_stone) != mp.end() && isPossible(mp[next_stone],nxtJump,stones,dp)){
                    return dp[i][jump] = true;
                }
            }
        }

        return dp[i][jump] = false;
    }
public:
    bool canCross(vector<int>& stones) {
        if(stones[1] != 1) return false;
        mp.clear();
        n = stones.size();

        for(int i=0; i<n; i++){
            mp[stones[i]] = i;
        }

        int dp[2002][2002];
        memset(dp,-1,sizeof(dp));

        return isPossible(0,0,stones,dp);
    }
};