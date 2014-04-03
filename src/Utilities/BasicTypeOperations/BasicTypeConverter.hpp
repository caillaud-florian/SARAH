/**
 * \file		BasicTypeConverter.hpp
 * \author		fcaillaud
 * \version 	1.0
 * \date     	1 Avril 2014
 * \brief     	Fichier utilitaire implémentant les opérations usuelles de convertions 
 * 				de type simple à type simple.
 * \todo 		Voir pour gérer les cas d'erreur de conversion avec des exceptions.
 */


#ifndef GENERAL_UTLITIES_BASICTYPECONVERTER
#define GENERAL_UTLITIES_BASICTYPECONVERTER

#include <cstring>
#include <cstdio>
#include <iostream>
#include <cctype>

/**
 * \namespace 	gu
 * \brief		Nom de domaine tertiaire, partie utilitaire.
 */
namespace gu
{
	//======================== char * to others ==========================

	/**
	 * Convertit un pointeur sur char en char.
	 * \param 	pA 	La chaîne de caractères à convertir.
	 * \return	Le premier caractère de la chaîne.
	 */
	char AtoChar(const char * pA);

	/**
	 * Convertit une chaîne de caractères en std::string.
	 * \param 	pA 	La chaîne de caractères à convertir.
	 * \return 	Un objet std::string résultant de pA.
	 */
	std::string AtoString(const char * pA);

	/**
	 * Convertit une chaîne de caractères en booléen.
	 * \param 	pA 	La chaîne de caractères à convertir.
	 * \result	true si pA = "true", false si pA = "false", erreur sinon.
	 * \details La comparaison n'est pas sensible à la casse.
	 * \todo 	utiliser plutôt des exceptions.
	 */
	bool AtoBool(const char * pA);

	/**
	 * Convertit une chaîne de caractères en entier.
	 * \param 	pA 	La chaîne de caractères à convertir.
	 * \result	L'entier correspondant à pA.
	 */
	int AtoInt(const char * pA);

	/**
	 * Convertit une chaîne de caractères en entier non signé.
	 * \param 	pA 	La chaîne de caractères à convertir.
	 * \result	L'entier non signé correspondant à pA.
	 */
	unsigned int AtoUInt(const char * pA);

	/**
	 * Convertit une chaîne de caractères en entier court.
	 * \param 	pA 	La chaîne de caractères à convertir.
	 * \result	L'entier court correspondant à pA.
	 */
	short int AtoSInt(const char * pA);

	/**
	 * Convertit une chaîne de caractères en entier long.
	 * \param 	pA 	La chaîne de caractères à convertir.
	 * \result	L'entier long correspondant à pA.
	 */
	long int AtoLInt(const char * pA);

	/**
	 * Convertit une chaîne de caractères en entier doublement long.
	 * \param 	pA 	La chaîne de caractères à convertir.
	 * \result	L'entier doublement long correspondant à pA.
	 */
	long long int AtoLLInt(const char * pA);

	/**
	 * Convertit une chaîne de caractères en double.
	 * \param 	pA 	La chaîne de caractères à convertir.
	 * \result	Le double correspondant à pA.
	 */
	double AtoDouble(const char * pA);

	/**
	 * Convertit une chaîne de caractères en double long.
	 * \param 	pA 	La chaîne de caractères à convertir.
	 * \result	Le double long correspondant à pA.
	 */
	long double AtoLDouble(const char * pA);

	/**
	 * Convertit une chaîne de caractères en float.
	 * \param 	pA 	La chaîne de caractères à convertir.
	 * \result	Le float correspondant à pA.
	 */
	float AtoFloat(const char * pA);

	/**
	 * Convertit une chaîne de caractères en chaîne de caractères minuscules. 
	 * \param 	pA 	La chaîne de caractères à convertir.
	 * \result	La chaîne de caractères correspondant à pA en minuscules.
	 */
	char * AtoLower(const char * pA);

	/**
	 * Convertit une chaîne de caractères en chaîne de caractères majuscules. 
	 * \param 	pA 	La chaîne de caractères à convertir.
	 * \result	La chaîne de caractères correspondant à pA en majuscules.
	 */
	char * AtoUpper(const char * pA);
	
}

#endif
