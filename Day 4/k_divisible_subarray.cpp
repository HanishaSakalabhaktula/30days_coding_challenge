#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        set<vector<int>> s; 
        for(int i = 0; i < nums.size(); i++){
            vector<int> temp;
            int cnt = 0;
            int j = i;
            while(cnt <= k and j < nums.size()){
                temp.push_back(nums[j]);
                if(nums[j]%p == 0){
                    cnt++;
                }
                
                if(cnt <= k){
                    s.insert(temp);
                }
                j++;
            }
        }
        
        return s.size();
    }
};