/**
 * \file		BasicNumberOperation.hpp
 * \author		fcaillaud
 * \version 	1.0
 * \date     	1 Avril 2014
 * \brief     	Fichier utilitaire implémentant les opérations usuelles sur les nombres.
 * \todo 		Mettre en const référence les paramètres juste analysés.
 */

#ifndef BASICNUMBEROPERATION
#define BASICNUMBEROPERATION

#include <iostream>
#include <sstream>
#include <cmath>

/**
 * \namespace 	gu
 * \brief 		Nom de domaine tertiaire, partie utilitaire.
 */
namespace gu
{

	/**
	 * Récupération du signe d'un nombre de type double.
	 * \param 	pNumber 	Nombre analysé.
	 * \return 	1 si pNumber est positif, -1 sinon.
	 */
	int Sign(double pNumber);

	/**
	 * Récupération du nombre de chiffres après la virgule d'un nombre de type double.
	 * \param 	pNumber 	Nombre analysé.
	 * \return 	Le nombre de chiffres après la virgule de pNumber.
	 * \todo 	À revoir car cela ne détecte pas plus de 16 chiffres après la virgule (à cause de la conversion int/double).
	 */
	unsigned int NbFractDigit(double pNumber);

	/**
	 * Récupération du nombre de chiffres avant la virgule d'un nombre de type int.
	 * \param 	pNumber 	Nombre analysé.
	 * \return 	Le nombre de chiffres avant la virgule de pNumber.
	 * \details	Le type de pNumber (int) est choisi car il faut de toute façon une conversion en int.
	 * 			Donc il n'y a pas de perte d'informations ici.
	 */
	unsigned int NbIntDigit(int pNumber);

	/**
	 * Récupération du nombre total de chiffres d'un nombre de type double.
	 * \param 	pNumber 	Nombre analysé.
	 * \return 	Le nombre total de chiffres de pNumber (avant et après la virgule).
	 */
	unsigned int NbDigit(double pNumber);

	/**
	 * Récupération du nombre total d'éléments d'un nombre de type double.
	 * \param 	pNumber 	Nombre analysé.
	 * \return 	Le nombre total d'éléments composants pNumber.
	 * \details	Un élément peut être un chiffre, un signe (- ou +) ou un point (virgule).
	 * \todo 	Vérifier si cela ne comprend pas l'écriture scientifique également.
	 */
	unsigned int NbAlpha(double pNumber);

	/**
	 * Récupération de la troncature d'un nombre de type double.
	 * \param 	pNumber 			Nombre analysé.
	 * \param 	pNbLeftFractDigit	Nombre de décimale voulue après troncature.
	 * \return 	Le nombre pNumber avec seulement pNbLeftFractDigit chiffres après la virgule.
	 * \details	Si pNbLeftFractDigit est 0 alors le résultat sera un entier.
	 * 			Si pNbLeftFractDigit est plus grand que le nombre de chiffre après la virgule
	 *			de pNumber alors le résultat est égal à pNumber.
	 * \todo 	Vérifier la fonction car il me semble qu'elle est fausse.
	 */
	double Truncate(double pNumber, unsigned int pNbLeftFractDigit);

}

#endif
