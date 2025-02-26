#include <bits/stdc++.h>
using namespace std;

class DLL
{
public:
    DLL *next;
    DLL *prev;
    int val;
    DLL(int val)
    {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

class LRUcache // class for making a hashed linked list where time of access and insertion is O(1)
{
public:
    int capacity;
    unordered_map<int, DLL *> cacheMap;
    DLL *head;
    DLL *tail;
    LRUcache(int capacity)
    {
        this->capacity = capacity;
        head = new DLL(-1);
        tail = new DLL(-1);
        head->next = tail;
        tail->prev = head;
    }

    void add(DLL *node) // Helper function to add a node TC: O(1)
    {
        DLL *nextNode = head->next;
        head->next = node;
        node->prev = head;
        node->next = nextNode;
        nextNode->prev = node;
    }

    void remove(DLL *node) // To remove a node TC: O(1)
    {
        DLL *nextNode = node->next;
        DLL *prevNode = node->prev;
        nextNode->prev = prevNode;
        prevNode->next = nextNode;
    }

    int get(int value) // To check if exists and change position to latest if yes, TC: O(1)(average), O(c) worst case
    {
        if (cacheMap.find(value) == cacheMap.end())
        {
            return -1;
        }
        remove(cacheMap[value]);
        add(cacheMap[value]);
        return 1;
    }

    void put(int val) // TC: O(c), average is O(1)
    {
        if (cacheMap.find(val) != cacheMap.end()) 
        {
            DLL *toDelete = cacheMap[val];
            remove(toDelete); 
            delete toDelete; 
            cacheMap.erase(val);
        }
        DLL *newNode = new DLL(val);
        cacheMap[newNode->val] = newNode;
        add(newNode);

        if (cacheMap.size() > capacity)
        {
            DLL *toDelete = tail->prev;
            remove(toDelete);
            cacheMap.erase(toDelete->val);
            delete (toDelete);
        }
    }
};

class Solution{
    public:
        int pageFaults(int N, int C, int pages[]){ // O(n*c) worst case // space : O(2c)
            LRUcache cache(C);
            int count=0;
            for(int i=0;i<N;i++)
            {
              if(cache.get(pages[i])==-1)
              {
                count++;
              }
              cache.put(pages[i]);
            }
            return count;
        }
    };

int main()
{
    int n,c;
    cin>>n>>c;
    int arr[n];
    for(int i=0;i<n;i++)
    {
      cin>>arr[i];
    }
    Solution sol;
    int ans=sol.pageFaults(n,c,arr);
    cout<<ans;
    return 0;
}