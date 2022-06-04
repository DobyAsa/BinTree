#include "BinTree.h"
using namespace std;
void initialize(BinTree<char>& tree);

int main() {
    BinTree<char> tree("A(B(D(,G)),C(E,F))");
    return 0;
}




void initialize(BinTree<char>& tree){
    BinNode<char>* b = tree.insert('B', tree.root());
    BinNode<char>* c = tree.insert(tree.root(), 'C');
    BinNode<char>* d = tree.insert('D', b);
    BinNode<char>* e = tree.insert('E', c);
    BinNode<char>* f = tree.insert(c, 'F');
    BinNode<char>* g = tree.insert(d, 'G');
}