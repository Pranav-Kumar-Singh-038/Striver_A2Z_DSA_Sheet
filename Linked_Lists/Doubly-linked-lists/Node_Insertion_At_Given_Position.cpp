#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
 Node* prev;
 int data;
 Node* next;

 Node()
 {
    prev=NULL;
    data=0;
    next=NULL;
 }

 Node(int data)
 {
    this->prev=NULL;
    this->data=data;
    this->next=NULL;
 }
};

class Solution
{
public:
 void printDLL(Node* head)
 {
    Node* current=head;
    while(current!=NULL)
    {
        cout<<current->data<<" ";
        current=current->next;
    }
 }

 Node* constructDLL(vector<int> vec)
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
        newNode->prev=current;
        current=newNode;
    }
    return head;
 }

Node *addNode(Node *head, int pos, int data) {
    Node* newNode = new Node(data);
    Node* current = head;
    int index = 0;

    while (index < pos) 
    {
        current = current->next;
        index++;
    }

    Node* upcoming = current->next;
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
 Node* head=sol.constructDLL(vec);
 Node* newHead=sol.addNode(head,pos, data);
sol.printDLL(newHead);


}