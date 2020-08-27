#ifndef KARBAR_NODE_H
#define KARBAR_NODE_H
#include"karbar.h"

class karbar_node
{
    karbar data;
    karbar_node* next;
    karbar_node* prev;
public:
    karbar_node();

    karbar getData();
    void setData(karbar x);

    karbar_node *getNext();
    void setNext(karbar_node* x);

    karbar_node* getPrev();
    void setPrev(karbar_node* x);
};

#endif // KARBAR_NODE_H
