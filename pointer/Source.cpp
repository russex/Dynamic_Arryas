#include<iostream>
using namespace std;

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);
void OddEven(int arr[], const int n, int even[], int odd[]);
int* PushFront(int arr[], int& n,int& value);
int* PushBack(int arr[], int& n, int& value);
void insert(int arr[], int& n, int value, int  it);
void pop_back(int arr[], int& n);
void pop_front(int arr[], int& n);
void erase(int arr[], int& n, int  it);
void main()
{
	setlocale(LC_ALL, "Rus");
	int n;
	int t=0;
	int a=0;
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
#ifdef DEBUG
	int* arr2 = new int[n] {};
	FillRand(arr2, n);
	Print(arr2, n);
	int value;
	cout << "Введите добавляемое значение: "; cin >> value;
	PushFront(arr2, n, value);
	Print(arr2, n);
	delete[] arr;
	FillRand(arr2, n);
	Print(arr2, n);
	int value2;
	cout << "Введите добавляемое значение: "; cin >> value2;
	PushBack(arr2, n, value2);
	Print(arr2, n);
	delete[] arr2;
#endif // DEBUG
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
	return arr;

}
void insert(int arr[], int& n, int value,int  it)
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
	
}
void pop_back(int arr[], int& n)
{
	int* buffer = new int[n - 1]{};
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	n--;
}
void pop_front(int arr[], int& n)
{
	int* buffer = new int[n - 1]{};
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i+1];
	}
	delete[] arr;
	n--;
}
void erase(int arr[], int& n, int  it)
{
	int* buffer = new int[n - 1]{};
	for (int i = 0; i < n; i++)
	{
		i < it ? buffer[i] = arr[i] : buffer[i] = arr[i+1];
	}
	delete[] arr;
	n--;
}