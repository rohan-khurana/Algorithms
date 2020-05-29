/*
PROBLEM
There are a total of numCourses courses you have to take, labeled from 0 to numCourses-1.
Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

Example 1:
Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0. So it is possible.

Example 2:
Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0, and to take course 0 you should
             also have finished course 1. So it is impossible.
*/

class Solution {
public:
    vector<vector<int>> graph;
    bool dfs(int current, vector<int>& v) 
    {
        if(v[current] == 1) return true;
        if(v[current] == 2) return false;
        v[current] = 1;
        for(int i : graph[current])
            if(dfs(i, v)) 
                return true;
        
        v[current] = 2;
        
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        graph = vector<vector<int>>(numCourses);
        for(auto i : prerequisites)
            graph[i[0]].push_back(i[1]);

        vector<int> v(numCourses, 0);
        for(int i=0; i<numCourses;i++)
            if(dfs(i, v)) 
                return false;
        return true;
    }
    
};
