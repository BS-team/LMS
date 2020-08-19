#include "book_linkedlist.h"

book_linkedlist::book_linkedlist()
{
    this->head=this->tail=nullptr;
}

book_node *book_linkedlist::getHead()
{
    return this->head;
}

void book_linkedlist::setHead(book_node* x)
{
    this->head=x;
}

book_node *book_linkedlist::getTail()
{
    return this->tail;
}

void book_linkedlist::setTail(book_node* x)
{
    this->tail=x;
}

void book_linkedlist::addfront(book t)
{
    book_node* tmp=new book_node();
        tmp->setData(t);

        if (tail == nullptr)
        {
            tail = tmp;
        }
        if (head == nullptr)
        {
            head = tmp;
        }
        else
        {
            head->setPrev(tmp);
            tmp->setNext(head);
            head = tmp;
        }
}

void book_linkedlist::pushback(book t)
{
    book_node* tmp=new book_node();
    tmp->setData(t);
    if (tail == nullptr)
    {
        addfront(t);
    }
    else
    {
        tail->setNext(tmp);
        tmp->setPrev(tail);
        tail = tmp;
    }
}

void book_linkedlist::pop()
{
    head = head->getNext();
}
