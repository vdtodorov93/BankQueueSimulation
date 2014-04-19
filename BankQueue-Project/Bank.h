#include "Cashier.h"
#include "Client.h"
#include "QueueGenerator.h"
#include<queue>
#include<iostream>
#define CASHIERS_COUNT 4
#define WORK_TIME 480
class Bank
{
private:
	Cashier cashiers[CASHIERS_COUNT];
	std::queue<Client> clients;
	int servedClients;
	int totalWaitedTime;
	int totalQueueSize;
	int maxQueueSize;
	int totalCashiersFreeTime;

	void ResetDatas();
public:
	Bank();
	void SimulateWorkDay();

	void MakeFullReport();
};