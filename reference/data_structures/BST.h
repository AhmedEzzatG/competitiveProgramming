#include<bits/stdc++.h>
using namespace std;

class node {
public:
	int key;
	node* left, * right, * parent;
	node() { key = 0; left = right = parent = NULL; }
	node(int key, node* left = NULL, node* right = NULL, node* parent = NULL) :
		key(key), left(left), right(right), parent(parent) {}
};

typedef node* nodeptr;

class BST {
private:
	nodeptr minimum(nodeptr root) {
		if (root->left == NULL)return root;
		return minimum(root->left);
	}
	nodeptr maximum(nodeptr root) {
		if (root->right == NULL)return root;
		return maximum(root->right);
	}
	nodeptr successor(nodeptr cur) {//smallest key larger than cur
		if (cur->right != NULL)return minimum(cur->right);
		nodeptr tmp = cur->parent;
		while (tmp != NULL && tmp->right == cur)
			cur = tmp, tmp = tmp->parent;
		return tmp;
	}
	nodeptr bredecessor(nodeptr cur) {//biggest key less than cur
		if (cur->left != NULL)return maximum(cur->left);
		nodeptr tmp = cur->parent;
		while (tmp != NULL && tmp->left == cur)
			cur = tmp, tmp = tmp->parent;
		return tmp;
	}
	nodeptr find(nodeptr root, int key) {
		if (root == NULL)return NULL;
		if (key == root->key)return root;
		if (key < root->key)return find(root->left, key);
		return find(root->right, key);
	}
	nodeptr insert(nodeptr root, int key) {
		if (root == NULL)root = new node(key);
		else if (key < root->key) {
			root->left = insert(root->left, key);
			root->left->parent = root;
		}
		else if (key > root->key) {
			root->right = insert(root->right, key);
			root->right->parent = root;
		}
		return root;
	}
	nodeptr erase(nodeptr root,int key) {
		if (root == NULL)return root;
		if (key < root->key) {
			root->left = erase(root->left, key);
			root->left->parent = root;
		}
		else if (key > root->key) {
			root->right = erase(root->right, key);
			root->right->parent = root;
		}
		else {
			nodeptr tmp;
			if (root->left == NULL || root->right == NULL) {
				if (root->left == NULL)tmp = root->right;
				else tmp = root->left;
				free(root);
				return tmp;
			}
			else {
				tmp = successor(root);
				root->key = tmp->key;
				root->right = erase(root->right, tmp->key);
				root->right->parent = root;
			}
		}
		return root;
	}
public:
	nodeptr root;
	BST() : root(NULL) {}
	nodeptr find(int key) { return find(root, key); }
	void insert(int key) { root = insert(root, key); }
	void erase(int key) { root = erase(root, key); }
};

void inorder(nodeptr root) {
	if (root == NULL)return;
	inorder(root->left);
	cout << root->key;
	if (root->parent != NULL) cout << ' ' << root->parent->key;
	cout << endl;
	inorder(root->right);
}

void preorder(nodeptr root) {
	if (root == NULL)return;
	cout << root->key << ' ';
	preorder(root->left);
	preorder(root->right);
}

void postorder(nodeptr root) {
	if (root == NULL)return;
	postorder(root->left);
	postorder(root->right);
	cout << root->key << ' ';
}