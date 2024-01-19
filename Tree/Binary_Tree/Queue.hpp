#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

template <class T>
class Queue;

template <class T>
struct qnode
{
    T data;
    qnode<T> *next;

    friend class Queue<T>;
};

template <class T>
class Queue
{
    qnode<T> *head;

public:
    Queue() : head(nullptr) {}

    void display() const
    {
        qnode<T> *temp = head;

        while (temp != nullptr)
        {
            std::cout << "|" << temp->data << "|->";
            temp = temp->next;
        }
    }

    bool is_empty() const { return head == nullptr; }

    void enqueue(T data)
    {
        qnode<T> *temp = nullptr;
        qnode<T> *new_node = new qnode<T>;
        if (new_node == nullptr)
            return;

        new_node->data = data;
        new_node->next = nullptr;

        if (head == nullptr)
        {
            head = new_node;
            return;
        }

        temp = head;

        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = new_node;
    }

    T dequeu()
    {
        T deleted_data;
        qnode<T> *temp = nullptr;

        if (head == nullptr)
            return nullptr;

        temp = head;
        deleted_data = temp->data;
        head = head->next;
        delete temp;
        return deleted_data;
    }
};

#endif // QUEUE_H
