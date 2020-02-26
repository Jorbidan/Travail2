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

//GET------------------------------------------------------------------------------------
string Commande::getNomClient() const
{
	return nomClient;
}

bool Commande::getcommandeFinal() const
{
	return commandeFinal;
}
