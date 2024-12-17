#include <iostream>
using namespace std;

template <typename T>
struct Node
{
    T data;
    Node *next;
};

template <typename T>
class LinkedList
{
public:
    void insert(T data)
    {
        Node<T> *node = new Node<T>;
        node->data = data;
        if (!head)
        {
            head = node;
            tail = head;
        }
        else
        {
            tail->next = node;
            tail = tail->next;
        }
    }

    ~LinkedList()
    {
        Node<T> *temp = head;

        while (temp)
        {
            Node<T> *t = temp->next;
            cout << "Deleting data: " << temp->data << endl;
            delete temp;
            temp = t;
        }
    }

    template <typename U>
    friend ostream &operator<<(ostream &os, LinkedList<U> &ll);

private:
    Node<T> *head = nullptr;
    Node<T> *tail = nullptr;
};

template <typename T>
std::ostream &operator<<(ostream &os, LinkedList<T> &ll)
{
    Node<T> *curr = ll.head;

    while (curr)
    {
        os << curr->data << "->";
        curr = curr->next;
    }
    os << endl;

    return os;
}

int main()
{
    LinkedList<string> ll;

    ll.insert(".");
    ll.insert("b");
    ll.insert("c");
    ll.insert("d");
    ll.insert("e");
    ll.insert("f");
    cout << ll;

    return 0;
}