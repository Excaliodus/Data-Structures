#include <iostream>
#include<vector>
#include<list>
using namespace std;

template <class T>
class HashMaps
{
	vector <list<T>> v1;
	int size;
	int maxsize;
public:
	HashMaps(int s=20)
	{
		size = 0;
		maxsize = s;
		v1.resize(s);
	}
	bool isLoadFactor()
	{
		return ((maxsize / size) > 2);
	}
	void Rehash()
	{
		vector <list<T>> temp(v1);
		v1.clear();
		v1.resize(maxsize * 2);
		maxsize = maxsize * 2;
		size = 0;
		for (auto i = temp.begin(); i != temp.end(); i++)
		{
			list<T> templist = *i;
			for (auto j = templist.begin(); j != templist.end(); j++)
			{
				Insert(*j);
			}
		}
	}
	void Update(T d)
	{
		int data = ++d;
		int index = data % (maxsize);
		for (auto j = v1[index].begin(); j != v1[index].end(); j++)
		{
			if (*j == d)
			{
				*j = d;
			}
		}
	}
	void Remove(int d)
	{
		int index = d % (maxsize);
		v1[index].remove_if([&](T c) {return c == d; });
		size--;
	}
	bool search(int d)
	{
		int index = d % (maxsize);
		list<T> temp = v1[index];
		for (auto j = temp.begin(); j != temp.end(); j++)
		{
			if (*j == d)
			{
				return true;
			}
		}
		return false;
	}
	void Insert(T d)
	{
		int data = ++d;
		int index = data % (maxsize);
		v1[index].push_back(d);
		size++;
		if (isLoadFactor() == false)
		{
			this->Rehash();
		}
	}
	void Print(int d)
	{
		int index = d % (maxsize);
		list<T> temp = v1[index];
		for (auto j = temp.begin(); j != temp.end(); j++)
		{
			if (*j == d)
			{
				cout << *j << endl;
				return;
			}
		}
		cout << "Not Found." << endl;
	}
};
class Book
{
private:
	int ISSN;
	string Title;
	list<string> Authors;
	int Total_Refrence;
	int Total_Issuable;
public:
	Book(int issn, string title, list<string> authors, int t_ref, int t_issue)
	{
		ISSN = issn;
		Title = title;
		Authors = authors;
		Total_Refrence = t_ref;
		Total_Issuable = t_issue;
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
	int operator++()
	{
		return ISSN;
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
	friend ostream& operator<<(ostream& out, Book& obj);
};
ostream& operator<<(ostream& out, Book& obj)
{
	cout << "ISSN: " << obj.ISSN << endl;
	cout << "Title: " << obj.Title << endl;
	cout << "Authors: " << endl;
	for (auto j = obj.Authors.begin(); j != obj.Authors.end(); j++)
	{
		cout << *j << endl;
	}
	cout << "Total number of copies available as refrenece books are: " << obj.Total_Refrence << endl;
	cout << "Total number of copies available as issuable books are: " << obj.Total_Issuable << endl;
	return out;
}


int main()
{
	HashMaps<int> h1(4);
	HashMaps<Book> h2;
	char x = 'A';
	while (x != 'E' && x != 'e')
	{
		cout << "\t\t\t\t\t\t\t Book Records" << endl;
		cout << "Press C to create a book record." << endl;
		cout << "Press R to review a book record." << endl;
		cout << "Press U to update a book record." << endl;
		cout << "Press D to delete a book record." << endl;
		cout << "Press E to exit the menu." << endl;
		cin >> x;
		if (x == 'C' || x == 'c')
		{
			int issn;
			string title;
			int Tauthors;
			int Tref;
			int Tissue;
			list<string>authors;
		label:
			cout << "Enter the ISSN number for the book record you want to create." << endl;
			cin >> issn;
			if (h2.search(issn))
			{
				cout << "A record with this ISSN already exists. Pls reenter another ISSN number." << endl;
				goto label;
			}
			cout << "Enter the title for the book record." << endl;
			cin >> title;
			cout << "Enter the total number of authors for the book record." << endl;
			cin >> Tauthors;
			for (int i = 1; i <= Tauthors; i++)
			{
				string Aname;
				cout << "Enter the name of author " << i << endl;
				cin >> Aname;
				authors.emplace_back(Aname);
			}
			cout << "Enter the total number of available reference books for the book record." << endl;
			cin >> Tref;
			cout << "Enter the total number of issuable books available for the book record." << endl;
			cin >> Tissue;
			Book temp(issn, title, authors, Tref, Tissue);
			h2.Insert(temp);
		}
		else if (x == 'R' || x == 'r')
		{
			cout << "Enter the ISSN to review the contents of the coresponding book record." << endl;
			int issn;
			cin >> issn;
			h2.Print(issn);
		}
		else if (x == 'U' || x == 'u')
		{
			cout << "Enter the ISSN to update the contents of the coresponding book record." << endl;
			int issn;
			cin >> issn;
			if (h2.search(issn))
			{
				string title;
				int Tauthors;
				int Tref;
				int Tissue;
				list<string>authors;
				cout << "Enter the title for the book record." << endl;
				cin >> title;
				cout << "Enter the total number of authors for the book record." << endl;
				cin >> Tauthors;
				for (int i = 1; i <= Tauthors; i++)
				{
					string Aname;
					cout << "Enter the name of author " << i << endl;
					cin >> Aname;
					authors.emplace_back(Aname);
				}
				cout << "Enter the total number of available reference books for the book record." << endl;
				cin >> Tref;
				cout << "Enter the total number of issuable books available for the book record." << endl;
				cin >> Tissue;
				Book temp(issn, title, authors, Tref, Tissue);
				h2.Update(temp);
			}
			else
			{
				cout << "A record with the following ISSN does not exist." << endl;
			}
		}
		else if (x == 'D' || x == 'd')
		{
			cout << "Enter the ISSN to delete the coresponding book record." << endl;
			int issn;
			cin >> issn;
			if (h2.search(issn))
			{
				h2.Remove(issn);
				cout << "The book record has been deleted." << endl;
			}
		}
		else if (x != 'E' && x != 'e')
		{
			cout << "Enter a valid input." << endl;
		}
	}
}