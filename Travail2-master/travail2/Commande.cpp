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
	/*bool trouver = false;
	for (int cpt = 0; cpt < 5 && trouver == false; cpt++)
	{
		if (lignesAchat[cpt].getQuantite() == NULL)
		{
			trouver = true;
			lignesAchat[cpt].setQuantite(inQuantite);
			lignesAchat[cpt].setProduit(inProduit);
		}
	}*/
	lignesAchat[cpt].setQuantite(inQuantite);
	lignesAchat[cpt].setProduit(inProduit);
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
