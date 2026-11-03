#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

void insertEnd(Node*& head, int x)
{
    Node* newNode = new Node;
    newNode->data = x;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node* temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

int countAndDelete(Node*& head, int key)
{
    int count = 0;

    while (head != NULL && head->data == key)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
        count++;
    }

    Node* temp = head;

    while (temp != NULL && temp->next != NULL)
    {
        if (temp->next->data == key)
        {
            Node* del = temp->next;
            temp->next = del->next;
            delete del;
            count++;
        }
        else
        {
            temp = temp->next;
        }
    }

    return count;
}

void display(Node* head)
{
    if (head == NULL)
    {
        cout << "Empty List";
        return;
    }

    while (head != NULL)
    {
        cout << head->data;

        if (head->next != NULL)
            cout << "->";

        head = head->next;
    }
}

int main()
{
    Node* head = NULL;
    int n, x, key;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter node values: ";

    for (int i = 0; i < n; i++)
    {
        cin >> x;
        insertEnd(head, x);
    }

    cout << "Enter key to delete: ";
    cin >> key;

    int count = countAndDelete(head, key);

    cout << "Count: " << count << endl;
    cout << "Updated Linked List: ";
    display(head);

    return 0;
}
