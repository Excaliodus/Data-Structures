#include <iostream>;
using namespace std;

template<class T>
class SingleList
{
private:
	class Node
	{
	public:
		T data;
		Node* next;
	};
	Node* head;
	Node* tail;
	int size;
public:
	SingleList()
	{
		head = tail = nullptr;
		size = 0;
	}
	void insertStart(T const d)
	{
		Node* temp = new Node;
		temp->data = d;
		size++;
		temp->next = head;
		if (isEmpty())
		{
			head = tail = temp;
		}
		else
			head = temp;
	}
	void insertEnd(T const d)
	{
		if (isEmpty())
		{
			insertStart(d);
		}
		else
		{
			size++;
			Node* temp = new Node;
			temp->data = d;
			temp->next = nullptr;
			tail->next = temp;
			tail = temp;
		}
	}
	void Print()const
	{
		Node* current;
		current = head;
		while (current != nullptr)
		{
			cout << current->data << endl;
			current = current->next;
		}
		cout << endl;
	}
	bool Search(T const& d)const
	{
		Node* current;
		current = head;
		while (current != nullptr)
		{
			if (current->data == d)
				return true;
			else
				current = current->next;
		}
		return false;
	}
	bool isEmpty()const
	{
		if (head == nullptr)
			return true;
		return false;
	}
	void DeleteAtStart()
	{
		if (head != nullptr)
		{
			Node* temp = head;
			head = head->next;
			delete temp;
			size--;
		}
		if (head == nullptr)
		{
			tail = nullptr;
		}
	}
	void DeleteAtEnd()
	{
		if (head != nullptr)
		{
			if (head == tail)
			{
				delete head;
				head = tail = nullptr;
			}
			else
			{
				Node* temp = head;
				while (temp->next != tail)
				{
					temp = temp->next;
				}
				delete tail;
				tail = temp;
				tail->next = nullptr;
			}
			size--;
		}
	}
	~SingleList()
	{
		while (head)
		{
			DeleteAtStart();
		}
	}
};

template<class T>
class Queue
{
	friend class SingleList<T>;
private:
	SingleList<T> List;
	int maxsize;
public:
	Queue(int m = 10)
	{
		maxsize = m;
	}
	bool isFull()
	{
		if (List.size == maxsize)
		{
			return true;
		}
		return false;
	}
	bool isEmpty() {
		if (List.size == 0)
			return true;
		return false;
	}
	void Enqueue(T d)
	{
		if (!isFull())
		{
			List.insertEnd(d);
		}
	}
	void Dequeue() {
		if (!isEmpty())
		{
			List.DeleteAtStart();
		}
	}
	T Front() {
		if (!List.isEmpty())
		{
			return List.head->data;
		}
	}
	void Print()
	{
		List.Print();
	}
	T Rear()
	{
		if (!List.isEmpty())
		{
			return List.tail->data;
		}
	}
};

template<class T>
class ArrayQueue
{
private:
	T* QArray;
	int maxsize;
	int size;
	int front;
	int rear;
public:
	ArrayQueue(int d) 
	{
		maxsize = d;
		size = 0;
		QArray = new T[maxsize];
		front = -1;
		rear = 0;
	}
	bool isFull()
	{
		if (size == maxsize)
		{
			return true;
		}
		return false;
	}
	bool isEmpty()
	{
		if (size == 0)
		{
			return true;
		}
		return false;
	}
	bool Enqueue(T d)
	{
		if (!isFull()) 
		{
			QArray[rear] = d;
			rear++;
			size++;
			return true;
		}
		return false;
	}
	bool Dequeue(T& d)
	{
		if (!isEmpty())
		{
			front++;
			d = QArray[front % maxsize];
			size--;
			return true;
		}
		return false;
	}
	void Print()
	{
		for (int i = 0; i < size; i++)
		{
			cout << QArray[i] << " ";
		}
		cout << endl;
	}
	void ArrangeAlternate()
	{
		int current = size / 2;
		T* temp = new int[size];
		int count = 0;
		for (int i = 0; i < size / 2; i++)
		{
			temp[count] = QArray[i];
			count++;
			temp[count] = QArray[current + i];
			count++;
		}
		for (int k = 0; k < size; k++)
		{
			QArray[k] = temp[k];
		}
	}
};
int main()
{
	system("pause");
	return 0;
}