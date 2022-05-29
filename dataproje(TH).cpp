
#include<iostream>
using namespace std;
struct BstNode {
	int data; 
	BstNode* left;
	BstNode* right;
};

BstNode* GetNewNode(int data) {
	BstNode* newNode = new BstNode();
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

BstNode* Insert(BstNode* root,int data) {
	if(root == NULL) { // empty tree,we can create new node
		root = GetNewNode(data);
	}
	// if data to be added is lesser, insert in left subtree. 
	else if(data <= root->data) {
		root->left = Insert(root->left,data);
	}
	// else, add it right subtree. 
	else {
		root->right = Insert(root->right,data);
	}
	return root;
}
//To search an element in BST, returns true if element is found
bool Search(BstNode* root,int data) {
	if(root == NULL) {
		return false;
	}
	else if(root->data == data) {
		return true;
	}
	else if(data <= root->data) {
		return Search(root->left,data);
	}
	else {
		return Search(root->right,data);
	}
}
int main() {
	BstNode* root = NULL; 
	/*Code to test the logic*/
	root = Insert(root,10);	
	root = Insert(root,20);	
	root = Insert(root,30);
	root = Insert(root,5);
	root = Insert(root,8);
	root = Insert(root,2);
	int number;
	cout<<"Enter a number";
	cin>>number;
	//If number is found, print "FOUND"
	if(Search(root,number) == true) cout<<"Found";
	else cout<<"Not Found";
}