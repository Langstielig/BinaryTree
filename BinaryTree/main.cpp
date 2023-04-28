#include <iostream>
#include "BinaryTree.h"

using namespace std;

void print(int& elem) {
	cout << elem << ' ';
}

void printTree(TTree root, int level) 
{
	if (root != nullptr) {
		printTree(root->right, level + 1);
		for (size_t i = 0; i < level; i++)
			std::cout << "\t";
		std::cout << root->data << "->{" << "\n";
		printTree(root->left, level + 1);
	} 
}

void print0Tree(TTree root) {
	if (root != nullptr) {
		print0Tree(root->left);
		if (root->data == 0)
			printTree(root, 0); //тут кароче должно быть копирование (в очередь например)
		print0Tree(root->right);
	}
}

int countOf0(TTree root) {
	if (root == nullptr)
		return 0;
	else
		if (root->data == 0)
			return 1 + countOf0(root->left) + countOf0(root->right);
		else 
			return 0 + countOf0(root->left) + countOf0(root->right);
}

void toStrictlyBinaryTree(TTree root) {
	if (root != nullptr) {
		toStrictlyBinaryTree(root->left);
		toStrictlyBinaryTree(root->right);
		bool emptyLeft = isEmpty(root->left), emptyRight = isEmpty(root->right);
		if (emptyLeft && !emptyRight)
			destroyTree(root->right);
		else if (!emptyLeft && emptyRight)
			destroyTree(root->left);
	}
}

int main() {
	setlocale(LC_ALL, "rus");
	TTree root = new Node;
	createTree(root);
	/*preorder(root, print);
	cout << endl;
	toStrictlyBinaryTree(root);
	preorder(root, print);*/
	printTree(root, 0);
	cout << endl << countOf0(root);
	return 0;
}