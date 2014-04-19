#include "QueueGenerator.h"


std::queue<Client> QueueGenerator::GetClientsForDay()
{
	srand ( time(NULL) );
	std::vector<Client> clients;
	int totalNumberClients = 50 + rand() % 200;
	for(int i = 0 ; i < totalNumberClients ; i++)
	{
		Client newClient;
		//sets the new customer to enter the bank between  1 and 480 minute
		newClient.SetMinuteToComeIn(1 + rand() % 480);
		clients.push_back(newClient);
	}
	//sorting them by the moment they come into the bank
	for(int i = 0 ; i < clients.size() - 1 ; i++)
	{
		for(int j = i + 1; j < clients.size() ; j++)
		{
			if(clients[i].GetMinuteToComeIn() > clients[j].GetMinuteToComeIn())
			{
				Client tmp = clients[i];
				clients[i] = clients[j];
				clients[j] = tmp;
			}
		}
	}

	std::queue<Client> result;
	for(int i = 0 ; i < clients.size() ; i++)
	{
		if(i == 0 || (clients[i].GetMinuteToComeIn() != clients[i-1].GetMinuteToComeIn()))
		{
			result.push(clients[i]);
		}
	}
	return result;
}