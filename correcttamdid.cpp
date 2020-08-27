#include "correcttamdid.h"

int correctTamdid(QString _id,QString _code)
{
    int k=0;
    for(book_gharz_pass_node* tmp=checkBookgharzandpass();tmp!=nullptr;tmp=tmp->getNext())
    {
        if(tmp->getData().getCode_of_book()==_code&&tmp->getData().getNational_gharzgirande()==_id)
        {
            if(tmp->getData().getPass().getDay()!=0)
            {
                for(book_gharz_pass_node* tmp1=tmp->getNext();tmp1!=nullptr;tmp1=tmp1->getNext())
                {
                    if(tmp1->getData().getGharz()==tmp->getData().getPass() && date_now()-tmp1->getData().getPass()>14)
                    {
                        k=1;
                        break;
                    }
                }
            }
        }
    }
    if(k==1)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
