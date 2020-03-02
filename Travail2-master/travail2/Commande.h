#ifndef CommandeH
#define CommandeH

#include <iostream>
#include <string>
#include "produit/Produit.h"
#include "LigneCommande.h"

using namespace std;

const int maxProduitCommande = 5; //erreur qu'il existe deja dans produit.obj?? mais ne me permet pas de l'utilier dans main...

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
		void setLignesAchat(int,int, Produit*);
		void setQuantiteLigneAchat(int,int);
	//get
		string getNomClient() const;
		bool getcommandeFinal() const;
		LigneCommande getLigneAchat(int) const;
		Produit* getProduitLigneAchat(int) const;
		string getCodeProduitLigneAchat(int)const;
		string getNomProduitLigneAchat(int)const;
		int getPrixProduitLigneAchat(int)const;
		int getQuantiteLigneAchat(int)const;
};







#endif