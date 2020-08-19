#include "book_node.h"

book_node::book_node()
{
    prev=next=nullptr;
}

book book_node::getData()
{
    return this->data;
}

void book_node::setData(book x)
{
    this->data=x;
}

book_node *book_node::getNext()
{
    return this->next;
}

void book_node::setNext(book_node *x)
{
    this->next=x;
}

book_node *book_node::getPrev()
{
    return this->prev;
}

void book_node::setPrev(book_node *x)
{
    this->prev=x;
}
