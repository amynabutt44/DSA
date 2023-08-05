#include<iostream>
#include <queue>
using namespace std;
struct node {
	int  data;
	node* right;
	node * left;
	
	node( int  val)
	{
		data = val;
		right = nullptr;
		left = nullptr;
	 }
};

node * buildtree(node *  & root)
{
	int  temp;
	cout << " enter the root data " << endl;
	cin >> temp;
	root = new node (temp);
	if (temp == -1)
	{
		return nullptr;
	}
	cout << " enter data for the left of " << temp << endl;
	root->left = buildtree(root->left);
	cout << " enter data for the  right of " << temp << endl;
	root->right = buildtree(root->right);
	return root;
}

void levelOrderTraversal(node * root)
{
	queue<node* > q;

	q.push(root);
	q.push(nullptr);
	while (!q.empty())
	{
		node* temp = q.front();
		q.pop();
		if (temp == nullptr)
		{
			cout << endl;
			if (!q.empty())
			{
				q.push(nullptr);
			}
		}
		else
		{
			cout << temp->data << " ";
			if (temp->left)
				q.push(temp->left);
			if (temp->right)
				q.push(temp->right);
		}
		
	}

}
void inorder(node* root)
{
	if (root == nullptr)
	{
		return;
	}
	inorder(root->left);
	cout << root->data;
	inorder(root->right);
}
void preorder(node* root)
{
	if (root == nullptr)
	{
		return;
	}
	cout << root->data;
	preorder(root->left);
	
	preorder(root->right);
}
void postorder(node* root)
{
	if (root == nullptr)
	{
		return;
	}
	postorder(root->left);
	
	postorder(root->right);
	cout << root->data;
}
node* buildfromleveloredertraversal(node*& root)
{
	queue<node*> q;
	int val;
	cout << " enter data "<<endl;
	cin >> val;
	root = new node(val);
	q.push(root);

	while (!q.empty())
	{
		node* temp = q.front();
		q.pop();
		int leftdata;
		cout << " enter left data of " << temp->data << endl;
		cin >> leftdata;
		if ( leftdata!= -1)
		{
			temp->left = new node(leftdata);
			q.push(temp->left);
		}
		int rightdata;
		cout << " enter right data of " << temp->data << endl;
		cin >> rightdata;
		if (leftdata != -1)
		{
			temp->right = new node(rightdata);
			q.push(temp->right);
		}
	}
	return root;

}
int main()
{
	node* root = nullptr;
	buildfromleveloredertraversal(root);
	                       
	/*root = buildtree(root);*/
	levelOrderTraversal(root);
}