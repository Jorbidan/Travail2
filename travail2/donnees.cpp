#include "donnees.h"

Donnees::Donnees()
{
	AjouterLesProduitsAVendre();
}

void Donnees::AjouterLesProduitsAVendre()
{
	produitsAVendre[0].InitialiserProduit("obj1", "feuxfous fuseboum", "feux d'artifices invuln�rables aux sorts", 7);
	produitsAVendre[1].InitialiserProduit("obj2", "leurre explosif", "sert � faire diversion", 6);
	produitsAVendre[2].InitialiserProduit("bon6", "berlingot de fi�vre", "confiserie qui fait monter la temp�rature et provoque des furoncles sur les fesses", 2);
	produitsAVendre[3].InitialiserProduit("bon1", "chocogrenouille", "confiserie qui prend la forme d'une grenouille qui saute", 1);
	produitsAVendre[4].InitialiserProduit("bon2", "drag�e surprise de Bertie Crochue", "drag�e existant en plusieurs saveurs: chocolat, foie, tripe, sang de gobelin, fraise, gazon, �", 2);
	produitsAVendre[5].InitialiserProduit("bon3", "boite � flemme", "confiserie dont la premi�re moiti� rend malade et la deuxi�me est un antidote", 4);
	produitsAVendre[6].InitialiserProduit("bon4", "pastille de gerbe", "confiserie qui fait vomir", 2);
	produitsAVendre[7].InitialiserProduit("bon5", "bulle baveuse", "gomme produisant des bulles mauves", 1);
	produitsAVendre[8].InitialiserProduit("obj3", "cape bouclier", "cape protectrice contre mal�fice mineur", 5);
	produitsAVendre[9].InitialiserProduit("obj4", "r�ve �veill�", "plonge la personne dans un r�ve r�aliste pendant 30 min", 7);
	produitsAVendre[10].InitialiserProduit("obj5", "poudre d'obscurit�", "poudre noire produisant une obscurit� dense", 8);
	produitsAVendre[11].InitialiserProduit("obj6", "�chec", "jeu d'�chec version sorcier o� les pi�ces sont anim�es et grandeur nature", 12);
	produitsAVendre[12].InitialiserProduit("obj7", "oreille � rallonge", "permet d'�couter une conversation inaudible", 5);
	produitsAVendre[13].InitialiserProduit("obj8", "plume � papotte", "note des propos en les exag�rant", 5);
	produitsAVendre[14].InitialiserProduit("pot1", "potion de babillage", "provoque des propos insens�s", 3);
	produitsAVendre[15].InitialiserProduit("pot2", "potion d'enflure", "potion qui fait enfler la personne", 4);
	produitsAVendre[16].InitialiserProduit("pot3", "philtre d'amour", "rend temporairement une personne vraiment amouseuse d'une autre", 9);
	produitsAVendre[17].InitialiserProduit("bon7", "marque des t�n�bres comestible", "confiserie qui rend malade � coup s�r", 3);
	produitsAVendre[18].InitialiserProduit("obj9", "mar�cage portable", "transforme un espace en mar�cage", 6);
	produitsAVendre[19].InitialiserProduit("obj10", "chapeau sans t�te", "une fois sur la t�te, le chapeau et la t�te de la personne deviennent invisibles", 4);

}



