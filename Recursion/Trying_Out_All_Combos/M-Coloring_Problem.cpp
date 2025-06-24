#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isSafe(int node, vector<int> &color, vector<vector<int>> &adj, int c)
    {
        for (int neighbor : adj[node]) // TC: O(v)
        {
            if (color[neighbor] == c)
            {
                return false;
            }
        }
        return true;
    }

    bool solve(int node, vector<int> &color, vector<vector<int>> &adj, int m, int V)
    {

        if (node == V)
        {
            return true;
        }

        for (int c = 1; c <= m; c++) // TC: O(m)
        {
            if (isSafe(node, color, adj, c)) // TC: O(v)
            {
                color[node] = c;
                if (solve(node + 1, color, adj, m, V)) // SC: O(v)
                {
                    return true;
                }
                color[node] = 0;
            }
        }
        return false;
    }

    bool graphColoring(int V, vector<vector<int>> &edges, int m) // first make an adjacency list for traversal, , then for each node assing one color then check for the next node, if it continues then return true, if it breaks any where try with next color, have a color matrix which stores the color of each node which can be used later to confirm if there are any nodes of the same color nearby
    {
        // TC: O(m^v*v + e), SC: O(v+v*v+m)
        vector<vector<int>> adj(V); // SC: O(v+e)  //     For each edge {u, v}: You do adj[u].push_back(v) and adj[v].push_back(u) for undirected So, each edge appears twice, once in each list. That’s: O(2E)(i.e., E neighbors per side) O(2E)
        for (auto &edge : edges) // TC: O(edges.size())
        {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> color(V, 0); // SC: O(m)
        return solve(0, color, adj, m, V);
    }
};

int main()
{
    int v, e, m;
    cin >> v >> e >> m;
    vector<vector<int>> edges(e, vector<int>(2));
    for (vector<int> &vec : edges)
    {
        for (int &val : vec)
        {
            cin >> val;
        }
    }

    Solution sol;
    bool ans = sol.graphColoring(v, edges, m);
    cout << ans;
    return 0;
}