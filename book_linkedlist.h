#ifndef BOOK_LINKEDLIST_H
#define BOOK_LINKEDLIST_H
#include "book_node.h"

class book_linkedlist
{
    book_node* head;
    book_node* tail;
public:
    book_linkedlist();
    ~book_linkedlist();

    book_node * getHead();
    void setHead(book_node*);

    book_node* getTail();
    void setTail(book_node*);

    void addfront(book t);
    void pushback(book t);

    void pop();
};

#endif // BOOK_LINKEDLIST_H
