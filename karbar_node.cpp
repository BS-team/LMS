#include "karbar_node.h"

karbar_node::karbar_node()
{
    prev=next=nullptr;
}

karbar karbar_node::getData()
{
    return this->data;
}

void karbar_node::setData(karbar x)
{
    this->data=x;
}

karbar_node *karbar_node::getNext()
{
    return this->next;
}

void karbar_node::setNext(karbar_node *x)
{
    this->next=x;
}

karbar_node *karbar_node::getPrev()
{
    return this->prev;
}

void karbar_node::setPrev(karbar_node *x)
{
    this->prev=x;
}
