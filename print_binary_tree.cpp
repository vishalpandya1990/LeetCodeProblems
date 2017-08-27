
/*
 * Problem statement :- https://leetcode.com/problems/print-binary-tree/description/
 */


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int getHeight(TreeNode *root) {
        if(!root) return 0;
        int l = getHeight(root->left);
        int r = getHeight(root->right);
        return 1 + max(l, r);
    }
    void printSubTreeAtThisRoot(TreeNode *root, vector<vector<string>>& res, int row, int colStart, int colEnd) {
        if(!root) return;
        int mid = (colStart + colEnd)/2;
        assert(mid >= 0 && mid < res[row].size());
        res[row][mid] = to_string(root->val);
        if(root->left){
            printSubTreeAtThisRoot(root->left, res, row + 1, colStart, mid-1);
        }
        if(root->right){
            printSubTreeAtThisRoot(root->right, res, row + 1, mid+1, colEnd);
        }
    }
    vector<vector<string>> printTree(TreeNode* root) {
        int h = getHeight(root);
        int m = h;
        int n = pow(2, h) - 1;
        vector<vector<string>> res(m);
        for(int i = 0; i < m; i++) {
            res[i].resize(n);
            for(int j = 0; j < n; j++)
                res[i][j]="";
        }
        printSubTreeAtThisRoot(root, res, 0, 0, n-1);
        return res;
    }
};
