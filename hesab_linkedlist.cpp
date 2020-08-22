#include "hesab_linkedlist.h"

hesab_linkedlist::hesab_linkedlist()
{
    this->head=this->tail=nullptr;
}

hesab_node *hesab_linkedlist::getHead()
{
    return this->head;
}

void hesab_linkedlist::setHead(hesab_node* x)
{
    this->head=x;
}

hesab_node *hesab_linkedlist::getTail()
{
    return this->tail;
}

void hesab_linkedlist::setTail(hesab_node* x)
{
    this->tail=x;
}

void hesab_linkedlist::addfront(hesab t)
{
    hesab_node* tmp=new hesab_node();
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

void hesab_linkedlist::pushback(hesab t)
{
    hesab_node* tmp=new hesab_node();
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

void hesab_linkedlist::pop()
{
    head = head->getNext();
}
