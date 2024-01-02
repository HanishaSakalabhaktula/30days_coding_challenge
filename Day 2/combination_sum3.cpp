#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> res;
    void helper(int num, int k, int n, vector<int> temp){
        if(k == 0 and n == 0){
            res.push_back(temp);
            return;
        }

        if(k <= 0 || n <= 0){
            return;
        }

        for(int i = num; i <= 9; i++){
            temp.push_back(i);
            helper(i+1, k-1, n-i, temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        if(k == 1 and n >= 1 and n <= 9){
            return {{n}};
        }else if(k == 1){
            return res;
        }

        vector<int> temp;
        helper(1, k, n, temp);
        return res;
    }

int main(){
    int k, n;
    cin>>k>>n;

    vector<vector<int>> res = combinationSum3(k, n);
    return 0;
}