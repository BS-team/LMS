#include "book_gharz_pass_node.h"

book_gharz_pass_node::book_gharz_pass_node()
{
    this->next=this->prev=nullptr;
}

book_gharz_pass_node::book_gharz_pass_node(book_gharz_pass x)
{
    this->data=x;
}

book_gharz_pass book_gharz_pass_node::getData()
{
    return this->data;
}

void book_gharz_pass_node::setData(book_gharz_pass x)
{
    this->data=x;
}

book_gharz_pass_node *book_gharz_pass_node::getNext()
{
    return this->next;
}

void book_gharz_pass_node::setNext(book_gharz_pass_node *x)
{
    this->next=x;
}

book_gharz_pass_node *book_gharz_pass_node::getPrev()
{
    return  this->prev;
}

void book_gharz_pass_node::setPrev(book_gharz_pass_node *x)
{
    this->prev=x;
}
