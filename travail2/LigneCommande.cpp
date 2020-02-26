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

//GET------------------------------------------------------------------------------------
int LigneCommande::getQuantite() const
{
	return quantite;
}
