#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMoves2(vector<int>& nums) {
       sort(nums.begin(), nums.end());
       int n = nums.size();
       int num ;
       if(n%2 == 0){
           int a = nums[n/2];
           int b = nums[n/2-1];

           num = a + (b-a)/2;
       } else{
           num = nums[n/2];
       }

       int ans = 0;
           for(int i = 0; i < n; i++){
               ans += abs(num - nums[i]);
           }
           return ans;
    }
};