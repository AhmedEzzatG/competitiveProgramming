#include"BST.h"

struct AVLnode {
	int key, height;
	AVLnode* left, * right, * parent;
	static AVLnode* sentinel;
	AVLnode() {
		parent = left = right = sentinel;
		height = 0;
	}
	AVLnode(int key) : key(key) {
		parent = left = right = sentinel;
		height = 0;
	}
	void updateHeight() {
		height = 1 + max(left->height, right->height);
	}
	int balanceFactor() {
		return left->height - right->height;
	}
};

AVLnode* AVLnode::sentinel = new AVLnode();

class AVL : public BST {
	typedef AVLnode* nodeptr;
public:
	nodeptr root;
	AVL() : root(NULL) {}
	void insert(int key) { root = insert(root, key); }
private:
	nodeptr rightRotation(nodeptr Q) {
		nodeptr P = Q->left;
		Q->left = P->right;
		Q->left->parent = Q;
		P->right = Q;
		P->parent = Q->parent;
		Q->parent = P;
		Q->updateHeight();
		P->updateHeight();
		return P;
	}
	nodeptr leftRotation(nodeptr P) {
		nodeptr Q = P->right;
		P->right = Q->left;
		P->right->parent = P;
		Q->left = P;
		Q->parent = P->parent;
		P->parent = Q;
		Q->updateHeight();
		P->updateHeight();
		return Q;
	}
	nodeptr balance(nodeptr root) {
		if (root->balanceFactor() == 2) {
			if (root->left->balanceFactor() == -1)
				root->left = leftRotation(root->left);
			root = rightRotation(root);
		}
		else if (root->balanceFactor() == -2) {
			if (root->right->balanceFactor() == 1)
				root->right = rightRotation(root->right);
			root = leftRotation(root);
		}
		return root;
	}
	nodeptr insert(nodeptr root, int key) {
		if (root == AVLnode::sentinel)
			return root = new AVLnode(key);
		if (key < root->key) {
			root->left = insert(root->left, key);
			root->left->parent = root;
		}
		else if (key > root->key) {
			root->right = insert(root->right, key);
			root->right->parent = root;
		}
		root->updateHeight();
		root = balance(root);
		return root;
	}
};
