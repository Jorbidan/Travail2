#include <string>
#include <conio.h>
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include "..\screen\screen.h"
using namespace std;

#include "donnees.h" 

Donnees gestionCommande;

char AfficherMenu();
void CreerCommande();
void AjouterCommande(Commande);
void AfficherLesCommandes();
void TraiterLesCommandes();
bool AjouterUneLigne(string, Commande);

void main()
{
	char choix = ' ';
	while (choix != '0')
	{
		choix = AfficherMenu();
		switch (choix)
		{
		case '1': CreerCommande();
			break;
		case '2': AfficherLesCommandes();
			break;
		case '3': TraiterLesCommandes();
			break;
		}
	}
}
char AfficherMenu()
{
	char choix;
	TextBackground(Blue);
	TextColor(White);
	ClrScr();
	Gotoxy(40,1);
	cout << "Choisir une option";
	Gotoxy(40, 4);
	cout << "1- Creer une commande";
	Gotoxy(40, 6);
	cout << "2- Afficher les commandes";
	Gotoxy(40, 8);
	cout << "3- Traiter les commandes";
	Gotoxy(40, 10);
	cout << "0- Arreter";
	Gotoxy(40, 12);
	cout << "Choix: ";
	cin >> choix;
	TextBackground(Black);
	TextColor(Lightgray);
	return choix;
}
void CreerCommande()
{
	ClrScr();
	Commande laCommande;
	string reponseStr;
	cout << "Nom du client : ";
	cin >> reponseStr;
	laCommande.setNomClient(reponseStr);
	ClrScr();
	cout << "Bonjour "<<laCommande.getNomClient()<<",\n";
	string achatProduit = "";
	for (int cpt = 0; cpt< 5;cpt++)
	{
		cout << "Voulez-vous ajouter un autre produit a votre commande?(oui/non)\n";
		cin >> achatProduit;
		if (achatProduit != "non" && cpt < 5&& achatProduit != "NON")
		{
			cout << "Entrez le code de produit que vous voulez acheter.\n";
			cin >> reponseStr;
			if (AjouterUneLigne(reponseStr, laCommande) == true)
			{
				int reponseInt;
				cout << "Combien voulez-vous en acheter?\n";
				cin >> reponseInt;
				laCommande.setLignesAchat(cpt,reponseInt, &gestionCommande.produitsAVendre[cpt]);
			}
			else{
				cout << "Aucun code de produit correspond au code entre.\n";
			}
		}
		else
		{
			cpt = 5;
		}
	}
	ClrScr();
AjouterCommande(laCommande);
}
bool AjouterUneLigne(string reponseStr, Commande laCommande)
{
	bool codeTrouver = false;
	for (int cpt = 0; cpt < maxProduitsAVendre && codeTrouver == false; cpt++)
	{
		if (reponseStr == gestionCommande.produitsAVendre[cpt].getCode())
		{
			codeTrouver = true;	
		}
	}
	return codeTrouver;
}

//pour tester constructeur par recopie
void AjouterCommande(Commande inCommande) 
{
	for (int cpt = 0; cpt < maxCommandes; cpt++)
	{
		if (&gestionCommande.commandesFait[cpt] == NULL)
		{
			gestionCommande.setCommandeFait(cpt, inCommande);
			cpt = maxCommandes;
		}
	}
}

void AfficherLesCommandes()
{

}

void TraiterLesCommandes()
{

}

