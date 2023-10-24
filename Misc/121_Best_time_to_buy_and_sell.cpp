#include <iostream>
#include <vector>

//Optimal
//TC: O(n)
//SC: O(1)
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int min_price = prices[0];
//         int maxprof = 0;

//         for(int i=1;i<prices.size();i++){
//             maxprof = max(maxprof,prices[i]-min_price);
//             min_price = min(prices[i],min_price);
//         }

//         return maxprof;
//     }
// };

//Optimized:
//TC: O(n)
//SC: O(1)
// class Solution {
// public:
//     int maxProfit(std::vector<int>& prices) {
//         int minPrice = INT_MAX;
//         int maxProfit = 0;

//         for (int price : prices) {
//             if (price < minPrice) {
//                 minPrice = price;
//             } else if (price - minPrice > maxProfit) {
//                 maxProfit = price - minPrice;
//             }
//         }
//         return maxProfit;
//     }
// };

//MY: 
//TC: O(n^2)
//SC: O(1)
class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int maxProfit=0;
        for(int i=0;i<prices.size();i++)
        {
         int profit=0;
         int bought=prices[i];
         for(int j=i+1;j<prices.size();j++)
         {
            if(prices[j]>bought)
            {
                profit=prices[j]-bought;
            }
            if(profit>maxProfit)
            {
             maxProfit=profit;
            }
         }
        }
        return maxProfit;
    }
};

int main()
{
  int n;
  std::cin>>n;
  std::vector<int> nums;
  for(int i=0;i<n;i++)
  {
    int x;
    std::cin>>x;
    nums.push_back(x);
  }
  Solution sol;
  int ans=sol.maxProfit(nums);
  std::cout<<ans;
}