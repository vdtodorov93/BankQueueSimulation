#ifndef CLIENT_H
#define CLIENT_H
class Client
{
private:
	int minuteToComeIn;

public:
	void SetMinuteToComeIn(int);

	int GetMinuteToComeIn();

	Client();
};
#endif