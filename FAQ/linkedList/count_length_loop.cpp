// gfg

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

Node *isLoop(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    while (slow != NULL && fast != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            return slow;
        }
    }
    return NULL;
}
int lengthCount(Node *meetPoint, Node *head)
{

    Node *slow = head;
    Node *fast = meetPoint;
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    int length = 1;
    fast = fast->next;
    while (slow != fast)
    {
        fast = fast->next;
        length++;
    }
    return length;
}
int countNodesinLoop(Node *head)
{
    // Code here
    Node *meetPoint = isLoop(head);
    if (meetPoint == NULL)
    {
        return 0;
    }
    return lengthCount(meetPoint, head);
}
int main()
{
    // your code goes here
    Node *head = new Node(1);
    Node *second = new Node(2);
    head->next = second;
    // Node * head = new Node(1);
    // Node * temp = head;

    // // Create a linked list of 12 nodes
    // for (int i = 2; i <= 10; i++) {
    //     temp->next = new Node(i);
    //     temp = temp->next;
    // }

    // // Introduce a loop after 5th node
    // Node * loopStart = head;
    // for (int i = 1; i < 4; i++) {
    //     loopStart = loopStart->next;
    // }

    // // Connect the last node (12th node) to the 5th node to create a loop
    // temp -> next = loopStart;

    // Output to verify the structure of the linked list
    cout << "Linked list with a loop created." << endl;

    cout << countNodesinLoop(head);

    return 0;
}