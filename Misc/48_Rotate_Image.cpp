#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    void rotate(std::vector<std::vector<int>>& matrix) {
        int row = matrix.size();
        for(int i=0;i<row; i++){
            for(int j=0; j<=i;j++){
                std::swap(matrix[i][j], matrix[j][i]);
            }
        }
        for(int i=0;i<row;i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
        for(int i=0;i<matrix.size();i++)
        { 
            for(int j=0;j<matrix.size();j++)
            {
                std::cout<<matrix[i][j]<<" ";
            }
            std::cout<<std::endl;
        }
    }
};

int main()
{
  std::vector<std::vector<int>> vec;
  int n;
  std::cin>>n;
  for(int i=0;i<n;i++)
  {
    std::vector<int> nums;
    for(int j=0;j<n;j++)
    {
      int x;
      std::cin>>x;
      nums.push_back(x);
    }
    vec.push_back(nums);
  }
  Solution sol;
  sol.rotate(vec);
}