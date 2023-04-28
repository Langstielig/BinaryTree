#pragma once

struct Node {
	int data;
	Node* left;
	Node* right;
};

typedef Node* TTree;
typedef void(*FunctionType) (int& node);

void initTree(TTree& root);
void initTree(TTree& root, int elem);
void initTree(TTree& root, int elem, TTree leftTree, TTree rightTree);
void destroyTree(TTree& root);
bool isEmpty(TTree root);
void attachLeftSon(TTree &root, int elem);
void attachRightSon(TTree &root, int elem);
void attachLeftSubtree(TTree &root, TTree subTree);
void attachRightSubtree(TTree &root, TTree subTree);
void preorder(TTree root, FunctionType visit);
void inorder(TTree root, FunctionType visit);
void postorder(TTree root, FunctionType visit);
void createTree(TTree &root);