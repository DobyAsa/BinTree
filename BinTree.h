//
// Created by DobyAsa on 2022/6/1.
//

#ifndef BINTREE_BINTREE_H
#define BINTREE_BINTREE_H
#include "BinNode.h"
#include <iostream>
#include <queue>
#include <stack>
template<typename T>
class BinTree {
protected:
    int _size;
    BinNode<T>* _root = nullptr;
public:
    BinTree(const char *str){
        int i = 0;
        int k = 0;
        BinNode<T>* p;
        std::stack<BinNode<T>*> s;
        while(str[i]){
            switch (str[i]) {
                case '(':
                    s.push(p); k = 1; break;
                case ')':
                    s.pop(); break;
                case ',':
                    k = 2; break;
                default:
                    p = new BinNode<T>(str[i]);
                    p->rChild = p->lChild = nullptr;
                    if(_root == nullptr){
                        _root = p;
                    }else{
                        switch (k) {
                            case 1:
                                s.top()->lChild = p; break;
                            case 2:
                                s.top()->rChild = p; break;
                        }
                    }
            }
            i++;
        }
    }
    ~BinTree(){
        std::queue<BinNode<T>*> queue;
        queue.push(_root);
        BinNode<T>* x;
        while(!queue.empty()){
            x = queue.front();
            if (x) {
                queue.push(x->lChild);
                queue.push(x->rChild);
                std::cout << x->data << std::endl;
                delete (x);
            }
            queue.pop();
        }
    }
    int size(){
        return _size;
    }
    bool isEmpty(){
        return !_root;
    }
    BinNode<T>* root(){
        return _root;
    }
    BinNode<T>* insert(T const & e, BinNode<T>* x){
        // 作为左孩子
        _size++;
        x->insertAsLC(e);
        return x->lChild;
    }
    BinNode<T>* insert(BinNode<T>* x, T const & e){
        // 作为右孩子
        _size++;
        x->insertAsRC(e);
        return x->rChild;
    }
};


#endif //BINTREE_BINTREE_H
