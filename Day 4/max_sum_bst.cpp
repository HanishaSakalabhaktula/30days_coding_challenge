#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int res;
    vector<int> helper(TreeNode* root){
        if(root == NULL){
            return {0, INT_MIN, INT_MAX};
        }
        vector<int> l = helper(root->left);
        vector<int> r = helper(root->right);

        vector<int> ans;
        ans.push_back(l[0] + r[0] + root->val);

        if(root->val > l[1] and root->val < r[2]){
            res = max(res, l[0] + r[0] + root->val);
            if(r[1] == INT_MIN){
                ans.push_back(root->val);
            }else{
                ans.push_back(r[1]);
            }

            if(l[2] == INT_MAX){
                ans.push_back(root->val);
            }else{
                ans.push_back(l[2]);
            }
        }else{
            ans.push_back(INT_MAX);
            ans.push_back(INT_MIN);
        }

        return ans;
    }
    int maxSumBST(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        res = 0;
        vector<int> v = helper(root);
        return res;
    }
};