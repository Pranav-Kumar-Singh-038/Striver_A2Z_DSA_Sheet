#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}

class Solution
{
public:
    Node *insertAtEnd(Node *head, int x)
    {
        if (head == NULL)
        {
            Node *newNode = new Node(x);
            head = newNode;
            return head;
        }
        Node *current = head;
        Node *newNode = new Node(x);

        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
        return head;
    }

    Node *constructLL(vector<int> &arr)
    {
        if (arr.empty())
        {
            return NULL;
        }
        Node *head = new Node(arr[0]);
        // new is used to dynamically allocate memory for a variable (or an object)
        // on the heap. When you use new, it returns the memory address of the newly
        // allocated memory.
        Node *current = head;
        for (int i = 1; i < arr.size(); i++)
        {
            Node *newNode = new Node(arr[i]);
            current->next = newNode;
            current = current->next;
        }

        return head;
    }
};

int main()
{
    vector<int> vec;
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        vec.push_back(x);
    }

    Solution sol;
    Node *head = sol.constructLL(vec);
    cin >> x;
    Node *newHead = sol.insertAtEnd(head, x);
    printList(newHead);
}
