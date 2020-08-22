#include "book_gharz_pass_linkedlist.h"

book_gharz_pass_linkedList::book_gharz_pass_linkedList()
{
    this->head=this->tail=nullptr;
}

book_gharz_pass_node *book_gharz_pass_linkedList::getHead()
{
    return this->head;
}

void book_gharz_pass_linkedList::setHead(book_gharz_pass_node *x)
{
    this->head=x;
}

book_gharz_pass_node *book_gharz_pass_linkedList::getTail()
{
    return this->tail;
}

void book_gharz_pass_linkedList::setTail(book_gharz_pass_node * x)
{
    this->tail=x;
}

void book_gharz_pass_linkedList::addfront(book_gharz_pass t)
{
    book_gharz_pass_node* tmp=new book_gharz_pass_node();
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

void book_gharz_pass_linkedList::pushback(book_gharz_pass t)
{
    book_gharz_pass_node* tmp=new book_gharz_pass_node();
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

void book_gharz_pass_linkedList::pop()
{
    head = head->getNext();
}
