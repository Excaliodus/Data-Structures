#include<iostream>
using namespace std;
class Block
{
private:
	int start_Byte_ID;
	int total_bytes;
public:
	Block()
	{
		start_Byte_ID = 0;
		total_bytes = 0;
	}
	Block(int i, int s)//parameterised constructor
	{
		start_Byte_ID = i;
		total_bytes = s;
	}
	//getter setters
	int GetStart()
	{
		return start_Byte_ID;
	}
	int GetTotal()
	{
		return total_bytes;
	}
	void SetStart(int obj)
	{
		start_Byte_ID = obj;
	}
	void SetTotal(int obj)
	{
		total_bytes = obj;
	}

	bool operator>=(const int& i)//removing chunk of memory required from pool if available
	{
		if (this->total_bytes >= i) {
			this->total_bytes -= i;
			this->start_Byte_ID += i;
			return true;
		}
		else
			return false;
	}
	bool operator<(const Block& i)//comparing start id of two blocks
	{
		if (this->start_Byte_ID < i.start_Byte_ID) {
			return true;
		}
		else
			return false;
	}
	bool isEmpty()
	{
		if (total_bytes == 0)
			return true;
		return false;
	}
	bool operator>(const int& i)//comparing total bytes
	{
		if (this->total_bytes >= i) {
			return true;
		}
		else
			return false;
	}
	Block(const Block& obj)//copy constructor
	{
		start_Byte_ID = obj.start_Byte_ID;
		total_bytes = obj.total_bytes;
	}
	Block operator=(const Block& obj)//assignment operator
	{

		start_Byte_ID = obj.start_Byte_ID;
		total_bytes = obj.total_bytes;
		return *this;
	}
	bool operator==(const Block& obj)//if equal
	{
		if (start_Byte_ID == obj.start_Byte_ID && total_bytes == obj.total_bytes)
			return true;
		return false;
	}
	int operator-(int obj)//subtracting total bytes
	{
		return total_bytes - obj;
	}
	void merge(Block& obj)
	{
		start_Byte_ID = start_Byte_ID - obj.total_bytes;
		total_bytes += obj.total_bytes;
	}
	bool operator&(Block& obj)//operator for merging
	{
		if (obj.start_Byte_ID + obj.total_bytes == start_Byte_ID)
		{
			this->merge(obj);
			return true;
		}
		return false;
	}
	friend ostream& operator<<(ostream& out, Block& d);//display
};
ostream& operator<<(ostream& out, Block& d)
{

	cout << d.start_Byte_ID << " - " << d.total_bytes << endl;
	return out;
}



template<class T>
class LinkList
{

private:
	class Node
	{
	public:
		Node* Next;
		T Data;
	};
	Node* Head;
	Node* Tail;
	int Size;
public:
	LinkList()
	{
		Head = nullptr;
		Tail = nullptr;
		Size = 0;
	}

	void InsertAtStart(const T& obj)
	{

		Node* temp = new Node;
		temp->Data = obj;
		Size += 1;
		temp->Next = nullptr;
		if (Head == nullptr && Tail == Head)
		{
			Head = Tail = temp;
			Head->Next = nullptr;
		}

		else {
			temp->Next = Head;
			Head = temp;
		}

	}
	void InsertAtEnd(const T& obj)
	{
		if (Head == nullptr && Tail == Head)
			InsertAtStart(obj);
		else
		{
			Node* temp = new Node;
			temp->Data = obj;
			Size += 1;
			temp->Next = nullptr;
			Tail->Next = temp;
			Tail = temp;
		}
	}

	void Display()
	{
		if (Head != nullptr) {
			Node* curr = Head;
			for (int i = 0; i < Size; i++) {
				cout << curr->Data;
				curr = curr->Next;
			}
			cout << endl;
		}

	}

	bool Search(T const& obj)
	{
		Node* curr = Head;

		for (int i = 0; i < Size; i++)
		{
			if (curr->Data == obj)
				return true;
			curr = curr->Next;
		}
		return false;
	}
	bool FindIT(int S)//memory available??
	{
		bool flag = false;
		Node* curr = Head;

		while (curr != nullptr)
		{
			if (curr->Data > S)
			{

				return true;
			}
			curr = curr->Next;
		}
		return false;
	}
	T& FindFirstFit(int S)//finding the first chunk and returning it after updating pool
	{
		bool flag = false;
		Node* curr = Head;

		while (curr != nullptr)
		{
			if (curr->Data >= S)
			{

				return curr->Data;
			}
			curr = curr->Next;
		}
	}

	T FindBestFit(int S)//finding the best chunk and returning it after updating pool
	{
		bool flag = false;
		Node* curr = Head;
		int diff = 99999;
		while (curr != nullptr)
		{
			if (curr->Data > S)
			{
				if (diff > curr->Data - S)
					diff = curr->Data - S;
			}
			curr = curr->Next;
		}
		curr = Head;
		while (curr != nullptr)
		{
			if (diff == curr->Data - S)
			{
				flag = curr->Data >= S;
				return curr->Data;
			}
			curr = curr->Next;
		}


	}
	bool isEmpty()
	{
		Node* curr = Head;
		if (Head == nullptr)
			return true;
		return false;
	}
	void DeleteAtStart()
	{
		if (Head != nullptr)
		{
			Node* temp = Head;
			Head = Head->Next;
			temp->Next = nullptr;
			delete temp;
			if (Head == nullptr)
				Tail = nullptr;
			Size--;
		}
	}
	void DeleteAtEnd()
	{
		if (Head != nullptr)
		{
			if (Head == Tail)
			{
				DeleteAtStart();
			}
			else {
				Node* curr = Head;
				while (curr->Next != Tail)
				{
					curr = curr->Next;
				}
				delete Tail;
				Tail = curr;
				curr->Next = nullptr;
				Size--;
			}

		}
	}

	void InsertBefore(T const v1, T const v2)//Element v1 is inserted before element v2 in the list
	{
		if (Head != nullptr)
		{
			if (Head->Data == v2)
			{
				InsertAtStart(v1);
			}
			else {
				Node* curr = Head->Next;
				Node* Prev = Head;
				Node* Temp = new Node;
				bool val = false;
				while (val != true)
				{
					if (curr->Data == v2)
					{
						Size += 1;
						Temp->Data = v1;
						Prev->Next = Temp;
						Temp->Next = curr;
						val = true;

					}
					Prev = curr;
					curr = curr->Next;
					if (curr == nullptr)
					{
						val = true;

					}
				}
			}
		}
	}
	void deleteItem(T& obj)//item is searched in the list and deleted if found
	{

		Node* curr = Head;
		Node* prev;
		if (curr->Data == obj)
		{
			DeleteAtStart();
		}
		else if (Tail->Data == obj)
		{

			DeleteAtEnd();
		}
		else {
			prev = curr;
			curr = curr->Next;
			bool flag = false;
			while (flag == false)
			{

				if (curr->Data == obj)
				{
					prev->Next = curr->Next;
					flag = true;
					delete curr;
					Size--;
				}
				else {
					prev = prev->Next;
					curr = curr->Next;
				}


			}
		}
	}
	LinkList(const LinkList<T>& obj)//copy constructor
	{
		Head = Tail = nullptr;
		Size = 0;

		Node* curr = obj.Head;
		while (curr != nullptr)
		{
			this->InsertAtEnd(curr->Data);
			curr = curr->Next;
		}
	}


	LinkList<T> operator=(const LinkList<T>& obj)//assignment operator
	{
		while (Head)
		{
			DeleteAtStart();
		}
		Node* curr = obj.Head;
		while (curr != nullptr)
		{
			this->InsertAtEnd(curr->Data);
			curr = curr->Next;
		}
		return *this;
	}

	T GetData()//getter
	{
		Node* temp = Head;
		return temp->Data;
	}
	void Update(T& obj)//updating data in current list
	{
		Node* curr = Head;
		while (curr != nullptr)
		{
			if (curr->Data == obj)
			{
				curr->Data += obj;
			}
			curr = curr->Next;
		}
	}
	void UpdateParameter(T& obj)//updates the paremeter if its ID is available in list
	{
		Node* curr = Head;
		while (curr != nullptr)
		{
			if (curr->Data == obj)
			{
				obj = curr->Data;
			}
			curr = curr->Next;
		}
	}

	void merge(LinkList<T>& obj)//merge two lists
	{
		Node* curr = Head;
		Node* temp = obj.Head;
		bool flag = false;
		for (int i = 0; i < obj.Size; i++) {
			for (int y = 0; y < Size; y++)
			{

				if (temp->Data < curr->Data)
				{

					this->InsertBefore(temp->Data, curr->Data);
					flag = true;


				}

				if (flag == true)
				{
					y = Size;
				}

				curr = curr->Next;
			}
			if (flag = false) {
				this->InsertAtEnd(temp->Data);
				flag = true;
			}
			temp = temp->Next;
			curr = Head;
		}
	}
	void CombineData()//combines two consecutive node datas
	{

		Node* temp = Head;
		Node* temp2 = temp->Next;
		bool flag = true;
		while (flag == true)
		{
			if (temp2->Data & temp->Data) {
				this->DeleteAtStart();

				temp = temp2;
				temp2 = temp2->Next;
			}
			else {
				flag = false;
			}
			if (temp2 == nullptr)
			{
				flag = false;
			}
		}



		while (temp2 != nullptr)
		{
			if (temp2->Data & temp->Data)
			{
				this->deleteItem(temp->Data);

			}

			temp = temp2;
			temp2 = temp2->Next;



		}


	}


	~LinkList()//destructor
	{
		while (Head)
		{
			DeleteAtStart();
		}
	}
};

class Prog
{

private:
	int ID;
	int size;
	LinkList <Block> list;
public:
	Prog()
	{
		ID = 0;
		size = 0;
	}
	Prog(int i, int s, LinkList<Block>& obj)//parametised constructor
	{
		ID = i;
		size = s;
		list = obj;
	}
	Prog(const Prog& obj)//copy constructor
	{
		ID = obj.ID;
		size = obj.size;
		list = obj.list;
	}
	//setters
	void SetID(int obj)
	{
		ID = obj;
	}
	void SetSize(int obj)
	{
		size = obj;
	}
	void SetBlock(Block& obj)
	{
		list.InsertAtEnd(obj);
	}
	LinkList<Block>& GetList()//getter
	{
		return list;
	}
	Prog& operator=(const Prog& obj)//assignment operator
	{
		ID = obj.ID;
		size = obj.size;
		list = obj.list;
		return *this;
	}
	void InsertElem(Block& obj)
	{
		size += obj.GetTotal();
		list.InsertAtEnd(obj);
	}
	bool operator==(const int& i)//if equal
	{
		if (ID == i)
			return true;
		else
			return false;
	}
	Prog operator+=(Prog& obj)//update list of block and size
	{
		size += obj.size;
		list.InsertAtEnd(obj.list.GetData());
		list.CombineData();
		return*this;

	}
	void deallocate()
	{
		while (list.isEmpty() != true)
		{
			list.DeleteAtStart();
		}
	}
	bool operator==(const Prog& i)//if equal
	{

		if (ID == i.ID)
			return true;
		else
			return false;
	}

	bool operator>=(const Prog& i)
	{
		if (ID >= i.ID)
			return true;
		return false;
	}

	friend ostream& operator<<(ostream& out, Prog& p);
};
ostream& operator<<(ostream& out, Prog& p)//display operator overloaded
{
	cout << "ID: P" << p.ID << "\nSpace: " << p.size << endl;
	p.list.Display();
	return out;
}
class MemoryManagementSystem
{

private:
	LinkList<Block> pool;
	LinkList<Prog> Progs;
	int sizeOfMemory;
	bool Strategy;
public:
	MemoryManagementSystem(int m, int s)
	{
		sizeOfMemory = m;
		Strategy = s;
		Block b(0, sizeOfMemory);//first memory segment start from 0
		pool.InsertAtEnd(b);//initially only 1 block in pool
	}
	void GetMem(int PI, int S)
	{
		Block temp;
		if (pool.FindIT(S) == true)//checking if enough memory is availble or not
		{

			if (Strategy == true) {
				temp = pool.FindFirstFit(S);//for firstfit
			}
			else
			{
				temp = pool.FindBestFit(S);//for bestfit
			}

			temp.SetStart(temp.GetStart() - S);
			temp.SetTotal(S);
			//block temp now has value to be inserted in prog
			Prog temp2;
			temp2.SetID(PI);
			temp2.SetSize(S);
			temp2.SetBlock(temp);
			//prog temp2 made with the block temp
			if (Progs.Search(temp2) == true)//if prog ID is already available in list of programs
			{

				Progs.Update(temp2);//update the required prog using temp2

			}
			else
			{
				Progs.InsertAtEnd(temp2);//insert new prog with the data of temp2
			}
		}
		else
		{
			cout << "Memory not available\n\n";
		}
	}
	void DeleteProgram(int obj)
	{
		Prog temp;
		temp.SetID(obj);
		temp.SetSize(0);
		if (Progs.Search(temp) == true)//if prog id given is correct
		{

			Progs.UpdateParameter(temp);//updating the value of temp
			pool.merge(temp.GetList());//merging the list in temp with the list of pool 
			pool.CombineData();//combing block which are consecutive
			Progs.deleteItem(temp);//deleting the required program from list of programs

		}
		else
			cout << "Program ID not found\n\n";
	}
	void Display()//output
	{
		cout << "Pool: \n";
		pool.Display();
		cout << "Programs:\n";
		Progs.Display();
	}
	LinkList<Block> GetPool()//getter
	{
		return pool;
	}

};
int main()
{

	int Ram = 0;
	cout << "Enter RAM size in kb:\t";
	cin >> Ram;
	Ram = (Ram * 1024) - 1;//converting kb to bytes
	cout << "Enter the Strategy\nFirstFit:press1\nBestFit:Press any key except 1\n";
	int x;
	bool strat;//asking user for which strategy to use
	cin >> x;
	if (x == 1)
	{
		strat = true;
	}
	else
		strat = false;
	MemoryManagementSystem M(Ram, strat);
	int choice = 0;
	while (choice != -1) {
		cout << "MEMORY MANAGEMENT SYSTEM\n\n";
		cout << "Display: Press1\n";
		cout << "Get memory:Press2\n";
		cout << "DeleteProgram:Press3\n";
		cout << "Quit: Press-1\n\n";
		cin >> choice;
		if (choice == 1)
		{
			M.Display();
		}
		else if (choice == 2)
		{
			int p;
			cout << "Enter the Program Number\n";
			cin >> p;
			int m;
			cout << "Enter the memory required by program in bytes\n";
			cin >> m;
			M.GetMem(p, m);
		}
		else if (choice == 3)
		{
			int p;
			cout << "Enter the program you want to delete\n";
			cin >> p;
			M.DeleteProgram(p);
		}
		else if (choice != -1)
		{
			cout << "Invalid choice\n\n";
		}
	}


}