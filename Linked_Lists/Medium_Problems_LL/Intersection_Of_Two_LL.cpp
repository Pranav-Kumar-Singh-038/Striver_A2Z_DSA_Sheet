#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode()
    {
        val = 0;
        next = NULL;
    }
    ListNode(int val, ListNode *next)
    {
        this->val = val;
        this->next = next;
    }
    ListNode(int val)
    {
        this->val = val;
        next = NULL;
    }
};

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) // Using two pointer // Another method is to increase the lagging node by d distance to check but TC is O(n1 + 2N2)
    {
        // TC: O(n1+ n2), SC: O(1) (optimal)
        if (!headA || !headB)
            return NULL;

        ListNode *a = headA, *b = headB;

        while (a != b)
        {
            if (a == NULL)
                a = headB; 
            else
                a = a->next; 

            if (b == NULL)
                b = headA; 
            else
                b = b->next;
        }

        return a;
    }

    ListNode *getIntersectionNode2(ListNode *headA, ListNode *headB) // Using unorderedMap to store addresses
    {
        // TC: O(n), SC: O(n)
        unordered_map<ListNode *, bool> myMap;
        ListNode *currentA = headA;
        while (currentA != NULL)
        {
            myMap[currentA] = true;
            currentA = currentA->next;
        }
        ListNode *currentB = headB;
        while (currentB != NULL)
        {
            if (myMap[currentB] == true)
            {
                return currentB;
            }
            currentB = currentB->next;
        }
        return NULL;
    }

    void createIntersection(ListNode *headA, ListNode *headB, int skipA, int skipB, int intersectVal)
    {
        if (intersectVal == 0 || headA->next == NULL || headB->next == NULL)
        {
            return;
        }
        ListNode *currentA = headA;
        while (skipA > 1 && currentA->next != NULL)
        {
            currentA = currentA->next;
            skipA--;
        }

        ListNode *currentB = headB;
        while (skipB > 1 && currentB->next != NULL)
        {
            currentB = currentB->next;
            skipB--;
        }

        currentB->next = currentA->next;
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
            cout << current->val << " ";
            current = current->next;
        }
        return;
    }
};

int main()
{
    int n, m, intersectVal, skipA, skipB;
    cin >> n >> m >> intersectVal >> skipA >> skipB;

    vector<int> vecA(n);
    vector<int> vecB(m);

    for (int &x : vecA)
    {
        cin >> x;
    }
    for (int &x : vecB)
    {
        cin >> x;
    }

    Solution sol;
    ListNode *headA = sol.constructLL(vecA);
    ListNode *headB = sol.constructLL(vecB);
    sol.createIntersection(headA, headB, skipA, skipB, intersectVal);

    ListNode *intersectNode = sol.getIntersectionNode(headA, headB);
    if (intersectNode == NULL)
    {
        cout << 0;
    }
    else
    {
        cout << intersectNode->val;
    }
    // sol.printLL(headA);
    // cout << endl;
    // sol.printLL(headB);
}