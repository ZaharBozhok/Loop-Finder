//
// Created by User on 8/19/18.
//

#ifndef CYCLEDLIST_SIMPLELIST_H
#define CYCLEDLIST_SIMPLELIST_H

#include<cstddef>

template<class T>
class SimpleList
{
public:
    class Node
    {
    public:

        Node(const T & value):value(value),next(nullptr){}

        ~Node(){/* Destructing node */}

        const Node * Next()const {return this->next;}

        Node * Next(){return this->next;} // this function is used only in SimpleList

        const T & Value()const {return this->value;}

        void Next(Node * next){this->next = next;}

    private:
        T value;
        Node * next;
    };

    SimpleList():head(nullptr),tail(nullptr),size(0){}
    ~SimpleList();

    void append(const T & value);
    const Node *    Head()  const   {return this->head;}
    const size_t &  Size()  const   {return this->size;}

private:
    Node * head;
    Node * tail;
    size_t size;
};

template<class T>
SimpleList<T>::~SimpleList() {
    while(this->head)
    {
        Node * tmp = this->head->Next();
        delete this->head;
        this->head = tmp;
    }
    this->tail = nullptr;
}

template<class T>
void SimpleList<T>::append(const T &value)     {
    if(this->head == nullptr && this->tail == nullptr) {
        this->head = new Node(value);
        this->tail = this->head;
    } else {
        this->tail->Next(new Node(value));
        this->tail = this->tail->Next();
    }
    ++this->size;
}
#endif //CYCLEDLIST_SIMPLELIST_H
