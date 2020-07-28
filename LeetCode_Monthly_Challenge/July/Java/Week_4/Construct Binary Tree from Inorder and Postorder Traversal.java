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
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
 
 
class Solution {
    int post;
    int in; 
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        post = postorder.length - 1;
        in = inorder.length - 1;
        return Helper(inorder, postorder, Integer.MIN_VALUE - 1);
    }

    private TreeNode Helper(int[] inorder, int[] postorder, int stop) {
        if (post == -1) {
            return null;
        }
        if (inorder[in] == stop) {
            in--;
            return null;
        }
        int root_val = postorder[post--];
        TreeNode root = new TreeNode(root_val);
        root.right = Helper(inorder, postorder, root_val);
        root.left = Helper(inorder, postorder, stop);
        return root;
    }
}
