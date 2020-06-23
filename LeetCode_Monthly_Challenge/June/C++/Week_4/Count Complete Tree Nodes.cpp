/*
PROBLEM:
Given a complete binary tree, count the number of nodes.
Example:
Input: 
    1
   / \
  2   3
 / \  /
4  5 6
Output: 6
*/



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
    int countNodes(TreeNode* root) {
        if(root==NULL)
            return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
