// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП

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
		T* temp=new T[s];
        for (size_t i=0; i<capacity; i++)
             temp[i]=data[i];
        delete[] data;
        data=temp;
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
	bool operator==(const Vector &v) const
    {
	bool flag=true;
	if (size!=v.size) flag=false;
	else 
		for (int i=0; i<size; i++)
			if (data[i]!=v.data[i]) { flag=false; break; };
    return flag;
    };
	bool operator!=(const Vector &v) const
    { 
      return !(*this==v);
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
	Stack(const Stack& s): Vector(s) {};
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
template <class T>
class Queue: public Vector <T> {
private:
	T *start;
	T *end;
	void insert(T elem, int index) {};
	void erase(int index) {};
	void pop_back() {};
	void pop_front() {};
	void push_back(T elem) {};
	void push_front(T elem) {};
public:
	Queue(): Vector() { start=nullptr; end=nullptr; };
	Queue(int n): Vector(n) { start=data; end=data+size-1; };
	Queue(const Queue& q): Vector(q)
	{ start=q.start; end=q.end; };
	~Queue() {};
	T front()
	{
		if (size==0) throw std::logic_error("Impossible to take the first element of queue");
		else return *start;
	};
	T back()
	{
		if (size==0) throw std::logic_error("Impossible to take the last element of queue");
	    else return *end;
	};
	void push(T elem)
	{
		if (this->full()==true) resize(size_t(COEFFICIENT*capacity)+1); 
		if (end==data+capacity-1) end=data;
		else end++;
		*end=elem;
		size++;
	};
	void pop()
	{
		if (this->empty()==true) throw std::logic_error ("Impossible to pop");
		start++;
		size--;
	};
	void resize (size_t s)
	{
		T* temp = new T[s];
		int k=0;
        for (size_t i=(start-data)/sizeof(T); i<capacity; i++)
        {
			temp[k]=data[i];
			k++;
		}
		for (size_t i=0; i<(start-data)/sizeof(T); i++)
        {
			temp[k]=data[i];
			k++;
		}
        delete[] data;
        data = temp;
        capacity=s;
		start=data;
		end=data+size-1;
	};
	bool empty()
	{
		if (size==0) return true;
		else return false;	
	};
	bool full() 
	{
		if (((start==data)&&(size==capacity))||(start==end+1)) return true;
		else return false;
	};
	bool operator ==(const Queue& q) const
	{
	bool flag=true;
	if ((size!=q.size)||(start!=q.start)||(end!=q.end)) flag=false;
	else 
		for (int i=0; i<size; i++)
			if (data[i]!=q.data[i]) { flag=false; break; };
    return flag;
	};
	bool operator!=(const Queue &q) const
    { 
      return !(*this==q);
    };
};