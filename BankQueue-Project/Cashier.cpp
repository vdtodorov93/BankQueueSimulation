//#include "Client.h"
#include "Cashier.h"
Cashier::Cashier()
{
	this->minutesToServeClient = 0;
	this->minutesFree = 0;
	this->clientsServed = 0;
	this->currentClient = nullptr;
}

int Cashier::GetMinutesToServeClient()
{
	return minutesToServeClient;
}

void Cashier::SetMinutesToServeClient(int minToServe)
{
	this ->minutesToServeClient = minToServe;
}

int Cashier::GetMinutesFree()
{
	return minutesFree;
}

void Cashier::SetMinutesFree(int minFree)
{
	this ->minutesFree = minFree;
}


int Cashier::GetClientsServed()
{
	return clientsServed;
}

void Cashier::SetClientsServed(int served)
{
	this ->clientsServed = served;
}

Client * Cashier::GetCurrentClient()
{
	return this->currentClient;
}

void Cashier::SetCurrentClient(Client *client)
{
	if(this->currentClient != nullptr)
	{
		delete this->currentClient;
	}
	this->currentClient = client;
}

void Cashier::DecrementMinutesToServerClient()
{
	this->minutesToServeClient--;
}

void Cashier::IncrementServedClientsCount()
{
	this->clientsServed++;
}

void Cashier::IncrementMinutesFree()
{
	this->minutesFree++;
}