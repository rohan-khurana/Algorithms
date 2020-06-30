/*
Given a 2D board and a list of words from the dictionary, find all words in the board.
Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.
Example:
Input: 
board = [
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]
words = ["oath","pea","eat","rain"]
Output: ["eat","oath"]

Note:
All inputs are consist of lowercase letters a-z.
The values of words are distinct.
*/



class Solution {
    class TrieNode {
        TrieNode[] next = new TrieNode[26];
        String word;
    }
    
    public List<String> findWords(char[][] board, String[] words) {
        List<String> result = new ArrayList<String>();
        TrieNode root = buildTrie(words);
        for(int i=0; i<board.length; i++){
            for(int j=0; j<board[0].length; j++){
                dfs(i, j, board, root, result);
            }
        }
        return result;
    }
    
    
    private void dfs(int i, int j, char[][] board, TrieNode p, List<String> result){
        if(i>=board.length|| i<0|| j>=board[0].length || j<0) return;
        char c = board[i][j];
        if(c=='#' || p.next[c-'a']==null) return;
        p = p.next[c - 'a'];
        if(p.word!=null){
            result.add(p.word);
            p.word = null;
        }
        board[i][j] = '#';
        dfs(i+1, j, board, p, result);
        dfs(i-1, j, board, p, result);
        dfs(i, j+1, board, p, result);
        dfs(i, j-1, board, p, result);
        board[i][j] = c;
    }

    public TrieNode buildTrie(String[] words) {
        TrieNode root = new TrieNode();
        for (String word : words) {
            TrieNode p = root;
            for (char c : word.toCharArray()) {
                int i = c - 'a';
                if (p.next[i] == null) p.next[i] = new TrieNode();
                p = p.next[i];
           }
           p.word = word;
        }
        return root;
    }
    
}
