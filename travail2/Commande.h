#ifndef CommandeH
#define CommandeH

#include <iostream>
#include <string>
#include "produit/Produit.h"
#include "Client.h"
#include "LigneCommande.h"

using namespace std;


class Commande
{
private:
	int maxProduitCommande = 5;
	Client nomClient;
	bool commandeFinal;
public:
	//constructeur
	Commande();
	Commande(const Commande& inCommande);
	//set
	void setNomClient(string);
	void setCommandeFinal(bool);
	//get
	string getNomClient() const;
	bool getcommandeFinal() const;

};







#endif