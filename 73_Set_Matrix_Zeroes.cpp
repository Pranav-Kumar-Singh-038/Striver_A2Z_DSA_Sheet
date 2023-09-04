#include <iostream>
#include <vector>
#include <map>
#include <set>

/*
Optimal: Two boolean flags, flag1 and flag2, are initialized to false. These flags will help us identify if the first row and
 the first column need to be zeroed out later.

The code starts with two loops to check the first row and the first column for zeros. If any element in the first row is zero,
 flag1 is set to true. Similarly, if any element in the first column is zero, flag2 is set to true. This initial scan identifies
  whether the first row and first column need to be zeroed out later.

The code then proceeds to a double-loop (nested loop) structure, starting from the second row and the second column (i.e., i=1 and j=1).
 It iterates through the entire matrix except for the first row and first column.

If the element at matrix[i][j] is zero, it sets the corresponding elements in the first row (matrix[i][0]) and the first column
 (matrix[0][j]) to zero. This step marks the rows and columns that need to be zeroed out later.

After marking the rows and columns, the code goes through the matrix again using two nested loops, starting from the second row
 and the second column. If either matrix[i][0] or matrix[0][j] is zero, it sets matrix[i][j] to zero. This step zeros out the elements
  in the matrix based on the marks made in step 6.

Finally, the code checks the flag1 and flag2 flags. If flag1 is true, it sets all elements in the first column to zero, effectively
 zeroing out the entire first row. If flag2 is true, it sets all elements in the first row to zero, effectively zeroing out the entire
  first column.
Time Complexity : O(N*M)
Space Complexity : O(1)
*/




// class Solution {
// public:
//     void setZeroes(std::vector<std::vector<int>>& matrix) {
//         int n = matrix.size();
//         int m = matrix[0].size();
//         bool flag1 = false, flag2 = false;
//         for(int i=0; i<n; i++){
//             if(matrix[i][0] == 0){
//                 flag1 = true;
//             }
//         }
//         for(int j=0; j<m; j++){
//             if(matrix[0][j] == 0){
//                 flag2 = true;
//             }
//         }
//         for(int i=1; i<n; i++){
//             for(int j=1; j<m; j++){
//                 if(matrix[i][j] == 0){
//                     matrix[i][0] = matrix[0][j] = 0;
//                 }
//             }
//         }
//         for(int i=1; i<n; i++){
//             for(int j=1; j<m; j++){
//                 if(matrix[i][0] == 0 || matrix[0][j] == 0){
//                     matrix[i][j] = 0;
//                 }
//             }
//         }
//         if(flag1 == true){
//             for(int i=0; i<n; i++){
//                 matrix[i][0] = 0;
//             }
//         }
//         if(flag2 == true){
//             for(int j=0; j<m; j++){
//                 matrix[0][j] = 0;
//             }
//         }
//     }
// };

/*
My : I iterate through the loop to store the indexes with 0 in a map and 
then I update the matrix according the values in map, then i print it
TC : O(m*n) or O(n^2)
SC : O(m+n) or O(n-+)
*/
class Solution 
{
 public:
    void setZeroes(std::vector<std::vector<int>>& matrix) 
    {
     std::map<char,std::set<int>> m;
     for(int i=0;i<matrix.size();i++)
      {
       for(int j=0;j<matrix[i].size();j++)
        {
        if(matrix[i][j]==0)
         {
          m['i'].insert(i);
          m['j'].insert(j);
         } 
        }
      }
    for(int i=0;i<matrix.size();i++)
    {
    for(int k=0;k<matrix[i].size();k++)
    {
      if(m['i'].find(i) != m['i'].end() || m['j'].find(k) != m['j'].end())
      {
       matrix[i][k]=0;
      }
    }
  }
  for(auto row:matrix)
  {
    for(auto column:row)
    {
        std::cout<<column<<" ";
    }
    std::cout<<"\n";
  }
    }
};

int main()
{
  int m,n;
  std::cin>>m>>n;
  std::vector<std::vector<int>> vec;
  while(m--)
  {
    std::vector<int> nums;
    for(int k=0;k<n;k++)
    {
        int x;
        std::cin>>x;
        nums.push_back(x);
    }
    vec.push_back(nums);
  }
  Solution sol;
  sol.setZeroes(vec);
}