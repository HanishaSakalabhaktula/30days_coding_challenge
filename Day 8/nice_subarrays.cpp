#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int odd = 0;
        int nice = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i]%2 == 1){
                odd++;
            }

            if(odd == k){
                nice++;
            }
            if(odd >= k){
                nice += (mp[odd - k]);
            }
            mp[odd]++;
        }
        return nice;
    }
};