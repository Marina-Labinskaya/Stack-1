// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// utmatrix.h - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (21.04.2015)
//
// Верхнетреугольная матрица - реализация на основе шаблона вектора

#pragma once
#include <iostream>
#include "conio.h"
const double COEFFICIENT = 1.3;
const int MAX_SIZE = 1000;
template <class T>
class Vector
{
protected:
	T* data;
	size_t capacity; //размер выделенной памяти
    size_t size; //размер занятой памяти 
public:
	Vector() 
	{data = nullptr; capacity=0; size=0;};
	~Vector() 
	{delete[] data; data=nullptr; size=0; capacity=0;};
	size_t GetSize() { return size; };
	Vector (int n)
	{
		if ((n<0)||(n>MAX_SIZE)) throw std::logic_error ("Invalid size");
		else {
		capacity=size_t(COEFFICIENT*n)+1;
		data = new T[capacity];
		size=n;
		for (size_t i=0;i<capacity; i++)
			data[i]=0;
		}
	};
	Vector (const Vector& v)
	{
		capacity=v.capacity;
		size=v.size;
		data = new T[capacity];
		for (size_t i=0; i<size; i++)
			data[i]=v.data[i];
		for (size_t i=size; i<capacity; i++)
			data[i]=0;
	};
	void push_back (T elem)
	{
		if (size==MAX_SIZE) throw std::logic_error("Impossible to push back");
		if ((size+1)>capacity) {
		       capacity=size_t(COEFFICIENT*capacity)+1;
			   resize(capacity);
		    }
	     data[size]=elem;
		 size++;
	};
	void pop_back()
	{
		if (size==0) throw std::logic_error ("Impossible to pop");
		else {
	         size--;
	         data[size]=0;
		};
	};
	void push_front (T elem)
	{
		this->insert(elem,0);
	};
	void pop_front ()
	{
	   for (size_t i=0; i<size; i++)
		   data[i]=data[i+1];
	   data[size-1]=0;
	   size--;
	};
	void resize (size_t s)
	{
		T* temp = new T[s];
        for (size_t i=0; i<capacity; i++)
             temp[i]=data[i];
        delete[] data;
        data = temp;
        capacity=s;
	};
	T& operator[] (size_t index) 
	{
      if ((index<0)||(index>=size)) throw std::logic_error("Invalid index");
	  else return data[index];
	};
	T operator[] (size_t index) const 
	{
	   if ((index<0)||(index>=size)) throw std::logic_error("Invalid index");
	   else return data[index];
	};
	void insert (T elem, int index)
		{
			  if ((size+1)>capacity) {
			     capacity=size_t(COEFFICIENT*capacity)+1;
			     resize(capacity);
				 for (size_t i=size; i>=index; i--)
					 data[i]=data[i-1];
				 data[index-1]=elem;
			     size++;
		      }
		      else 
			  { for (size_t i=size; i>=index; i--)
					 data[i]=data[i-1];
				 data[index-1]=elem;
			     size++;
			  };
	    };
	void erase (int index)
    { 
	   for (size_t i=index-1; i<size-1; i++)
		   data[i]=data[i+1];
	   data[size-1]=0;
	   size--;
    };
};
template <class T>
class Stack: public Vector <T> {
private:
	void push_front() {};
	void pop_front() {};
	void insert(T elem, int index) {};
	void erase (int index) {};
public:
	Stack():Vector() {};
	Stack(int n): Vector(n) {};
	~Stack() {};
    T top() 
	{ 
		if (size==0) throw std::logic_error("Impossible to take the top of stack");
	    else return data[size-1];
	};
	void push(T elem) 
	{
		Vector<T>::push_back(elem);
	};
	void pop() 
	{
	   Vector<T>::pop_back();
	};
	bool empty() 
	{
		if (size==0) return true;
		else return false;
	};
	bool full() 
	{
		if (size==capacity) return true;
		else return false;
	};
};