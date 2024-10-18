#include <bits/stdc++.h>

using namespace std;
struct ListNode
{
    int data;
    struct ListNode *next;
    ListNode(int x)
    {
        data = x;
        next = NULL;
    }
};
void printLinkedList(ListNode *head)
{
    ListNode *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " "; // Print the current node's data
        temp = temp->next;         // Move to the next node
    }

    cout << endl;
}

ListNode *deleteMiddle(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;
    ListNode *prev = head;
    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (prev->next->next == slow)
        {
            prev = prev->next;
        }
    }

    // here we have to delet slow
    prev->next = slow->next;
    delete slow;
    return head;
}
int main()
{
    // your code goes here
    // Node *head = new Node(1);
    // Node *second = new Node(2);
    // head->next = second;
    ListNode *head = new ListNode(1);
    ListNode *temp = head;

    // // Create a linked list of 12 nodes
    for (int i = 2; i <= 10; i++)
    {
        temp->next = new ListNode(i);
        temp = temp->next;
    }

    printLinkedList(head);
    ListNode *node = deleteMiddle(head);
    printLinkedList(node);

    // Output to verify the structure of the linked list
    cout << "Linked list with a loop created." << endl;

    // cout << countNodesinLoop(head);

    return 0;
}