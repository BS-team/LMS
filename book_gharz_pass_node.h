#ifndef BOOK_GHARZ_PASS_NODE_H
#define BOOK_GHARZ_PASS_NODE_H

#include"book_gharz_pass.h"

class book_gharz_pass_node
{
    book_gharz_pass data;
    book_gharz_pass_node* next;
    book_gharz_pass_node* prev;

public:
    book_gharz_pass_node();
    book_gharz_pass_node(book_gharz_pass x);

    book_gharz_pass getData();
    void setData(book_gharz_pass x);

    book_gharz_pass_node *getNext();
    void setNext(book_gharz_pass_node* x);

    book_gharz_pass_node* getPrev();
    void setPrev(book_gharz_pass_node* x);

};

#endif // BOOK_GHARZ_PASS_NODE_H
