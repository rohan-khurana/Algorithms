"""
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

"""


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


class Solution:
    def invertTree(self, root: TreeNode) -> TreeNode:
        if root is None:
            return None
        l=self.invertTree(root.left)
        r=self.invertTree(root.right)
            
        root.right=l
        root.left=r
        return root