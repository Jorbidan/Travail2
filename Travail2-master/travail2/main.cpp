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
void AfficherUneLigneCommande(int, int);


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
		if (achatProduit != "non" && cpt < maxProduitCommande && achatProduit != "NON")
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
				cpt -= 1;
			}
		}
		else
		{
			cpt = maxProduitCommande;
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
		if (gestionCommande.commandesFait[cpt].getProduitLigneAchat(0) == NULL)
		{															
			gestionCommande.setCommandeFait(cpt, inCommande);
			cpt = maxCommandes;
		}
	}
}

void AfficherLesCommandes()
{
	ClrScr();
	for (int cpt = 0; (cpt < maxCommandes) && (gestionCommande.commandesFait[cpt].getProduitLigneAchat(0) != NULL); cpt++)
	{
		cout << gestionCommande.commandesFait[cpt].getNomClient() << "\n";
		int totalCommande = 0;
		for (int cptLignes = 0; cptLignes < maxProduitCommande; cptLignes++)
		{
			if (gestionCommande.commandesFait[cpt].getProduitLigneAchat(cptLignes) != NULL)
			{
				AfficherUneLigneCommande(cpt, cptLignes);
				totalCommande += gestionCommande.commandesFait[cpt].getPrixProduitLigneAchat(cptLignes) * gestionCommande.commandesFait[cpt].getQuantiteLigneAchat(cptLignes);
				if ((gestionCommande.commandesFait[cpt].getProduitLigneAchat(cptLignes + 1) == NULL) || (cptLignes + 1 == maxProduitCommande))
				{
					cout << totalCommande << "$ au total pour la commande!\nI---------------------------I\n";
				}
			}
		}
	}
	system("pause");
	
	/*for (int cpt = 0; cpt < maxCommandes; cpt++)
	{
		if (gestionCommande.commandesFait[cpt].getNomClient() != "")
		{
			int totalCommande = 0;
			cout << gestionCommande.commandesFait[cpt].getNomClient() << "\n";
			for (int cptLignes = 0; cptLignes < maxProduitCommande; cptLignes++)
			{
				if (gestionCommande.commandesFait[cpt].getLigneAchat(cptLignes).getProduit() != NULL)//4:ajouter apres pour regler l'erreur mais sans succès....
				{																							  //5:oui c'Est vraiment qu'il lit quelquechose de vide et n'Aiime pas ca....
					cout << gestionCommande.commandesFait[cpt].getLigneAchat(cptLignes).getProduit()->getCode() << " "//1:Erreur a partir d'ici??? On dirait qu'il trouve une valeur NULL et il n'aime pas ca...
						<< gestionCommande.commandesFait[cpt].getLigneAchat(cptLignes).getProduit()->getNom() << " "  //2:Il en affiche 1 au complet, mais pas plus...
						<< gestionCommande.commandesFait[cpt].getLigneAchat(cptLignes).getProduit()->getPrix() << "$ chaque " //3:si le tableau est plein il ne semble aps faire l'erreur
						<< gestionCommande.commandesFait[cpt].getLigneAchat(cptLignes).getQuantite() << " fois\n     Pour "
						<< gestionCommande.commandesFait[cpt].getLigneAchat(cptLignes).getProduit()->getPrix() * gestionCommande.commandesFait[cpt].getLigneAchat(cptLignes).getQuantite() << "$.\n";
					totalCommande += gestionCommande.commandesFait[cpt].getLigneAchat(cptLignes).getProduit()->getPrix() * gestionCommande.commandesFait[cpt].getLigneAchat(cptLignes).getQuantite();
				}
				else
				{
					cptLignes = maxProduitCommande;
				}
			}
			cout << totalCommande << "$ au total pour la commande!\nI---------------------------I\n";
		}
	}
	system("pause");*/
}

void AfficherUneLigneCommande(int cpt,int cptLignes)
{
		cout << gestionCommande.commandesFait[cpt].getCodeProduitLigneAchat(cptLignes) << " "
			<< gestionCommande.commandesFait[cpt].getNomProduitLigneAchat(cptLignes) << " "
			<< gestionCommande.commandesFait[cpt].getPrixProduitLigneAchat(cptLignes) << "$ chaque "
			<< gestionCommande.commandesFait[cpt].getQuantiteLigneAchat(cptLignes) << " fois\n     Pour "
			<< gestionCommande.commandesFait[cpt].getPrixProduitLigneAchat(cptLignes) * gestionCommande.commandesFait[cpt].getQuantiteLigneAchat(cptLignes) << "$.\n";
}

void TraiterLesCommandes()
{
	ClrScr();
	for (int cpt = 0; cpt < maxCommandes; cpt++)
	{
		string reponseStr;
		int reponseInt;
		if (gestionCommande.commandesFait[cpt].getProduitLigneAchat(0) != NULL && gestionCommande.commandesFait[cpt].getcommandeFinal() == false)
		{
			int totalCommande = 0;
			cout << gestionCommande.commandesFait[cpt].getNomClient() << "\n";
			for (int cptLignes = 0; cptLignes < maxProduitCommande && gestionCommande.commandesFait[cpt].getProduitLigneAchat(cptLignes) != NULL; cptLignes++)
			{
				if (gestionCommande.commandesFait[cpt].getProduitLigneAchat(cptLignes) != NULL)
				{
					AfficherUneLigneCommande(cpt, cptLignes);
					totalCommande += gestionCommande.commandesFait[cpt].getPrixProduitLigneAchat(cptLignes) * gestionCommande.commandesFait[cpt].getQuantiteLigneAchat(cptLignes);
					if ((gestionCommande.commandesFait[cpt].getProduitLigneAchat(cptLignes + 1) == NULL) || (cptLignes + 1 == maxProduitCommande))
					{
						cout << totalCommande << "$ au total pour la commande!\nI---------------------------I\n";
					}
				}
			}
			cout <<"Voulez-vous finaliser la commande?(oui/non)\n";
			cin >> reponseStr;
			if (reponseStr != "non" && reponseStr != "NON")
			{
				while (reponseStr != "non" && reponseStr != "NON")
				{												  
					cout << "Voulez-vous modifier des quantites?(oui/non)\n";
					cin >> reponseStr;
					if (reponseStr != "non" && reponseStr != "NON")
					{
						cout << "Entrez le code de produit que vous voulez modifiez la quantite.\n";
						cin >> reponseStr;
						bool codeTrouver = false;
						for (int cptLignes = 0; cptLignes < maxProduitCommande && codeTrouver == false; cptLignes++)
						{
							if (reponseStr == gestionCommande.commandesFait[cpt].getCodeProduitLigneAchat(cptLignes))
							{
								cout << "Quel sera la nouvelle quantite?\n";
								cin >> reponseInt;
								gestionCommande.commandesFait[cpt].setQuantiteLigneAchat(cpt,reponseInt);
								codeTrouver = true;
								cout << "Modification effectue avec succes.\n";
							}
						}
						if (codeTrouver == false)
						{
							cout << "Aucun code de produit commander correspond au code entre.\n";
						}
					}
				}
				cout << "La commande est maintenant final!\n";
				gestionCommande.commandesFait[cpt].setCommandeFinal(true);
			}
			else
			{
				cout << "Aucun changement effectue!\n";
			}
		}
	}
	cout << "Il n'y as plus de commande a finnaliser.\n";
	system("pause");
}

