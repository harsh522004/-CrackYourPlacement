// Sort a linked list of 0s, 1s and 2s
#include <iostream>
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
Node *segregate(Node *head)
{
    Node *mainHead1 = new Node(-1);
    Node *mainHead2 = new Node(-1);
    Node *H0 = head;
    Node *H1 = mainHead1;
    Node *H2 = mainHead2;
    Node *zeroTrace = head;
    bool isFirstZero = false;

    while (H0 != NULL)
    {

        if (H0->data == 1)
        {
            H1->next = H0;
            H1 = H1->next;
            H0 = H0->next;
            H1->next = NULL;
        }
        else if (H0->data == 2)
        {
            H2->next = H0;
            H2 = H2->next;
            H0 = H0->next;
            H2->next = NULL;
        }
        else
        {
            if (!isFirstZero)
            {

                head = H0;
                zeroTrace = head;
                isFirstZero = true;
            }
            else
            {
                zeroTrace->next = H0;
                zeroTrace = zeroTrace->next;
            }
            H0 = H0->next;
            zeroTrace->next = NULL;
        }
    }
    zeroTrace->next = mainHead1->next;
    H1->next = mainHead2->next;
    delete mainHead1;
    delete mainHead2;
    return head;

    // Add code here
}