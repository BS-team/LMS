#include "hesab_node.h"

hesab_node::hesab_node()
{
    prev=next=nullptr;
}

hesab hesab_node::getData()
{
    return this->data;
}

void hesab_node::setData(hesab x)
{
    this->data=x;
}

hesab_node *hesab_node::getNext()
{
    return this->next;
}

void hesab_node::setNext(hesab_node *x)
{
    this->next=x;
}

hesab_node *hesab_node::getPrev()
{
    return this->prev;
}

void hesab_node::setPrev(hesab_node *x)
{
    this->prev=x;
}
