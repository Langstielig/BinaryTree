#include "BinaryTree.h"
#include <iostream>


void initTree(TTree& root) {
	root = nullptr;
}

void initTree(TTree& root, int elem) {
	root = new Node;
	root->data = elem;
	root->left = nullptr;
	root->right = nullptr;
}

void initTree(TTree& root, int elem, TTree leftTree, TTree rightTree) {
	initTree(root, elem);
	attachLeftSubtree(root, leftTree);
	attachRightSubtree(root, rightTree);
}

void destroyTree(TTree& root) {
	if (root != nullptr) {
		destroyTree(root->left);
		destroyTree(root->right);
		delete root;
		root = nullptr;
	}
}

bool isEmpty(TTree root) {
	return root == nullptr;
}

void attachLeftSon(TTree &root, int elem) {
	TTree p = new Node;
	p->data = elem;
	p->left = nullptr;
	p->right = nullptr;
	root->left = p;
}

void attachRightSon(TTree &root, int elem) {
	TTree p = new Node;
	p->data = elem;
	p->left = nullptr;
	p->right = nullptr;
	root->right = p;
}

void attachLeftSubtree(TTree &root, TTree subTree) {
	root->left = subTree;
}

void attachRightSubtree(TTree &root, TTree subTree) {
	root->right = subTree;
}

void preorder(TTree root, FunctionType visit) {
	if (root != nullptr) {
		visit(root->data);
		preorder(root->left, visit);
		preorder(root->right, visit);
	}
}

void inorder(TTree root, FunctionType visit) {
	if (root != nullptr) {
		inorder(root->left, visit);
		visit(root->data);
		inorder(root->right, visit);
	}
}

void postorder(TTree root, FunctionType visit) {
	if (root != nullptr) {
		postorder(root->left, visit);
		postorder(root->right, visit);
		visit(root->data);
	}
}

void createTree(TTree &root) {
	char x = '1';
	int elem;
	std::cout << "Введите значение корня" << std::endl;
	std::cin >> elem;
	initTree(root, elem);
	TTree current = root, previous = nullptr;
	while (x != '0') {
		std::cout << "Выберите поддерево: l-левое, r-правое, - -вернуться назад, a-вернуться к корню, 0-закончить заполнение: " << std::endl;
		std::cin >> x;
		if (x == 'l') {
			std::cout << "Введите значение: " << std::endl;
			std::cin >> elem;
			previous = current;
			attachLeftSon(current, elem);
			current = current->left;
		}
		else if (x == 'r') {
			std::cout << "Введите значение: " << std::endl;
			std::cin >> elem;
			previous = current;
			attachRightSon(current, elem);
			current = current->right;
		}
		else if (x == '-') 
			current = previous;
		else if (x == 'a') 
			current = root;
	}
}