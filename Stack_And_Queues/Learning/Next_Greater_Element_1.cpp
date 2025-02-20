#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2){
    // We traverse the array from the end and keep removing elements from the stack until we find a greater element, which becomes the Next Greater Element (NGE). Then, we push the current element onto the stack.
    // This ensures that the top of the stack always holds the smallest element, while the bottom holds the greatest, making the stack monotonic (maintaining a specific order). When we pop smaller elements, we are not
    //  actually removing potential NGEs because the current element is greater and appears before the previous one. This guarantees that the NGE will always be the current element.
    // The intuition behind this approach is similar to looking at towers—smaller towers are hidden behind taller ones in front. We only need to track the closest taller tower to determine the next greater element.
    
    // Time Complexity: O(n + m)
    // Space Complexity: O(m + n)
       stack<int> stk;
       vector<int> ans(nums1.size());
       unordered_map<int,int> NGE;
       for(int i=nums2.size()-1;i>=0;i--)
       {
        int element=nums2[i];
        while(!stk.empty() && element>stk.top())
        {
           stk.pop();
        }
        if(stk.empty())
        {
            NGE[element]=-1;
        }
        else
        {
            NGE[element]=stk.top();
        }
        stk.push(element);
       }
       for(int i=0;i<nums1.size();i++)
       {
        ans[i]=NGE[nums1[i]];
       }
       return ans;
    }

    vector<int> nextGreaterElement1(vector<int> &nums1, vector<int> &nums2) // simple method
    {// TC: O(n*m), SC: O(n)  the ans variable
        vector<int> ans;
        for (int &i : nums1)
        {
            bool rightPart = false;
            int val = -1;
            for (int &j : nums2)
            {
                if (i == j)
                {
                    rightPart = true;
                }
                if (j > i && rightPart)
                {
                    val = j;
                    break;
                }
            }
            ans.push_back(val);
        }
        return ans;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> nums1(n), nums2(m);
    for (int &i : nums1)
    {
        cin >> i;
    }
    for (int &i : nums2)
    {
        cin >> i;
    }
    Solution sol;
    vector<int> ans = sol.nextGreaterElement(nums1, nums2);
    for (auto it : ans)
    {
        cout << it << " ";
    }
    return 0;
}