#include <bits/stdc++.h>
using namespace std;

bool isPossibleToPaint(vector<int> &boards,int k, int minBoards)
{
    // TC: O(n), SC: O(1)
   long long sum=0;
   int count=1;
   for(auto boardLength:boards)
   {
     if(sum+boardLength>minBoards)
     { 
        count++;
        sum=boardLength;
     }
     else
     {
        sum+=boardLength;
     }
   }
//    cout<<count<<endl;
   return k>=count;
}

int findLargestMinDistance(vector<int> &boards, int k) // Same as book allocation problem, but cleaner code
{
    // TC: O(nlog(accumulate(boards))), SC: O(1)
    long long l=*max_element(boards.begin(),boards.end());
    long long r=accumulate(boards.begin(),boards.end(),0LL);
    int mid,ans;
    bool isPossible;
    while(l<=r)
    {
        mid=l+(r-l)/2;
        isPossible=isPossibleToPaint(boards,k,mid);
        if(isPossible)
        {
            ans=mid;
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
    return ans;
}

int main()
{
 int n,k;
 cin>>n>>k;
 vector<int> vec(n);
 for(int &element:vec)
 {
    cin>>element;
 }

 int ans=findLargestMinDistance(vec, k);
 cout<<ans;
}