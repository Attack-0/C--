#pragma once
#include <iterator>
///////////////////////////////////////////////////////////////////////
// list结点, 提供双向访问能力
///////////////////////////////////////////////////////////////////////
/*
*  | next |------>| next |------>| next |------>| next |
*  | prev |<------| prev |<------| prev |<------| prev |
*  | data |       | data |       | data |       | data |
*/
///////////////////////////////////////////////////////////////////////
template <typename _Tnode>
struct __list_node //list结点的结构
{
	typedef void* void_pointer;
	void_pointer next;
	void_pointer prev;
	_Tnode       data;
};
///////////////////////////////////////////////////////////////////////
//list迭代器
///////////////////////////////////////////////////////////////////////
template<class T, class Ref, class Ptr>
struct __list_iterator
{
	typedef __list_iterator<T, T&, T*>   iterator;//STL强制要求
	typedef __list_iterator<T, const T&, const T*> const_iterator;
	typedef __list_iterator<T, Ref, Ptr>  self;
	typedef std::bidirectional_iterator_tag  iterator_category;
	typedef T            value_type;
	typedef Ref          reference;
	typedef Ptr          pointer;
	typedef __list_node<T>*  link_type;
	typedef size_t      size_type;
	typedef ptrdiff_t   differebce_type;

	//指向list结点
	link_type node;

	__list_iterator() :node(){}
	__list_iterator(link_type x) :node(x){}
	__list_iterator(const iterator&x) :node(x.node){}

	bool operator==(const self& x)const{ return node == x.node; }
	bool operator!=(const self& x)const{ return node != x.node; }

	reference operator*()const { return (*node).data; }
	pointer operator->()const{ return  &operator*(); }

	self& operator++()
	{
		node = (link_type)((*node).next);
		return *this;
	}

	self operator++(int)
	{
		self tmp = *this;
		++*this;
		return tmp;
	}
	self& operator--()
	{
		node = (link_type)((*node).prev);
		return *this;
	}

	self operator--(int)
	{
		self tmp = *this;
		--*this;
		return tmp;
	}
};
///////////////////////////////////////////////////////////////////////
// list 环状双向链表
///////////////////////////////////////////////////////////////////////
/*			            end()         begin()
*			             ↓               ↓
* ---->| next |------>| next |------>| next |------>| next |------
* |  --| prev |<------| prev |<------| prev |<------| prev |<--| |
* |  | | data |       | data |       | data |       | data |   | |
* |	 | 														   | |
* ---|-| next |<------| next |<------| next |<------| next |<--|--
*    ->| prev |------>| prev |------>| prev |------>| prev |----
*      | data |       | data |       | data |       | data |
*/
///////////////////////////////////////////////////////////////////////

//allocator
//空间适配器 内存池实现小块内存分配
//解决内存碎片问题
//大概实现   一级空间适配器  直接封装malloc free
//			二级空间适配器  内存池 自由链表
//实现原理   用户申请内存 > 128 ? 一级 ： 二级
//

template <typename _Ty, class _Alloc = std::allocator<_Ty>>
class Mylist
{
protected:
	typedef __list_node<_Ty> list_node;
public:
	typedef list_node* link_type;

protected:
	link_type node;//只要一个指针，可以表示整个环状链表，头指针
	//...
};