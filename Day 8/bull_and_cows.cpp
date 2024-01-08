#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0;
        int cows = 0;
        unordered_map<char, int> mp;

        for(int i = 0; i < secret.size(); i++){
            if(secret[i] == guess[i]){
                bulls++;
                secret[i] = '#';
            }else{
                mp[guess[i]]++;
            }
        }  

        for(int i = 0; i < secret.size(); i++){
            if(secret[i] != '#'){
                if(mp.find(secret[i]) != mp.end()){
                    cows++;
                    mp[secret[i]]--;
                    if(mp[secret[i]] == 0){
                        mp.erase(secret[i]);
                    }
                }
            }
        }

        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};