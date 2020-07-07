/*
PROBLEM:
You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water.
Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).
The island doesn't have "lakes" (water inside that isn't connected to the water around the island). One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.
Example:
Input:
[[0,1,0,0],
 [1,1,1,0],
 [0,1,0,0],
 [1,1,0,0]]
Output: 16
*/



class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>& grid){
        int count=0;
        if(i>0 && grid[i-1][j]==1)
            count++;
        if(j>0 && grid[i][j-1]==1)
            count++;
        if(i<grid.size()-1 && grid[i+1][j]==1)
            count++;
        if(j<grid[0].size()-1 && grid[i][j+1]==1)
            count++;
        return count;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int result = 0;
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[0].size(); j++)
                if (grid[i][j] == 1)
                    result += (4-dfs(i,j,grid));
        return result;
    }
};
