#include <iostream>
using namespace std;
struct Node
{
	struct Node *left;
	int info;
	struct Node *right;
}; typedef struct Node Node;

Node *newNode(int data)
{
	Node *temp; 
	temp = (Node * )malloc(sizeof(Node));
	temp->info = data;
	temp->left = temp->right = NULL;
	return temp;

}
Node *insert(Node *root, int data)
{
	if (root == NULL)
	{
		root = newNode(data);
		
	}
	else if (data <= root->info)
	{
		root->left = insert(root->left, data);
	}
	else
	{
		root->right = insert(root->right, data);
	}
	return root;
}

bool search(Node *root, int data)
{
	if (root == NULL)
		return false;
	else
	{
		if (root->info == data)
			return true;
		else if (data <= root->info)
			return search(root->left, data);
		else
			return search(root->right, data);
	}
}
Node *findMax(Node *root)
{
	while (root->right != NULL)
		root = root->right;
	return root;
}
Node *deleteNode(Node *root, int data)
{
	if (root == NULL)
		return root;
	else if (data < root->info)
		root->left = deleteNode(root->left, data);
	else if (data > root->info)
		root->right = deleteNode(root->right, data);
	else
	{
		if (root->left == NULL && root->right == NULL) // leaf
		{
			free(root);
			root = NULL;
		}
		
		else if (root->left == NULL && root->right != NULL) // only right child 
		{
			Node *temp = root;
			// root->right = NULL;
			root = temp->right;
			free(temp);
		}
		else if (root->left != NULL && root->right == NULL) // only left child
		{
			Node *temp = root;
			// root->left = NULL;
			root = temp->left;
			free(temp);
		}
		else // 2 children
		{
			Node *temp;
			temp = findMax(root->left);
			root->info = temp->info;
			root->left = deleteNode(root->left, root->info);
		}
	}
	return root;
}
int numberOfLeaves(Node *root) 
{
	if(root==NULL) 
	{
    	return 0;
    }
    else if(root->left==NULL && root->right==NULL) 
    {
    	return 1;
    }
    else if(root->left==NULL && root->right!=NULL) 
    {
    	return numberOfLeaves(root->right);
    }
    else if(root->right==NULL && root->left!=NULL)
    {
    	return numberOfLeaves(root->left);
    }
    else 
    {
        return (numberOfLeaves(root->left)+numberOfLeaves(root->right));
    }
    
}
void Inorder(Node *root)
{

	if (root == NULL)
		return;
	else
	{
		Inorder(root->left);
		cout<<(root->info)<<'\t';
		Inorder(root->right);
	}
}
void Preorder(Node *root)
{
	if (root == NULL)
		return;
	else
	{

		cout<<(root->info)<<'\t';
		Preorder(root->left);
		Preorder(root->right);
	}
}
void Postorder(Node *root)
{
	if (root == NULL)
		return;
	else
	{
		Postorder(root->left);
		Postorder(root->right);
		cout<<(root->info)<<'\t';
	}
}
void deleteTree(Node *root)
{
	if (root->left == NULL && root->right == NULL)
		free(root);
	else if (root->right == NULL)
		deleteTree(root->left);
	else if (root->left == NULL)
		deleteTree(root->right);
	else
	{
		deleteTree(root->left);
		deleteTree(root->right);
	}
	free(root);
}

void InorderWithMsg(Node *root)
{
	cout<<"Inorder: \n";
	Inorder(root);
	cout<<endl;
}
void PreorderWithMsg(Node *root)
{
	cout<<"Preorder: \n";
	Preorder(root);
	cout<<endl;
}
void deleteNodeWithMsg(Node *root, int data)
{
	cout<<"Deleting node with value: " << data<<endl;
	deleteNode(root, data);
	PreorderWithMsg(root);

}


int main()
{
	Node *root;
	root = NULL;
	//cout<< search(root, 5)<<endl;
	root = insert(root, 15);
	root = insert(root, 10);
	root = insert(root, 20);
	root = insert(root, 40);
	root = insert(root, 30);
	root = insert(root, 5);
	root = insert(root, 25);
	root = insert(root, 12);
	root = insert(root, 14);
	root = insert(root, 35);
	
	// cout<< search(root, 5)<<endl;
	// cout<< search(root, 60)<<endl;
	cout<<"Number Of Leaf Nodes = "<<numberOfLeaves<<endl;
	InorderWithMsg(root);

	deleteNodeWithMsg(root, 15);

	deleteNodeWithMsg(root, 10);

	deleteTree(root);
	InorderWithMsg(root);


}