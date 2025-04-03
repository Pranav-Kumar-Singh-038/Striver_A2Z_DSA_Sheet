#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> bfs(vector<vector<int>> &adj)
    {
        vector<int> ans;               
        vector<bool> visited(adj.size(), false); 
        queue<int> q;

        q.push(0);
        visited[0] = true;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for (int neighbor : adj[node])
            {
                if (!visited[neighbor])
                {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        return ans;
    }

};

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> vec(n);
    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        for (int j = 0; j < m; j++)
        {
            int x;
            cin >> x;
            vec[i].push_back(x);
        }
    }

    Solution sol;
    vector<int> ans = sol.bfs(vec);
    for (auto &it : ans)
    {
        cout << it << " ";
    }
}