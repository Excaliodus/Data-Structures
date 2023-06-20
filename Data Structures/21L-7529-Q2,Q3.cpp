#include <iostream>;
using namespace std;

template<class T>
class DoubleList
{
private:
	class DoubleNode
	{
	public:
		T data;
		DoubleNode* next;
		DoubleNode* prev;
	};
	DoubleNode* head;
	DoubleNode* tail;
public:
	DoubleList()
	{
		head = new DoubleNode;
		tail = new DoubleNode;
		head->next = tail;
		head->prev = nullptr;
		tail->next = nullptr;
		tail->prev = head;
	}
	void InsertatHead(T const d)
	{
		DoubleNode* temp = new DoubleNode;
		temp->data = d;
		temp->prev = head;
		temp->next = head->next;
		head->next->prev = temp;
		head->next = temp;
	}
	void InsertatEnd(T const d)
	{
		DoubleNode* temp = new DoubleNode;
		temp->data = d;
		temp->next = tail;
		temp->prev = tail->prev;
		tail->prev->next = temp;
		tail->prev = temp;
	}
	void Print()const
	{
		DoubleNode* current;
		current = head->next;
		while (current->next != nullptr)
		{
			cout << current->data << endl;
			current = current->next;
		}
		cout << endl;
	}
	void PrintReverse()const
	{
		DoubleNode* current;
		current = tail->prev;
		while (current->prev != nullptr)
		{
			cout << current->data << endl;
			current = current->prev;
		}
		cout << endl;
	}
	void DeleteatStart()

	{
		if (head->next != tail)
		{
			DoubleNode* temp = head->next;
			temp->prev->next = head;
			head->next = temp->next;
			delete temp;
		}
	}
	void DeleteatEnd()
	{
		if (head->next != tail)
		{
			DoubleNode* temp = tail->prev;
			temp->prev->next = tail;
			tail->prev = temp->prev;
			delete temp;
		}
	}
	void swapNodes(int n)
	{
		DoubleNode* endp = tail;
		DoubleNode* startp = head;
		for (int i = 0; i < n; i++)
		{
			startp = startp->next;
			endp = endp->prev;
		}
		T temp;
		temp = startp->data;
		startp->data = endp->data;
		endp->data = temp;
	}
	~DoubleList()
	{
		while (head)
		{
			DeleteatStart();
		}
	}
};

int main()
{
	DoubleList<int> linkedlist;

	linkedlist.InsertatHead(4);
	linkedlist.InsertatHead(7);
	linkedlist.InsertatHead(9);
	linkedlist.InsertatEnd(2);
	linkedlist.InsertatHead(3);
	linkedlist.InsertatHead(7);
	linkedlist.InsertatHead(1);

	linkedlist.Print();

	linkedlist.PrintReverse();

	linkedlist.DeleteatStart();
	linkedlist.DeleteatEnd();

	linkedlist.Print();

	linkedlist.swapNodes(1);

	linkedlist.Print();

	return 1;
}