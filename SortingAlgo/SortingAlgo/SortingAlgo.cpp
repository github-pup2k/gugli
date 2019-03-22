// SortingAlgo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

#include "BaseSort.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "ShuffleSort.h"

#include <memory>

using namespace std;

int main()
{ 
	try
	{
		//Selection Sort
		{
			unique_ptr< BaseSort<string> > pBaseStringSort = make_unique< SelectionSort<string> >();

			vector<string> files = { "Harsh", "Jashan", "Baloch", "Jyoti", "Amrish", "Brinda", "Dhruva" };

			pBaseStringSort->Sort(files);

			//Sort array of integers
			unique_ptr< BaseSort<int> > pBaseIntSort = make_unique< SelectionSort<int> >();

			vector<int> ints = { 5, 11, 41, 35, 37, 30, 1 };

			pBaseIntSort->Sort(ints);

			// Sort array of characters
			unique_ptr< BaseSort<char> > pBaseCharSort = make_unique< SelectionSort<char> >();

			vector<char> chars = { 'K', 'A', 'J', 'X', 'D', 'M', 'H' };

			pBaseCharSort->Sort(chars);
		}

		//Insertion Sort
		{
			unique_ptr< BaseSort<string> > pBaseStringSort = make_unique< InsertionSort<string> >();

			vector<string> names = { "Harsh", "Jashan", "Baloch", "Jyoti", "Amrish", "Brinda", "Dhruva" };

			pBaseStringSort->Sort(names);

			//Sort array of integers
			unique_ptr< BaseSort<int> > pBaseIntSort = make_unique< InsertionSort<int> >();

			vector<int> ages = { 5, 11, 41, 35, 37, 30, 1 };

			pBaseIntSort->Sort(ages);

			// Sort array of characters
			unique_ptr< BaseSort<char> > pBaseCharSort = make_unique< InsertionSort<char> >();

			vector<char> chars = { 'K', 'A', 'J', 'X', 'D', 'M', 'H' };

			pBaseCharSort->Sort(chars);
		}

		//shuffle Sort
		{
			unique_ptr< BaseSort<int> > pBaseCardsSort = make_unique< ShuffleSort<int> >();

			vector<int> cards;

			cards.resize(52);
			for (int i = 0; i < 52; i++)
				cards[i] = i;

			pBaseCardsSort->Sort(cards);
		}
	}
	catch (std::bad_alloc& e)
	{
		cout << "Out of memory: " << e.what() << endl;
	}



    std::cout << "Hello World!\n"; 
}

