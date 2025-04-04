#include <bits/stdc++.h>
using namespace std;


// 0 -> [1, 2, 4, 8]
// 1 -> [0, 5, 6, 9]
// 2 -> [0, 4]
// ...

//     For node 0, we process 4 neighbors.

//     For node 1, we process 3 new neighbors (since 0 is already visited).

//     Each edge is checked only once.

// Thus, the sum of neighbors over all nodes is exactly E, not V^2.

class Solution
{
public:
    vector<int> dfs(vector<vector<int>> &adj) 
    {
    /*Using a Stack:
      We use a stack for DFS since it follows a last-in, first-out (LIFO) order, ensuring deeper nodes are explored first.
    Maintaining Adjacency Order:
      To ensure nodes are visited in the given order, we push neighbors in reverse so that the first neighbor appears at the top of the stack.
    Marking Nodes as Visited:
      A node is marked only when it is popped from the stack (visited), not when it is pushed.
      This prevents skipping nodes if a shorter path to the same node is found later.
    Avoiding Redundant Stack Entries:
      If a node appears multiple times in the stack (due to different paths), only the latest occurrence matters since earlier ones become redundant.*/

        // TC:O(V+E) explanation above, SC:O(V) not counting the input
        if (adj.empty())
        {
            return {};
        }

        vector<int> ans;
        stack<int> s;
        vector<bool> visited(adj.size(), false);
        s.push(0);

        while (!s.empty())
        {
            int node = s.top();
            s.pop();

            if (visited[node])
            {
                continue;
            }

            visited[node] = true;
            ans.push_back(node);

            for (auto it = adj[node].rbegin(); it != adj[node].rend(); ++it)
            {
                if (!visited[*it])
                {
                    s.push(*it);
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
    vector<int> ans = sol.dfs(vec);
    for (auto &it : ans)
    {
        cout << it << " ";
    }
}
