#include <iostream>

using namespace std;

struct Node {
	const char* element;
	Node *next;

	Node(const char* e = NULL, Node *n = NULL)
	{
		element = e;
		next = n;
	}
};

struct SLinkedList {
	public:
	Node* head;
	Node* tail;
	int size;

	SLinkedList() 
	{
	head = NULL;
	tail = NULL;
	size = 0;
	}
	
	bool isEmpty() { return head == NULL; }
	
	void addFirst (const char* s)
	{
		Node* newNode = new Node(s, head);
		head = newNode;
	}
	
	void addLast(const char *s) 
	{
		Node* newNode = new Node(s, NULL);
	    if (head == NULL) head = newNode;
	    else tail->next = newNode;
	    tail = newNode;
	}
	
	void removeFirst()
	{
		Node *tmp = head;
		head = head->next;
		delete tmp;
	}
	
	void removeLast()
	{
		Node *tmp = head;
		while (tmp->next != tail) tmp = head->next;
		Node* tmp2 = tail;
		tail = tmp;
		tmp = tmp2;
		delete tmp;
		tail->next = NULL;
	}
	
	bool destructor()
	{
		while (head != NULL)
		{
			Node* tmp = head;
			head = head->next;
			delete tmp;
		}
		tail = NULL;
	}
	
	bool insertAfter(Node* p, const char* s)
	{
		Node* newNode = new Node(s, p->next);
		p->next = newNode;
	}
	
	const char *remove(Node* p)
	{
		Node* tmp = head;
		while (tmp->next != p) tmp = head->next;
		tmp->next = p->next;
		return p->element;
	}
	
	void print()
	{
		if (head == NULL) cout << "Empty";
		else {
			Node *tmp = head;
			while (tmp != NULL)
			{
				cout << tmp->element << ' ';
				tmp = tmp->next;
			}
		}

		cout << endl;
	}
};

SLinkedList linkedList;

void testA1()
{
	linkedList.addLast("a");
	linkedList.addLast("b");
	linkedList.addFirst("c");
	linkedList.print();
}

void testA2()
{
	linkedList.removeFirst();
	linkedList.print();
}

void testA3()
{
	linkedList.destructor();
	linkedList.print();
}

void testA4()
{
	linkedList.addLast("a");
	linkedList.addLast("b");
	linkedList.addFirst("c");
	linkedList.removeLast();
	linkedList.print();
}

void testA5()
{
	linkedList.insertAfter(linkedList.head, "d");
	linkedList.insertAfter(linkedList.tail, "e");
	linkedList.print();
}

void testA6()
{
	Node* p = linkedList.head->next;
	cout << linkedList.remove(p) << endl;
	linkedList.print();
}

int main()
{
	testA1();
	testA2();
	testA3();
	testA4();
	testA5();
	testA6();
}
	
