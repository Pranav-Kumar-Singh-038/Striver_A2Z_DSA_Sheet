#include <bits/stdc++.h>

using namespace std;
//Optimal same but less code
// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;
        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] != 0)
                nums[i++] = nums[j];
        }

        while (i < nums.size())
            nums[i++] = 0;
    }
};


//First:
// Time complexity: O(n)
// Space complexity: O(1)

// class Solution {
// public:
//     void moveZeroes(vector<int>& nums) {
//         //sort(nums.begin(),nums.end());
//         auto begin=nums.begin();
//         auto end=nums.end()-1;
//         while(*end==0 && end!=begin)
//         {
//             end--;
//         }
//         while(begin<=end)
//         {
//             if(*begin==0 )
//             {
//               *begin=*end;
//               *end=0;
//               end--;
//               begin++;
//             }
//             else
//             {
//             begin++;
//             }
//         }
//         for(int i:nums)
//         {
//             cout<<i<<" ";
//         }
//     }
// };

//Second:
//Time complexity: O(n)
//Space complexity: O(1)

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int ct=count(nums.begin(),nums.end(),0); //O(n)
        nums.erase(remove(nums.begin(), nums.end(), 0), nums.end());//O(n)
        while(ct!=0)//O(n) worst case
        {
          nums.push_back(0);
          ct--;
        }
        for(int i:nums)
        {
            cout<<i<<" ";
        }
    }
};

int main()
{
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++)
    {
      int x;
      cin>>x;
      v.push_back(x);
    }

    Solution sol;
    sol.moveZeroes(v);
}