#include<iostream>
#include<fstream>
using namespace std;

template<class T>
class Stack
{
private:
	int size;
	int stk_ptr;
	T* stackArray;
public:
	Stack(int s = 10)
	{
		size = s;
		stk_ptr = 0;
		stackArray = new T[size];
	}
	bool isFull()
	{
		return (stk_ptr == size);
	}
	bool isEmpty()
	{
		return (stk_ptr == 0);
	}
	int Size()
	{
		return stk_ptr;
	}
	bool top(T& d)
	{
		if (!isEmpty())
		{
			d = stackArray[stk_ptr - 1];
				return true;
		}
		return false;
	}
	bool push(T& n)
	{
		if (!isFull())
		{
			stackArray[stk_ptr] = n;
			stk_ptr++;
			return true;
		}
		return false;
	}
	bool pop(T& n)
	{
		if (!isEmpty())
		{
			n = stackArray[--stk_ptr];
			return true;
		}
		return false;
	}
	void print()
	{
		for (int i = 0; i < stk_ptr; i++)
		{
			cout << stackArray[i];
		}
		cout << endl;
	}
};

class coords
{
private:
	int xcoord;
	int ycoord;
public:
	coords()
	{}
	coords(int x, int y)
	{
		xcoord = x;
		ycoord = y;
	}
	void Setxcoord(int d)
	{
		xcoord = d;
	}
	void Setycoord(int d)
	{
		ycoord = d;
	}
	int Getxcoord()
	{
		return xcoord;
	}
	int Getycoord()
	{
		return ycoord;
	}
	coords& operator=(const coords& var)
	{
		xcoord = var.xcoord;
		ycoord = var.ycoord;
		return *this;
	}
	friend ostream& operator<<(ostream& out, coords d);
};

ostream& operator<<(ostream& out, coords d)
{
	cout << "(" << d.xcoord << ", " << d.ycoord << ")\n";
	return out;
}

class Rooms
{
private:
	char** maze;
	int maxr;
	int maxc;
	coords current;
public:
	Rooms()
	{}
	Rooms(string filename)
	{
		ifstream rin(filename);
		if (rin.is_open())
		{
			int x;
			int y;
			rin >> maxr;
			rin >> maxc;
			rin >> x;
			rin >> y;
			current.Setxcoord(x);
			current.Setycoord(y);
			maze = new char* [maxr];
			for (int i = 0; i < maxr; i++)
			{
				maze[i] = new char[maxc];
				for (int j = 0; j < maxc; j++)
				{
					rin >> maze[i][j];
				}
			}
			rin.close();
		}
		else
		{
			cout << filename << " is not open" << endl;
		}
	}
	Rooms& operator=(const Rooms& d)
	{
		maxr = d.maxr;
		maxc = d.maxc;
		current = d.current;
		maze = new char* [maxr];
		for (int i = 0; i < maxr; i++)
		{
			maze[i] = new char[maxc];
			for (int y = 0; y < maxc; y++)
			{
				maze[i][y] = d.maze[i][y];
			}
		}
		return*this;
	}
	bool Search(char d)
	{
		for (int i = 0; i < maxr; i++)
		{
			for (int y = 0; y < maxc; y++)
			{
				if (maze[i][y] == d)
					return true;
			}
		}
		return false;
	}
	void Display()
	{
		for (int i = 0; i < maxr + 2; i++)
		{
			for (int j = 0; j < maxc + 2; j++)
			{
				if (i - 1 == current.Getxcoord() && j - 1 == current.Getycoord())
					cout << "P ";
				else if (i == 0 || j == 0 || i == maxr + 1 || j == maxc + 1)
					cout << "# ";
				else if (maze[i - 1][j - 1] != 'X')
					cout << "  ";
				else
					cout << "# ";
			}
			cout << endl;
		}
		cout << endl << endl;
	}
	bool move(char d, Stack<coords>& s)
	{
		if (d == 'W' || d == 'w')
		{
			if (current.Getxcoord() == 0 || maze[current.Getxcoord() - 1][current.Getycoord()] == 'X')
			{
				cout << "Unable to move in this direction" << endl;
			}
			else
			{
				current.Setxcoord(current.Getxcoord()-1);
				s.push(current);
				return true;
			}
		}
		else if (d == 'A' || d == 'a')
		{
			if (maze[current.Getxcoord()][current.Getycoord() - 1] == 'X' || current.Getycoord() == 0)
			{
				cout << "Unable to move in this direction" << endl;
			}
			else
			{
				current.Setycoord(current.Getycoord() - 1);
				s.push(current);
				return true;
			}
		}
		else if (d == 'S' || d == 's')
		{
			if (current.Getxcoord() == maxr - 1 || maze[current.Getxcoord() + 1][current.Getycoord()] == 'X')
			{
				cout << "Unable to move in this direction" << endl;
			}
			else
			{
				current.Setxcoord(current.Getxcoord() + 1);
				s.push(current);
				return true;
			}
		}
		else if (d == 'D' || d == 'd')
		{
			if (maze[current.Getxcoord()][current.Getycoord() + 1] == 'X' || current.Getycoord() == maxc - 1)
			{
				cout << "Unable to move in this direction" << endl;
			}
			else
			{
				current.Setycoord(current.Getycoord() + 1);
				s.push(current);
				return true;
			}
		}
		return false;
	}
	char GetChar()
	{
		return maze[current.Getxcoord()][current.Getycoord()];
	}
	coords Getcoords()
	{
		return current;
	}
};
int cointoss(void)
{
	return (1 + rand() % 2);
}
int Portal(int trooms, int curr)
{
	int num=curr;
	while (num == curr)
	{
		num = 1 + rand() % trooms;
	}
	return num;
}
void Recusrsive(int trooms, Rooms* roomarr, int currentroom, Stack<coords>& path)
{
	int i = 0;
	while (roomarr[i].Search('T') != true)
		i++;
	bool finish = false;
	char movement;
	//path.push(roomarr[currentroom].Getcoords());
	coords temp = roomarr[currentroom].Getcoords();
	path.push(temp);
	if (!finish)
	{
		cout << "Enter WASD to move the player in desired direction" << endl;
		cin >> movement;
		if (roomarr[currentroom].move(movement, path) == true)
		{
			if (roomarr[currentroom].GetChar() == 'D')
			{
				cout << "You lose!\nYou have encountered the DEVIL!\nGame end" << endl;
				finish = true;
			}
			else if (roomarr[currentroom].GetChar() == 'G')
			{
				cout << "The GASPER has teleported you to the treasure room." << endl;
				currentroom = i;
			}
			else if (roomarr[currentroom].GetChar() == 'P')
			{
				cout << "You are stuck in a portal!\nYour fate will be decided by a coin toss." << endl;
				if (cointoss() == 1)
				{
					cout << "You got Heads.\nTeleporting to a random room!" << endl;
					currentroom = Portal(trooms, currentroom + 1) - 1;
				}
				else
				{
					cout << "You got Tails." << endl;
					if (currentroom == 0)
					{
						cout << "You have been teleported outside of the house\nYou Lose!" << endl;
						finish = true;
					}
					else
						currentroom--;
				}
			}
			else if (roomarr[currentroom].GetChar() == 'T')
			{
				cout << "Congratulations you have found the treasure." << endl;
				cout << "Your current postion is: " << roomarr[currentroom].Getcoords() << endl;
				path.print();
				finish = true;
			}
			else
				system("cls");
		}
		else if (movement == 'Q')
		{
			cout << "You have exited the game." << endl;
			finish = true;
		}
		else
			cout << "Command entered is invalid.\nPlease enter a valid command\n";
		if (!finish) {
			cout << "Room Number: " << currentroom + 1 << endl;
			roomarr[currentroom].Display();
			return Recusrsive(trooms, roomarr, currentroom, path);
		}
	}
}
void Iterative(int trooms, Rooms* roomarr, int currentroom, Stack<coords>& path)
{
	int i = 0;
	while (roomarr[i].Search('T') != true)
		i++;
	bool finish = false;
	char movement;
	//path.push(roomarr[currentroom].Getcoords());
	coords temp = roomarr[currentroom].Getcoords();
	path.push(temp);
	while (!finish)
	{
		cout << "Enter WASD to move the player in desired direction" << endl;
		cin >> movement;
		if (roomarr[currentroom].move(movement, path) == true)
		{
			if (roomarr[currentroom].GetChar() == 'D')
			{
				cout << "You lose!\nYou have encountered the DEVIL!\nGame end" << endl;
				finish = true;
			}
			else if (roomarr[currentroom].GetChar() == 'G')
			{
				cout << "The GASPER has teleported you to the treasure room." << endl;
				currentroom = i;
			}
			else if (roomarr[currentroom].GetChar() == 'P')
			{
				cout << "You are stuck in a portal!\nYour fate will be decided by a coin toss." << endl;
				if (cointoss() == 1)
				{
					cout << "You got Heads.\nTeleporting to a random room!" << endl;
					currentroom = Portal(trooms, currentroom + 1) - 1;
				}
				else
				{
					cout << "You got Tails." << endl;
					if (currentroom == 0)
					{
						cout << "You have been teleported outside of the house\nYou Lose!" << endl;
						finish = true;
					}
					else
						currentroom--;
				}
			}
			else if (roomarr[currentroom].GetChar() == 'T')
			{
				cout << "Congratulations you have found the treasure." << endl;
				cout << "Your current postion is: " << roomarr[currentroom].Getcoords() << endl;
				path.print();
				finish = true;
			}
			else
				system("cls");
		}
		else if (movement == 'Q')
		{
			cout << "You have exited the game." << endl;
			finish = true;
		}
		else
			cout << "Command entered is invalid.\nPlease enter a valid command\n";
		if (!finish) {
			cout << "Room Number: " << currentroom + 1 << endl;
			roomarr[currentroom].Display();
		}
	}
}

int main()
{
	ifstream fin("hauntedhouse.txt");
	string fname;
	int currentroom = 0;
	if (fin.is_open())
	{
		string fname;
		int tfiles;
		fin >> tfiles;
		Rooms* roomsarr = new Rooms[tfiles];
		Rooms temproom;
		Stack<coords> path;
		for (int i = 0; i < tfiles; i++)
		{
			fin >> fname;
			Rooms temproom(fname);
			roomsarr[i] = temproom;
		}
		cout << "Room Number: " << currentroom + 1 << endl;
		roomsarr[currentroom].Display();
		Iterative(tfiles, roomsarr, currentroom, path);
		//Recusrsive(tfiles, roomsarr, currentroom, path);
		fin.close();
	}
	else
	{
		cout << "File did not open" << endl;
	}
}