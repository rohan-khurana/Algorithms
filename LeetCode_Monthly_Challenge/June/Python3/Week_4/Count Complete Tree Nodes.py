"""
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
"""



# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


class Solution:
    def countNodes(self, root: TreeNode) -> int:
        if root==None:
            return 0
        return 1 + self.countNodes(root.left) + self.countNodes(root.right)
        
