// SearchProj.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<string>

using namespace std;

template <class T, class V>
class LinkList
{
	class Node
	{
	public:
		Node(T k, V v, Node *next)
		{
			this->key = k;
			this->value = v;
			this->next = next;
		}

		T key;
		V value;
		Node *next;
	};

public:
	LinkList() { head_ = nullptr; }
	~LinkList() { }

	void put(T k, V v)
	{
		try
		{
			Node *tmp = head_;
			while (tmp != nullptr)
			{
				if (tmp->key == k)
				{
					tmp->value = v;
					return;
				}
				tmp = tmp->next;
			}
			head_ = new Node(k, v, head_);
		}
		catch (std::bad_alloc&)
		{
			//Do nothing
		}
	}

	V Get(T k)
	{
		V value;
		Node *tmp = head_;

		while (tmp != nullptr)
		{
			if (tmp->key == k)
			{
				value = tmp->value;
				break;
			}
			tmp = tmp->next;
		}
		return value;
	}

	void DeleteNodes()
	{
		Node *current = head_;
		Node *next = nullptr;
		while (current != nullptr)
		{
			next = current->next;
			delete current;
			current = next;
		}
	}

	void Display()
	{
		Node *tmp = head_;

		while (tmp != nullptr)
		{
			cout << tmp->key << ":" << tmp->value << endl;
			tmp = tmp->next;
		}
	}

private: 
	Node *head_;

};

int main()
{
	LinkList<string, int> *stable = new LinkList<string, int>();

	stable->put("SA", 12);
	stable->put("EA", 12);
	stable->put("AA", 12);
	stable->put("RA", 12);
	stable->put("CA", 12);
	stable->put("HA", 12);
	stable->put("EA", 12);
	stable->put("XA", 12);
	stable->put("AA", 24);
	stable->put("MA", 56);
	stable->put("PA", 35);
	stable->put("LA", 78);
	stable->put("EA", 67);

	int k = stable->Get("MA");

	stable->Display();

	stable->DeleteNodes();

    std::cout << "\nHello World!\n"; 
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
