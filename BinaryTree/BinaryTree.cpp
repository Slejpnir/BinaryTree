// BinaryTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;
struct TNode
{
	int data;
	TNode* left;
	TNode* right;
};

struct TNodeWordCount
{
	int count;
	std::string word;
	TNodeWordCount* left;
	TNodeWordCount* right;
};



void treePrintPrefix(TNode* root)
{
	if (root == nullptr)
		return;
	std::cout << root->data << std::endl;
	treePrintPrefix(root->left);
	treePrintPrefix(root->right);
}

void treePrintInfix(TNode* root)
{
	if (root == nullptr)
		return;
	treePrintInfix(root->left);
	std::cout << root->data << std::endl;
	treePrintInfix(root->right);
}

void treePrintInfix(TNodeWordCount* root)
{
	if (root == nullptr)
		return;
	treePrintInfix(root->left);
	std::cout << root->word<<" "<<root->count << std::endl;
	treePrintInfix(root->right);
}

void treePrintPostfix(TNode* root)
{
	if (root == nullptr)
		return;
	treePrintPostfix(root->left);
	treePrintPostfix(root->right);
	std::cout << root->data << std::endl;
}

TNode* treeInsert(TNode* root, int data)
{
	if (root == nullptr)
	{
		root = new TNode;
		root->data = data;
		root->left = nullptr;
		root->right = nullptr;
		return root;
	}
	else {
		if (data < root->data)
			root->left = treeInsert(root->left, data);
		else
			root->right = treeInsert(root->right, data);
		return root;
	}
}

TNodeWordCount* treeInsert(TNodeWordCount* root, string word)
{
	if (root == nullptr)
	{
		root = new TNodeWordCount;
		root->word = word;
		root->count = 1;
		root->left = nullptr;
		root->right = nullptr;
		return root;
	}
	else {
		if (word == root->word)
		{
			root->count++;
			return root;
		}
		else {
			if (word < root->word)
				root->left = treeInsert(root->left, word);
			else
				root->right = treeInsert(root->right, word);
			return root;
		}
	}
}

void treeDelete(TNode* root)
{
	if (root == nullptr)
		return;
	treeDelete(root->left);
	treeDelete(root->right);
	delete root;
}

void treeDelete(TNodeWordCount* root)
{
	if (root == nullptr)
		return;
	treeDelete(root->left);
	treeDelete(root->right);
	delete root;
}

void split_str(string const& str, const char delim, vector<string>& out) {
	stringstream s(str);
	string s2;
	while (getline(s, s2, delim))
	{
		out.push_back(s2);
	}
}

int main()
{
	/*int a;
	TNode* root = nullptr;
	for (int i = 0; i < 8; i++)
	{
		std::cin >> a;
		root = treeInsert(root, a);
	}
	treePrintInfix(root);
	treeDelete(root);
	cout << endl<<endl;*/
	
	TNodeWordCount* root2 = nullptr;
	string str = "I am it cat am I he am he dog ";
	char delim = ' ';
	vector<string> out;
	split_str(str, delim, out);
	for (const auto& s2 : out)
	{
		//cout << s2 << endl;
		root2 = treeInsert(root2, s2);
	}
	treePrintInfix(root2);
	treeDelete(root2);
	
	vector<int> A { 1,2,3,4,5,6,7,8,9,10 };
	cout << A[1]<<" "<<A.at(3);
	cout << A.size();
	A.resize(15);
	
	vector<int> B;
	for (int i = 0; i < 5; ++i)
	{
		B.push_back(i);
	}
	B.pop_back();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
