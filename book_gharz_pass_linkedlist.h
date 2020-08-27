#ifndef BOOK_GHARZ_PASS_LINKEDLIST_H
#define BOOK_GHARZ_PASS_LINKEDLIST_H
#include"book_gharz_pass_node.h"

class book_gharz_pass_linkedList
{
    book_gharz_pass_node* head;
    book_gharz_pass_node* tail;
public:
    book_gharz_pass_linkedList();

    book_gharz_pass_node * getHead();
    void setHead(book_gharz_pass_node*);

    book_gharz_pass_node* getTail();
    void setTail(book_gharz_pass_node*);

    void addfront(book_gharz_pass t);
    void pushback(book_gharz_pass t);

    void pop();
};

#endif // BOOK_GHARZ_PASS_LINKEDLIST_H
