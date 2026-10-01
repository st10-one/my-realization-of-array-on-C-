#include <iostream>

using namespace std;

typedef struct
{
	size_t size;
	int capacity;
	int* data;

}MyArray;


MyArray init(MyArray* arr, size_t size);

bool isEmpty(MyArray* arr);

void add(MyArray* arr, int value);

int removeT(MyArray* arr, int index);

int getByIndex(MyArray* arr, int index);

void destroy(MyArray* arr);


MyArray init(MyArray* arr, size_t size) 
{
	if (arr->data != nullptr && arr->size != 0)
	{
		arr->data = new int[size];
		arr->size = 0;
		arr->capacity = size;

		return *arr;
	}
}

bool isEmpty(MyArray* arr)
{
	if (arr->size == 0) return true;
	else return false;
}

void add(MyArray* arr, int value)
{
	if (arr->size >= arr->capacity)
	{
		cout << "Buffer overflow" << endl;
		destroy(arr);
		exit(1);
	}
	else
	{
		*(arr->data + arr->size) = value;
		arr->size++;
	}

}

int getByIndex(MyArray* arr, int index)
{
	int* myIndex = arr->data;
	if (arr->size >= index) return *(myIndex + index);
	else return NULL;
}

int removeT(MyArray* arr, int index)
{
	if (arr->size >= index)
	{
		*(arr->data + index) = NULL;
		return *(arr->data + index);
	}
	else return NULL;
}

void destroy(MyArray* arr)
{
	if (arr->data == nullptr || *(arr->data) == NULL || arr->size == 0)
	{
		return;
	}
	delete arr->data;
	arr->size = 0;
	arr->data = nullptr;
}

int main() {
	MyArray a = init(&a, 10);

	bool is_empty = isEmpty(&a);
	cout << "array is: " <<  is_empty << endl;

	for (int i = 0; i < 10; i++)
	{
		add(&a, i);
	}

	for (int  i = 0; i < 10; i++)
	{
		int result = getByIndex(&a, i);
		cout << result << "\n" << endl;
	}

	int res = removeT(&a, 5);

	for (int i = 0; i < 10; i++)
	{
		int result = getByIndex(&a, i);
		cout << result << endl;
	}

	destroy(&a);

	return 0;
}
