#if 0

/* list 双向循环列表 
   数据元素通过链表指针串联成逻辑上的线性表
   每一个结点都包括信息块，一个前驱指针，一个后驱指针

   随机插入和删除方便 O(1)  随机访问效率低 O(n)
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
	//区分和vector用法
	list<int>  list_test1;   //空链表
	list<int>  list_test2(5);//含5个元素默认值是0的链表
	list<int>  list_test3(5,2);//含5个元素默认值是2的链表
	list<int>  list_test4(list_test1);
	//list_test1[begin(), end()];
	list<int>  list_test5(list_test1.begin(), list_test1.end());
	list_test1.push_back(10);
	list_test1.push_back(20);
	list_test1.push_back(30);
	list_test1.push_back(40);
	list_test1.pop_back();
	//没有capacity()  reserve()
	//没有[]  at
	
	//reverse()翻转
	list_test1.reverse();//vector没有此成员函数
	//sort();
	list_test1.sort();//vector没有此成员函数

	//头部插入 删除
	list_test1.push_front(80);
	list_test1.push_front(90);
	list_test1.pop_front();
	//merge  合并两个有序链表并排序
	list_test1.clear();
	list_test2.clear();
	list_test1.push_back(3);
	list_test1.push_back(6);

	list_test2.push_back(2);
	list_test2.push_back(4);
	list_test1.merge(list_test2);

	//remove()  清除匹配所有元素
	list_test1.push_back(4);
	list_test1.push_back(4);
	list_test1.push_back(4);
	list_test1.remove(9);
	//remove_if()  清除满足条件的元素
	list_test1.remove_if([](int x){return x > 3; });
	//splice()
	//unique()   删除重复值
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
/*deque 双端队列 double ended queue
	是一种双向开口的连续线性空间 允许头尾两端操作

	优点 随机访问方便  支持[] 和at()
	     随机插入删除方便  两端都可以push  pop
	缺点 占用内存多

	//增 删 改     查
	vector VS list  VS deque
	1.需要高效的随机存取，不在乎插入和删除效率  vector
	2.需要大量的插入和删除，不关系随机存取  list
	3.需要随机存取，而且关心两端数据的插入和删除  deque

	各自迭代器比较
	vector和deque迭代器支持算术运算  list的迭代器只能进行++/--操作，不支持普通的算术运算
	向量的iterator使用之后就释放 但是链表list不同，迭代器使用之后还可以继续用
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