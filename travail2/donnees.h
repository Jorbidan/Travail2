#pragma once
#include "produit/Produit.h"
#include "Commande.h"
const int maxCommandes = 25;
const int maxProduitsAVendre = 40;

class Donnees
{
private:
	void AjouterLesProduitsAVendre();
public:
	Donnees();
	Produit produitsAVendre[maxProduitsAVendre];
	Commande commandesFait[maxCommandes];
};

