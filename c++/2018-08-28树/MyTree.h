#pragma once

//��ҵ   1.��֤����   2 void clear(TreeNode<T>* root) ��û������

//ͨ�������ֵ�ʵ��
//���ڵ�
template<typename T>
struct TreeNode
{
	T data;//������
	//ָ����
	TreeNode* parent;//ָ��˫�׽���ָ��
	TreeNode* brother;//ָ���ֵܽ���ָ��
	TreeNode* child;//ָ���ӽ���ָ��
	TreeNode(T d)
	{
		data = d;
		parent = nullptr;
		brother = nullptr;
		child = nullptr;
	}
};

//��
template <typename T>
class CMyTree
{
	TreeNode<T> *pRoot;//���ڵ�
public:
	CMyTree();
	~CMyTree();
	void clear();
	bool isFind(T const& value);
	void insert(T const& findValue, T const& insertValue, bool isChild);
private:
	void clear(TreeNode<T>* root);//�����ݹ�ɾ����������
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
	//׼��һ�����
	TreeNode<T>* insertNode = new TreeNode<T>;
	insertNode->data = insertValue;
	insertNode->parent = nullptr;
	insertNode->brother = nullptr;
	insertNode->child = nullptr;

	if (pRoot)
	{
		//�ڷǿ������ҵ�findValue���ڵĽ��
		TreeNode<T>* findNode = find(pRoot, findValue);
		if (findNode)
		{
			//�ҵ�����λ��
			if (isChild)
			{
				if (findNode->child) //�к��ӽ�㣬ͨ���ֵܽ�����
				{
					TreeNode<T>* tempNode = findNode->child;
					while (tempNode->brother)
						tempNode = tempNode->brother;
					tempNode->brother = insertNode;
					insertNode->parent = tempNode->parent;
				}
				else  //�����ӽ�����
				{
					findNode->child = insertNode;
					insertNode->parent = findNode;
				}
			}
			else //�ֵܽ�����
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
			//����ǿ�����û��findValue��㡣
			//����������㶨
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
