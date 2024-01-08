#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if(s.size() <= 10){
            return {};
        }
        unordered_map<string, int> mp;
        for(int i = 0; i <= s.size()-10; i++){
            string str = s.substr(i, 10);
            mp[str]++;
        }

        vector<string> res;
        for(auto p: mp){
            if(p.second > 1){
                res.push_back(p.first);
            }
        }

        return res;
    }
};