#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
   int data;
   ListNode *next;

   ListNode()
   {
      data = 0;
      next = NULL;
   }

   ListNode(int data)
   {
      this->data = data;
      this->next = NULL;
   }
};

class Solution
{
public:
   ListNode *middleNode(ListNode *head)
   {
      ListNode *current = head;
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

   ListNode *middleNodeOptimal(ListNode *head)
   {
      ListNode *slow = head, *fast = head;
      while (fast && fast->next)
      {
         slow = slow->next;
         fast = fast->next->next;
      }
      return slow;
   }

   ListNode *constructLL(vector<int> vec)
   {
      if (vec.empty())
      {
         return NULL;
      }

      ListNode *head = new ListNode(vec[0]);
      ListNode *current = head;
      for (int i = 1; i < vec.size(); i++)
      {
         ListNode *newNode = new ListNode(vec[i]);
         current->next = newNode;
         current = current->next;
      }
      return head;
   }

   void printLL(ListNode *head)
   {
      if (head == NULL)
      {
         return;
      }
      ListNode *current = head;
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
   ListNode *head = sol.constructLL(vec);
   ListNode *middleNode = sol.middleNode(head);
   sol.printLL(middleNode);
}