#include <bits/stdc++.h>
using namespace std;

static int MOD=1e9+7;
class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<long> dp(n+1,1);    
        dp[0]=0;  
        for(int i=1;i<=n;i++)
            for(int j=delay;j<forget;j++) 
                if(i-j>=0)
                    dp[i]=(dp[i]+dp[i-j])%MOD;   
        return (dp[n]-dp[n-forget]+MOD)%MOD; 
    }
};