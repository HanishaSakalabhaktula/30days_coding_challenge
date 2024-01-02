#include <bits/stdc++.h>
using namespace std;
void helper(string digits, int idx, int n, vector<string>& answer, unordered_map<int, vector<char>>& mp, string temp){
        if(idx >= n){
            answer.push_back(temp);
            return;
        }

        int num = digits[idx] - '0';
        for(auto ch: mp[num]){
            helper(digits, idx+1, n, answer, mp, temp + ch);
        }
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<int, vector<char>> mp;
        mp[2] = {'a', 'b', 'c'};
        mp[3] = {'d', 'e', 'f'};
        mp[4] = {'g', 'h', 'i'};
        mp[5] = {'j', 'k', 'l'};
        mp[6] = {'m', 'n', 'o'};
        mp[7] = {'p', 'q', 'r', 's'};
        mp[8] = {'t', 'u', 'v'};
        mp[9] = {'w', 'x', 'y', 'z'};

        vector<string> answer;
        if(digits.size() == 0){
            return answer;
        }
        helper(digits, 0, digits.size(), answer, mp, "");

        return answer;
    }

int main(){
    string str;
    cin>>str;

    vector<string> answer = letterCombinations(str);
    return 0;
}