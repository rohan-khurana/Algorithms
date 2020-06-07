/*
PROBLEM:
Invert a binary tree.
Example:
Input:

     4
   /   \
  2     7
 / \   / \
1   3 6   9
Output:
     4
   /   \
  7     2
 / \   / \
9   6 3   1
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
    public TreeNode invertTree(TreeNode root) {
        if(root==null)
            return null;
        else{
            TreeNode temp;
            invertTree(root.left);
            invertTree(root.right);
            
            temp=root.left;
            root.left=root.right;
            root.right=temp;
        }
        return root;
    }
}