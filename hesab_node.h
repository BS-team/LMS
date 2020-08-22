#ifndef HESAB_NODE_H
#define HESAB_NODE_H
#include "hesab.h"


class hesab_node
{
    hesab data;
    hesab_node * next;
    hesab_node * prev;
public:
    hesab_node();

    hesab getData();
    void setData(hesab x);


    hesab_node *getNext();
    void setNext(hesab_node* x);

    hesab_node* getPrev();
    void setPrev(hesab_node* x);
};

#endif // HESAB_NODE_H




