#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *bottom;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->bottom = NULL;
    }
};

class Solution
{
public:
    Node *merge(Node *a, Node *b)
    {
        // TC: O(min(a,b)), SC: O(a+b)
        Node dummy(0); // SC: O(a+b)
        Node *tail = &dummy;

        while (a && b) // TC: O(min(a,b))
        {
            if (a->data < b->data)
            {
                tail->bottom = a;
                a = a->bottom;
            }
            else
            {
                tail->bottom = b;
                b = b->bottom;
            }
            tail = tail->bottom;
        }

        tail->bottom = (a != NULL) ? a : b;

        return dummy.bottom;
    }

    Node *flatten(Node *root) // Didn't understand
    {
        // TC: O(nlogm) m is the number of lists, SC: O(1)
        if (!root || !root->next)
        {
            return root;
        }

        // Recursively flatten the next lists
        root->next = flatten(root->next);

        // Merge current list with the flattened next list
        return merge(root, root->next);
    }

    Node *flatten1(Node *root) // Consider it as a small part of merge sort where the only the merging is left, as each bottom ll is sorted, make a merge function to construct the final ll
    {
        // TC: O(n^2), SC: O(1)
        if (!root)
        {
            return NULL;
        }

        Node *newHead = NULL;
        Node *current = root;

        while (current != NULL)
        {
            newHead = merge(current, newHead);
            current = current->next;
        }

        return newHead;
    }

    Node *constructLL(const vector<vector<int>> &arr)
    {
        Node *head = NULL;
        Node *prevColHead = NULL;

        for (const auto &column : arr)
        {
            if (column.empty())
                continue;

            Node *colHead = new Node(column[0]);
            if (!head)
                head = colHead;
            if (prevColHead)
                prevColHead->next = colHead;

            Node *current = colHead;
            for (int i = 1; i < column.size(); ++i)
            {
                current->bottom = new Node(column[i]);
                current = current->bottom;
            }

            prevColHead = colHead;
        }

        return head;
    }

    void printByBottom(Node *head)
    {
        while (head)
        {
            Node *curr = head;
            while (curr)
            {
                cout << curr->data << " ";
                curr = curr->bottom;
            }
            head = head->next;
        }
        cout << endl;
    }

    void printBottomLL(Node *head)
    {
        Node *current = head;
        while (current != NULL)
        {
            cout << current->data << " ";
            current = current->bottom;
        }
    }
};

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> arr(n);
    for (int i = 0; i < n; ++i)
    {
        int m;
        cin >> m;

        arr[i].resize(m);
        for (int j = 0; j < m; ++j)
        {
            cin >> arr[i][j];
        }
    }

    Solution sol;
    Node *head = sol.constructLL(arr);
    Node *newHead = sol.flatten(head);
    sol.printBottomLL(newHead);

    return 0;
}
