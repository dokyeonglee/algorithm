#include <iostream>
using namespace std;

struct Node{
	int data;
	Node* left;
	Node* right;
};

Node* insert(Node* root, int data){
	if(root == NULL){
		root = new Node();
		root->data = data;
		root->left = root->right = NULL;
	}else if(root->data > data){
		root->left = insert(root->left, data);
	}else{
		root->right = insert(root->right, data);
	}
	return root;
}

void postorder(Node* root){
	if(root == NULL){
		return;
	}
	postorder(root->left);
	postorder(root->right);
	cout << root->data << "\n";
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	Node* root = NULL;
	
	int x;
	while(cin >> x){
		root = insert(root, x);
	}
	
	postorder(root);
	
	return 0;
}