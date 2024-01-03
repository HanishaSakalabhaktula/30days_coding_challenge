#include <bits/stdc++.h>
using namespace std;

class Solution{   
public:
    string final_ans;
    void helper(string s, int idx, int n, string &ans, vector<int>& used){
        if(idx >= n){
            final_ans = final_ans.size() == 0 ? ans : min(final_ans, ans);
            return ;
        }
        
        for(int i = 1; i <= 9; i++){
            if(s[idx] == 'I' and ans[idx] < (i + '0') and used[i] == 0){
                ans += (i + '0');
                used[i] = 1;
                helper(s, idx+1, n, ans, used);
                used[i] = 0;
                ans.pop_back();
            }
            
            if(s[idx] == 'D' and ans[idx] > (i + '0') and used[i] == 0){
                ans += (i + '0');
                used[i] = 1;
                helper(s, idx+1, n, ans, used);
                used[i] = 0;
                ans.pop_back();
            }
        }
    }
    string printMinNumberForPattern(string S){
        // code here 
        vector<int> used(10, 0);
        for(int i = 1; i <= 9; i++){
            string output = "";
            output += (i+'0');
            used[i] = 1;
            helper(S, 0, S.size(), output, used);
            used[i] = 0;
        }
        
        return final_ans;
    }
};