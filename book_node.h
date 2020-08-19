#ifndef BOOK_NODE_H
#define BOOK_NODE_H
#include "book.h"


class book_node
{
    book data;
    book_node* next;
    book_node* prev;
public:
    book_node();

    book getData();
    void setData(book x);

    book_node *getNext();
    void setNext(book_node* x);

    book_node* getPrev();
    void setPrev(book_node* x);
};

#endif // BOOK_NODE_H
