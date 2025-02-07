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
    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
};

class Solution
{
public:
    int countNodesinLoop2(Node *head) //Unordered Map
    {
        // TC: O(n)(avg), O(n^2) (worst); SC: O(n)
        unordered_map<Node *, int> myMap;
        int index = 0;
        Node *current = head;
        Node *prev = NULL;

        while (current != NULL)
        {
            if (myMap[current])
            {
                return myMap[prev] - myMap[current]+1;
            }

            myMap[current] = index;
            prev = current;
            current = current->next;
            index++;
        }
        return 0;
    }

    int countNodesinLoop(Node* head) // Floyd's, Tortoise and hare
    {
        // TC: O(n)(worst) ; SC: O(1)  
        Node* fast=head;
        Node* slow=head;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
            {
                int count=1;
                Node *temp = slow;
                while(temp->next!=slow)
                {
                    count++;
                    temp=temp->next;
                }
                return count;
            }
        }
        return 0;
    }

    Node *constructLL(vector<int> vec, int pos)
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
        Node *newHead = addLoop(head, pos);
        return newHead;
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
        return;
    }

    Node *addLoop(Node *head, int pos)
    {
        if (pos == 0)
        {
            return head;
        }
        pos--;
        Node *current = head;
        while (pos != 0 && current != NULL)
        {
            current = current->next;
            pos--;
        }
        Node *tail = head;
        while (tail->next != NULL)
        {
            tail = tail->next;
        }
        tail->next = current;
        return head;
    }
};

int main()
{
    int n, pos;
    cin >> n;
    cin >> pos;
    vector<int> vec;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        vec.push_back(x);
    }
    Solution sol;
    Node *head = sol.constructLL(vec, pos);
    int ans = sol.countNodesinLoop(head);
    cout << ans;
}