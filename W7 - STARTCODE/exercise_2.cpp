#include <iostream>
#include "BinaryTree.h"
#include "Node.h"
#include<ctime>

using namespace std;

void insert(Node* node, int value){
    int direction = rand() % 2;
    if(direction == 0){
        if(node->left != nullptr){
            insert(node->left, value);
        }else{
            node->left = new Node(value);
        }
    }
    else{
        if(node->right != nullptr){
            insert(node->right, value);
        }else{
            node->right = new Node(value);
        }
    }
}

 void printTree(Node* node, int space, int levelWidth = 4) {
        if (node == nullptr) {
            return;
        }

        space += levelWidth;

        printTree(node->right, space);

        std::cout << std::endl;
        for (int i = levelWidth; i < space; i++) {
            std::cout << " ";
        }
        std::cout << node->data;

        printTree(node->left, space);
    }

int height(Node* root){
    if(root==nullptr){
        return 0;
    }
    return max(height(root->left), height(root->right)) + 1;
}

int main() {
    srand(time(0));
    BinaryTree tree(50);
    for(int i=0; i<50 ; i++){
        int num = rand() % 100;
        insert(tree.getroot(), num);
    }
    cout<<"In-Order: "<< tree.inOrderTraverse()<<"\n"; 
    cout<<"Pre-Order: "<< tree.preOrderTraverse()<<"\n"; 
    cout<<"Post-Order: "<< tree.postOrderTraverse()<<"\n";

    printTree(tree.getroot(), 1);

    cout<<endl<<"Height of small tree: "<< height(tree.getroot());

    BinaryTree bigtree(500);
    for(int i=0; i<1000 ; i++){
        int Num = rand() % 1000;
        insert(bigtree.getroot(), Num);
    }
    cout<<"In-Order: "<< tree.inOrderTraverse()<<"\n"; 
    cout<<"Pre-Order: "<< tree.preOrderTraverse()<<"\n"; 
    cout<<"Post-Order: "<< tree.postOrderTraverse()<<"\n";

    printTree(bigtree.getroot(), 1);

    cout<<endl<<"Height of big tree: "<< height(bigtree.getroot());
    return 0;
}