#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node
{
    Node *next;
    Node *prev;
    int value;
    int key;
    Node(Node *p, Node *n, int k, int val) : prev(p), next(n), key(k), value(val){};
    Node(int k, int val) : prev(NULL), next(NULL), key(k), value(val){};
};

class Cache
{

protected:
    map<int, Node *> mp;            //map the key to the node in the linked list
    int cp;                         //capacity
    Node *tail;                     // double linked list tail pointer
    Node *head;                     // double linked list head pointer
    virtual void set(int, int) = 0; //set function
    virtual int get(int) = 0;       //get function
};

class LRUCache : public Cache
{
public:
    LRUCache(int);
    void insertIntoHead(Node *);
    void listRemoveNode(Node *);
    virtual void set(int, int);
    virtual int get(int);
};
LRUCache::LRUCache(int cap)
{
    cp = cap;
    head = nullptr;
    tail = nullptr;
}
void LRUCache::set(int k, int v)
{
    if (cp <= 0)
        return;
    map<int, Node *>::iterator it = mp.find(k);
    if (it != mp.end()) //the iterator points to the end if key was not found
    {
        Node *found = it->second;
        found->value = v;
        insertIntoHead(found);
    }
    else
    {
        if (mp.size() >= cp)
        {
            Node *del = tail;
            tail = tail->prev;
            tail->next = nullptr;
            mp.erase(del->key);
            delete del;
        }
        Node *node = new Node(k, v);
        insertIntoHead(node);
        mp.insert(make_pair(k, node));
    }
}
int LRUCache::get(int key)
{
    map<int, Node *>::iterator it = mp.find(key);
    if (it == mp.end())
    {
        return -1;
    }
    else
    {
        int ret = it->second->value;
        insertIntoHead(it->second);
        return ret;
    }
}

void LRUCache::insertIntoHead(Node *node)
{
    if (!node)
    {
        return;
    }
    listRemoveNode(node);
    if (head)
    {
        head->prev = node;
    }
    node->next = head;
    node->prev = nullptr;
    if (!tail)
    {
        tail = node;
    }
    head = node;
}
void LRUCache::listRemoveNode(Node *node)
{
    if (!node)
    {
        return;
    }
    if (node == head)
    {
        head = head->next;
    }
    if (node == tail)
    {
        tail = tail->prev;
    }
    if (node->prev)
    {
        node->prev->next = node->next; //should be nullptr if they don't exist
    }
    if (node->next)
    {
        node->next->prev = node->prev; //should be nullptr if they don't exist
    }
}

int main()
{
    int n, capacity, i;
    cin >> n >> capacity;
    LRUCache l(capacity);
    for (i = 0; i < n; i++)
    {
        string command;
        cin >> command;
        if (command == "get")
        {
            int key;
            cin >> key;
            cout << l.get(key) << endl;
        }
        else if (command == "set")
        {
            int key, value;
            cin >> key >> value;
            l.set(key, value);
        }
    }
    return 0;
}
