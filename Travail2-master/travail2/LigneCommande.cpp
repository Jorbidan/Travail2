#include "LigneCommande.h"

//CONSTRUCTEUR---------------------------------------------------------------------------
LigneCommande::LigneCommande(): produitAchat()
{
	quantite = 0;
}

LigneCommande::LigneCommande(const LigneCommande& inLigneCommande) : produitAchat(inLigneCommande.produitAchat)
{
	quantite = inLigneCommande.getQuantite();
}

//SET------------------------------------------------------------------------------------
void LigneCommande::setQuantite(int inQuantite)
{
	quantite = inQuantite;
}

void LigneCommande::setProduit(Produit* inProduit)
{
	produitAchat = inProduit;
}

//GET------------------------------------------------------------------------------------
int LigneCommande::getQuantite() const
{
	return quantite;
}

Produit* LigneCommande::getProduit() const
{
	return produitAchat;
}
