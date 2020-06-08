/*
PROBLEM:
Return the root node of a binary search tree that matches the given preorder traversal.
(Recall that a binary search tree is a binary tree where for every node, any descendant of node.left has a value < node.val, and any descendant of node.right has a value > node.val.  Also recall that a preorder traversal displays the value of the node first, then traverses node.left, then traverses node.right.)
It's guaranteed that for the given test cases there is always possible to find a binary search tree with the given requirements.
Example 1:
Input: [8,5,1,7,10,12]
Output: [8,5,10,1,7,null,12]

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
    TreeNode* buildBST(TreeNode* &root, int item)
    {
        if(!root)
            return root=new TreeNode(item);
        if(item<root->val)
            root->left=buildBST(root->left,item);
        else
            root->right=buildBST(root->right,item);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root=NULL;
        for(auto i : preorder)
        {
            buildBST(root,i);
        }
        return root;
    }
};
