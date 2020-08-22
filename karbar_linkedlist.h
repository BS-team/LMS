#ifndef KARBAR_LINKEDLIST_H
#define KARBAR_LINKEDLIST_H

#include"karbar_node.h"
#pragma once
class karbar_linkedlist
{
    karbar_node* head;
    karbar_node* tail;
public:
    karbar_linkedlist();
    ~karbar_linkedlist();

    karbar_node * getHead();
    void setHead(karbar_node*);

    karbar_node* getTail();
    void setTail(karbar_node*);

    void addfront(karbar t);
    void pushback(karbar t);

    void pop();
};

#endif // KARBAR_LINKEDLIST_H
