#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int val)
    {
        this->val = val;
        this->next = NULL;
        this->random = NULL;
    }
};

class Solution
{
public:
    Node *copyRandomList1(Node *head) // make a normal ll, then for each random node or original node, finds a node in a similar position in newnode and assigns random
    // TC: O(n^2), SC: O(n)
    {
        if (head == NULL)
        {
            return NULL;
        }
        Node *newHead = new Node(head->val);
        Node *newCurrent = newHead;
        Node *current = head;
        current = current->next;
        while (current != NULL)
        {
            Node *newNode = new Node(current->val);
            newCurrent->next = newNode;
            newCurrent = newCurrent->next;
            current = current->next;
        }
        current = head;
        newCurrent = newHead;
        while (current != NULL)
        {
            Node *originalCounter = head;
            Node *newCounter = newHead;
            Node *originalRandom = current->random;
            if (originalRandom == NULL)
            {
                newCurrent->random = NULL;
            }
            else
            {
                while (originalCounter != originalRandom)
                {
                    originalCounter = originalCounter->next;
                    newCounter = newCounter->next;
                }
                newCurrent->random = newCounter;
            }
            current = current->next;
            newCurrent = newCurrent->next;
        }
        return newHead;
    }

    Node *copyRandomList(Node *head) // Make a hash table store the original ll, and next to it the new one, then for each pass find the new random node associated with the old random
    {
        // TC: O(n), SC: O(2*n)
        if (head == NULL)
            return NULL;

        unordered_map<Node *, Node *> oldToNew;

        Node *current = head;
        while (current != NULL)
        {
            oldToNew[current] = new Node(current->val);
            current = current->next;
        }

        current = head;
        while (current != NULL)
        {
            // the left part points to the next of new node,  right points to the new node of the current next;
            oldToNew[current]->next = oldToNew[current->next];
            oldToNew[current]->random = oldToNew[current->random];
            current = current->next;
        }

        return oldToNew[head];
    }

    Node *constructRandomLL(const vector<pair<int, optional<int>>> &arr)
    {
        if (arr.empty())
        {
            return NULL;
        }
        Node *head = new Node(arr[0].first);
        Node *current = head;
        for (int i = 1; i < arr.size(); i++)
        {
            Node *newNode = new Node(arr[i].first);
            current->next = newNode;
            current = current->next;
        }
        Node *finalHead = addRandom(arr, head);
        return finalHead;
    }

    Node *addRandom(const vector<pair<int, optional<int>>> &arr, Node *head)
    {
        Node *current = head;
        for (auto &node : arr)
        {
            Node *target = head;
            int counter = 0;
            optional<int> index = node.second;
            if (!index.has_value())
            {
                current->random = NULL;
            }
            else
            {
                while (counter != index.value())
                {
                    counter++;
                    target = target->next;
                }
                current->random = target;
            }
            current = current->next;
        }
        return head;
    }

    void printRandomLL(Node *head)
    {
        Node *current = head;
        while (current != NULL)
        {
            cout << "Value: " << current->val << ", Random Value: ";
            if (current->random)
            {
                cout << current->random->val;
            }
            else
            {
                cout << "null";
            }
            cout << endl;
            current = current->next;
        }
        return;
    }
};

int main()
{
    int n;
    cin >> n;

    vector<pair<int, optional<int>>> arr;
    for (int i = 0; i < n; ++i)
    {
        int value;
        string input;
        optional<int> randomIndex;
        cin >> value;
        cin >> input;
        if (input != "null")
        {
            randomIndex = stoi(input);
        }
        arr.push_back({value, randomIndex});
    }

    Solution sol;
    Node *head = sol.constructRandomLL(arr);
    Node *newHead = sol.copyRandomList(head);
    sol.printRandomLL(newHead);

    return 0;
}
