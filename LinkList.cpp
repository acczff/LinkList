#include <stdio.h>
#include <iostream>

struct Node
{
    int data;
    Node* next;
    Node* last;

    Node(int value) : data(value), next(nullptr), last(nullptr) {};
};

class LinkList
{
private:
    Node* head;
    Node* tail;
    int length;
public:
    LinkList() : head(nullptr), tail(nullptr), length(0) {};
    ~LinkList();

    void append(int value)
    {
        Node* newNode = new Node(value);
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
            length++;
            delete newNode;
            return;
        }
        tail->next = newNode;
        newNode->last = tail;
        tail = newNode;
        length++;
    }

    //按照position插入value
    void insert(int value, int position)
    {
        Node* newNode = new Node(value);
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
        Node* nowNode = head;
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
        Node* nowNode = head;
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
    int query(int position)
    {
        if (position > length)
        {
            std::cout << "Query failure : position > length" << std::endl;
            return -1;
        }
        else if (position == 0)
        {
            std::cout << "Query failure : position must be > 0" << std::endl;
            return -1;
        }
        else if (position == 1)
        {
            
            return head->data;
        }
        Node* nowNode = head;
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

        Node* current = head;
        while (current != nullptr)
        {
            int last_data = (current->last != nullptr) ? current->last->data : 0;
            int next_data = (current->next != nullptr) ? current->next->data : 0;

            std::cout << current->data << " ";
            std::cout << "<" << last_data << "," << next_data << ">" << std::endl;

            current = current->next;
        }
        std::cout << "Head: " << head->data << std::endl;
        std::cout << "Tail: " << tail->data << std::endl;
        std::cout << "Length: " << length << std::endl;
    }
};

LinkList::~LinkList()
{
    Node* current = head;
    while (current != nullptr)
    {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
    tail = nullptr;
}



int main() {
    LinkList lt;
    lt.append(1);
    lt.append(2);
    //lt.append(3);
    lt.append(4);
    lt.append(5);
    lt.append(6);
    //lt.appendMiddle(0);
    lt.insert(3, 3);
    //lt.insert(0, 1);
    //lt.deleteValue(4);
    lt.print();
    std::cout << "Query:" << lt.query(0) << std::endl;
 
    return 0;
}