//
// Created by DobyAsa on 2022/6/1.
//

#ifndef BINTREE_BINNODE_H
#define BINTREE_BINNODE_H

template<typename T>
struct BinNode {
    T data;
    BinNode<T> *lChild, *rChild;

    BinNode(T const & e){
        data = e;
    }
    BinNode<T>* insertAsLC(T const & e){
        return lChild = new BinNode(e);
    }
    BinNode<T>* insertAsRC(T const & e){
        return rChild = new BinNode(e);
    }
    int size(){
        int s = 1;//自身大小为1
        if (lChild) s += lChild->size();
        if (rChild) s += rChild->size();
        return s;
    }
};


#endif //BINTREE_BINNODE_H
