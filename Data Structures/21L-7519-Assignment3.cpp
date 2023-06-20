#include <iostream>
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
	void Deleteall()
	{
		while (head)
		{
			DeleteatStart();
		}
	}
	~SingleList()
	{
		while (head)
		{
			DeleteatStart();
		}
	}
	SingleList<T> operator=(const SingleList<T>& obj)
	{
		Deleteall();
		Node* temp = obj.head;
		while (temp)
		{
			this->insertEnd(temp->data);
			temp = temp->next;
		}
		return *this;
	}
};



template<class T>
class DoubleNode
{
public:
	T data;
	DoubleNode* next;
	DoubleNode* prev;
};
template<class T>
class DoubleList
{
private:
	DoubleNode<T>* head;
	DoubleNode<T>* tail;
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
		DoubleNode<T>* temp = new DoubleNode;
		temp->data = d;
		temp->prev = head;
		temp->next = head->next;
		head->next->prev = temp;
		head->next = temp;
	}
	void InsertatEnd(T const d)
	{
		DoubleNode<T>* temp = new DoubleNode;
		temp->data = d;
		temp->next = tail;
		temp->prev = tail->prev;
		tail->prev->next = temp;
		tail->prev = temp;
	}
	void InsertBehind(DoubleNode<T>* obj, const T& d)
	{
		DoubleNode<T>* temp = new DoubleNode<T>;
		DoubleNode<T>* t = obj;
		temp->data = d;
		temp->next = t;
		temp->prev = t->prev;
		t->next->prev = temp;
		t->next = temp;
	}

	bool Search(int& obj)
	{
		DoubleNode<T>* temp = head;
		if (head == nullptr)
			return false;
		while (temp != nullptr)
		{
			if (temp->data == obj)
				return true;
			temp = temp->next;
		}
		retun false;
	}
	bool PrintNode(int& obj)
	{
		if (Search(obj))
		{
			cout << curr->Data << endl;
			return true;
		}
		else
		{
			cout << "The element was not found\n\n";
			return false;
		}
	}
	void Print()const
	{
		DoubleNode<T>* current;
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
		DoubleNode<T>* current;
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
			DoubleNode<T>* temp = head->next;
			temp->prev->next = head;
			head->next = temp->next;
			delete temp;
		}
	}
	void DeleteatEnd()
	{
		if (head->next != tail)
		{
			DoubleNode<T>* temp = tail->prev;
			temp->prev->next = tail;
			tail->prev = temp->prev;
			delete temp;
		}
	}
	bool DeleteNode(int obj)
	{
		if (Search(obj))
		{
			DoubleNode<T>* temp = head;
			while (curr->Data != obj)
			{
				temp = temp->Next;
			}
			temp->Prev->Next = temp->Next;
			temp->Next->Prev = temp->Prev;
			delete curr;
			return true;
		}
		else
		{
			cout << "The element was not found" << endl;
			return false;
		}
	}
	void swapNodes(int n)
	{
		DoubleNode<T>* endp = tail;
		DoubleNode<T>* startp = head;
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
	void SortedInsert(cost T& obj, )
	{
		if (isEmpty() || head->data > d)
		{
			InsertatHead(d);
			return; 
		}
		else
		{
			DoubleNode<T>* current;
			current = head;
			while (current->next != nullptr)
			{
				if (current->next->data > d)
				{
					DoubleNode<T>* temp = new Node;
					temp->data = d;
					temp->next = current->next;
					current->next = temp;
					return;
				}
				current = current->next;
			}
			InsertatEnd(d);
		}
	}
	~DoubleList()
	{
		while (head)
		{
			DeleteatStart();
		}
	}
};


template <class T>
class Avltree
{
	class Avlnode
	{
	public:
		T data;
		Avlnode* left;
		Avlnode* right;
		int height;

		Avlnode(T d, Avlnode* l, Avlnode* r, int h)
		{
			data = d;
			left = l;
			right = r;
			height = h;
		}
	};
	Avlnode* root;
public:
	Avltree()
	{
		root = nullptr;
	}
	int heightgetter(Avlnode* r)
	{
		if (r == nullptr)
			return -1;
		else
			return r->height;
	}
	int balanceFactor(Avlnode* r)
	{
		return (heightgetter(r->left) - heightgetter(r->right));
	}
	void RotateLeft(Avlnode*& X)
	{
		Avlnode* Y = X->right;
		X->right = Y->left;
		Y->left = X;
		X->height = 1 + max(heightgetter(X->left), heightgetter(X->right));
		Y->height = 1 + max(heightgetter(X->left), heightgetter(Y->right));
		X = Y;
	}
	void RotateRight(Avlnode*& X)
	{
		Avlnode* Y = X->left;
		X->left = Y->right;
		Y->right = X;
		X->height = 1 + max(heightgetter(X->left), heightgetter(X->right));
		Y->height = 1 + max(heightgetter(X->left), heightgetter(Y->right));
		X = Y;
	}
	void RotateLeftLeft(Avlnode*& X)
	{
		RotateRight(X->right);
		RotateLeft(X);
	}
	void RotateRightRight(Avlnode*& X)
	{
		RotateLeft(X->left);
		RotateRight(X);
	}
	int max(int h1, int h2)
	{
		if (h1 > h2)
			return h1;
		return h2;
	}
	void Insert(Avlnode*& r, T d)
	{
		if (r == nullptr)
			r = new Avlnode(d, nullptr, nullptr, 0);
		else
		{
			if (d < r->data)
			{
				Insert(r->left, d);
				if (heightgetter(r->left) - heightgetter(r->right) == 2)
				{
					if (d < r->left->data)
						RotateRight(r);
					else
						RotateRightRight(r);
				}
			}
			else if (d > r->data)
			{
				Insert(r->right, d);
				if (heightgetter(r->left) - heightgetter(r->right) == -2)
				{
					if (d > r->right->data)
						RotateLeft(r);
					else
						RotateLeftLeft(r);
				}
			}
		}
		r->height = 1 + max(heightgetter(r->left), heightgetter(r->right));
	}
	void Insert(T d)
	{
		Insert(root, d);
	}
	void Printinorder(Avlnode* curr)
	{
		if (curr != nullptr)
		{
			Printinorder(curr->left);
			cout << curr->data << " ";
			Printinorder(curr->right);
		}
	}
	void Printinorder()
	{
		Printinorder(root);
		cout << endl;
	}
	void deleteNode(Avlnode* curr, T key)
	{
		if (curr->data == key)
		{
			if (curr->left == nullptr && curr->right == nullptr)
			{
				Avlnode* temp = curr;
				curr = nullptr;
				delete temp;
			}
			else if (curr->right == nullptr && curr->left != nullptr)
			{
				Avlnode* temp = curr;
				curr = curr->left;
				delete temp;
			}
			else if (curr->left == nullptr && curr->right != nullptr)
			{
				Avlnode* temp = curr;
				curr = curr->right;
				delete temp;
			}
			else
			{
				Avlnode* k = curr->left;
				Avlnode* prev = nullptr;
				while (k->right != nullptr)
				{
					prev = k;
					k = k->right;
				}
				if (prev == nullptr)
				{
					curr->left = nullptr;
					curr->data = k->data;
					delete k;
				}
				else
				{
					curr->data = k->data;
					prev->right = nullptr;
					delete k;
				}
			}
			return;
		}
		else if (curr->data < key)
		{
			deleteNode(curr->right, key);
		}
		else if (curr->data > key)
		{
			deleteNode(curr->left, key);
		}
		curr->height = 1 + max(heightgetter(curr->left), heightgetter(curr->right));
		if (balanceFactor(curr) == -2)
		{
			if (balanceFactor(curr->right) <= -1)
			{
				RotateLeft(curr);
			}
			else
			{
				RotateRight(curr->right);
				RotateLeft(curr);
			}
		}
		else if (balanceFactor(curr) == 2)
		{
			if (balanceFactor(curr->left) >= 1)
			{
				RotateRight(curr);
			}
			else
			{
				RotateLeft(curr->left);
				RotateRight(curr);
			}
		}
	}
	void deleteNode(T d)
	{
		if (root != nullptr)
			deleteNode(root, d);
	}
};


class Book
{
private:
	int ISSN;
	string Title;
	SingleList<string> Authors;
	int Total_Refrence;
	int Total_Issuable;
public:
	Book(int issn, string title, SingleList<string> authors, int t_ref, int t_issue)
	{
		ISSN = issn;
		Title = title;
		Authors = authors;
		Total_Refrence = t_ref;
		Total_Issuable = t_issue;
	}
	Book(Book& temp)
	{
		ISSN = temp.ISSN;
		Title = temp.Title;
		Authors = temp.Authors;
		Total_Refrence = temp.Total_Refrence;
		Total_Issuable = temp.Total_Issuable;
	}
	Book operator=(const Book& temp)
	{
		ISSN = temp.ISSN;
		Title = temp.Title;
		Authors = temp.Authors;
		Total_Refrence = temp.Total_Refrence;
		Total_Issuable = temp.Total_Issuable;
		return *this;
	}
	bool operator!=(int temp)
	{
		if (ISSN != temp)
			return true;
		return false;
	}
	bool operator==(int temp)
	{
		if (ISSN == temp)
			return true;
		return false;
	}
	bool operator==(const Book& temp)
	{
		if (ISSN == temp.ISSN)
			return true;
		return false;
	} 
	bool operator<(const Book& temp)
	{
		if (ISSN <= temp.ISSN) {
			return true;
		}
		else
			return false;
	}
	bool operator>(const Book& temp)
	{
		if (ISSN >= temp.ISSN) {
			return true;
		}
		else
			return false;
	}
	bool operator<(const int& temp)
	{
		if (ISSN <= temp) {
			return true;
		}
		else
			return false;
	}
	bool operator>(const int& temp)
	{
		if (ISSN >= temp) {
			return true;
		}
		else
			return false;
	}
	friend ostream& operator<<(ostream& out, Book& obj);
};
ostream& operator<<(ostream& out, Book& obj)
{
	cout << "ISSN: " << obj.ISSN << endl;
	cout << "Title: " << obj.Title << endl;
	cout << "Authors: "<< endl;
	cout << "Total number of copies available as refrenece books are: " << obj.Total_Refrence << endl;
	cout << "Total number of copies available as issuable books are: " << obj.Total_Issuable << endl;
}

class Index
{
private:
	int ISSN;
	DoubleNode<Book>* obj;
public:
	Index()
	{
		obj = nullptr;
	}
	Index(DoubleNode<Book>*& Obj, int issn)
	{
		ISSN = issn;
		obj = Obj;
	}
	Index(Index& temp)
	{
		ISSN = temp.ISSN;
		obj = temp.obj;
	}
	Index operator=(const Index& temp)
	{
		ISSN = temp.ISSN;
		obj = temp.obj;
		return *this;
	}
	bool operator!=(int temp)
	{
		if (ISSN != temp)
			return true;
		return false;
	}
	bool operator==(int temp)
	{
		if (ISSN == temp)
			return true;
		return false;
	}
	bool operator==(const Index& temp)
	{
		if (ISSN == temp.ISSN)
			return true;
		return false;
	}
	bool operator<(const Index& temp)
	{
		if (ISSN <= temp.ISSN) {
			return true;
		}
		else
			return false;
	}
	bool operator>(const Index& temp)
	{
		if (ISSN >= temp.ISSN) {
			return true;
		}
		else
			return false;
	}
	bool operator<(const int& temp)
	{
		if (ISSN <= temp) {
			return true;
		}
		else
			return false;
	}
	bool operator>(const int& temp)
	{
		if (ISSN >= temp) {
			return true;
		}
		else
			return false;
	}
	friend ostream& operator<<(ostream& out, Index& obj);
};
ostream& operator<<(ostream& out, Index& obj)
{
	cout << obj.ISSN << " ";
	return out;
}

int main()
{
	Avltree<Index> AvlISSN;
	DoubleList<Book> Books;

	system("pause");
	return 0;
}