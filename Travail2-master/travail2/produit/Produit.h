#ifndef produitH
#define produitH
#include <string>
using namespace std;

class Produit
{
private:
	string codeProduit;
	string nom;
	string description;
	int prixUnitaire;
public:
	Produit();
	Produit(const Produit&);
	string getCode() const;
	string getNom() const;
	string getDescription() const;
	int getPrix() const;
	//retourne une chaine de caract�res form�e du code et du nom du produit
	string ObtenirIdentificationProduit() const;
	//donne une valeur � tous les attributs du produit
	//retourne un bool indiquant si l'initialisation a r�ussie (param�tres valides)
	bool InitialiserProduit(string code, string nom, string description, int prixUnitaire);
};

#endif