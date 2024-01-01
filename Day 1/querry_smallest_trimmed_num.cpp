#include <bits/stdc++.h>
using namespace std;

vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> res;
        int n = nums.size();

        for(auto q: queries){
            int k = q[0];
            int d = q[1];

            k = min(k, n);

            priority_queue<pair<string, int> > pq;
            for(int i = 0; i < n; i++){
                string str = nums[i].substr(nums[i].size()-d);
                if(pq.size() < k){
                    pq.push({str , i});
                }else{
                    if(pq.top().first > str){
                        pq.pop();
                        pq.push({str, i});
                    }
                }
            }

            res.push_back(pq.top().second);
        }
        return res;
    }

int main(){
    int n, q;
    cin>>n>>q;

    vector<string> nums;
    vector<vector<int>> queries;

    for(int i = 0; i < n; i++){
        string str;
        cin>>str;
        nums.push_back(str);
    }

    cout<<"Enter the querries"<<endl;
    for(int i = 0; i < q; i++){
        int a, b;
        cin>>a>>b;

        queries.push_back({a, b});
    }

    vector<int> res = smallestTrimmedNumbers(nums, queries);
    return 0;
}