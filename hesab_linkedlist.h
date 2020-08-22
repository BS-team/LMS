#ifndef HESAB_LINKEDLIST_H
#define HESAB_LINKEDLIST_H

#include "hesab_node.h"


class hesab_linkedlist
{
    hesab_node *head;
    hesab_node *tail;
public:
    hesab_linkedlist();
    ~hesab_linkedlist();


    hesab_node * getHead();
    void setHead(hesab_node*);

    hesab_node* getTail();
    void setTail(hesab_node*);

    void addfront(hesab t);
    void pushback(hesab t);

    void pop();
};

#endif // HESAB_LINKEDLIST_H
