#include <iostream>
using namespace std;
template<class T>
class Node {
public:
	T data;
	Node<T>* next;
	Node() {
		data = 0;
		next = nullptr;
	}
	Node(T d) {
		data = d;
	}
};

template<class T>
class  SortedSet {
public:
	Node<T>* head;
	//Node<T>* tail;
	SortedSet() {
		head = nullptr;
		//tail = nullptr;
	}
	bool isEmpty() {
		if (head == nullptr)
			return true;
		else
			return false;
	}
	/*void insertEnd(T const element){
		Node<T>* current = head;
		Node<T>* temp = new Node<T>;
		temp->data = element;
		while (current->next != NULL) {
			if (current->next == NULL) {
				temp->next = NULL;
				current->next = temp;
			}
			else
				current = current->next;
		}
	}*/
	void insert(T const d) {
		Node<T>* temp = new Node<T>;
		temp->data = d;
		if(head==nullptr){
			head = temp;
			return;
		}
		if (head->data > d){
			//insert at start
			temp->next = head;
			head = temp;
			return;
		}
			Node<T>* current = head;
			while (current->next != nullptr){
				if (current->next->data > d && current->data < d ){
					temp->next = current->next;
					current->next = temp;
					return;
				}
				current = current->next;
			}
			//insert at end
			if (temp->data > current->data) {
				temp->next = nullptr;
				current->next = temp;
			}
	}
	void Delete(int const index) {
		//checks if the given index exists or not
		Node<T>* current = head;
		int count = 0;
		while (current->next != NULL) {
			current = current->next;
			count++;
		}
		if (index >= count || index<0) {
			cout << "the given index does not exit\n";
		}
		else {
			current = head;
			T value;
			for (int i = 0; i<index-1; i++) {
					current = current->next;
			}
			Node<T>* temp = current->next;
			current->next = current->next->next;
			delete temp;
		}
	}
	void print() {
		Node<T>* current = head;
		while (current != NULL) {
			cout << current->data << " ";
			current = current->next;
		}
		cout << endl;
	}
	void Union(SortedSet<T> const& otherSet) {
		Node <T>* other_current = otherSet.head;
		Node <T>* current = head;
		int value;
		while (other_current->next != nullptr) {
			value = other_current->data;
			insert(value);
			other_current = other_current->next;
		}

	}
	void Rotate(int k) {
		if (k == 0) {
			cout << "zero\n";
			return;
		}
		else {
			for (int i = 0; i < k; i++) {
				Node<T>* current = head;
				Node<T>* last = new Node<T>;

				while (current->next != nullptr) {
					current = current->next;
				}
				last = current;
				current = head;
				last->next = head;
				head = current->next;
				current->next = nullptr;
			}
		}
	}
	void Reverse(SortedSet<T> const& set) {
		Node<T>* current = set.head;
		Node<T>* previous = new Node<T>;
		Node<T>* temp = new Node<T>;
		if (current->next == NULL || set.head==NULL) {
			return;
		}
			while (current != NULL) {
				temp = current->next;
				current->next = previous;
				previous = current;
				current = temp;
			}
			head = previous;
		}
};

int main() {
	SortedSet<int> obj1;
	obj1.insert(10);
	obj1.insert(20);
	obj1.insert(30);
	obj1.insert(40);
	obj1.insert(50);
	obj1.insert(60);
	obj1.print();
	obj1.Delete(2);
	obj1.print();

	SortedSet<int> obj2;
	obj2.insert(8);
	obj2.insert(9);
	obj2.insert(-4);
	obj2.insert(0);
	obj2.print();

	obj1.Union(obj2);

	obj1.print();

	int k = 0;
	cout << "enter a number for rotation: ";
	cin >> k;
	//for (int i = 0; i < k; i++) {
		obj1.Rotate(k);
	//}
	obj1.print();
	obj1.Reverse(obj1);
	obj1.print();
	return 0;
}