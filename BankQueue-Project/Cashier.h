#include "Client.h"
#ifndef CASHIER_H
#define CASHIER_H
class Cashier
{
private:
	int minutesToServeClient;
	int minutesFree;
	int clientsServed;
	Client *currentClient;

public:
	Cashier();
	
	int GetMinutesToServeClient();

	void SetMinutesToServeClient(int);

	int GetMinutesFree();

	void SetMinutesFree(int);

	int GetClientsServed();

	void SetClientsServed(int);

	Client * GetCurrentClient();

	void SetCurrentClient(Client *);

	void DecrementMinutesToServerClient();

	void IncrementServedClientsCount();

	void IncrementMinutesFree();
};
#endif