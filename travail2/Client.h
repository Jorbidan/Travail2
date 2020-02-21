#ifndef ClientH
#define ClientH

#include <iostream>
#include <string>

using namespace std;


class Client
{
private:
	string nomClient;
	int Telephone;
	string adresse;
public:
	//constructeur
	Client();
	Client(const Client & inCLient);
	//set
	void setNomClient(string);
	void setTelephone(int);
	void setAdresse(string);

	//get
	string getNomClient() const;
	int getTelephone() const;
	string getAdresse() const;

};

#endif