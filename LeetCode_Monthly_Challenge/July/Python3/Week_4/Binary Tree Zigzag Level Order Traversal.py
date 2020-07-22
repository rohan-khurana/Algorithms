"""
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
"""



# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right



class Solution:
    def DFS(self, root: TreeNode, level: int, ans: List[List[int]]):
        if root is None: return
        if len(ans) <= level:
            ans.append([]);
        if level % 2 == 0:
            ans[level].append(root.val);
        else:
            ans[level].insert(0, root.val);
        self.DFS(root.left, level + 1, ans);
        self.DFS(root.right, level + 1, ans);
    
    def zigzagLevelOrder(self, root: TreeNode) -> List[List[int]]:
        ans = []
        self.DFS(root, 0, ans)
        return ans
