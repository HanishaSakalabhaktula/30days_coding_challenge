#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[4001][1001];
    int helper(int startPos, int endPos, int k){
        if(startPos == endPos and k == 0){
            return 1;
        }
        if(k <= 0) return 0;

        if(dp[startPos+1000][k] != -1){
            return dp[startPos+1000][k];
        }

        int mod = 1e9+7;

        int op1 = helper(startPos+1, endPos, k-1);
        int op2 = helper(startPos-1, endPos, k-1);

        dp[startPos+1000][k] = (op1 + op2)%mod;
        return dp[startPos+1000][k];
    }
    int numberOfWays(int startPos, int endPos, int k) {
        for(int i = 0; i < 3001; i++){
            for(int j = 0; j < 1001; j++){
                dp[i][j] = -1;
            }
        }
        return helper(startPos, endPos, k);
    }
};