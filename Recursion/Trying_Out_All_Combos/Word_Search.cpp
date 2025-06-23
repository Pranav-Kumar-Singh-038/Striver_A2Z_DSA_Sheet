#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool recursiveCheck(vector<vector<char>> &board, string &word, int row, int col, int index, vector<vector<bool>> &path, int ROW, int COL)
    {
        if (row < 0 || col < 0 || row >= ROW || col >= COL || board[row][col] != word[index] || path[row][col])
        {
            return false;
        }

        if (index == word.size() - 1)
        {
            return true;
        }

        path[row][col] = true;

        bool res = recursiveCheck(board, word, row + 1, col, index + 1, path, ROW, COL) ||
                   recursiveCheck(board, word, row - 1, col, index + 1, path, ROW, COL) ||
                   recursiveCheck(board, word, row, col + 1, index + 1, path, ROW, COL) ||
                   recursiveCheck(board, word, row, col - 1, index + 1, path, ROW, COL);

        path[row][col] = false; 
        return res;
    }

    bool exist(vector<vector<char>> &board, string word) // we travel each letter in board one by one, for each letter, we then check if the neighbouring is the required element in the string, by making 4 recursive calls, if any one matches we store that path and continue, once the index reaches the required length we got it, else false, we are storing each path because we can't have the same letter from the same position, for ABA, we can't select the first A twice.
    {
        // TC: O(n*m*4^wordsize), SC: O(m*n+wordsize)
        int ROW = board.size();
        int COL = board[0].size();
        vector<vector<bool>> path(ROW, vector<bool>(COL, false));

        for (int row = 0; row < ROW; row++)
        {
            for (int col = 0; col < COL; col++)
            {
                if (recursiveCheck(board, word, row, col, 0, path, ROW, COL))
                {
                    return true;
                }
            }
        }
        return false;
    }
};

int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<char>> board(m, vector<char>(n));

    for (vector<char> &row : board)
    {
        for (char &ch : row)
        {
            cin >> ch;
        }
    }

    string word;
    cin >> word;

    Solution sol;
    bool ans = sol.exist(board, word);
    cout << ans << endl;

    return 0;
}
