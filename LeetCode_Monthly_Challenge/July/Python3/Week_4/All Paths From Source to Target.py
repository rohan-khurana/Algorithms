"""
PROBLEM:
Given a directed, acyclic graph of N nodes.  Find all possible paths from node 0 to node N-1, and return them in any order.
The graph is given as follows:  the nodes are 0, 1, ..., graph.length - 1.  graph[i] is a list of all nodes j for which the edge (i, j) exists.
Example:
Input: [[1,2], [3], [3], []] 
Output: [[0,1,3],[0,2,3]] 
Explanation: The graph looks like this:
0--->1
|    |
v    v
2--->3
There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.
Note:
The number of nodes in the graph will be in the range [2, 15].
You can print different paths in any order, but you should keep the order of nodes inside one path.
"""



class Solution:
    def dfs(self, curr: int, graph: List[List[int]], path: List[int], result: List[List[int]]):
        if curr == (len(graph)-1):
            result.append(path)
            return
        for i in graph[curr]:
            self.dfs(i, graph, path + [i], result)
                
    def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:
        result = []
        self.dfs(0, graph, [0], result)
        return result
