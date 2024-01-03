#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        // code here
        int axorb = 0;
        for(int i = 0; i < n; i++){
            axorb = (axorb ^ arr[i]);
            axorb = (axorb ^ (i+1));
        }
        
        int differentiating_bit = 0;
        while(true){
            if(((1 << differentiating_bit) & axorb) != 0){
                break;
            }
            differentiating_bit++;
        }
        
        int zero = 0;
        int one = 0;
        
        for(int i = 0; i < n; i++){
            if((arr[i] & (1 << differentiating_bit)) != 0){
                one = (one ^ arr[i]);
            }else{
                zero = (zero ^ arr[i]);
            }
            
            if(((i+1) & (1 << differentiating_bit)) != 0){
                one = (one ^ (i+1));
            }else{
                zero = (zero ^ (i+1));
            }
        }
        
        int rep, miss;
        
        for(int i = 0; i < n; i++){
            if(arr[i] == zero){
                return {zero, one};
            }
            
            if(arr[i] == one){
                return {one, zero};
            }
        }
        
        return {};
    }
};