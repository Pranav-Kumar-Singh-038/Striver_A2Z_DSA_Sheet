#include <bits/stdc++.h>
using namespace std;

class DLLNode
{
public:
 DLLNode* prev;
 int data;
 DLLNode* next;

 DLLNode()
 {
    prev=NULL;
    data=0;
    next=NULL;
 }

 DLLNode(int data)
 {
    this->prev=NULL;
    this->data=data;
    this->next=NULL;
 }
};

class Solution
{
public:
 void printDLL(DLLNode* head)
 {
    DLLNode* current=head;
    while(current!=NULL)
    {
        cout<<current->data<<" ";
        current=current->next;
    }
 }

 DLLNode* constructDLL(vector<int> vec)
 {
    if(vec.empty())
    {
        return NULL;
    }
    DLLNode* head=new DLLNode(vec[0]);
    DLLNode* current=head;
    for(int i=1;i<vec.size();i++)
    {
        DLLNode* newNode=new DLLNode(vec[i]);
        current->next=newNode;
        newNode->prev=current;
        current=newNode;
    }
    return head;
 }

DLLNode *addNode(DLLNode *head, int pos, int data) {
    DLLNode* newNode = new DLLNode(data);
    DLLNode* current = head;
    int index = 0;

    while (index < pos) 
    {
        current = current->next;
        index++;
    }

    DLLNode* upcoming = current->next;
    newNode->next = upcoming;
    newNode->prev = current;
    current->next = newNode;

    if (upcoming != NULL) {
        upcoming->prev = newNode;
    }

    return head;
}

};

int main()
{
 int n,pos,data;
 cin>>n>>pos>>data;

 vector<int> vec;
 for(int i=0;i<n;i++)
 {
    int x;
    cin>>x;
    vec.push_back(x);
 }
 
 Solution sol;
 DLLNode* head=sol.constructDLL(vec);
 DLLNode* newHead=sol.addNode(head,pos, data);
sol.printDLL(newHead);


}