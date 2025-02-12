#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void bubbleSort(vector<int> &arr)
    {
        for(int i=0;i<arr.size();i++)
        {
            for(int j=0;j<arr.size()-1-i;j++)
            {
                if(arr[j]>arr[j+1])
                {
                    swap(arr[j],arr[j+1]);
                }
            }
        }
        for(auto it:arr)
        {
            cout<<it<<" ";
        }
    }

};

int main()
{
    int n;
    cin >> n;
    vector<int> vec(n, 0);
    for (int &x : vec)
    {
        cin >> x;
    }

    Solution sol;
    sol.bubbleSort(vec);
    return 0;
}