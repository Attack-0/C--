#pragma once
#include <iterator>
///////////////////////////////////////////////////////////////////////
// list���, �ṩ˫���������
///////////////////////////////////////////////////////////////////////
/*
*  | next |------>| next |------>| next |------>| next |
*  | prev |<------| prev |<------| prev |<------| prev |
*  | data |       | data |       | data |       | data |
*/
///////////////////////////////////////////////////////////////////////
template <typename _Tnode>
struct __list_node //list���Ľṹ
{
	typedef void* void_pointer;
	void_pointer next;
	void_pointer prev;
	_Tnode       data;
};
///////////////////////////////////////////////////////////////////////
//list������
///////////////////////////////////////////////////////////////////////
template<class T, class Ref, class Ptr>
struct __list_iterator
{
	typedef __list_iterator<T, T&, T*>   iterator;//STLǿ��Ҫ��
	typedef __list_iterator<T, const T&, const T*> const_iterator;
	typedef __list_iterator<T, Ref, Ptr>  self;
	typedef std::bidirectional_iterator_tag  iterator_category;
	typedef T            value_type;
	typedef Ref          reference;
	typedef Ptr          pointer;
	typedef __list_node<T>*  link_type;
	typedef size_t      size_type;
	typedef ptrdiff_t   differebce_type;

	//ָ��list���
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
// list ��״˫������
///////////////////////////////////////////////////////////////////////
/*			            end()         begin()
*			             ��               ��
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
//�ռ������� �ڴ��ʵ��С���ڴ����
//����ڴ���Ƭ����
//���ʵ��   һ���ռ�������  ֱ�ӷ�װmalloc free
//			�����ռ�������  �ڴ�� ��������
//ʵ��ԭ��   �û������ڴ� > 128 ? һ�� �� ����
//

template <typename _Ty, class _Alloc = std::allocator<_Ty>>
class Mylist
{
protected:
	typedef __list_node<_Ty> list_node;
public:
	typedef list_node* link_type;

protected:
	link_type node;//ֻҪһ��ָ�룬���Ա�ʾ������״����ͷָ��
	//...
};