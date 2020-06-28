//https://leetcode.com/explore/featured/card/june-leetcoding-challenge/542/week-4-june-22nd-june-28th/3374/
/*
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
    void dfs(string s,vector<string>&ans,map<string,priority_queue<string,vector<string>,greater<string>>>&mp)
    {
        while(!mp[s].empty())
        {
            string temp = mp[s].top();
            mp[s].pop();
            dfs(temp,ans,mp);
        }
        ans.insert(ans.begin(),s);
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        map<string,priority_queue<string,vector<string>,greater<string>>>mp;
        for(int i=0;i<tickets.size();i++){
            mp[tickets[i][0]].push(tickets[i][1]);
        }
        
        vector<string>ans;
        dfs("JFK",ans,mp);
        return ans;
        
    }
};
