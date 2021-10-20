#include<iostream>
using namespace std;
#include"Arryas.h"
#include"Memory.h"
//#define DEBUG
//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2

void main()
{
	setlocale(LC_ALL, "Rus");
#ifdef DYNAMIC_MEMORY_1
	int n;
	int t = 0;
	int a = 0;
	cout << "Введите размер массива"; cin >> n;
	int* arr = new int[n] {};
	FillRand(arr, n);
	Print(arr, n);
	for (int i = 0; i < n; i++)
	{
		arr[i] % 2 == 0 && arr[i] != 0 ? t++ : arr[i] == 0 ? a : a++;
	}
	int* even = new int[t] {};
	int* odd = new int[a] {};
	OddEven(arr, n, even, odd);
	cout << "Нечётные элементы массива: "; Print(odd, a);
	cout << "Чётные элементы массива: "; Print(even, t);
	delete[] odd;
	delete[] even;
	//delete[] arr;  
#endif // DYNAMIC_MEMORY_1

#ifdef DEBUG

	//int* arr2 = new int[n] {};
	//FillRand(arr, n);
	Print(arr, n);
	int value;
	cout << "Введите добавляемое значение: "; cin >> value;
	arr=PushFront(arr, n, value);
	Print(arr, n);
	cout << "Введите добавляемое значение: "; cin >> value;
	arr=PushBack(arr, n, value);
	Print(arr, n);
	int it;
	cout << "Введите добавляемое значение: "; cin >> value;
	cout << "Введите индек для добавления элемента массива: "; cin >> it;
	arr = insert(arr, n, value,it);
	Print(arr, n);
	cout << "Удаляет последний элемент массива: "; arr = pop_back(arr, n );
	Print(arr, n);
	cout << "Удаляет первый элемент массива: "; arr = pop_front(arr, n);
	Print(arr, n);
	cout << "Введите индек для удаления элемента массива: "; cin >> it;
	arr = erase(arr, n, it);
	Print(arr, n);
	delete[] arr;


#endif // DEBUG
#ifdef	DYNAMIC_MEMORY_2
	int rows;
	int cols;
	int it;
	cout << "Введите добавляемое значение строк: "; cin >> rows;
	cout << "Введите добавляемое значение элементов строки : "; cin >> cols;
	char** arr = allocate<char>(rows, cols);
	
	cout << endl;
	FillRand(arr, rows, cols);
	Print(arr, rows, cols);
	Push_Row_Back(arr, rows, cols);
	Print(arr, rows, cols);
	Push_Row_Front(arr, rows, cols);
	Print(arr, rows, cols);
	cout << endl;
	cout << "Введите индекс добавляемой строки: "; cin >> it;
	insert_row(arr, rows, cols, it);
	Print(arr, rows, cols);
	cout<< "Введите индекс удаляемой строки: "; cin >> it;
	erase_row(arr, rows, cols, it);
	Print(arr, rows, cols);
	Pop_Row_Back(arr, rows, cols);
	Print(arr, rows, cols);
	Pop_Row_Front(arr, rows, cols);
	Print(arr, rows, cols);
	Push_Col_Back(arr, rows, cols);
	Print(arr, rows, cols);
	Pop_Col_Back(arr, rows, cols);
	Print(arr, rows, cols);
	Pop_Col_Front(arr, rows, cols);
	Print(arr, rows, cols);
	Push_Col_Front(arr, rows, cols);
	Print(arr, rows, cols);
	cout << "Введите индекс добавляемого ряда: "; cin >> it;
	insert_col(arr, rows, cols, it);
	Print(arr, rows, cols);
	cout << "Введите индекс удаляемого ряда: "; cin >> it;
	erase_col(arr, rows, cols, it);
	Print(arr, rows, cols);
	clear(arr, rows);

#endif // Dynamic

}

