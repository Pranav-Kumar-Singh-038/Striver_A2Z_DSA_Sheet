#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
   int data;
   Node *next;

   Node()
   {
      data = 0;
      next = NULL;
   }

   Node(int data)
   {
      this->data = data;
      this->next = NULL;
   }
};

class Solution
{
public:
   Node *middleNode(Node *head)
   {
      Node *current = head;
      int length = 0;
      int middleNode;
      while (current != NULL)
      {
         current = current->next;
         length++;
      }
      current = head;
      middleNode = length / 2;
      while (middleNode != 0)
      {
         current = current->next;
         middleNode--;
      }
      return current;
   }

   Node *middleNodeOptimal(Node *head)
   {
      Node *slow = head, *fast = head;
      while (fast && fast->next)
      {
         slow = slow->next;
         fast = fast->next->next;
      }
      return slow;
   }

   Node *constructLL(vector<int> vec)
   {
      if (vec.empty())
      {
         return NULL;
      }

      Node *head = new Node(vec[0]);
      Node *current = head;
      for (int i = 1; i < vec.size(); i++)
      {
         Node *newNode = new Node(vec[i]);
         current->next = newNode;
         current = current->next;
      }
      return head;
   }

   void printLL(Node *head)
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
   }
};

int main()
{
   int n;
   cin >> n;
   vector<int> vec;
   for (int i = 0; i < n; i++)
   {
      int x;
      cin >> x;
      vec.push_back(x);
   }

   Solution sol;
   Node *head = sol.constructLL(vec);
   Node *middleNode = sol.middleNode(head);
   sol.printLL(middleNode);
}
