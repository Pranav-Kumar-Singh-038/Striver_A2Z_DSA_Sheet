#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//Optimal
//TC: O(m+n)
//SC:O(1)
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;
        
        while (j >= 0) {
            if (i >= 0 && nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }
    }
};
//MY
// TC:O(m+n)log(m+n)
// SC:O(1)
// class Solution {
// public:
//     void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//       for(int i=m;i<m+n;i++)
//       {
//         nums1[i]=nums2[i-m];
//       }
//       sort(nums1.begin(),nums1.end());
//     }
// };

int main()
{
int m,n;
cin>>m>>n;
vector<int> first(m+n,0);
vector<int> second(n,0);
for(int i=0;i<m;i++)
{
    cin>>first[i];
}
for(int i=0;i<n;i++)
{
    cin>>second[i];
}
Solution sol;
sol.merge(first,m,second,n);
}