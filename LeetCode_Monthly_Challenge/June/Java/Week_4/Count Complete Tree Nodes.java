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
    public int countNodes(TreeNode root) {
        if(root==null)
            return 0;
        return 1 + countNodes(root.left) + countNodes(root.right);
    }
}
