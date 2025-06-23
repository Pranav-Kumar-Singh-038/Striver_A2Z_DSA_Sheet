#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void storePaths(vector<vector<int>> &maze, vector<vector<bool>> &path, int row, int col, vector<string> &ans, string directions)
    {
        int n = maze.size();
        if (row < 0 || col < 0 || row >= n || col >= n || path[row][col] || maze[row][col] == 0)
        {
            return;
        }

        if (row == n - 1 && col == n - 1)
        {
           ans.push_back(directions);
        }
        path[row][col] = true;
        storePaths(maze, path, row - 1, col, ans, directions+"U");
        storePaths(maze, path, row + 1, col, ans, directions+"D");
        storePaths(maze, path, row , col-1, ans, directions+"L");
        storePaths(maze, path, row , col+1, ans, directions+"R");
        path[row][col]=false;
        return;
    }

    vector<string> ratInMaze(vector<vector<int>> &maze) // same as word search but instead of doing for all cells we only need to do for the first cell, have a directions string to update the current path, rest is same
    {
        // TC: O(4^n*n+ nlogn), n*n when it has to visit every cell to reach the last cell, SC: O(2*n*n+n*n*validPaths+n*n(stack size))
        int n=maze.size();
        vector<vector<bool>> path(n,vector<bool>(n));
        int row=0,col=0;
        vector<string> ans;
        string directions="";
        storePaths(maze, path, row, col, ans, directions);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> maze(n,vector<int>(n));
    for(auto &row:maze)
    {
        for(auto &col:row)
        {
            cin>>col;
        }
    }
    Solution sol;
    vector<string> ans=sol.ratInMaze(maze);
    for(auto &it:ans)
    {
        cout<<it<<endl;
    }
    return 0;
}