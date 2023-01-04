// 05binarytree.cpp : �������̨Ӧ�ó������ڵ㡣
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

// 1 ��CMyTree_Node�д����������ĳ�����ͺ���
// 2 ��1�������õݹ�ķ�ʽ������������������ (2)�ж�һ�����Ƿ�����ȫ������
//��1���ͣ�2����ѡһ
//˼·1 ����������������ҵ���һ��������� ���֮��Ľ�㻹�з�����㣬����
//˼·2 �����н��ȫ��ѹ����У�ÿ���ж϶���ͷΪ��������ѭ�� ������к��滹��Ԫ�ؾͲ�����ȫ������