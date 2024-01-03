#include <bits/stdc++.h>
using namespace std;

class DataStream {
public:
    vector<int> v;
    int val, k_;
    DataStream(int value, int k) {
        val = value;
        k_ = k;
        v = {};
    }
    
    bool consec(int num) {
        if(num != val){
            v = {};
            return false;
        }else{
            v.push_back(num);
            if(v.size() >= k_){
                return true;
            }
            return false;
        }
    }
};