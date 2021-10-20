#pragma once
#include<iostream>
using namespace std;

#include"Memory.h"

void FillRand(int arr[], const int n, int minRand, int maxRand)
{

	for (int i = 0; i < n; i++)
	{
		//»спользу€ арифметику указателей и оператор разыменовани€:
		*(arr + i) = rand() % (maxRand - minRand) + minRand;
	}
}
void FillRand(char arr[], const int n, int minRand, int maxRand)
{
	for (int i = 0; i < n; i++)
	{
		//»спользу€ арифметику указателей и оператор разыменовани€:
		*(arr + i) = rand();
	}
}
void FillRand(double arr[], const int n, int minRand, int maxRand)
{
	minRand *= 100;
	maxRand *= 100;
	for (int i = 0; i < n; i++)
	{
		//»спользу€ арифметику указателей и оператор разыменовани€:
		*(arr + i) = rand() % (maxRand - minRand) + minRand;
		*(arr + i) /= 100;
	}
}
void FillRand(int** arr, const int rows, const int cols, int minRand, int maxRand)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % (maxRand - minRand) + minRand;
		}
	}
}
void FillRand(char** arr, const int rows, const int cols, int minRand, int maxRand)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand();
		}
	}
}
void FillRand(double** arr, const int rows, const int cols, int minRand, int maxRand)
{
	minRand *= 100;
	maxRand *= 100;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % (maxRand - minRand) + minRand;
			arr[i][j] /= 100;
		}
	}
}
template<typename T>void Print(T arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}
template<typename T>void OddEven(T arr[], const int n, int even[], int odd[])
{
	int o = 0; int d = 0;
	for (int i = 0; i < n; i++)
	{
		arr[i] % 2 == 0 && arr[i] != 0 ? (even[o] = arr[i], o++) : arr[i] == 0 ? d/* остыль*/ : (odd[d] = arr[i], d++);
	}
}

template<typename T>T* PushFront(T arr[], int& n, int& value)
{
	T* buffer = new T[n + 1]{};
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	buffer[n] = value;
	n++;
	return buffer;

}
template<typename T>T* PushBack(T arr[], int& n, T value)
{
	T* buffer = new T[n + 1]{};
	for (int i = 0; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	buffer[0] = value;
	n++;
	arr = buffer;
	return arr;

}
template<typename T>T insert(T arr[], int& n, int value, int  it)
{
	T* buffer = new T[n + 1]{};
	for (int i = 0; i < n; i++)
	{
		i < it ? buffer[i] = arr[i] : buffer[i + 1] = arr[i];
	}
	buffer[it] = value;
	delete[] arr;
	arr = buffer;
	arr[0] = value;
	n++;
	return arr;
}
template<typename T>T pop_back(T arr[], int& n)
{
	T* buffer = new T[n - 1]{};
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	n--;
	return buffer;

}
template<typename T>T* pop_front(T arr[], int& n)
{
	T* buffer = new T[n - 1]{};
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete[] arr;
	n--;
	return buffer;

}
template<typename T>T* erase(T arr[], int& n, int  it)
{
	T* buffer = new T[n - 1]{};
	for (int i = 0; i < n; i++)
	{
		i < it ? buffer[i] = arr[i] : buffer[i] = arr[i + 1];
	}
	delete[] arr;
	n--;
	return buffer;

}
void FillRand(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
}
template<typename T>void Print(T** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
}
template<typename T>void Push_Row_Back(T**& arr, int& rows, const int cols)
{
	T** buffer = new T * [rows + 1]{};
	for (int i = 0; i < rows + 1; i++)
	{
		buffer[i] = arr[i];
	}
	delete[]arr;
	buffer[rows] = new T[cols]{};
	rows++;
	arr = buffer;
}
template<typename T>void Push_Row_Front(T**& arr, int& rows, const int cols)
{
	T** buffer = new T * [rows + 1]{};
	for (int i = 0; i < rows + 1; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[]arr;
	buffer[0] = new T[cols]{};
	rows++;
	arr = buffer;
}
template<typename T>void insert_row(T**& arr, int& rows, const int cols, int it)
{
	T** buffer = new T * [rows + 1]{};
	for (int i = 0; i < rows + 1; i++)
	{
		i < it - 1 ? buffer[i] = arr[i] : buffer[i + 1] = arr[i];
	}
	delete[]arr;
	buffer[it - 1] = new T[cols]{};
	rows++;
	arr = buffer;
}

template<typename T>void Pop_Row_Back(T**& arr, int& rows, const int cols)
{
	//int** buffer = new int*[rows - 1]{};
	T** buffer = new T * [--rows]{};
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i];
	}
	//rows--;
	delete[] arr[rows];
	delete[]arr;
	arr = buffer;
}
template<typename T>void Pop_Row_Front(T**& arr, int& rows, const int cols)
{
	//rows--;
	//int** buffer = new int* [rows - 1]{};
	T** buffer = new T * [--rows]{};
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete[] arr[0];
	delete[]arr;
	arr = buffer;
}
template<typename T>void clear(T** arr, const int rows)
{
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}
template<typename T>T** allocate(int const rows, int const cols)
{
	T** arr = new T * [rows] {};
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new T[cols]{};
	}
	return arr;
}

template<typename T>void Push_Col_Back(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols + 1]{};
		for (int j = 0; j < cols; j++)buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}
template<typename T>void Pop_Col_Back(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols - 1]{};
		for (int j = 0; j < cols; j++)buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols--;
}
template<typename T>void Pop_Col_Front(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols - 1]{};
		for (int j = 0, o = 1; j < cols - 1; j++, o++)buffer[j] = arr[i][o];
		arr[i] = buffer;
	}
	cols--;
}
template<typename T>void Push_Col_Front(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols + 1]{};
		for (int j = 0; j < cols + 1; j++)buffer[j + 1] = arr[i][j];
		arr[i] = buffer;
	}
	cols++;

}
template<typename T>void erase_row(T**& arr, int& rows, const int cols, int it)
{
	T** buffer = new T * [--rows]{};
	for (int i = 0; i < rows; i++)
	{
		i < it - 1 ? buffer[i] = arr[i] : buffer[i] = arr[i + 1];
	}
	delete[] arr;
	arr = buffer;
}
template<typename T>void insert_col(T** arr, const int rows, int& cols, int it)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols + 1]{};
		for (int j = 0; j < cols + 1; j++)	j < it - 1 ? buffer[j] = arr[i][j] : buffer[j + 1] = arr[i][j];
		arr[i] = buffer;
	}
	cols++;
}
template<typename T>void erase_col(T** arr, const int rows, int& cols, int it)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols - 1]{};
		for (int j = 0; j < cols - 1; j++)	j < it - 1 ? buffer[j] = arr[i][j] : buffer[j] = arr[i][j + 1];
		arr[i] = buffer;
	}
	cols--;
}
