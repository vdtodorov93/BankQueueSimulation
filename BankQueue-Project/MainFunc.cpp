#include<iostream>
#include "Cashier.h"
#include<vector>
#include "QueueGenerator.h"
#include "Bank.h"
int main()
{
	Bank corpBank;
	corpBank.SimulateWorkDay();
	corpBank.MakeFullReport();
	
	return 0;
}