#ifndef _MYITERATOR_H_
#define _MYITERATOR_H_

#include <iostream>

template <typename T>
class Myiterator
{
public:
	Myiterator(T *it = nullptr) : _it(it) {}
	Myiterator(const Myiterator& other) : _it(other._it) {}
	Myiterator operator++();
	bool operator!=(const Myiterator &it);
	bool operator<(const Myiterator &it);
	Myiterator operator++(int);
	T& operator*();
private:
	T *_it;
};

template<typename T>
Myiterator<T> Myiterator<T>::operator++()
{
	++_it;
	return *this;
}
template<typename T>
bool Myiterator<T>::operator<(const Myiterator<T> &it)
{
	return (_it < it);
}
template<typename T>
bool Myiterator<T>::operator!=(const Myiterator<T> &it)
{
	return (_it != it._it);
}
template<typename T>
Myiterator<T> Myiterator<T>::operator++(int)
{
	(_it++);
	return *this;
}
template<typename T>
T& Myiterator<T>::operator*()
{
	return *(_it);
}


#endif
