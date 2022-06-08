#include </Users/kushaldas/Desktop/bits/stdc++.h>
using namespace std;

class LRUCache
{

    class node
    {
    public:
        int key;
        int value;
        node *next;
        node *prev;
        node(int key, int value)
        {
            this->key = key;
            this->value = value;
            this->next = NULL;
            this->prev = NULL;
        }
    };

public:
    int capacity;
    unordered_map<int, node *> m;
    node *head = new node(-1, -1);
    node *tail = new node(-1, -1);
    LRUCache(int capacity)
    {
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head;
    }
    void addnode(node *newnode)
    {
        node *temp = head->next;
        newnode->next = temp;
        head->next = newnode;
        newnode->prev = head;
        temp->prev = newnode;
    }
    void deletenode(node *delnode)
    {
        node *delprev = delnode->prev;
        node *delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }
    int get(int key)
    {
        if (m.find(key) != m.end())
        {
            node *resnode = m[key];
            int res = resnode->value;
            m.erase(key);
            deletenode(resnode);
            addnode(resnode);
            m[key] = head->next;
            return res;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (m.find(key) != m.end())
        {
            node *existingnode = m[key];
            m.erase(key);
            deletenode(existingnode);
        }
        if (m.size() == capacity)
        {
            m.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        addnode(new node(key, value));
        m[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
int main(int argc, char const *argv[])
{
    int num;
    int num;
    cout << num << endl;
    int num;
    vector<int> vec(n);
    return 0;
}
