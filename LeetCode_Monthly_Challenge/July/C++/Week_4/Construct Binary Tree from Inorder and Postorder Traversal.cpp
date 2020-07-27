/*
PROBLEM:
Given inorder and postorder traversal of a tree, construct the binary tree.
Note:
You may assume that duplicates do not exist in the tree.
For example, given
inorder = [9,3,15,20,7]
postorder = [9,15,7,20,3]
Return the following binary tree:
    3
   / \
  9  20
    /  \
   15   7
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
private:
    int post,in;
    TreeNode* Helper(vector<int>& inorder, vector<int>& postorder, int stop) {
    if (post == -1) {
        return NULL;
    }
    
    if (inorder[in] == stop) {
        in--;
        return NULL;
    }
    
    int root_val = postorder[post--];
    TreeNode* root = new TreeNode(root_val);
    root->right = Helper(inorder, postorder, root_val);
    root->left = Helper(inorder, postorder, stop);
    return root;
}

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        post = postorder.size() - 1;
        in = inorder.size() - 1;
        return Helper(inorder, postorder, INT_MIN);
    }
};
