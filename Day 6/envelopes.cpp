#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b){
        if(a[0]==b[0]){
            return a[1]>b[1];
        }
        return a[0]<b[0];
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), cmp);
        vector<vector<int> > dp;
        dp.push_back(envelopes[0]);

        for(int i = 1; i < envelopes.size(); i++){
            int prev_w = dp[dp.size()-1][0];
            int prev_h = dp[dp.size()-1][1];

            int w = envelopes[i][0];
            int h = envelopes[i][1];

            if(prev_w < w and prev_h < h){
                dp.push_back(envelopes[i]);
            }else{
                //search and replace
                int s = 0;
                int e = dp.size()-1;
                int idx = -1;

                while(s <= e){
                    int mid = s + (e-s)/2;
                    if(dp[mid][1] < envelopes[i][1]){
                        idx = mid;
                        s = mid+1;
                    }else{
                        e = mid-1;
                    }
                }

                dp[idx+1] = envelopes[i];
            }
        }

        return dp.size();
    }
};