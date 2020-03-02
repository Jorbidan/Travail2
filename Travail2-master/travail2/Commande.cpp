#include "Commande.h"

//CONSTRUCTEUR---------------------------------------------------------------------------
Commande::Commande() : lignesAchat()
{
	 nomClient = "";
	 commandeFinal = false;
}

Commande::Commande(const Commande& inCommande)
{
	nomClient = inCommande.nomClient;
	commandeFinal = inCommande.commandeFinal;
	for (int cpt = 0; cpt < 5; cpt++)
	{
		lignesAchat[cpt] = inCommande.lignesAchat[cpt];
	}
}


//SET------------------------------------------------------------------------------------
void Commande::setNomClient(string inNomClient)
{
	nomClient = inNomClient;
}

void Commande::setCommandeFinal(bool inCommandeFinal)
{
	commandeFinal = inCommandeFinal;
}

void Commande::setLignesAchat(int cpt,int inQuantite, Produit* inProduit)
{

	lignesAchat[cpt].setQuantite(inQuantite);
	lignesAchat[cpt].setProduit(inProduit);
}

void Commande::setQuantiteLigneAchat(int cpt,int inQuantite)
{
	lignesAchat[cpt].setQuantite(inQuantite);
}

//GET------------------------------------------------------------------------------------
string Commande::getNomClient() const
{
	return nomClient;
}

bool Commande::getcommandeFinal() const
{
	return commandeFinal;
}

LigneCommande Commande::getLigneAchat(int cpt) const
{
	return 	lignesAchat[cpt];
}

Produit* Commande::getProduitLigneAchat(int cpt) const
{
	return 	lignesAchat[cpt].getProduit();
}

string Commande::getCodeProduitLigneAchat(int cpt) const
{
	string code = "";
	if (lignesAchat[cpt].getProduit() != NULL)
	{
		code = lignesAchat[cpt].getProduit()->getCode();
	}
	return code;
}

string Commande::getNomProduitLigneAchat(int cpt) const
{
	string nom = "";
	if (lignesAchat[cpt].getProduit() != NULL)
	{
		nom = lignesAchat[cpt].getProduit()->getNom();
	}
	return nom;
}

int Commande::getPrixProduitLigneAchat(int cpt) const
{
	int prix = 0;
	if (lignesAchat[cpt].getProduit() != NULL)
	{
		prix = lignesAchat[cpt].getProduit()->getPrix();
	}
	return prix;
}

int Commande::getQuantiteLigneAchat(int cpt) const
{
	return lignesAchat[cpt].getQuantite();
}
