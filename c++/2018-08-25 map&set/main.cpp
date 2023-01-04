#include <string>
#include <iostream>

#if 0
#include <map>
using std::map;
using std::multimap;
using std::string;
using std::pair;
using std::cout;
using std::endl;
int main()
{
	map<int, string> map_test1;  //构造一个空的map
	map<int, string> map_test2(map_test1.begin(), map_test1.end());
	map<int, string> map_test3(map_test1);
	map<string, string> map_test4{ { "a", "aaa" }, { "b", "aaa" }, { "c", "ccc" } };
	map<int, string>map_test5{ pair<int, string>(1, "a"), pair<int, string>(2, "c") };
	map<int, string>map_test6{ std::make_pair(1, "a"), std::make_pair(2, "c") };
	//插入
	//1.用数组的方式插入数据
	map_test1[1] = "obj_0";
	map_test1[2] = "obj_2";
	map_test1[3] = "obj_3";
	map_test1[1] = "obj_1";
	for (map<int, string>::iterator iter = map_test1.begin(); iter != map_test1.end(); ++iter)
		cout << "key:" << iter->first << ",value:" << iter->second << endl;
	cout << "---------------------" << endl;
	//2 insert函数插入pair对象
	map_test1.insert(pair<int, string>(5, "obj_5"));
	map_test1.insert(pair<int, string>(4, "obj_4"));
	map_test1.insert(pair<int, string>(1, "obj_100"));
	for (map<int, string>::iterator iter = map_test1.begin(); iter != map_test1.end(); ++iter)
		cout << "key:" << iter->first << ",value:" << iter->second << endl;
	cout << "---------------------" << endl;
	//3 insert函数插入value_type数据
	map_test1.insert(map<int, string>::value_type(6, "obj_6"));
	map_test1.insert(map<int, string>::value_type(7, "obj_7"));
	map_test1.insert(map<int, string>::value_type(1, "obj_200"));
	for (map<int, string>::iterator iter = map_test1.begin(); iter != map_test1.end(); ++iter)
		cout << "key:" << iter->first << ",value:" << iter->second << endl;
	cout << "---------------------" << endl;
	//后面两种效果上完全一样的，用insert插入数据，重复关键字不能插入。数组方式可以覆盖以前的关键字对应的值
	//大小
	cout << map_test1.size() << endl;
	//map_test1.clear();

	//遍历
	//1.前向迭代器
	//2.反向迭代器
	map<int, string>::reverse_iterator iter;
	for (iter = map_test1.rbegin(); iter != map_test1.rend(); ++iter)
		cout << "key:" << iter->first << ",value:" << iter->second << endl;
	cout << "---------------------" << endl;
	//3.用[]的方式
	map_test4["abc"] = "xyz";
	cout << map_test4["abc"] << endl;
	cout << map_test4.at("abc") << endl;

	//查找并获取map中的元素
	//1. 用count函数判断关键字是够出现 出现是1  没有是0
	cout << map_test1.count(1) << endl;
	cout << map_test1.count(0) << endl;
	//2. 用find 返回迭代器 没找到返回end()
	map<int, string>::iterator it = map_test1.find(0);
	if (it != map_test1.end())
		cout << it->second << endl;
	else
		cout << "do not find" << endl;
	//3 
	it = map_test1.lower_bound(3);//>=
	cout << it->second << endl;

	it = map_test1.upper_bound(3);//>
	cout << it->second << endl;

	//删除
	//用迭代器删除
	map_test1.erase(map_test1.begin());
	//用关键字删除
	map_test1.erase(2);
	//范围删除
	//map_test1.erase(map_test1.begin(), map_test1.end());

	multimap<int, string> mu_test;
	mu_test.insert({ 1, "aaa" });
	mu_test.insert({ 1, "bbb" });
	return 0;
}

#endif //map 映射

#if 1
#include <set>
using namespace std;

int main()
{
	set<int> set_test;
	set_test.insert(5);
	set_test.insert(1);
	set_test.insert(3);
	set_test.insert(2);
	set_test.insert(5);//键值重复 不会插入
	int a[] = { 7, 8, 9 };
	set_test.insert(a, a + 3);
	set<int>::iterator it;
	for (it = set_test.begin(); it != set_test.end(); ++it)
		cout << *it << " ";
	cout << endl;
	cout << "----------" << endl;
	set<int>::reverse_iterator rit;
	for (rit = set_test.rbegin(); rit != set_test.rend(); ++rit)
		cout << *rit << " ";
	cout << endl;
	
	set_test.erase(set_test.find(1));
	set_test.erase(2);
	return 0;
}
#endif //set 集合