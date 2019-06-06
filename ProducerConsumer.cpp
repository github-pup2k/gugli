// ProducerConsumer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include<thread>
#include<mutex>
#include<queue>
#include <fstream>

using namespace std;
class ProducerConsumer
{
public:
	ProducerConsumer() {
		size_ = 9;
		m_iValue = 1;
		m_bExit = false;
		m_producerfile.open("Producer.txt", std::fstream::in | std::ofstream::out | std::ofstream::trunc);
		m_consumerfile.open("Consumer.txt", std::fstream::in | std::ofstream::out | std::ofstream::trunc);
	}
	~ProducerConsumer() {
		m_producerfile.close();
		m_consumerfile.close();
	}


	void Monitor()
	{
		cout << "Monitor thread is started...";
		while (!m_bExit)
		{

			int k = 0;
			cout << "\nEnter 1 for exit: "; cin >> k;

			switch (k)
			{
			case 1:
			{
				unique_lock<mutex> locker(m_mutex);
				m_bExit = true;
				locker.unlock();
				m_cvSpace.notify_all();
				m_cvItem.notify_all();
				break;
			}
			}
		}

		cout << "\nMonitor thread is ended...";
	}

	void DumpContent()
	{
		string line;

		cout << "\nProducer: ";
		m_producerfile.seekp(0);
		while (getline(m_producerfile, line))
		{
			cout << line << '\n';
		}

		cout << "\nConsumer: ";
		m_consumerfile.seekp(0);
		while (getline(m_consumerfile, line))
		{
			cout << line << '\n';
		}

	}

	void Produce()
	{
		while (true)
		{
			unique_lock<mutex> locker(m_mutex);
			//If queue is full, the producer will wait for space to put the item in queue
			m_cvSpace.wait(locker, [this]() {return (m_alphabets.size() < size_) || m_bExit; });

			if (m_bExit)
			{
				cout << "\nProducer is exited...";
				return;
			}

			m_alphabets.push(m_iValue % size_);
			m_producerfile << " " << m_iValue % size_;
			m_iValue++;

			locker.unlock();
			m_cvItem.notify_all();
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
		}
	}
	void Consume()
	{
		while (true)
		{
			unique_lock<mutex> locker(m_mutex);
			//As soon as the item would available in queue, the consumer will consume it.
			m_cvItem.wait(locker, [this]() {return  (m_alphabets.size() > 0) || m_bExit; });

			if (m_bExit)
			{
				cout << "\nConsumer is exited...";
				return;
			}

			m_consumerfile << " " << m_alphabets.front(); ;
			m_alphabets.pop();

			locker.unlock();
			m_cvSpace.notify_all();
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
		}
	}

private:

	queue<int> m_alphabets;
	condition_variable m_cvSpace;
	condition_variable m_cvItem;
	mutex m_mutex;
	unsigned int size_;
	fstream  m_producerfile;
	fstream  m_consumerfile;
	bool m_bExit;
	int m_iValue;

};

int main()
{
	ProducerConsumer pc;
	vector<thread> threads;

	//Producers
	for (int i = 1; i <= 1; ++i)
	{
		threads.push_back(thread(&ProducerConsumer::Produce, &pc));
	}

	//Consumers
	for (int i = 1; i <= 1; ++i)
	{
		threads.push_back(thread(&ProducerConsumer::Consume, &pc));
	}

	threads.push_back(thread(&ProducerConsumer::Monitor, &pc));

	for (auto& thread1 : threads)
	{
		thread1.join();
	}

	pc.DumpContent();

	return 0;
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
