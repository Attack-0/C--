// 05binarytree.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "MyTree.h"

int _tmain(int argc, _TCHAR* argv[])
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	CMyTree_Arr<int>* mta = new CMyTree_Arr<int>;
	mta->initTree(arr, 10);
	bool b = mta->find(6);
	b = mta->find(11);
	mta->prePrint();
	cout << endl;
	mta->inPrint();
	cout << endl;
	mta->posPrint();
	mta->clera();
	delete mta;
	cout << endl;
	cout << "--------------------------" << endl;
	CMyTree_Node<int>* mtn = new CMyTree_Node<int>;
	mtn->initTree(arr, 10);
	mtn->prePrint();
	cout << endl;
	mtn->inPrint();
	cout << endl;
	mtn->posPrint();
	cout << endl;
	mtn->levelPrint();
	mtn->clear();
	delete mtn;
	return 0;
}

// 1 将CMyTree_Node中创建二叉树改成中序和后序
// 2 （1）不采用递归的方式来先序遍历，中序遍历 (2)判断一颗数是否是完全二叉树
//（1）和（2）二选一
//思路1 层序遍历二叉树，找到第一个非满结点 如何之后的结点还有非满结点，则不是
//思路2 讲所有结点全部压入队列，每次判断队列头为空则跳出循环 如果队列后面还有元素就不是完全二叉树