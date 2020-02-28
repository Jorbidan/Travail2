#ifndef LigneCommandeH
#define LigneCommandeH

#include <iostream>
#include <string>
#include "produit/Produit.h"

using namespace std;

class LigneCommande
{
	private:
		int quantite;
		Produit* produitAchat;
	public:
	//constructeur
		LigneCommande();
		LigneCommande(const LigneCommande& inLigneCommande);
	//set
		void setQuantite(int);
		void setProduit(Produit*);
	//get
		int getQuantite() const;
		Produit* getProduit()const;
};
#endif
