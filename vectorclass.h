#ifndef _VECTORCLASS_H_
#define _VECTORCLASS_H_

#include <iostream>
#include "myiterator.h"

template < typename T >
class vector
{
public:
	vector() : _N(0), _mass(nullptr), _count(0) {}
	vector(const size_t &N);
	void push_back(const T &a);
	void pop_back();
	const size_t& size() { return _N; }
	bool empty();
	void clear();
	T& operator[](const size_t i);
	const T& front();
	const T& back();
	Myiterator<T> begin();
	Myiterator<T> end();
	void swap(vector &other);
	~vector() { delete[]_mass; _mass = nullptr; _N = 0; _count = 0; }
private:
	size_t _N;
	T *_mass;
	size_t _count;
};

template < typename T >
vector<T>::vector(const size_t &N)
	: _N(N), _mass(new T[N]){}

template < typename T >
void vector<T>::push_back(const T &a)
{
	if (_N == 0)
	{
		_count = 8; 
		_mass = new T[_count];
		_mass[0] = a;
		_N = 1;
	}
	else
	{
		if ((_count - _N) > 0)
			_mass[_N++] = a;
		else
		{
			T *mass2 = new T[_N + 1];
			for (size_t i = 0; i < _N; ++i)
				mass2[i] = _mass[i];
			mass2[_N] = a;
			delete[]_mass;
			_count = _N + 8;
			_mass = new T[_count];
			for (size_t i = 0; i < _N + 1; ++i)
				_mass[i] = mass2[i];
			++_N;
			delete[]mass2;
		}
	}
}
template < typename T >
void vector<T>::pop_back()
{
	if (_N > 0)
	{
		T *mass2 = new T[_N - 1];
		for (size_t i = 0; i < _N - 1; ++i)
			mass2[i] = _mass[i];
		delete[]_mass;
		_mass = new T[_N - 1];
		for (size_t i = 0; i < _N - 1; ++i)
			_mass[i] = mass2[i];
		--_N;
		delete[]mass2;
	}
	else
		throw std::logic_error("\nпустой вектор\n");
}
template < typename T >
bool vector<T>::empty()
{
	return _N == 0;
}
template < typename T >
void vector<T>::clear()
{
	delete[]_mass;
	_mass = nullptr;
	_N = 0;
	_count = 0;
}
template < typename T >
T& vector<T>::operator[](const size_t i)
{
	return _mass[i];
}
template < typename T >
const T& vector<T>::front()
{
	return *_mass;
}
template < typename T >
const T& vector<T>::back()
{
	return *(_mass + _N );
}
template < typename T >
Myiterator<T> vector<T>::begin()
{
	return Myiterator<T>(_mass);
}
template < typename T >
Myiterator<T> vector<T>::end()
{
	return Myiterator<T>(_mass + _N);
}
template < typename T >
void vector<T>::swap(vector &other)
{
	vector v;
	for (size_t i = 0; i < other.size(); ++i)
	{
		v[i] = other[i];
	}
	other.clear();
	for (size_t i = 0; i < _N; ++i)
		other[i] = _mass[i];
	delete[]_mass;
	_mass = new T[other.size()];
	for (size_t i = 0; i < v.size(); ++i)
		_mass[i] = v[i];
}
#endif
