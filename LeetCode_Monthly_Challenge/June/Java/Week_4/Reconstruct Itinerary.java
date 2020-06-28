/*
PROBLEM:
Given a list of airline tickets represented by pairs of departure and arrival airports [from, to], reconstruct the itinerary in order. All of the tickets belong to a man who departs from JFK. Thus, the itinerary must begin with JFK.
Note:
If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string. For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
All airports are represented by three capital letters (IATA code).
You may assume all tickets form at least one valid itinerary.
One must use all the tickets once and only once.

Example 1:
Input: [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
Output: ["JFK", "MUC", "LHR", "SFO", "SJC"]

Example 2:
Input: [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
Output: ["JFK","ATL","JFK","SFO","ATL","SFO"]
Explanation: Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"].
             But it is larger in lexical order.
*/



class Solution {
    private List<String> result = new ArrayList<>();
    private Map<String, PriorityQueue<String>> adjList = new HashMap<>();
    
    public List<String> findItinerary(List<List<String>> tickets) {
        for(List<String> ticket : tickets){
            String from = ticket.get(0);
            String to = ticket.get(1);
            if(!adjList.containsKey(from))
            {
                PriorityQueue<String> p = new PriorityQueue<>();
                p.add(to);
                adjList.put(from, p);
            }
            else
            {
                adjList.get(from).add(to);
            }
        }
        dfs("JFK");
        return result;
    }
    
    
     private void dfs(String start){
        while(adjList.containsKey(start) && adjList.get(start).size() != 0){
            dfs(adjList.get(start).poll());
        }
        result.add(0, start);
    }
}
