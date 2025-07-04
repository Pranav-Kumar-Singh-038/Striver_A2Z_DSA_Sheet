#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    int value;
    Node *prev;
    Node *next;
    Node(int k, int v) 
    {
        this->next=NULL;
        this->prev=NULL;
        this->key=k;
        this->value=v;
    }
};

// Logic: we use DLL and unordered map for this, unordered map gives constant time access to a node, and DLL allows removal of Nodes in O(1) time, 
// In DLL we have two pointers the top points to the first node, the tail points to last node
// Whenever we add a node, we add to front via make newnode->next=old first node, old first node->prev=newNode
// newnode->prev=head, head->next=newNode, to remove simply, node prevous's next should point to node's next
// node's next's prev should point to node's prev, Now when we get a "Get" we check in map if it is there
// then if available, remove the current node, add to front, making it recently used, and return node value
// for put, if already in map, then update the value, remove, add to front, making it recently used
// if not in map, create the node, add to front, add in map, if capacity exceeded fetch the tail->prev remove it
// both form dll and map, remember to delete
//
class LRUCache
{
private:
    int capacity;
    unordered_map<int, Node *> map; // SC: O(n)
    Node *head; 
    Node *tail;

    void remove(Node *node) // TC: O(1), SC:O (1)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insertToFront(Node *node)// TC: O(1), SC:O (1)
    {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

public:
    LRUCache(int capacity)
    {
        this->capacity=capacity;
        head = new Node(-1, -1); 
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key)
    {
        if (map.find(key) == map.end()) // TC: O(1) Avg, worst O(n)
            return -1;

        Node *node = map[key];
        remove(node);// TC: O(1), SC:O (1)
        insertToFront(node);// TC: O(1), SC:O (1)

        return node->value;
    }

    void put(int key, int value)
    {
        if (map.find(key) != map.end()) // TC: O(1) Avg, worst O(n)
        {
            Node *existing = map[key];
            existing->value = value;
            remove(existing); // TC: O(1), SC:O (1)
            insertToFront(existing);// TC: O(1), SC:O (1)
        }
        else
        {
            if (map.size() == capacity)
            {
                Node *lru = tail->prev;
                remove(lru); // TC: O(1), SC:O (1)
                map.erase(lru->key);  // TC: O(1) Avg, worst O(n)
                delete lru;
            }
            Node *newNode = new Node(key, value);
            insertToFront(newNode);  // TC: O(1), SC:O (1)
            map[key] = newNode;
        }
    }
};

int main()
{
    int capacity;
    cin >> capacity;
    LRUCache LRU(capacity);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string cmd;
        cin >> cmd;
        if (cmd == "put")
        {
            int key, value;
            cin >> key >> value;
            LRU.put(key, value);
        }
        else
        {
            int key;
            cin >> key;
            int ans = LRU.get(key);
            cout << ans<<" ";
        }
    }
    return 0;
}