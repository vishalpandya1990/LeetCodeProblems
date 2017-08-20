
/*
 * https://leetcode.com/problems/add-one-row-to-tree/description/
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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if(d == 1) {
             TreeNode *newNode = new TreeNode(v);
             newNode->left = root;
             return newNode;
        }
        
        if(root == NULL) return root;
        struct ds{
          TreeNode *ptr;
          int depth;
        };
        queue<ds> traversalQ;
        ds tmp = {root, 1};
        traversalQ.push(tmp);
        while(!traversalQ.empty()) {
            ds f = traversalQ.front();
            traversalQ.pop();
            if(f.ptr == NULL) continue;
            if(f.depth == d-1){
                TreeNode *l = new TreeNode(v);
                TreeNode *r = new TreeNode(v);
                TreeNode *oldLeft = (f.ptr)->left;
                TreeNode *oldRight = (f.ptr)->right;
                l->left = oldLeft;
                r->right = oldRight;
                (f.ptr)->left = l;
                (f.ptr)->right = r;
            }
            else {
                ds t1 = {(f.ptr)->left, (f.depth)+1};
                ds t2 = {(f.ptr)->right, (f.depth)+1};
                traversalQ.push(t1);
                traversalQ.push(t2);
            }
            
        }
        
       return root;    
    }
};
