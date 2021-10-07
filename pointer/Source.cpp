#include<iostream>
using namespace std;

void FillRand(int arr[], const int n);
void FillRand(int** arr, const int rows, const int cols);
void Print(int arr[], const int n);
void Print(int** arr, const int rows, const int cols);
void OddEven(int arr[], const int n, int even[], int odd[]);
int* PushFront(int arr[], int& n,int& value);
int** Push_Row_Front(int** arr, int& rows, const int cols);
int* PushBack(int arr[], int& n, int& value);
int** Push_Row_Back(int** arr, int& rows, const int cols);
int* insert(int arr[], int& n, int value, int  it);
int** insert_col(int** arr, int& rows, const int cols, int it);
int* pop_back(int arr[], int& n);
int** Pop_Row_Back(int** arr, int& rows, const int cols);
int* pop_front(int arr[], int& n);
int** Pop_Row_Front(int** arr, int& rows, const int cols);
int* erase(int arr[], int& n, int  it);
void clear(int** arr, const int rows);
int** allocate(int const rows, int const cols);
void Push_Col_Back(int** arr, const int rows, int& cols);
void Pop_Col_Back(int** arr, const int rows, int& cols);
void 


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
	int** arr = new int* [rows] {};
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols] {};
	}
	cout << endl;
	FillRand(arr, rows, cols);
	Print(arr, rows, cols);
	arr=Push_Row_Back(arr, rows, cols);
	Print(arr, rows, cols);
	arr = Push_Row_Front(arr, rows, cols);
	Print(arr, rows, cols);
	cout << endl;
	cout << "Введите индекс добавляемой строки: "; cin >> it;
	arr = insert_col(arr, rows, cols, it);
	Print(arr, rows, cols);
	arr = Pop_Row_Back(arr, rows, cols);
	Print(arr, rows, cols);
	arr = Pop_Row_Front(arr, rows, cols);
	Print(arr, rows, cols);
	Push_Col_Back(arr, rows, cols);
	Print(arr, rows, cols);

	clear(arr, rows);

#endif // Dynamic

}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % 100;
	}
}
void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}
void OddEven(int arr[], const int n, int even[], int odd[])
{
	int o = 0; int d = 0;
	for (int i = 0; i < n; i++)
	{
		arr[i] % 2 == 0 && arr[i] != 0 ? (even[o] = arr[i], o++) : arr[i] == 0 ? d/*Костыль*/ : (odd[d] = arr[i], d++);
	}
}

int* PushFront(int arr[], int& n, int& value)
{
	int* buffer = new int[n + 1]{};
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	buffer[n] = value;
	n++;
	return buffer;
	
}
int* PushBack(int arr[], int& n, int& value)
{
	int* buffer = new int[n + 1]{};
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
int* insert(int arr[], int& n, int value, int  it)
{
	int* buffer = new int[n + 1]{};
	for (int i = 0; i < n; i++)
	{
		i<it?buffer[i] = arr[i]: buffer[i + 1] = arr[i];
	}
	buffer[it] = value;
	delete[] arr;
	arr = buffer;
	arr[0] = value;
	n++;
	return arr;
}
int* pop_back(int arr[], int& n)
{
	int* buffer = new int[n - 1]{};
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	n--;
	return buffer;

}
int* pop_front(int arr[], int& n)
{
	int* buffer = new int[n - 1]{};
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i+1];
	}
	delete[] arr;
	n--;
	return buffer;

}
int* erase(int arr[], int& n, int  it)
{
	int* buffer = new int[n - 1]{};
	for (int i = 0; i < n; i++)
	{
		i < it ? buffer[i] = arr[i] : buffer[i] = arr[i+1];
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
void Print(int** arr, const int rows, const int cols)
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
int** Push_Row_Back(int** arr, int& rows, const int cols)
{
	int** buffer = new int* [rows + 1]{}; 
	for (int i = 0; i < rows + 1; i++)
	{
		buffer[i] = arr[i];
	}
	delete[]arr;
	buffer[rows] = new int[cols] {};
	rows++;
	return buffer;
}
int** Push_Row_Front(int** arr, int& rows, const int cols)
{
	int** buffer = new int* [rows + 1]{};
	for (int i = 0; i < rows+1; i++)
	{
		buffer[i+1] = arr[i];
	}
	delete[]arr;
	buffer[0] = new int[cols] {};
	rows++;
	return buffer;
}
int** insert_col(int** arr, int& rows, const int cols, int it)
{
	int** buffer = new int* [rows + 1]{};
	for (int i = 0; i < rows + 1; i++)
	{
		i < it-1 ? buffer[i] = arr[i] : buffer[i + 1] = arr[i];
	}
	delete[]arr;
	buffer[it-1] = new int[cols] {};
	rows++;
	return buffer;
}

int** Pop_Row_Back(int** arr, int& rows, const int cols)
{
	//int** buffer = new int*[rows - 1]{};
	int** buffer = new int*[--rows]{};
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i];
	}
	//rows--;
	delete[] arr[rows];
	delete[]arr;
	return buffer;
}
int** Pop_Row_Front(int** arr, int& rows, const int cols)
{
	//rows--;
	//int** buffer = new int* [rows - 1]{};
	int** buffer = new int* [--rows]{};
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i+1];
	}
	delete[] arr[0];
	delete[]arr;
	return buffer;
}
void clear(int** arr, const int rows)
{
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}
int** allocate(int const rows, int const cols)
{
	int** arr = new int* [rows] {};
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols] {};
	}
	return arr;
}

void Push_Col_Back(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols + 1]{};
		for (int j = 0; j < cols; j++)buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}
void Pop_Col_Back(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols - 1]{};
		for (int j = 0; j < cols; j++)buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols--;
}
