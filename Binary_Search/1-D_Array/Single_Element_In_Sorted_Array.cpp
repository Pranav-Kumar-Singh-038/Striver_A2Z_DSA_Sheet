#include <bits/stdc++.h>
using namespace std;

// Optimal
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while(left < right){
            int mid = (left + right)/2;
            if((mid % 2 == 0 && nums[mid] == nums[mid + 1]) || (mid % 2 == 1 && nums[mid] == nums[mid - 1]))
                left = mid + 1;
            else
                right = mid;
        }
        
        return nums[left];
    }
};

// My approach
// TC: O(logn) SC: O(1)
// Beats 49% in runtime, Beats 5% in memory
// bool checkSingle(vector<int> nums, int i)
// {

//     if (i == 0)
//     {
//         if (nums[i] == nums[i + 1])
//         {
//             return false;
//         }
//     }
//     else if (i == nums.size() - 1)
//     {
//         if (nums[i] == nums[i - 1])
//         {
//             return false;
//         }
//     }
//     else
//     {
//         if (nums[i] == nums[i + 1] || nums[i] == nums[i - 1])
//         {
//             return false;
//         }
//     }

//     return true;
// }

// bool isEven(int n)
// {
//     return ((n % 2) == 0);
// }

// class Solution
// {
// public:
//     int singleNonDuplicate(vector<int> &nums)
//     {
//         int l = 0;
//         int r = nums.size() - 1;
//         int mid;
//         while (l <= r)
//         {
//             mid = l + (r - l) / 2;
//             if (nums.size() == 1)
//             {
//                 return nums[0];
//             }
//             if (checkSingle(nums, mid))
//             {
//                 return nums[mid];
//             }
//             if (isEven(mid))
//             {
//                 if (nums[mid] == nums[mid - 1])
//                 {
//                     r = mid - 1;
//                 }
//                 else
//                 {
//                     l = mid + 1;
//                 }
//             }
//             else
//             {
//                 if (nums[mid] == nums[mid - 1])
//                 {
//                     l = mid + 1;
//                 }
//                 else
//                 {
//                     r = mid - 1;
//                 }
//             }
//         }
//         return nums[mid];
//     }
// };

// Simple Approach
//Complexities: same
// Runtime beats 95% memory beats 51%
// class Solution
// {
// public:
//     int singleNonDuplicate(vector<int> &nums)
//     {
//         int l = 0;
//         int r = nums.size() - 1;
//         while (l <= r)
//         {
//             int mid = l + (r - l) / 2;
//             // if (nums.size() == 1)
//             // {
//             //     return nums[0];
//             // }
//             if (isEven(mid))
//             {
//                 if (nums[mid + 1] == nums[mid])
//                 {
//                     l = mid + 1;
//                 }
//                 else
//                 {
//                     r = mid - 1;
//                 }
//             }
//             else
//             {
//                 if (nums[mid] == nums[mid - 1])
//                 {
//                     l = mid + 1;
//                 }
//                 else
//                 {
//                     r = mid - 1;
//                 }
//             }
//         }
//         return nums[l];
//     }
// };

int main()
{
    int n;
    cin >> n;
    vector<int> vec(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }
    Solution sol;
    int ans = sol.singleNonDuplicate(vec);
    cout << ans;
}