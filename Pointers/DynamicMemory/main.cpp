#include<iostream>
//using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"
#define delimeter "\n----------------------------------\n";




void FillRand(int arr[], const int n);
void FillRand(double arr[], const int n);
void FillRand(int** arr, const int rows, const int cols);
void FillRand(double** arr, const int rows, const int cols);


template<typename T>void Print(T arr[], const int n);
template<typename T>void Print(T** arr, const int rows, const int cols);

template<typename T>T* Push_back(T arr[], int& n, const T value);                  //добавляет последний элемент массива
template<typename T>T* Push_front(T arr[], int& n, const T value);                 //добавляет нулевой элемент массива

template<typename T>T* insert(T arr[], int& n, const T value, int index);          //добавляет значение по индексу

template<typename T>T* Pop_back(T arr[], int& n);                                 //удаляет последний элемент массива(&размер по ссылке)
template<typename T>T* Pop_front(T arr[], int& n);                                //удаляет нулевой элемент массива

template<typename T>T* Erase(T arr[], int& n, const int index);                   //удаляет элемент массива по указанному индексу


template<typename T>T** push_row_back(T** arr, int& rows, const int cols);        //добавляем строку в конец массива
template<typename T>T** push_row_front(T** arr, int& rows, int& cols);            //добавляем строку в начало массива
//int** insert_row(int** arr, int& rows, const int cols, const int index);        //добавляет строку в массив по указанному индексу
template<typename T>T** pop_row_back(T** arr, int& rows, const int cols);         //удаляет строку из конца массива

template<typename T>void push_col_back(T** arr, const int rows, int& cols);        //добавляет столбец в конец массива
template<typename T>void push_col_front(T** arr, const int rows, int& cols);       //добавляет столбец в начало массива
//int** insert_col(int** arr, const int rows, int& cols, const int index);         //добавляет столбец в массив по указанному индексу
template<typename T>void pop_col_back(T** arr, const int rows, int& cols);         //удалет столбик из конца массива

//#define DIN_MEM_1
#define DIN_MEM_2

#define DATA_TYPE double

void main()
{
	setlocale(LC_ALL, "");

#ifdef DIN_MEM_1


	int n;
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n];

	FillRand(arr, n);
	Print(arr, n);

	cout << arr << endl;
	cout << *arr << endl;
	for (int i = 0; i < n; i++)
	{
		cout << *(arr + i) << "\t";
	}
	cout << endl;


	int value;
	cout << "Введите добавляемое значение"; cin >> value;
	arr = Push_back(arr, n, value);
	Print(arr, n);

	cout << "Введите добавляемое значение"; cin >> value;
	arr = Push_front(arr, n, value);
	Print(arr, n);

	int index;
	cout << "Введите индекс добавляемого значение"; cin >> index;
	cout << "Введите значение добавляемого значение"; cin >> value;
	arr = insert(arr, n, value, index);
	Print(arr, n);

	cout << "Массив после уладения последнего элемента" << endl;
	Print(arr = Pop_back(arr, n), n);
	cout << "Массив после удаления нулевого элемента" << endl;
	Print(arr = Pop_front(arr, n), n);


	cout << "Введите индекс удаляемого значение"; cin >> index;
	cout << "Массив после удаления элемента по индексу" << endl;
	Print(arr = Erase(arr, n, index), n);



	delete[] arr;


#endif


#ifdef DIN_MEM_2

	int rows;
	int cols;
	cout << "Введите кол-во строк"; cin >> rows;
	cout << "Введите кол-во элементов строки"; cin >> cols;


	typedef double DataType; // существующему типу данных дает второе имя


	//(указатель ** на указатель)создаем массив указателей
	DataType** arr = new DataType * [rows];

	//выделяем память под строки двумерного динамич массива
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new DataType[cols];
	}
	cout << endl;

	/*cout << "Память выделена, для добавления столбца";
	system("PAUSE");
	push_col_back(arr, rows, cols);

	cout << "Столбец добавлен" << endl;*/

	FillRand(arr, rows, cols);
	Print(arr, rows, cols);

	arr = push_row_back(arr, rows, cols);
	Print(arr, rows, cols);

	arr = push_row_front(arr, rows, cols);
	Print(arr, rows, cols);

	push_col_back(arr, rows, cols);
	Print(arr, rows, cols);

	//push_col_front(arr, rows, cols);
	//Print(arr, rows, cols);

	arr = pop_row_back(arr, rows, cols);
	Print(arr, rows, cols);

	pop_col_back(arr, rows, cols);
	Print(arr, rows, cols);


	//очистить память
	for (int i = 0; i < rows; i++) // сначала удаляем строки
	{
		delete[] arr[i];
	}
	delete[] arr;                  // удаляем массив укзателей

#endif

}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
		//Index operator, Subscript operator;
	}
}
void FillRand(double arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 10000;
		arr[i] /= 100;
		//Index operator, Subscript operator;
	}
}
void FillRand(int** arr, const int rows, const int cols)
{
	//заполнем рандомом и выводим на экран
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
}
void FillRand(double** arr, const int rows, const int cols)
{
	{
		//заполнем рандомом и выводим на экран
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				arr[i][j] = double(rand() % 10000)/100;

			}
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
	cout << delimeter;

	cout << endl;
}

template<typename T>T* Push_back(T arr[], int& n, const T value)
{
	T* buffer = new T[n + 1];                     //переопределить память - создаем буфферный массив нужного массива
	for (int i = 0; i < n; i++)buffer[i] = arr[i];//копируем все содежимое исходного массива в буфферный массив
	delete[] arr;                                 //удаляем исходный массив 
	arr = buffer;                                 //подменяем адрес в указателе arr адресом нового массива
	arr[n] = value;                               //только после этого в конце массива появляется элемент, в которое можно сохранить добавляемое значение
	n++;                                          //после того как в массив дбавился элемент количество его элементов увеличивается на 1
	return arr;
}
template<typename T>T* Push_front(T arr[], int& n, const T value)
{
	T* buffer = new T[n + 1];                     //выделяем память нужного размера +1
	for (int i = 0; i < n; i++)buffer[i + 1] = arr[i];//копируем в буффер
	delete[] arr;                                     //удаляем исходный массив
	buffer[0] = value;                                // добавляем значение в нулевой элемент!!!!!!!!!!!!
	n++;                                              // кол-во элементов в массиве увеличивается
	return buffer;
}

template<typename T>T* insert(T arr[], int& n, const T value, int index)
{
	T* buffer = new T[n + 1];                      //выделяем память нужного элемента   
	for (int i = 0; i < index; i++)buffer[i] = arr[i]; //копируем в буффер до индекса!

	for (int i = index; i < n; i++)buffer[i + 1] = arr[i];//копируем после индекса
	delete[] arr;                                         //удаляем исходный массив 
	buffer[index] = value;                                //в элемент добавляем значение по индексу!
	n++;
	return buffer;
}

template<typename T>T* Pop_back(T arr[], int& n)
{
	cout << arr << endl;
	T* buffer = new T[--n];                        //память выделится в первую очередь из-за --
	for (int i = 0; i < n; i++)buffer[i] = arr[i];     //копируем массив в буффер
	delete[] arr;                                      //удаляем исходный
	return buffer;
}
template<typename T>T* Pop_front(T arr[], int& n)
{
	cout << arr << endl;
	T* buffer = new T[--n];
	for (int i = 0; i < n; i++)buffer[i] = arr[i + 1];
	delete[] arr;
	arr = buffer;

	return buffer;
}

template<typename T>T* Erase(T arr[], int& n, const int index)
{
	T* buffer = new T[--n];
	for (int i = 0; i < index; i++)buffer[i] = arr[i];
	for (int i = index; i < n; i++)buffer[i] = arr[i + 1];
	delete[] arr;
	arr = buffer;
	return buffer;
}



template<typename T>T** push_row_back(T** arr, int& rows, const int cols)
{
	T** buffer = new T* [rows + 1];                //создаем буфферный массив указателей нужного размера
	for (int i = 0; i < rows; i++)buffer[i] = arr[i];//копируем адреса строк в буфферный массив указателей
	delete[] arr;                                    // удаляем массив укзателей	
	buffer[rows] = new T[cols] {};                 //создаем добавляемую строку и записываем ее адрес в массив указателей 
	rows++;                                          //при добавлении в массив строки количество его строк увеличивается на 1
	return buffer;                                   //возвращаем новый массив на место вызова
}
template<typename T>T** push_row_front(T** arr, int& rows, int& cols)
{
	T** buffer = new T* [rows + 1];                   //создаем буффер указателей нужного размера
	for (int i = 0; i < rows; i++)buffer[i + 1] = arr[i];   //копируем адреса строк в буфферный массив указателей
	delete[] arr;                                         // удаляем массив укзателей	
	buffer[0] = new T[cols] {};                         //создаем добавляемую строку и записываем ее адрес в массив указателей
	rows++;                                               //при добавлении в массив строки количество его строк увеличивается на 1
	return buffer;                                        //возвращаем новый массив на место вызова
}

template<typename T>T** pop_row_back(T** arr, int& rows, const int cols)
{
	delete[] arr[rows - 1];                      //удалем последнюю строку
	T** buffer = new T* [--rows];                 //создеам буфферный массив указателей
	for (int i = 0; i < rows; i++)buffer[i] = arr[i]; // копируем оставшиеся строки в буферный массив указателей
	delete[] arr;                                 // удаляем массив указателей
	return buffer;
}

template<typename T>void push_col_back(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)       //память не переопределяем !!!
	{
		T* buffer = new T[cols + 1] {}; //создаем буфферный массив нужного размера 
		for (int j = 0; j < cols; j++)buffer[j] = arr[i][j];   // копируем элементы текущей строки
		delete[] arr[i];             //удаляем старый массив
		arr[i] = buffer;             //делаем новую строку
	}
	cols++;
}
template<typename T>void push_col_front(T** arr, const int rows, int& cols)
{

	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols] {};
		for (int j = 0; j < cols; j++)buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols--;
}
///??????
template<typename T>void pop_col_back(T** arr, const int rows, int& cols)
{
	cols--;
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols];
		for (int j = 0; j < cols; j++)buffer[j] = arr[i][j];    //копируем исходную строку в буффер
		delete[] arr[i];
		arr[i] = buffer;
	}
}