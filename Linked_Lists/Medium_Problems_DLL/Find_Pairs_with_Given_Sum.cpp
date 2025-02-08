#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
  int data;
  Node *next;
  Node *prev;

  Node(int data)
  {
    this->data = data;
    this->next = NULL;
    this->prev = NULL;
  }
};

class Solution
{
public:
  vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) // Two pointers
  {
    // TC: O(2n), SC: O(1)
    vector<pair<int,int>> vec;
    if(head==NULL || head->next==NULL)
    {
      return vec;
    }
    Node* start=head;
    while(start->next!=NULL)
    {
      start=start->next;
    }
    Node* last=start;
    start=head;
    while( start != last && start->prev != last)
    {
      int sum=start->data + last->data;
      if(sum>target)
      {
        last=last->prev;
      }
      else if(sum<target)
      {
        start=start->next;
      }
      else
      {
        vec.push_back({start->data, last->data});
        start=start->next;
        last=last->prev;
      }
    }
    return vec;
  }

  vector<pair<int, int>> findPairsWithGivenSum2(Node *head, int target) // using unordered map
  {
    // TC: O(n) n^2 in worst case, SC: O(n)
    unordered_map<int, int> myMap;
    set<pair<int, int>> uniquePairs;
    Node *current = head;
    while (current != NULL)
    {
      int complement = target - current->data;
      if (myMap.find(complement) != myMap.end())
      {
        uniquePairs.insert({min(current->data, complement), max(current->data, complement)});
      }

      myMap[current->data]++;
      current = current->next;
    }
    return vector<pair<int, int>>(uniquePairs.begin(), uniquePairs.end());
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
  vector<pair<int, int>> ans = sol.findPairsWithGivenSum(head, target);
  for (auto &it : ans)
  {
    cout << it.first << " " << it.second << endl;
  }
  // sol.printDLL(head);
}