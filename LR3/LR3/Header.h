#pragma once
using namespace std;

template<typename Type>
class Node 
{
public:
	Type d;
	Node* prev;
	Node* next;
	Node() { prev = NULL; next = NULL;};
};


template <typename Type>
class ListNode 
{
private:
	Node<Type>* head;
	Node<Type>* tail;
	Node<Type>* current;
	Node<Type>* FindNodePos(int i);
	Node<Type>* FindNode(Type data);
public:
	
	ListNode() :head(NULL), tail(NULL), current(NULL) {};  
	ListNode(Type d) { AddHead(d); };
	ListNode(Type arr[], int length);
	ListNode(ListNode& C);

	~ListNode() { Clear(); }

	void AddHead(Type d);
	void AddTail(Type d);
	void AddNode(Type d, int pos);
	void ListHead();
	void ListTail();
	Node<Type>* DeleteHead();
	Node<Type>* DeleteTail();
	void DeleteNode(int i);
	Node<Type>* Clear();
	bool isEmpty();
	void setValue(Type n, int pos);

	Type currentNode() { return current->d; };
	Node<Type>* Next() { return current->next; };
	Node<Type>* Pred() { return current->pred; };

	Type operator[](int pos) 
	{
		Node<Type>* it = FindNodePos(pos);
		return it->d; 
	};

	bool operator == (ListNode& List) { return head == List.head; };

	template<class T>
	T operator[](T data)
	{
		Node<Type>* it = FindNode(data);
		return it->d;
	};

	template<class T>
	void BusRoute(bool(*func) (T r, Node<Type>* BS), T rt)
	{
		Node<Type>* temp = head;
		while (temp != NULL)
		{
			if (func(rt, temp))
				cout << temp->d;
			temp = temp->next;
		}
	};
};


template <class Type>
ListNode<Type>::ListNode(ListNode& C)
{
	head = C.head;
	tail = C.tail;
	current = C.current;
}

template <class Type>
ListNode<Type>::ListNode(Type arr[], int length)
{
	for (int i = 0; i < length; i++)
		AddHead(arr[i]);
}

template <class Type>
Node<Type>* ListNode<Type>::FindNodePos(int pos)   
{
	Node<Type>* temp = head;
	while (temp != NULL && pos > 1)
	{
		temp = temp->next;
		pos--;
	}
	return temp;
}

template <class Type>
Node<Type>* ListNode<Type>::FindNode(Type data)    
{  
	Node<Type>* temp = head;
	while (temp != NULL)
	{
		if (temp->d == data)
			return temp;
		temp = temp->next;
	}
	return NULL;
}

template <class Type>
void ListNode<Type>::AddHead(Type val)
{
	Node<Type>* temp = new Node<Type>;
	temp->d = val;
	if (head == NULL)
	{
		head = temp;
		tail = temp;
		tail->next = NULL;
	}
	else
	{
		head->prev = temp;
		temp->next = head;
		head = temp;
		head->prev = NULL;
	}
}

template <class Type>
void ListNode<Type>::AddTail(Type val)
{
	Node<Type>* temp = new Node<Type>;
	temp->d = val;
	if (head == NULL)
	{
		head = temp;
		tail = temp;
		tail->next = NULL;
	}
	else
	{
		tail->next = temp;
		temp->prev = tail;
		tail = temp;
		temp->next = NULL;
	}
}

template <class Type>
void ListNode<Type>::AddNode(Type val, int pos)
{
	if (pos == 1)
		AddHead(val);
	else
	{
		Node<Type>* p = FindNodePos(pos);
		if (p == NULL)
			return;

		Node<Type>* temp = new Node<Type>;
		temp->d = val;
		temp->next = p;
		temp->prev = p->prev;
		p->prev->next = temp;
		p->prev = temp;
	}
}

template <class Type>
void ListNode<Type>::ListHead()
{
	Node<Type>* temp = head;
	while (temp != NULL)
	{
		cout << temp->d << " ";
		temp = temp->next;
	}
}

template <class Type>
void ListNode<Type>::ListTail()
{
	Node<Type>* temp = tail;
	while (temp != NULL)
	{
		cout << temp->d << " ";
		temp = temp->prev;
	}
}

template <class Type>
Node<Type>* ListNode<Type>::DeleteHead()
{
	if (head == NULL)
		return head;
	else 
	{
		Node<Type>* temp = head; 
		head = temp->next;
		if (head != NULL)
			head->prev = NULL;
		delete temp;
	}
	return head;
}

template <class Type>
Node<Type>* ListNode<Type>::DeleteTail()
{
	if (tail == NULL)
		return tail;
	else
	{
		Node<Type>* temp = tail;
		tail = temp->prev;
		tail->next = NULL;
		delete temp;
	}
}

template <class Type>
void ListNode<Type>::DeleteNode(int pos)
{
	Node<Type>* p = FindNodePos(pos);
	if (head == p)
		DeleteHead();

	if (tail == p)
		DeleteTail();

	if (p)
	{
		p->prev->next = p->next;
		p->next->prev = p->prev;
		delete p;
	}
}

template <class Type>
Node<Type>* ListNode<Type>::Clear()
{
	Node<Type>* temp = head;
	while (head != NULL)
		head = DeleteHead();
	return head;
}

template <class Type>
bool ListNode<Type>::isEmpty()
{
	return head == NULL;
}

template <class Type>
void ListNode<Type>::setValue(Type n, int pos)
{
	Node<Type>* it = FindNodePos(pos);
	it->d = n;
}