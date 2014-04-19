#include<vector>
#include<queue>
#include <cstdlib>
#include<time.h>
#include "Client.h"
#include<iostream>
#ifndef QUEUEGENERATOR_H
#define QUEUEGENERATOR_H
class QueueGenerator
{
public:
	std::queue<Client> GetClientsForDay();
};
#endif