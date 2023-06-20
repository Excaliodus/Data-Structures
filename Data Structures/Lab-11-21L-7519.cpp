#include<iostream>
using namespace std;

void Print(int* A, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;
}
void Heapify(int* A, int i, int n)
{
	int largest = i;
	if (2 * i + 1 < n && A[2 * i + 1] > A[largest])
		largest = 2 * i + 1;
	if (2 * i + 2 < n && A[2 * i + 2] > A[largest])
		largest = 2 * i + 2;
	if (i != largest)
	{
		swap(A[i], A[largest]);
		Heapify(A, largest, n);
	}
}
void BuildHeap(int* A, int n)
{
	for (int i = (n / 2) - 1; i >= 0; i--)
	{
		Heapify(A, i, n);
	}
}
void HeapSort(int* A, int n)
{
	BuildHeap(A, n);
	int i = n - 1;
	while (i > 0)
	{
		swap(A[i], A[0]);
		i--;
		Heapify(A, 0, i + 1);
	}
}

class BinaryHeap
{
private:
	int capacity;
	int size;
	int* Heap;
public:
	BinaryHeap()
	{
		capacity = 0;
		Heap = nullptr;
		size = 0;
	}
	BinaryHeap(int cap)
	{
		capacity = cap;
		Heap = new int[capacity];
		size = 0;
	}
	void Insert(int d)
	{
		Heap[++size] = d;
		int i = size;
		while (i > 1)
		{
			if (Heap[i] > Heap[i / 2])
			{
				swap(Heap[i], Heap[i / 2]);
			}
			else
			{
				break;
			}
			i = i / 2;
		}
	}
	void print()
	{
		for (int i = 1; i <= size; i++)
		{
			cout << Heap[i] << " ";
		}
	}
	void Heapify(int i)
	{
		int largest = i;
		if (2 * i <= size && Heap[2*i] > Heap[largest])
			largest = 2 * i;
		if (2 * i <= size && Heap[2 * i + 1] > Heap[largest])
			largest = 2 * i + 1;
		if (i != largest)
		{
			swap(Heap[i], Heap[largest]);
			Heapify(largest);
		}
	}
	int extractmax()
	{
		return Heap[1];
	}
	int extractmax(int i)
	{
		return Heap[i];
	}
	void IncKey(int i, int d)
	{
		Heap[i] = d;
		while (i > 1 && Heap[i] > Heap[i / 2])
		{
			swap(Heap[i], Heap[i / 2]);
			i = i / 2;
		}
	}
	void mergeHeap(BinaryHeap h1, BinaryHeap h2)
	{
		int j = 1;
		int k = 1;
		BinaryHeap h3(h1.size + h2.size);
		for (int i = 0; i < (h1.size + h2.size); i++)
		{
			if (i < h1.size)
			{
				h3.Insert(h1.Heap[j]);
				j++;
			}
			else
			{
				h3.Insert(h2.Heap[k]);
				k++;
			}
		}
		h3.print();
	}
};

int main()
{
	BinaryHeap h(10);
	h.Insert(14);
	h.Insert(19); 
	h.Insert(42);
	h.Insert(33);
	h.Insert(26);
	h.Insert(31);
	h.Insert(27);
	h.Insert(44);
	h.Insert(35);
	h.Insert(10);
	cout << "First heap" << endl;
	h.print();
	cout << endl;
	cout << "Maximum value is: " << h.extractmax(2) << endl;
	BinaryHeap h1(10);
	h1.Insert(15);
	h1.Insert(20);
	h1.Insert(43);
	h1.Insert(34);
	h1.Insert(27);
	h1.Insert(32);
	h1.Insert(28);
	h1.Insert(45);
	h1.Insert(36);
	h1.Insert(11);
	cout << "Second heap" << endl;
	h1.print();
	cout << endl;
	BinaryHeap h2;
	cout << "After merge: " << endl;
	h2.mergeHeap(h, h1);
	cout << endl;
	int arr[10] = { 14,19,42,33,26,31,27,44,35,10 };
	HeapSort(arr, 10);
	cout << "Array after heapsort." << endl;
	Print(arr, 10);
	cout << endl;
	return 1;
}