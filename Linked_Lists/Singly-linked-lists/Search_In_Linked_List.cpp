#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
  int data;
  Node* next;

  Node()
  {
    data=0;
    next=NULL;
  }
  Node(int data)
  {
    this->data=data;
    this->next=NULL;
  }
};

class Solution
{
public:
  bool searchKey(int n, Node* head, int k)
  {
    Node* current=head;
    while(current!=NULL)
    {
        if(current->data==k)
        {
            return true;
        }
        current=current->next;
    }
    return false;
  }

  Node* constructLL(vector<int> &vec)
  {
    if(vec.empty())
    {
        return NULL;
    }
    Node* head=new Node(vec[0]);
    Node* current=head;
    for(int i=1;i<vec.size();i++)
    {
        Node* newNode=new Node(vec[i]);
        current->next=newNode;
        current=current->next;
    }
    return head;
  }
};

int main()
{
 int n;
 cin>>n;
 int k;
 cin>>k;
 vector<int> vec;
 for(int i=0;i<n;i++)
 {
    int x;
    cin>>x;
    vec.push_back(x);
 }

 Solution sol;
 Node* head=sol.constructLL(vec);
 bool ans=sol.searchKey(n,head,k);
 cout<<ans<<endl;
}