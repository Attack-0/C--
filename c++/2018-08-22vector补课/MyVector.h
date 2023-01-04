#pragma once
template<typename T>
class CMyVector
{
	T* pBuff;//��̬�����׵�ַ
	size_t nSize;//��̬������Ԫ�ظ���
	size_t nCapacity;//��̬������󳤶�
	//Ĭ�Ϲ��캯��+���ι��캯��  ʹ��explicit��ֹ��ʽת��
public:
	typedef T* iterator;//��ͨ������
	typedef const T* const_iterator;//��������
public:
	struct MyIterator
	{
		T* pit;
		MyIterator& operator=(MyIterator const& srcit){
			pit = srcit.pit;
			return *this;
		}
	};

	MyIterator Mybegin()
	{
		MyIterator tempIt;
		tempIt.pit = pBuff;
		return tempIt;
	}
public:
	explicit CMyVector(int n = 0);
	CMyVector(CMyVector<T> const&);
	CMyVector(int n, T const&);
	void clear();
	~CMyVector();

public:
	iterator begin()
	{
		return pBuff;
	}
	iterator end()
	{
		return pBuff+nSize;
	}
	const_iterator cbegin()const
	{
		return pBuff;
	}
	const_iterator cend()const
	{
		return pBuff + nSize;
	}

public:
	CMyVector<T>& operator= (CMyVector<T> const&);
	bool operator == (CMyVector<T> const&)const;
	bool operator !=(CMyVector<T> const&)const;
	bool operator>(CMyVector<T> const&)const;//��ҵ
	bool operator>=(CMyVector<T> const&)const;//��ҵ
	bool operator<(CMyVector<T> const&)const;//��ҵ
	bool operator<=(CMyVector<T> const&)const;//��ҵ
public:
	void assign(int n, T const&);
	void swap(CMyVector<T>&);
	friend void swap(CMyVector<T>& v1, CMyVector<T>& v2)
	{
		v1.swap(v2);
	}
public:
	size_t size()const;
	size_t capacity()const;
	bool empty()const;
	void reserve(int n);
	void resize(int n);
	void resize(int n, T const&);

public:
	T& at(int index)const;
	T& operator[](int index)const;
	T& front();
	T& back();
public:
	void push_back(T const&);
	void pop_back();
};

template<typename T>
CMyVector<T>::CMyVector(int n /*= 0*/) :nSize(n), nCapacity(n), pBuff(nullptr)
{
	pBuff = new T[nCapacity];
	memset(pBuff, 0, sizeof(T)*nSize);//���Բ�д
}

template <typename T>
CMyVector<T>::CMyVector(CMyVector<T> const& that) :nSize(that.nSize), nCapacity(that.nCapacity), pBuff(nullptr)
{
	if (nCapacity)
	{
		pBuff = new T[nCapacity];
		memcpy(pBuff, that.pBuff, sizeof(T)*that.nSize);
	}
}

template <typename T>
CMyVector<T>::CMyVector(int n, T const& elem) :nSize(n), nCapacity(n), pBuff(nullptr)
{
	pBuff = new T[nCapacity];
	for (int i = 0; i < nSize; ++i)
	{
		pBuff[i] = elem;
	}
}

template <typename T>
void CMyVector<T>::clear()
{
	nSize = 0;
	if (pBuff)
		delete[] pBuff;
	pBuff = nullptr;
}

template <typename T>
CMyVector<T>::~CMyVector()
{
	clear();
}

template <typename T>
CMyVector<T>& CMyVector<T>::operator=(CMyVector<T> const&that)
{
	if (this != &that)//�����Ը�ֵ
	{
		//��������Դ ���������ͷű���ֵ�Ķ���
		T* p_tmp = new T[that.nCapacity];//��������Դ
		memcpy(p_tmp, that.pBuff, sizeof(T)*that.nSize);//��������Դ
		clear();//�ͷž���Դ
		this->pBuff = p_tmp;//�ӹ��ڴ�
		this->nSize = that.nSize;
		this->nCapacity = that.nCapacity;
	}
	return *this;//����������
}

template <typename T>
bool CMyVector<T>::operator==(CMyVector<T> const& srcVector) const//�ο�strcmp
{
	if (nSize != srcVector.nSize)
		return false;
	for (int i = 0; i < nSize; ++i)
	{
		if (pBuff[i] != srcVector.pBuff[i])
			return false;
	}
	return true;
}

template <typename T>
bool CMyVector<T>::operator!=(CMyVector<T> const& srcVector) const
{
	return !(*this == srcVector);
}

template <typename T>
void CMyVector<T>::assign(int n, T const&elem)
{
	clear();

	//CMyVector temp(n, elem);
	//swap(temp);

	//CMyVector temp2;
	//temp2 = temp;
	//temp = *this;
	//*this = temp2;
	nSize = nCapacity = n;
	pBuff = new T[nCapacity];
	for (int i = 0; i < n; ++i)
	{
		pBuff[i] = elem;
	}
}

template <typename T>
void CMyVector<T>::swap(CMyVector<T>& srcVector)
{
	CMyVector temp;
	temp = *this;
	*this = srcVector;
	srcVector = temp;
}

template <typename T>
size_t CMyVector<T>::size() const
{
	return nSize;
}

template <typename T>
size_t CMyVector<T>::capacity() const
{
	return nCapacity;
}

template <typename T>
bool CMyVector<T>::empty() const
{
	return nSize == 0;
	//return pBuff == nullptr;
}

template <typename T>
void CMyVector<T>::reserve(int n)
{
	if (n > nCapacity)
	{
		T* tempBuff = new T[n];
		memcpy(tempBuff, pBuff, sizeof(T)*nSize);
		if (pBuff)
			delete[] pBuff;
		pBuff = tempBuff;
		nCapacity = n;
	}
}

template <typename T>
void CMyVector<T>::resize(int n)
{
	if (n > nCapacity)
	{
		reserve(n);
		memset(&pBuff[nSize], 0, sizeof(T)*(n - nSize));
	}
	nSize = n;
}

template <typename T>
void CMyVector<T>::resize(int n, T const&elem)
{
	resize(n);
	for (size_t i = nSize; i < n; ++i)
	{
		pBuff[i] = elem;
	}
}

template <typename T>
T& CMyVector<T>::at(int index) const
{
	if (index >= 0 && index < nSize)
		return pBuff[index];
	throw std::out_of_range("Խ��");
}

template <typename T>
T& CMyVector<T>::operator[](int index) const
{
	return pBuff[index];
}

template <typename T>
T& CMyVector<T>::front()
{
	return pBuff[0];
}

template <typename T>
T& CMyVector<T>::back()
{
	return pBuff[nSize-1];
}

template <typename T>
void CMyVector<T>::push_back(T const&elem)
{
	if (nSize == nCapacity)//֤����������
	{
		reserve(2 * nCapacity + 1);
	}
	pBuff[nSize++] = elem;
}

template <typename T>
void CMyVector<T>::pop_back()
{
	if (nSize > 0)
		nSize--;
}
