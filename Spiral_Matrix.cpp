#include <iostream>
#include <vector>

//My:
//TC: O(m*n)
//SC: O(1)
class Solution {
public:
    std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
        std::vector<int> ans;
        int m = matrix.size();    
        int n = matrix[0].size(); 
        int left = 0, right = n - 1, top = 0, bottom = m - 1;

        while (left <= right && top <= bottom) {
            for (int j = left; j <= right; j++) {
                ans.push_back(matrix[top][j]);
            }
            top++;

            for (int i = top; i <= bottom; i++) {
                ans.push_back(matrix[i][right]);
            }
            right--;

            if (top <= bottom) {
                for (int j = right; j >= left; j--) {
                    ans.push_back(matrix[bottom][j]);
                }
                bottom--;
            }

            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return ans;
    }
};


int main()
{
    int n,m;
    std::cin>>n>>m;
    std::vector<std::vector<int>> vec;
    for(int i=0;i<n;i++)
    {
        std::vector<int> nums;
        for(int j=0;j<m;j++)
        {
         int x;
         std::cin>>x;
         nums.push_back(x);
        }
        vec.push_back(nums);
    }
    Solution sol;
    std::vector<int> ans=sol.spiralOrder(vec);
    for(auto it:ans)
        {
            std::cout<<it<<" ";
        }
        std::cout<<"\n";
}