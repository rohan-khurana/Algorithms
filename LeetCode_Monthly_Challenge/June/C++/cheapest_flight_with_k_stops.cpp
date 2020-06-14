/*
PROBLEM:
There are n cities connected by m flights. Each flight starts from city u and arrives at v with a price w.
Now given all the cities and flights, together with starting city src and the destination dst, your task is to find the cheapest price from src to dst with up to k stops. If there is no such route, output -1.

Example 1:
Input: 
n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
src = 0, dst = 2, k = 1
Output: 200

Example 2:
Input: 
n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
src = 0, dst = 2, k = 0
Output: 500
*/


class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K)
    {
        vector<int> distance(n, INT_MAX);
        distance[src] = 0;
        
        for(int i = 0; i<=K; i++)
        {
            vector<int> temp = distance;
            for (auto& flight : flights) {
                int u = flight[0], v = flight[1], w = flight[2];
                if (distance[u] != INT_MAX && temp[v] > distance[u] + w) {
                    temp[v] = distance[u] + w;
                }
            }
            distance = temp;
        }
        return distance[dst] == INT_MAX ? -1 : distance[dst];
    }
};
