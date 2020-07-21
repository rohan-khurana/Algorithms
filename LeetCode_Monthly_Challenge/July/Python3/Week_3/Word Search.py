"""
PROBLEM:
Given a 2D board and a word, find if the word exists in the grid.
The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example:
board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]
Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.
 
Constraints:
board and word consists only of lowercase and uppercase English letters.
1 <= board.length <= 200
1 <= board[i].length <= 200
1 <= word.length <= 10^3
"""



class Solution:
    def dfs(self, board: List[List[str]], word: str, i: int, j: int, index: int) -> bool:
        if index==len(word)-1: return True
        ch, board[i][j] = board[i][j], '#'
        
        if(i>0 and board[i-1][j]==word[index+1] and self.dfs(board,word,i-1,j,index+1)): return True
        if(j>0 and board[i][j-1]==word[index+1] and self.dfs(board,word,i,j-1,index+1)): return True
        if(i<len(board)-1 and board[i+1][j]==word[index+1] and self.dfs(board,word,i+1,j,index+1)): return True
        if(j<len(board[0])-1 and board[i][j+1]==word[index+1] and self.dfs(board,word,i,j+1,index+1)): return True
        
        board[i][j] = ch
        return False
        
    def exist(self, board: List[List[str]], word: str) -> bool:
        for i in range(len(board)):
            for j in range(len(board[0])):
                if board[i][j] == word[0] and self.dfs(board, word, i, j, 0): return True
        return False
