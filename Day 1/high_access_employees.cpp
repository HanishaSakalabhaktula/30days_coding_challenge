#include <bits/stdc++.h>
using namespace std;

    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        unordered_map<string, vector<int>> mp;

        for(auto v: access_times){
            int time = stoi(v[1].substr(0, 2)) * 60 + stoi(v[1].substr(2));
            mp[v[0]].push_back(time);
        }

        vector<string> res;

        for(auto p: mp){
            sort(p.second.begin(), p.second.end());
            for(int i = 0; i < p.second.size(); i++){
                if(i+2 < p.second.size() and p.second[i+2] - p.second[i] < 60){
                    res.push_back(p.first);
                    break;
                }
            }
        }

        return res;
    }
int main(){
    int n; //access_time length
    cin>>n;

    vector<vector<string>> v(n, vector<string>(2));
    for(int i = 0; i < n; i++){
        string emp, time;
        cin>>emp>>time;

        v[i][0] = emp;
        v[i][1] = time;
    }

    vector<string> res = findHighAccessEmployees(v);
    return 0;
}