#if 0

/* list ˫��ѭ���б� 
   ����Ԫ��ͨ������ָ�봮�����߼��ϵ����Ա�
   ÿһ����㶼������Ϣ�飬һ��ǰ��ָ�룬һ������ָ��

   ��������ɾ������ O(1)  �������Ч�ʵ� O(n)
*/
#include <list>
using namespace std;

bool foo(int x)
{
	//return x % 2 == 0;
	return x > 3;
}

int main()
{
	//���ֺ�vector�÷�
	list<int>  list_test1;   //������
	list<int>  list_test2(5);//��5��Ԫ��Ĭ��ֵ��0������
	list<int>  list_test3(5,2);//��5��Ԫ��Ĭ��ֵ��2������
	list<int>  list_test4(list_test1);
	//list_test1[begin(), end()];
	list<int>  list_test5(list_test1.begin(), list_test1.end());
	list_test1.push_back(10);
	list_test1.push_back(20);
	list_test1.push_back(30);
	list_test1.push_back(40);
	list_test1.pop_back();
	//û��capacity()  reserve()
	//û��[]  at
	
	//reverse()��ת
	list_test1.reverse();//vectorû�д˳�Ա����
	//sort();
	list_test1.sort();//vectorû�д˳�Ա����

	//ͷ������ ɾ��
	list_test1.push_front(80);
	list_test1.push_front(90);
	list_test1.pop_front();
	//merge  �ϲ�����������������
	list_test1.clear();
	list_test2.clear();
	list_test1.push_back(3);
	list_test1.push_back(6);

	list_test2.push_back(2);
	list_test2.push_back(4);
	list_test1.merge(list_test2);

	//remove()  ���ƥ������Ԫ��
	list_test1.push_back(4);
	list_test1.push_back(4);
	list_test1.push_back(4);
	list_test1.remove(9);
	//remove_if()  �������������Ԫ��
	list_test1.remove_if([](int x){return x > 3; });
	//splice()
	//unique()   ɾ���ظ�ֵ
	list_test1.clear();
	list_test1.push_back(4);
	list_test1.push_back(4);
	list_test1.push_back(3);
	list_test1.push_back(3);
	list_test1.push_back(2);
	list_test1.push_back(2);
	list_test1.unique();
	return 0;
}

#endif //list
#include <iostream>

#if 1
#include <deque>
#include <vector>
using std::deque;
using std::vector;
/*deque ˫�˶��� double ended queue
	��һ��˫�򿪿ڵ��������Կռ� ����ͷβ���˲���

	�ŵ� ������ʷ���  ֧��[] ��at()
	     �������ɾ������  ���˶�����push  pop
	ȱ�� ռ���ڴ��

	//�� ɾ ��     ��
	vector VS list  VS deque
	1.��Ҫ��Ч�������ȡ�����ں������ɾ��Ч��  vector
	2.��Ҫ�����Ĳ����ɾ��������ϵ�����ȡ  list
	3.��Ҫ�����ȡ�����ҹ����������ݵĲ����ɾ��  deque

	���Ե������Ƚ�
	vector��deque������֧����������  list�ĵ�����ֻ�ܽ���++/--��������֧����ͨ����������
	������iteratorʹ��֮����ͷ� ��������list��ͬ��������ʹ��֮�󻹿��Լ�����
*/

int main()
{
	deque<double> deq_test1;
	deque<double>::iterator it;
	deque<double>::iterator it1;
	vector<vector<int>> vec_2d;
	vector<vector<vector<int>>> vec_3d;

	return 0;
}

#endif //deque