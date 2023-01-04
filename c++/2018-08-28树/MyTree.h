#pragma once

//作业   1.验证代码   2 void clear(TreeNode<T>* root) 有没有问题

//通过孩子兄弟实现
//树节点
template<typename T>
struct TreeNode
{
	T data;//数据域
	//指针域
	TreeNode* parent;//指向双亲结点的指针
	TreeNode* brother;//指向兄弟结点的指针
	TreeNode* child;//指向孩子结点的指针
	TreeNode(T d)
	{
		data = d;
		parent = nullptr;
		brother = nullptr;
		child = nullptr;
	}
};

//树
template <typename T>
class CMyTree
{
	TreeNode<T> *pRoot;//根节点
public:
	CMyTree();
	~CMyTree();
	void clear();
	bool isFind(T const& value);
	void insert(T const& findValue, T const& insertValue, bool isChild);
private:
	void clear(TreeNode<T>* root);//借助递归删除所有子树
	TreeNode<T>* find(TreeNode<T>*root, T const& value);
};

template <typename T>
CMyTree<T>::~CMyTree()
{
	clear();
}

template <typename T>
void CMyTree<T>::clear()
{
	if (pRoot)
		_clear(pRoot);
}

template <typename T>
bool CMyTree<T>::isFind(T const& value)
{
	return find(pRoot, value) != nullptr;
}

template <typename T>
void CMyTree<T>::insert(T const& findValue, T const& insertValue, bool isChild)
{
	//准备一个结点
	TreeNode<T>* insertNode = new TreeNode<T>;
	insertNode->data = insertValue;
	insertNode->parent = nullptr;
	insertNode->brother = nullptr;
	insertNode->child = nullptr;

	if (pRoot)
	{
		//在非空树中找到findValue所在的结点
		TreeNode<T>* findNode = find(pRoot, findValue);
		if (findNode)
		{
			//找到插入位置
			if (isChild)
			{
				if (findNode->child) //有孩子结点，通过兄弟结点插入
				{
					TreeNode<T>* tempNode = findNode->child;
					while (tempNode->brother)
						tempNode = tempNode->brother;
					tempNode->brother = insertNode;
					insertNode->parent = tempNode->parent;
				}
				else  //按孩子结点插入
				{
					findNode->child = insertNode;
					insertNode->parent = findNode;
				}
			}
			else //兄弟结点插入
			{
				if (findNode->brother)
				{
					TreeNode<T>* tempNode = findNode->brother;
					while (tempNode->brother)
						tempNode = tempNode->brother;
					tempNode->brother = insertNode;
					insertNode->parent = tempNode->parent;
				}
				else
				{
					findNode->brother = insertNode;
					insertNode->parent = findNode->parent;
				}
			}
		}
		else
		{
			//代表非空树种没有findValue结点。
			//插入规则随你定
		}
	}
	else
		pRoot = insertNode;
}

template <typename T>
void CMyTree<T>::clear(TreeNode<T>* root)
{
	if (root)
	{
		clear(root->brother);
		clear(root->child);
		delete root;
		root = nullptr;
	}
}

template <typename T>
TreeNode<T>* CMyTree<T>::find(TreeNode<T>* root, T const& value)
{
	if (root)
	{
		if (root->data == value)
			return root;
		TreeNode<T>* tempNode = find(root->brother, value);
		if (tempNode)
			return tempNode;
		return find(root->child, value);
	}
	return nullptr;
}

template <typename T>
CMyTree<T>::CMyTree()
{
	pRoot = nullptr;
}
