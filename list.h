#ifndef __DLLIST__
#define __DLLIST__

#include <iostream>
#include <string>

using namespace std;

template<typename T> class List;

template<typename T>
class Node
{
private:
    T value;
    Node* prev;
    Node* next;
public:
    Node(T value, Node* prev = NULL, Node* next = NULL);
    friend class List<T>;
    void SetNext(Node*);
    void SetPrev(Node*);
    Node* GetNext();
    Node* GetPrev();
    T GetData();

};

template<typename T>
class List
{
private:
    Node<T>* head;
    Node<T>* tail;
public:
    List();
    List(const List<T>& src);
    ~List();
    bool IsEmpty() const;
    T GetHead() const;
    T GetTail() const;
    void AddToHead(T);
    void AddToTail(T);
    bool RemoveHead();
    bool RemoveTail();

    operator string() const;
    ///////////////////////////////////////////
    // Do not change the above prototype.
    // Add member function(s) below if you need.



    // Do not change the below.
    ///////////////////////////////////////////
};

template<typename T>
Node<T>::Node(T value, Node* prev, Node* next)
{
    this->value = value;
    this->prev = prev;
    this->next = next;
}

template<typename T>
void Node<T>::SetNext(Node * i) {
    next = i;
}

template<typename T>
Node<T>* Node<T>::GetNext() {
    return next;
}

template<typename T>
Node<T> *Node<T>::GetPrev() {
    return prev;
}

template<typename T>
T Node<T>::GetData() {
    return value;
}

template<typename T>
void Node<T>::SetPrev(Node *i) {
    prev = i;
}

template<typename T>
List<T>::operator string() const
{
    if (IsEmpty())
        return "()";
    stringstream os;
    os << "(";
    Node<T>* r = head;
    while (r != tail)
    {
        os << r->value << ",";
        r = r->next;
    }
    os << r->value << ")";
    string str = os.str();
    return str;
}

template<typename T>
List<T>::List()
{
    // make list empty
    head = tail = NULL;
}

template<typename T>
List<T>::List(const List<T>& src)
{
    // make list empty
    head = tail = NULL;

    // copy all contents in src into this
    Node<T>* node = src.head;
    while(node != NULL)
    {
        AddToTail(node->value);
        node = node->next;
    }
}

template<typename T>
bool List<T>::IsEmpty() const
{
    return (head == NULL);
}



///////////////////////////////////////////
// Do not change the above.
// Implement your own member functions below.

template<typename T>
List<T>::~List() {
    while (!IsEmpty()) {
        RemoveTail();
    }
} // fine

template<typename T>
T List<T>::GetHead() const {
    return head->GetData();
}// fine

template<typename T>
T List<T>::GetTail() const {
    return tail->GetData();
}// fine

template<typename T>
void List<T>::AddToHead(T data) {
    if (IsEmpty()) {
        head = tail = new Node<T>(data, nullptr, nullptr);
    } else {
        // DLNode(data, next, prev)
        auto temp = head;
        head = new Node<T>(data, head, nullptr);
        head->SetNext(temp);
        temp->SetPrev(head);
    }

}

template<typename T>
void List<T>::AddToTail(T data) {
    if (IsEmpty()) {
        head = tail = new Node<T>(data, nullptr, nullptr);
    } else {
        auto temp = tail;
        tail = new Node<T>(data, tail, nullptr); // set prev
        tail->GetPrev()->SetNext(tail); // set next
    }
}

template<typename T>
bool List<T>::RemoveHead() {
    if (IsEmpty()) {
        return false;
    }
    auto data = head->GetData();
    if (head == tail) {
        // one node case
        delete tail;
        head = tail = nullptr;
    } else {
        head = head->GetNext();
        delete head->GetPrev();
        head->SetPrev(nullptr);
    }
    return true;
}

template<typename T>
bool List<T>::RemoveTail() {
    if (IsEmpty()) {
       return false;
    }

    auto data = head->GetData();
    if (head == tail) {
        // one node case
        delete tail;
        head = tail = nullptr;
    } else {
        tail = tail->GetPrev();
        delete tail->GetNext();
        tail->SetNext(nullptr);
    }
    return true;
}

// Do not change the below.
///////////////////////////////////////////

#endif //__DLLIST__