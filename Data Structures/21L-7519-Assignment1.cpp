#include<iostream>
using namespace std;
class Block
{
private:
	int SByteID;
	int TBytes;
public:
	Block()
	{
		SByteID = 0;
		TBytes = 0;
	}
	Block(int i, int s)
	{
		SByteID = i;
		TBytes = s;
	}
	int GetSByteID()
	{
		return SByteID;
	}
	int GetTBytes()
	{
		return TBytes;
	}
	void SetSByteID(int b)
	{
		SByteID = b;
	}
	void SetTBytes(int b)
	{
		TBytes = b;
	}
	bool operator>=(const int& x)
	{
		if (TBytes >= x)
		{
			TBytes = TBytes - x;
			SByteID = SByteID + x;
			return true;
		}
		else
			return false;
	}
	bool operator<(const Block& x)
	{
		if (SByteID < x.SByteID)
			return true;
		return false;
	}
	bool isEmpty()
	{
		if (TBytes == 0)
			return true;
		return false;
	}
	bool operator>(const int& x)
	{
		if (TBytes >= x)
			return true;
		return false;
	}
	Block(const Block& d)
	{
		SByteID = d.SByteID;
		TBytes = d.TBytes;
	}
	Block operator=(const Block& d)
	{
		SByteID = d.SByteID;
		TBytes = d.TBytes;
		return *this;
	}
	bool operator==(const Block& d)
	{
		if (SByteID == d.SByteID && TBytes == d.TBytes)
			return true;
		return false;
	}
	int operator-(int d)
	{
		return TBytes - d;
	}
	friend ostream& operator<<(ostream& out, Block& d);
};
ostream& operator<<(ostream& out, Block& d)
{
	cout << "StartByteID: " << d.SByteID << " TotalBytes: " << d.TBytes << endl;
	return out;
}

template<class T>
class LinkList
{
private:
	class Node
	{
	public:
		Node* next;
		T data;
	};
	Node* head;
	Node* tail;
	int size;
public:
	LinkList()
	{
		head = nullptr;
		tail = nullptr;
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
			Node* temp = new Node;
			temp->data = d;
			temp->next = nullptr;
			tail->next = temp;
			tail = temp;
			size++;
		}
	}
	void Display()
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
	bool Search(T const& d)
	{
		Node* current;
		current = head;
		for (int i=0; i<size; i++)
		{
			if (current->data == d)
				return true;
			else
				current = current->next;
		}
		return false;
	}
	bool FindIT(int S)
	{
		bool flag = false;
		Node* current = head;
		while (current != nullptr)
		{
			if (current->data > S)
			{
				return true;
			}
			current = current->next;
		}
		return false;
	}
	T& FindFirstFit(int S)
	{
		bool flag = false;
		Node* current = head;
		while (current != nullptr)
		{
			if (current->data >= S)
			{
				return current->data;
			}
			current = current->next;
		}
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
		}
		if (head == nullptr)
		{
			tail = nullptr;
		}
		Size--;
	}
	void DeleteAtEnd()
	{
		if (head != nullptr)
		{
			if (head == tail)
			{
				delete head;
				head = tail = nullptr;
				Size--;
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
				Size--;
			}
		}
	}
	void InsertBefore(T const d1, T const d2)
	{
		if (Search(d2))
		{
			Node* current;
			current = head;
			Node* temp = new Node;
			temp->data = d1;
			for (int i = 0; i < Size; i++)
			{
				if (current->next->data == d2)
				{
					temp->next = current->next;
					current->next = temp;
					Size++;
					return;
				}
				else
					current = current->next;
			}
		}
		else
		{
			cout << "Not found" << endl;
		}
	}
	void deleteItem(T& d)
	{
		Node* current;
		current = head;
		if (current->data == d)
		{
			DeleteAtStart();
		}
		else if (tail->data == d)
		{

			DeleteAtEnd();
		}
		if (Search(d))
		{
			for (int i = 0; i < Size; i++)
			{
				if (current->next->data == d)
				{
					Node* temp= new Node;
					temp = current->next;
					current->next = current->next->next;
					delete temp;
					Size--;
					return;
				}
				else
					current = current->next;
			}
		}
		else
		{
			cout << "Not found" << endl;
		}
	}
	LinkList(const LinkList<T>& d)
	{
		head = tail = nullptr;
		size = 0;
		Node* current = d.head;
		while (current != nullptr)
		{
			this->insertEnd(current->data);
			current = current->next;
		}
	}
	LinkList<T> operator=(const LinkList<T>& d)
	{
		while (head)
		{
			DeleteAtStart();
		}
		Node* current = d.head;
		while (current != nullptr)
		{
			this->insertEnd(current->data);
			current = current->next;
		}
		return *this;
	}
	T GetData()
	{
		Node* temp = head;
		return temp->data;
	}
	void Update(T& d)
	{
		if (Search(d))
		{
			Node* current = head;
			while (current != nullptr)
			{
				if (current->data == d)
				{
					current->data = current->data * 2;
				}
				current = current->next;
			}
		}
		else
		{
			cout << "Not Found." << endl;
		}
	}
	void UpdateParameter(T& d)
	{
		if (Search(d))
		{
			Node* current = head;
			while (current != nullptr)
			{
				if (current->data == d)
				{
					d = current->data;
				}
				current = current->next;
			}
		}
		else
		{
			cout << "Not Found." << endl;
		}
	}
	~LinkList()
	{
		while (head)
		{
			DeleteAtStart();
		}
	}
};

class Program
{
private:
	int ID;
	int size;
	LinkList <Block> list;
public:
	Program()
	{
		ID = 0;
		size = 0;
	}
	Program(int i, int s, LinkList<Block>& d)
	{
		ID = i;
		size = s;
		list = d;
	}
	Program(const Program& d)
	{
		ID = d.ID;
		size = d.size;
		list = d.list;
	}
	void SetID(int d)
	{
		ID = d;
	}
	void SetSize(int d)
	{
		size = d;
	}
	void SetBlock(Block& d)
	{
		list.insertEnd(d);
	}
	LinkList<Block>& GetList()
	{
		return list;
	}
	Program& operator=(const Program& d)
	{
		ID = d.ID;
		size = d.size;
		list = d.list;
		return *this;
	}
	void InsertElement(Block& d)
	{
		size = size + d.GetTBytes();
		list.insertEnd(d);
	}
	bool operator==(const int& i)
	{
		if (ID == i)
			return true;
		else
			return false;
	}
	void deallocate()
	{
		while (list.isEmpty() != true)
		{
			list.DeleteAtStart();
		}
	}
	bool operator==(const Program& i)
	{
		if (ID == i.ID)
			return true;
		else
			return false;
	}
	bool operator>=(const Program& i)
	{
		if (ID >= i.ID)
			return true;
		return false;
	}
	friend ostream& operator<<(ostream& out, Program& p);
};
ostream& operator<<(ostream& out, Program& p)
{
	cout << "ID: " << p.ID << endl;
	cout << "Space: " << p.size << endl;
	p.list.Display();
	return out;
}
class MemoryManagementSystem
{
private:
	LinkList<Block> Pool;
	LinkList<Program> Programs;
	int sizeOfMemory;
	bool Strategy;
public:
	MemoryManagementSystem(int m, int s)
	{
		sizeOfMemory = m;
		Strategy = s;
		Block b(0, sizeOfMemory);
		Pool.insertEnd(b);
	}
	void Display()
	{
		cout << "Pool: " << endl;
		Pool.Display();
		cout << "Programs:" << endl;
		Programs.Display();
	}
	LinkList<Block> GetPool()
	{
		return Pool;
	}
};
int main()
{
	system("pause");
	return 0;
}