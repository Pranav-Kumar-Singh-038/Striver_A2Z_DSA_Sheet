#include <iostream>
#include <vector>
#include <algorithm>

// My approach;
//TC: O(n * (max - min))
//SC: O(max - min)
// Gives runtime error for accessing non defined memory(buffer overflow)
// class Solution
// {
// public:
//     std::vector<std::vector<int>> merge(std::vector<std::vector<int>> &intervals)
//     {
//         int n = intervals.size();
//         int min = 1001;
//         int max = -1;
//         for (auto it : intervals)
//         {
//             min = std::min(min, it[0]);
//             max = std::max(max, it[1]);
//         }

//         std::vector<int> temp;
//         for (int i = min; i <= max; i++)
//         {
//             temp.push_back(i);
//         }
//         std::vector<int> copy=temp;
//         for (auto it : intervals)
//         {
//             int dex1 = it[0] - min;
//             int dex2 = it[1] - min;
//             for (int i = dex1; i <= dex2; i++)
//             {
//                 copy[i] = -1;
//             }
//         }

//         int ind = 0;
//         int start = ind;
//         std::vector<std::vector<int>> ans;
//         while (true)
//         {
//             while (copy[ind] == -1 && ind < temp.size())
//             {
//                 ind++;
//             }
//             ind--;
//             ans.push_back({temp[start], temp[ind]});

//             if (ind == temp.size() - 1)
//             {
//                 break;
//             }
//             else
//             {
//                 ind++;
//                 while (copy[ind] != -1 && ind < temp.size())
//                 {
//                     ind++;
//                 }
//                 start = ind;
//                 ind = ind + 1;
//             }
//         }
//         return ans;
//     }
// };


//TC: O(nlogn) : 26ms
//SC: O(n): 19.05mb
class Solution {
public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
        std::vector<std::vector<int>> merged;
        if (intervals.empty()) {
            return merged;
        }

        std::sort(intervals.begin(), intervals.end());

        int start = intervals[0][0];
        int end = intervals[0][1];

        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] <= end) {
                end = std::max(end, intervals[i][1]);
            } else {
                merged.push_back({start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }

        merged.push_back({start, end});

        return merged;
    }
};

int main()
{
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> vec;
    while (n--)
    {
        int a, b;
        std::cin >> a >> b;
        vec.push_back({a, b});
    }
    Solution sol;
    std::vector<std::vector<int>> ans = sol.merge(vec);
    for (auto it : ans)
    {
        for (auto i : it)
        {
            std::cout << i << " ";
        }
        std::cout << "\n";
    }
}