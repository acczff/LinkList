#include <stdio.h>
#include <iostream>
#include "Mystring.cpp"

template <typename T>
struct Node
{
    T data;
    Node<T>* next;
    Node<T>* last;

    Node(T value) : data(value), next(nullptr), last(nullptr) {};
};

template <typename T>
class LinkList
{
private:
    Node<T>* head;
    Node<T>* tail;
    int length;
public:
    LinkList() : head(nullptr), tail(nullptr), length(0) {};
    ~LinkList()
    {
        Node<T>* current = head;
        while (current != nullptr)
        {
            Node<T>* next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
        tail = nullptr;
    };

    void append(T value)
    {
        Node<T>* newNode = new Node<T>(value);
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
            length++;
            return;
        }
        tail->next = newNode;
        newNode->last = tail;
        tail = newNode;
        length++;
    }

    //按照position插入value
    void insert(T value, int position)
    {
        Node<T>* newNode = new Node<T>(value);
        if (position > length)
        {
            std::cout << "Insertion failure : position > length" << std::endl;
            delete newNode;
            return;
        }
        else if (position == 0)
        {
            std::cout << "Insertion failure : position must be > 0" << std::endl;
            delete newNode;
            return;
        }
        else if (position == 1)
        {
            newNode->next = head;
            head->last = newNode;
            head = newNode;
            length++;
            delete newNode;
            return;
        }
        Node<T>* nowNode = head;
        int n = position - 1;
        while (n >= 0)
        {
            if (n == 0)
            {
                newNode->next = nowNode;
                newNode->last = nowNode->last;
                nowNode->last->next = newNode;
                nowNode->last = newNode;
                length++;
            }
            nowNode = nowNode->next;
            n--;
        }

    }

    //根据position删除value
    void deleteValue(int position)
    {
        Node<T>* nowNode = head;
        if (position > length)
        {
            std::cout << "DeleteValue failure : position > length" << std::endl;
            return;
        }
        else if (position == 0)
        {
            std::cout << "DeleteValue failure : position must be > 0" << std::endl;
            return;
        }
        else if (position == 1)
        {
            nowNode = head->next;
            nowNode->next->last = nullptr;
            head = nowNode;
            length--;
            return;
        }
        int n = position;
        while (n >= 0)
        {
            if (n == 0)
            {
                nowNode->next->last = nowNode->last;
                nowNode->last->next = nowNode->next;
                length--;
            }
            nowNode = nowNode->next;
            n--;
        }
    }

    //根据position查询value
    T query(int position)
    {
        if (position > length)
        {
            std::cout << "Query failure : position > length" << std::endl;
            return T();
        }
        else if (position == 0)
        {
            std::cout << "Query failure : position must be > 0" << std::endl;
            return T();
        }
        else if (position == 1)
        {
            
            return head->data;
        }
        Node<T>* nowNode = head;
        int n = position - 1;
        while (n >= 0)
        {
            if (n == 0)
            {
                return nowNode->data;
            }
            nowNode = nowNode->next;
            n--;
        }
    }

    //打印list
    void print()
    {

        Node<T>* current = head;
        while (current != nullptr)
        {
            std::cout << current->data;
            current = current->next;
        }
        std::cout << std::endl;
        std::cout << "Head: " << (head != nullptr ? head->data : "nullptr") << std::endl;
        std::cout << "Tail: " << (tail != nullptr ? tail->data : "nullptr") << std::endl;
        std::cout << "Length: " << length << std::endl;
    }
};



int main() {
    LinkList<Mystring> msList;
    Mystring ms1;
    Mystring* ms2 = &ms1;
    Mystring ms3 = ms1;
    return 0;
}