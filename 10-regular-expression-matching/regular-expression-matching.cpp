// 1. Top Down  - (Recursive)
//     n = s.size() m = p.size()
//     dp[i][j]  stores whether that it is possible to make  s[i....n-1] from p[j....m-1] or not 
// 	There are basically two cases possible 
// 	  ** here matching condition is using two properties 
// 	  --> either character of s and p should match 
// 	  --> or we have char* which can produce itself in the form of empty to infinity 
// 	       ex - (a*) === "","a", "aa","aaa","aaaa", ............................................
// 		   to convert it into code language just move the s idx and dont move the p idx 
 	
	class Solution {
    public:
    int dp[21][21];
    bool solve(int i,int j,string &s,string &p){
        if(j == p.size())return (i == s.size());
        
        if(dp[i][j] != -1)return dp[i][j];
        bool ans = 0;
        auto match = [&](int idx1,int idx2){
          return (p[idx2] == '.' ? idx1 < s.size() : (s[idx1] == p[idx2]));
        };
        
        if(j + 1 < p.size() && p[j + 1] == '*'){
            ans = solve(i,j + 2, s, p);
            ans |= (match(i,j) && solve(i + 1, j, s, p));
        
        }
        else if(match(i,j)){
            ans = solve(i + 1, j + 1, s, p);
        }
        return dp[i][j] = ans;
    }
    
    bool isMatch(string s, string p) {  
        memset(dp,-1,sizeof dp);
        return solve(0,0,s,p);
    }
};

// 2. Bottom Up (Iterative)

//     n = s.size() m = p.size()
//     dp[i][j]  stores whether that it is possible to make  s[0..j-1] from p[0...i-1] or not 

// class Solution {
// public:
//     bool isMatch(string s, string p) {
//         int n = p.size(), m = s.size();
//         bool dp[n + 1][m + 1];
//         memset(dp,0,sizeof dp);
//         dp[0][0] = 1;
//         for(int i = 2; i <= n; i++){
//             // s is empty and p is a* therefore p can become empty as well
//             // s = "" and p = a*b* then ultimately they both are equal
//             if(p[i-1] == '*')dp[i][0] = dp[i-2][0];
//         }
        
//         for(int i = 1; i <= n; i++){
//             for(int j = 1; j <= m; j++){
//                 // if both character are same or p can take the exact same character as s it
//                 if(p[i - 1] == s[j - 1] || p[i - 1] == '.')dp[i][j] = dp[i-1][j-1];
//                 else if(p[i - 1] == '*'){
//                     // if we take 0 into account of * that means we dont include * cnt 
//                     dp[i][j] |= dp[i - 2][j];
//                     //  or the character before * matches with the string s then we extent cnt of * acc to need
//                     if(p[i - 2] == s[j - 1] || p[i - 2] == '.')dp[i][j] |= dp[i][j-1];
//                 }
//             }
//         }
        
//         return dp[n][m];

        
//     }
// };


// to help optimize--
// https://stackoverflow.com/questions/17246670/0-1-knapsack-dynamic-programming-optimization-from-2d-matrix-to-1d-matrix/26325369#26325369