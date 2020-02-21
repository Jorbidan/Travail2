#ifndef LigneCommandeH
#define LigneCommandeH

#include <iostream>
#include <string>
#include "produit/Produit.h"
#include "LigneCommande.h"

using namespace std;

int maxProduitCommande = 5
class LigneCommande
{
	private:
		int quantite;
	public:
	//constructeur
		LigneCommande();
		LigneCommande(const LigneCommande& inLigneCommande);
	//set
		void setQuantite(int);
	//get
		int getQuantite() const;
};
#endif
