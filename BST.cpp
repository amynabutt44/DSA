#include <iostream>
#include<queue>
using namespace std;
struct Node
{
	int data;
	Node* right;
	Node* left;
	Node( int val)
	{
		data = val;
		right = nullptr;
		left = nullptr;
	}
};
Node* insertIntoBst(Node* root, int val)
{
	if (root == nullptr)
	{
		root = new Node(val);
		return root;
	}
	if (val > root->data)
	{
		root->right = insertIntoBst(root->right, val);
	}
	else
	{
		root->left= insertIntoBst(root->left, val);
	}
	return root;
}

void takeinput(Node*& root)
{
	int data;
	cout << " enter data " << endl;
	cin >> data;
	while (data != -1)
	{
		root = insertIntoBst(root, data);
		cin >> data;
	}
 }
void levelOrderTraversal(Node* root)
{
	queue<Node* > q;

	q.push(root);
	q.push(nullptr);
	while (!q.empty())
	{
		Node* temp = q.front();
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
int main()
{

	Node* root = nullptr;
	cout << "enter data to create output" << endl;
		takeinput(root);
		levelOrderTraversal(root);


 }