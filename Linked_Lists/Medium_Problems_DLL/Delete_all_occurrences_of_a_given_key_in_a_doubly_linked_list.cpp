#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
}; 


class Solution
{
public:
    void deleteAllOccurOfX(struct Node** head_ref, int x) { // idea is simple, at the start skip all matches, then whenever a match is found skip it by making the prevNode->next=nextNode, and nextNode->prev=prevNode, but
        // remember to update head_ref not head
        // to set current->prev = NULL if skipped starting nodes as a DLL
        // TC: O(n), SC: O(1)
    Node* head = *head_ref; 
    Node* current=head;
    while(current != NULL && current->data==x)
    {
        current=current->next;
        if (current) current->prev = NULL; // to notice
    }
    *head_ref = current;  // to notice
    while(current!=NULL)
    {
        Node* prevNode=current->prev;
        Node* nextNode=current->next;
        if(current->data==x)
        {
           if (prevNode) prevNode->next = nextNode;  // check before accessing as they can be null
           if (nextNode) nextNode->prev = prevNode;  // same
           current=nextNode;
        }
        else
        {
        current=current->next;
        }
    }
    }

  Node *constructDLL(vector<int> vec)
  {
    Node *head = new Node(vec[0]);
    Node *current = head;
    for (int i = 1; i < vec.size(); i++)
    {
      Node *newNode = new Node(vec[i]);
      current->next = newNode;
      newNode->prev = current;
      current = current->next;
    }
    return head;
  }

  void printDLL(Node *head)
  {
    if (head == NULL)
    {
      return;
    }

    Node *current = head;
    while (current != NULL)
    {
      cout << current->data << " ";
      current = current->next;
    }
    return;
  }
};

int main()
{
  int n, target;
  cin >> n >> target;
  vector<int> vec(n);

  for (int &x : vec)
  {
    cin >> x;
  }

  Solution sol;
  Node *head = sol.constructDLL(vec);
  sol.deleteAllOccurOfX(&head, target);
  sol.printDLL(head);
  return 0;
}