#include "Client.h"
void Client::SetMinuteToComeIn(int minute)
{
	this->minuteToComeIn = minute;
}

int Client::GetMinuteToComeIn()
{
	return this->minuteToComeIn;
}

Client::Client()
{
	this->minuteToComeIn = 0;
}
