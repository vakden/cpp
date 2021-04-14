#pragma once
#include <iostream>
#include <string>
#include <string>
#include <assert.h>
#include <iomanip>

using namespace std;

template <typename T>
class MyArray
{
public:
	int size;
	T* data;
	MyArray(int length, T* arr)//конструктор массива через массив элементов и размер
	{
		if (length <= 0)
		{
			cout << "Invalid length of array" << endl;
		}
		size = length;
		data = new T[size];
		for (int i = 0; i < size; i++)
		{
			data[i] = arr[i];
		}
	}
	MyArray(MyArray<T> &arr)//конструктор копирования
	{
		size = arr.size;
		data = new T[size];
		for (int i = 0; i < size; i++)
		{
			data[i] = arr.data[i];
		}
	}

	MyArray operator +=(MyArray<T> arr)
	{
		int newSize = size + arr.size;
		T* newData = new T[newSize];
		for(int i = 0; i < newSize; i++)
		{
			if(i < size)
			{
				newData[i] = data[i];
				continue;
			}
			newData[i] = arr.data[i-size];
		}
		delete[] data;
		data = newData;
		size = newSize;
		return *this;
	}
	~MyArray()
	{
		delete[] data;
	}
};
