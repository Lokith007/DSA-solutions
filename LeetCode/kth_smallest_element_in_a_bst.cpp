// Kth Smallest Element in a BST [Medium]
// https://leetcode.com/problems/kth-smallest-element-in-a-bst/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void preOrderTraversal(TreeNode* root, vector<int> &val){
        if(root == NULL){
            return;
        } 
        val.push_back(root->val);
        preOrderTraversal(root->left, val);
        preOrderTraversal(root->right, val);      
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> v; 
        preOrderTraversal(root, v);
        sort(v.begin(), v.end());
        return v[k-1];
    }
};