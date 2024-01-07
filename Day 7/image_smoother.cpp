#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(int i, int j, int n, int m){
        if(i >= 0 and i < n and j >= 0 and j < m){
            return true;
        }
        return false;
    }
    int getAvg(vector<vector<int>>&img, int i, int j){
        int cells = 1;
        int sum = img[i][j];

        if(isValid(i-1, j, img.size(), img[i].size())){
            cells++;
            sum += img[i-1][j];
        }
        if(isValid(i+1, j, img.size(), img[i].size())){
            cells++;
            sum += img[i+1][j];
        }
        if(isValid(i, j-1, img.size(), img[i].size())){
            cells++;
            sum += img[i][j-1];
        }
        if(isValid(i, j+1, img.size(), img[i].size())){
            cells++;
            sum += img[i][j+1];
        }
        if(isValid(i-1, j-1, img.size(), img[i].size())){
            cells++;
            sum += img[i-1][j-1];
        }
        if(isValid(i+1, j-1, img.size(), img[i].size())){
            cells++;
            sum += img[i+1][j-1];
        }
        if(isValid(i-1, j+1, img.size(), img[i].size())){
            cells++;
            sum += img[i-1][j+1];
        }
        if(isValid(i+1, j+1, img.size(), img[i].size())){
            cells++;
            sum += img[i+1][j+1];
        }


        return (sum / cells);
    }
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        vector<vector<int>> res(img.size(), vector<int>(img[0].size(), 0));

        for(int i = 0; i < img.size(); i++){
            for(int j = 0; j < img[i].size(); j++){
                res[i][j] = getAvg(img, i, j);
            }
        }

        return res;
    }
};