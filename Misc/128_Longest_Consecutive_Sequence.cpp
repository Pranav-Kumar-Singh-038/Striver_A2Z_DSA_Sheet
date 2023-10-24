#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
/*Optimal: This code defines a C++ class called Solution with a member 
function named longestConsecutive. The purpose of this function is to find 
the length of the longest consecutive subsequence in an input vector of 
integers (nums).

Here's a step-by-step explanation of the code:

An std::unordered_map<int, bool> named map is created. This map will be 
used to keep track of whether each number in the nums vector has been 
visited. The keys are integers, and the values are booleans, where true 
indicates that a number has been visited, and false indicates it hasn't.

The first for loop iterates through each element of the nums vector and 
sets the corresponding key in the map to true, indicating that the number 
has been visited.

The second for loop also iterates through the nums vector. For each element
 nums[i], it checks if nums[i]-1 exists in the map (i.e., if there's a 
 previous consecutive number). If it does, it sets the value of map[nums[i]]
  to false. This step is done to mark the start of a potential consecutive 
  subsequence.

An integer variable maxlen is initialized to 0. This variable will store the
 length of the longest consecutive subsequence found in the nums vector.

The third for loop iterates through the nums vector again. For each element
 nums[i], it checks if map[nums[i]] is true. If it is, it means that nums[i]
  is the start of a potential consecutive subsequence.

Inside this loop, there are two additional nested loops:

int j=0; int count=0; initializes two variables, j and count. j will be used
 to iterate through consecutive numbers, and count will keep track of the 
 length of the current consecutive subsequence.
The while loop with the condition map.count(nums[i]+j) > 0 checks if the 
next consecutive number (nums[i]+j) exists in the map. If it does, it 
increments j and count to continue checking for the next consecutive number.
If the while loop exits, it means that there are no more consecutive 
numbers in the sequence. It compares count with maxlen and updates maxlen 
if count is greater, effectively keeping track of the longest consecutive 
subsequence found so far.
After all iterations, the function returns maxlen, which represents the 
length of the longest consecutive subsequence in the nums vector.

In summary, this code uses an unordered map to efficiently track visited 
numbers and iterates through the input vector to find consecutive 
subsequences, keeping track of the longest one encountered.
*/
//Optimal: 
//TC: O(n)
//SC: O(n)
class Solution {
public:
    int longestConsecutive(std::vector<int>& nums) {
        std::unordered_map<int, bool> map;
        for(int i = 0; i<nums.size(); i++){
            map[nums[i]] = true;
        }
        for(int i=0; i<nums.size(); i++){
            if(map.count(nums[i]-1) > 0){
                map[nums[i]] = false;
            }
        }
        int maxlen = 0;
        for(int i=0; i<nums.size(); i++){
            if(map[nums[i]] == true){
                int j=0; int count=0;
                while(map.count(nums[i]+j) > 0){
                    j++;
                    count++;
                }
                if(count>maxlen){
                    maxlen = count;
                }
            }
        }
        return maxlen;
    }
};


//My sorts and then checks if difference of 1 is maintained, skips repeated digits
//TC: O(nlogn)
//SC: O(1)
class Solution {
public:
    int longestConsecutive(std::vector<int>& nums) 
    {
        if(nums.size()<=1)
        {
            return nums.size();
        }
        sort(nums.begin(),nums.end());
        int count=0;
        int maxCount=0;
        for(int i=0;i<nums.size()-1;i++)
        {
            if((nums[i+1]-nums[i])==1)
            {
                count++;
            }
            else if((nums[i+1]-nums[i])==0){
                continue;
            }
            else{
                count=0;
            }
            if(count>maxCount)
            {
                maxCount=count;
            }
        }
        return maxCount+1;
    }
};

int main()
{
 int n;
 std::cin>>n;
 std::vector<int> vec;
 while(n--)
 {
   int x;
   std::cin>>x;
   vec.push_back(x);
 }
 Solution sol;
 int ans=sol.longestConsecutive(vec);
 std::cout<<ans;
}