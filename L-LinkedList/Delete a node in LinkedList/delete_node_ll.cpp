#include <bits/stdc++.h>
using namespace std;

// cresting a node class for linked list
class Node
{
public:
    int data;
    Node *next;
};

// function to pushing the elements into the linked list
void push(Node **head_ref, int new_data)
{
    Node *new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

// function to delete a node in linked list
Node *deleteNode(Node *head, int i)
{
    if (i == 1)
        return head->next; // if we want to delete the head node then return the next node after head
    Node *copyhead = head;
    int c = 1;
    while (c != i - 1) // traverse the linked list just one before node which you want to delete
    {
        copyhead = copyhead->next;
        c++;
    }

    copyhead->next = copyhead->next->next; // make the new connection
    return head;
}

// function to print the linked list
void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
}

int main()
{
    Node *head = NULL;
    // Add elements in linked list
    push(&head, 7);
    push(&head, 1);
    push(&head, 3);
    push(&head, 2);

    cout << "Created Linked List: ";
    printList(head);
    int x;
    cin >> x;
    Node *t = deleteNode(head, x);

    cout << "\nLinked List after Deletion of " << x << "th Node: ";
    printList(t);
    return 0;
}

// Test Case #1
// I/P: 1
// O/P: 3 1 7

// Test Case #2
// I/P: 3
// O/P: 2 3 7

// Test Case #3
// I/P: 4
// O/P: 2 3 1
