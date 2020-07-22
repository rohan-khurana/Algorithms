/*
PROBLEM:
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).
For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]
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
    private void dfs(TreeNode root, int level, List<List<Integer>> result) {
        if (root == null) return;
        if (result.size() <= level) {
            result.add(new ArrayList<>());
        }
        if ((level % 2) == 0) {
            result.get(level).add(root.val);
        } else {
            result.get(level).add(0, root.val);
        }

        dfs(root.left, level + 1, result);
        dfs(root.right, level + 1, result);
    }
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> result = new ArrayList<>();
        dfs(root, 0, result);
        return result;
    }
}
