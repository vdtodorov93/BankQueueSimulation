#include "Bank.h"

void Bank::ResetDatas()
{
	servedClients = 0;
	totalWaitedTime = 0;
	totalQueueSize = 0;
	maxQueueSize = 0;
	totalCashiersFreeTime = 0;
	while(!clients.empty())
	{
		clients.pop();
	}
}

Bank::Bank()
{
	ResetDatas();
}
void Bank::SimulateWorkDay()
{
	ResetDatas();
	int currentClient = 0;
	QueueGenerator generator;
	std::queue<Client> dayClients = generator.GetClientsForDay();
	std::queue<Client> currentQueue;
	for(int currMinute = 1 ; currMinute <= WORK_TIME ; currMinute++)
	{
		//The client "enters" the bank
		if(!dayClients.empty())
		{
			if(dayClients.front().GetMinuteToComeIn() <= currMinute)
			{
				currentQueue.push(dayClients.front());
				dayClients.pop();
			}
		}
		//If there is a cashier, finishing his work with the current client right in that moment
		for(int i = 0 ; i < CASHIERS_COUNT ; i++)
		{
			Client* currentCashierClient = cashiers[i].GetCurrentClient();
			if(currentCashierClient != nullptr)
			{
				cashiers[i].DecrementMinutesToServerClient();
				if(cashiers[i].GetMinutesToServeClient() <= 0)
				{
					cashiers[i].SetCurrentClient(nullptr);
					cashiers[i].IncrementServedClientsCount();
				}
			}
		}

		//At this moment all the free cashiers should take customers from the queue, if there are people in it
		for(int i = 0 ; i < CASHIERS_COUNT ; i++)
		{
			if(cashiers[i].GetCurrentClient() == nullptr)
			{
				if(!currentQueue.empty())
				{
					Client *nextClient = new Client();
					*nextClient = currentQueue.front();
					currentQueue.pop();
					cashiers[i].SetCurrentClient(nextClient);
					cashiers[i].SetMinutesToServeClient(1 + rand() % 20);
					this->totalWaitedTime += currMinute - nextClient->GetMinuteToComeIn();
				}
			}

		}

		if(currentQueue.size() > this->maxQueueSize)
		{
			this->maxQueueSize = currentQueue.size();
		}
		this->totalQueueSize += currentQueue.size();

		for(int i = 0 ; i < CASHIERS_COUNT ; i++)
		{
			if(cashiers[i].GetCurrentClient() == nullptr)
			{
				cashiers[i].IncrementMinutesFree();
			}
		}
	}
	//the day is over. We accept that cashiers finish their work with current customers.

	for(int i = 0 ; i < CASHIERS_COUNT ; i++)
	{
		if(cashiers[i].GetCurrentClient() != nullptr)
		{
			cashiers[i].IncrementServedClientsCount();
		}
	}
	//Sending off all the not-served customers

	for(int i = 0 ; i < CASHIERS_COUNT ; i++)
	{
		this->servedClients += cashiers[i].GetClientsServed();
		this->totalCashiersFreeTime += cashiers[i].GetMinutesFree();
	}
}

void Bank::MakeFullReport()
{
	std::cout << "Total number of served clients: " << this->servedClients << std::endl;
	for(int i = 0 ; i < CASHIERS_COUNT ; i++)
	{
		std::cout << "Cashier " << i + 1 << " served " << cashiers[i].GetClientsServed() << " customers today" << std::endl;
	}
	std::cout << "Average time clients waited on queue is: " << (this->totalWaitedTime) / ((double)this->servedClients) << std::endl;
	std::cout << "Average queue size: " << this->totalQueueSize / ((double)WORK_TIME) << std::endl;
	std::cout << "Maximal queue size: " << this->maxQueueSize << std::endl;

	int totalWorkTime = WORK_TIME * CASHIERS_COUNT;
	std::cout << "Percent of time cashiers are free: " << 
		(this->totalCashiersFreeTime / ((double)totalWorkTime)) * 100 << "%" << std::endl;
}