#ifndef CommandeH
#define CommandeH

#include <iostream>
#include <string>
#include "produit/Produit.h"
#include "LigneCommande.h"

using namespace std;

int maxProduitCommande = 5;

class Commande
{
	private:
		string nomClient;
		bool commandeFinal;
		LigneCommande lignesAchat[5];
	public:
	//constructeur
		Commande();
		Commande(const Commande&);
	//set
		void setNomClient(string);
		void setCommandeFinal(bool);
		void setLignesAchat(int, Produit*);
	//get
		string getNomClient() const;
		bool getcommandeFinal() const;

};







#endif