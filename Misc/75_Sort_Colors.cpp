#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//Optimal : Dutch-national-flag algorithm/ one pass/ two pointer
//TC: O(n)
//SC: O(1)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size()-1;
        while(mid <= high){
            if(nums[mid] == 0){
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid] == 1){
                mid++;
            }
            else{
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};
//My quick sort
//TC: O(nlog(n))
//SC: O(1)
// class Solution {
// public:
//     void sortColors(std::vector<int>& nums) 
//     {
//          quicksort(nums, 0, nums.size() - 1);
         
//          for(int i : nums)
//          {
//             std::cout << i << " ";
//          }
//     }
    
//     void quicksort(std::vector<int>& nums, int low, int high) 
//     {
//         if (low < high) 
//         {
//             int pivotIdx = partition(nums, low, high);
//             quicksort(nums, low, pivotIdx - 1);
//             quicksort(nums, pivotIdx + 1, high);
//         }
//     }
    
//     int partition(std::vector<int>& nums, int low, int high) 
//     {
//         int pivot = nums[high];
//         int i = low - 1;
        
//         for (int j = low; j <= high - 1; j++) 
//         {
//             if (nums[j] < pivot) 
//             {
//                 i++;
//                 std::swap(nums[i], nums[j]);
//             }
//         }
        
//         std::swap(nums[i + 1], nums[high]);
//         return i + 1;
//     }
// };

//My bubble sort
//TC: O(n^2)
//SC: O(1)
// class Solution {
// public:
//     void sortColors(std::vector<int>& nums) 
//     {
//          for(int i=0;i<nums.size()-1;i++)
//          {
//             for(int j=0;j<nums.size()-1-i;j++)
//             {
//                 if(nums[j]>nums[j+1])
//                 {
//                 int temp=nums[j+1];
//                 nums[j+1]=nums[j];
//                 nums[j]=temp;
//                 }
//             }
//          }
//          for(int i:nums)
//          {
//             std::cout<<i<<" ";
//          }
//     }
// };

int main()
{
    int n;
    std::cin>>n;
    std::vector<int> v;
    for(int i=0;i<n;i++)
    {
      int x;
      std::cin>>x;
      v.push_back(x);
    }
    Solution sol;
    sol.sortColors(v);

}