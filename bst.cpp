// Binary Search Tree - Implemenation in C++
// Simple program to create a BST of integers and search an element in it 
#include<iostream>
#include<queue>

using namespace std;
//Definition of Node for Binary search tree
struct BstNode {
	int data; 
	BstNode* left;
	BstNode* right;
};

// Function to create a new Node in heap
BstNode* GetNewNode(int data) {
	BstNode* newNode = new BstNode();
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

// To insert data in BST, returns address of root node 
BstNode* Insert(BstNode* root,int data) {
	if(root == NULL) { // empty tree
		root = GetNewNode(data);
	}
	// if data to be inserted is lesser, insert in left subtree. 
	else if(data <= root->data) {
		root->left = Insert(root->left,data);
	}
	// else, insert in right subtree. 
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

void levelorder(BstNode *root) {
	if(root == NULL) return;
	queue<BstNode*> Q;
	Q.push(root);  
	//while there is at least one discovered node
	while(!Q.empty()) {
		BstNode* current = Q.front();
		Q.pop(); // removing the element at front
		cout<<current->data<<" ";
		if(current->left != NULL) Q.push(current->left);
		if(current->right != NULL) Q.push(current->right);
	}
}

bool isSubTreeGreater(BstNode* root, int val)
{
	return (root == null) return true;

	if(root->data>val &&
		isSubTreeGreater(root->left,val) &&
	    isSubTreeGreater(root->right,val))

	    return true;
	else 
		return false;

}

bool isSubTreelesser(BstNode* root, int val)
{
	return (root == null) return true;

	if(root->data<val &&
		isSubTreeGreater(root->left,val) &&
	    isSubTreeGreater(root->right,val))

	    return true;
	else 
		return false;

}

bool checkBST(node* root)
{
	if(root==null) return true;
	return (isSubTreelesser(root->left,root->data) && isSubTreeGreater(root->right,root->data)
				 && checkBST(root->left) && checkBST(root->right) );
}



int main() {
	BstNode* root = NULL;  // Creating an empty tree
	/*Code to test the logic*/
	root = Insert(root,15);	
	root = Insert(root,10);	
	root = Insert(root,20);
	root = Insert(root,25);
	root = Insert(root,8);
	root = Insert(root,12);
	// Ask user to enter a number.  
	int number;
	//cout<<"Enter number be searched\n";
	//cin>>number;
	//If number is found, print "FOUND"
	//if(Search(root,number) == true) cout<<"Found\n";
	//else cout<<"Not Found\n";
	levelorder(root);
	bool check = checkBST(root);
	cout<<check;

}