#include <iostream>
using namespace std;

template <class T>
class CircularList
{
	class Node
	{
	public:
		T data;
		Node* next;
	};
	Node* tail;
public:
	CircularList()
	{
		tail = nullptr;
	}
	bool NotNull()
	{
		if (tail)
		{
			return true;
		}
		return false;
	}
	void InsertAtStart(T d)
	{
		Node* temp = new Node;
		temp->data = d;
		if (NotNull())
		{
			temp->next = tail->next;
			tail->next = temp;
		}
		else
		{
			temp->next = temp;
			tail = temp;
		}
	}
	void InsertAtEnd(T d)
	{
		Node* temp = new Node;
		temp->data = d;
		if (NotNull())
		{
			temp->next = tail->next;
			tail->next = temp;
			tail = temp;
		}
		else
		{
			temp->next = temp;
			tail = temp;
		}
	}
	void InsertAtNth(int index, T d)
	{
		Node* temp = new Node;
		temp->data = d;
		if (index == 0 || !NotNull())
		{
			InsertAtStart(d);
		}
		else if (index >= (Length() - 1))
		{
			InsertAtEnd(d);
		}
		else
		{
			Node* current = tail;
			for (int i = 0; i < index; i++)
			{
				current = current->next;
			}
			temp->next = current->next;
			current->next = temp;
		}
	}
	void Print()
	{
		if (NotNull())
		{
			Node* current = tail->next;
			cout << current->data << " ";
			current = current->next;
			while (current != tail->next)
			{
				cout << current->data << " ";
				current = current->next;
			}
			cout << endl;
		}
	}
	int Length()
	{
		int count = 0;
		if (NotNull())
		{
			Node* current = tail->next;
			count++;
			current = current->next;
			while (current != tail->next)
			{
				count++;
				current = current->next;
			}
			return count;
		}
		else
		{
			return 0;
		}
	}
	void Rotate()
	{
		tail = tail->next;
	}
	void LatinForm()
	{
		Node* current;
		current = tail->next;
		if (tail->next->data == 'a' || tail->next->data == 'e' || tail->next->data == 'i' || tail->next->data == 'o' || tail->next->data == 'u')
		{
			InsertAtEnd('-');
			InsertAtEnd('w');
			InsertAtEnd('a');
			InsertAtEnd('y');
		}
		else
		{
			InsertAtEnd('-');
			while (tail->next->data != 'a' && tail->next->data != 'e' && tail->next->data != 'i' && tail->next->data != 'o' && tail->next->data != 'u')
			{
				if (tail->next != current)
				{
					Rotate();
				}
				else
				{
					Rotate();
					while (tail->next->data != 'y')
					{
						if (tail->next != current)
						{
							Rotate();
						}
						else
						{
							InsertAtEnd('w');
							InsertAtEnd('a');
							InsertAtEnd('y');
							return;
						}
					}
					InsertAtEnd('a');
					InsertAtEnd('y');
					return;
				}
			}
			InsertAtEnd('a');
			InsertAtEnd('y');
		}
	}
	bool Search(T const& d)
	{
		if (NotNull())
		{
			Node* current;
			current = tail->next;
			if (current->data == d)
			{
				return true;
			}
			else
			{
				current = current->next;
				while (current != tail->next)
				{
					if (current->data == d)
					{
						return true;
					}
					else
					{
						current = current->next;
					}
				}
			}
		}
		return false;
	}
	void DeleteAtStart()
	{
		if (NotNull())
		{
			Node* temp = tail->next;
			tail->next = temp->next;
			delete temp;
		}
	}
	void DeleteAtNth(int index)
	{
		if (!NotNull())
		{
			cout << "List is empty already.Nothing to delete." << endl;
		}
		else if (index == 0)
		{
			DeleteAtStart();
		}
		else if (index >= (Length() - 1))
		{
			DeleteAtEnd();
		}
		else
		{
			Node* current = tail;
			Node* temp = tail->next;
			for (int i = 0; i < index; i++)
			{
				current = current->next;
				temp = temp->next;
			}
			current->next = temp->next;
			delete temp;
		}
	}
	void DeleteAtEnd()
	{
		if (NotNull())
		{
			Node* curr = tail->next;
			while (curr->next != tail)
			{
				curr = curr->next;
			}
			curr->next = tail->next;
			delete tail;
			tail = curr;
		}
	}
	void CopyConcatinate(CircularList<T>& obj)
	{
		if (obj.NotNull())
		{
			Node* curr = obj.tail->next;
			while (curr != obj.tail)
			{
				InsertAtEnd(curr->data);
				curr = curr->next;
			}
			InsertAtEnd(curr->data);
		}
	}
	CircularList CopyDuplicate()
	{
		if (NotNull())
		{
			CircularList<T> List;
			Node* current = tail->next;
			List.InsertAtEnd(current->data);
			current = current->next;
			while (current != tail->next)
			{
				List.InsertAtEnd(current->data);
				current = current->next;
			}
			return List;
		}
		return NULL;
	}
	~CircularList()
	{
		if (NotNull())
		{
			Node* current = tail->next;
			while (current != tail)
			{
				DeleteAtEnd();
				current = current->next;
			}
			delete tail;
		}
	}
};

	void main()
	{
		CircularList<int> linkedlist;

		linkedlist.InsertAtStart(4);
		linkedlist.InsertAtStart(7);
		linkedlist.InsertAtStart(9);
		linkedlist.InsertAtStart(2);
		linkedlist.InsertAtStart(3);
		linkedlist.InsertAtStart(1);
		linkedlist.InsertAtNth(3, 5);

		linkedlist.Print();

		linkedlist.DeleteAtNth(3);

		linkedlist.Print();

		linkedlist.DeleteAtStart();
		linkedlist.DeleteAtEnd();

		linkedlist.Print();

		if (linkedlist.Search(7))
			cout << "Element found." << endl;
		else
			cout << "Element not found." << endl;

		cout << linkedlist.Length() << endl << endl;

		CircularList<char> Latin;

		Latin.InsertAtStart('y');
		Latin.InsertAtStart('b');

		Latin.LatinForm();

		Latin.Print();

	}