#include "karbar_linkedlist.h"

karbar_linkedlist::karbar_linkedlist()
{
    this->head=this->tail=nullptr;
}

karbar_node *karbar_linkedlist::getHead()
{
    return this->head;
}

void karbar_linkedlist::setHead(karbar_node* x)
{
    this->head=x;
}

karbar_node *karbar_linkedlist::getTail()
{
    return this->tail;
}

void karbar_linkedlist::setTail(karbar_node* x)
{
    this->tail=x;
}

void karbar_linkedlist::addfront(karbar t)
{
    karbar_node* tmp=new karbar_node();
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

void karbar_linkedlist::pushback(karbar t)
{
    karbar_node* tmp=new karbar_node();
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

void karbar_linkedlist::pop()
{
    head = head->getNext();
}
