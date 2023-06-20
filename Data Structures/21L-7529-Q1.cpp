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
public:
	SingleList()
	{
		head = tail = nullptr;
	}
	void insertStart(T const d)
	{
		Node* temp = new Node;
		temp->data = d;
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
		}
	}
	void InsertSorted(T const d)
	{
		if (isEmpty() || head->data > d)
		{
			insertStart(d);
			return;
		}
		else
		{
			Node* current;
			current = head;
			while (current->next != nullptr)
			{
				if (current->next->data > d)
				{
					Node* temp = new Node;
					temp->data = d;
					temp->next = current->next;
					current->next = temp;
					return;
				}
				current = current->next;
			}
			insertEnd(d);
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
	void PrintNth(int index)
	{
		Node* current;
		current = head;
		for (int i = 0; i < index; i++)
		{
			current = current->next;
		}
		cout << current->data << endl << endl;
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
	void DeleteatStart()
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
	}
	void DeleteatTail()
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
		}
	}
	void DeleteDuplicate()
	{
		Node* current;
		Node* temp;
		temp = head->next;
		current = head;
		while (temp->next != nullptr)
		{
			if (current->data == temp->data)
			{
				current->next = temp->next;
			}
			current = current->next;
			temp = temp->next;
		}
	}
	~SingleList()
	{
		while (head)
		{
			DeleteatStart();
		}
	}
};


void main()
{
	SingleList<int> linkedlist;

	linkedlist.InsertSorted(4);
	linkedlist.InsertSorted(7);
	linkedlist.InsertSorted(9);
	linkedlist.InsertSorted(2);
	linkedlist.InsertSorted(3);
	linkedlist.InsertSorted(1);

	linkedlist.Print();

	linkedlist.InsertSorted(4);

	linkedlist.PrintNth(3);

	linkedlist.Print();

	linkedlist.DeleteDuplicate();

	linkedlist.Print();

	linkedlist.DeleteatStart();
	linkedlist.DeleteatTail();

	linkedlist.Print();
}