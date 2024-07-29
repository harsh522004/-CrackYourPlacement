#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class LRUCache
{
private:
    class node
    {
    public:
        int key;
        int val;
        node *next;
        node *prev;
        node(int _key, int _val)
        {
            key = _key;
            val = _val;
        }
    };

    node *head = new node(-1, -1);
    node *tail = new node(-1, -1);

    map<int, node *> entry;

    int capacity;

public:
    LRUCache(int capacity) : capacity(capacity)
    {
        cout << "Instance created with capacity: " << this->capacity << endl;
        // cout << "Instance created. Map and stack initialized." << endl;
    }

    // add at next to head
    void addNode(node *newnode)
    {
        node *temp = head->next;
        newnode->next = temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev = newnode;
    }

    void deletNode(node *deletnode)
    {
        node *delprev = deletnode->prev;
        node *delnext = deletnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }

    int get(int key)
    {

        if (entry.find(key) != entry.end())
        {
            // get that node and vlaue
            node *resultNode = entry[key];
            int value = resultNode->val;

            // erase current position
            entry.erase(key);
            deletNode(resultNode);

            // add at most frequent one
            addNode(resultNode);
            entry[key] = head->next;
            return value;
        }
        else
        {
            return -1;
        }
    }

    void put(int key, int value)
    {
        // key alredy exitst
        if (entry.find(key) != entry.end())
        {
            node *existingNode = entry[key];
            entry.erase(key);
            deletNode(existingNode);
        }
        if (entry.size() == capacity)
        {
            entry.erase(tail->prev->key);
            deletNode(tail->prev);
        }

        addNode(new node(key, value));
        entry[key] = head->next;
    }
};

int main()
{
    int capacity = 2;

    LRUCache *obj = new LRUCache(capacity);

    obj->put(1, 1);
    obj->put(2, 2);
    obj->get(1);
    obj->put(3, 3);
    obj->get(1);
    obj->get(2);
    obj->put(4, 4);

    return 0;
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */