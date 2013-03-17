//

#ifndef VERTEX_H
#define	VERTEX_H

#include <list>

struct vertex
{
    //stores the number of the vertex
    int label;

    //stores the address of the representative vertex
    vertex* rep;

    //will hold the predecessor label so the path can be
    // walked through by user
    int predLabel;

    //rank helps the linker decide the smaller set to join
    size_t rank;

    //holds the other members of the set if it ever "wins"
    // a unionizer function "competition" by out-ranking
    std::list<vertex> theList;

    //set to true if this vertex "loses" a unionizer "competition"
    bool absorbed;

    bool operator == (const vertex& v) const
    {
        if( this->label != v.label ||
                this->predLabel != v.predLabel ||
                this->rank != v.rank ||
                this->theList != v.theList ||
                this->absorbed != v.absorbed )
        {
            return false;
        }

        else return true;

    }

    vertex& operator = (const vertex& v)
    {
        if (&v==this)
            return *this;

        this->label=v.label;
        this->rep=v.rep;
        this->predLabel=v.predLabel;
        this->rank=v.rank;
        this->theList=v.theList;
        this->absorbed=v.absorbed;

        return *this;
    }
};


#endif	/* VERTEX_H */

