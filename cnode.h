// file cnode.h

#ifndef CHAINNODE_H
#define CHAINNODE_H

template <class T> class Chain;

template <class T>
class ChainNode
{
    friend class Chain<T>;

private:
    T data;                
    ChainNode<T>* link;  
public:
   
    T getData() const {
        return data;
    }
};

#endif
