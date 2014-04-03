/**
 * \file		BasicStringOperation.hpp
 * \author		fcaillaud
 * \version 	1.0
 * \date     	1 Avril 2014
 * \brief     	Fichier utilitaire implémentant les opérations usuelles sur les chaîne de caractères.
 */

#ifndef STRINGOPERATION
#define STRINGOPERATION

#include <string>
#include <sstream>
#include <vector>

#ifdef OS_WINDOWS
 	/**
 	 * Délimiteur Windows
 	 */
	#define FILE_DELIMITOR '\\'
#else
 	/**
 	 * Délimiteur Unix
 	 */
	#define FILE_DELIMITOR '/'
#endif

/**
 * Opérateur de séparation entre le nom de fichier et l'extention.
 */
#define EXTENSION_SEPARATOR '.'

/**
 * \namespace 	gu
 * \brief 		Nom de domaine tertiaire, partie utilitaire.
 */
namespace gu
{

	/**
	 * Séparation d'une chaîne de caractères en plusieurs chaînes de caractères.
	 * \param 	stringToSplit 	Chaîne de caractères à séparer.
	 * \param 	delim 			Caractère de délimitation de la découpe.
	 * \return 	Une liste de chaîne de caractères.
	 */
	std::vector<std::string> Split(const std::string & stringToSplit, char delim);

	/**
	 * Récupération du nom et de l'extension d'un fichier à partir d'un chemin complet.
	 * \param 	filePath 		Chemin complet vers le fichier concerné.
	 * \param 	fileName 		Nom du fichier (donnée résultat).
	 * \param 	fileExtension 	Extension du fichier (donnée résultat).
	 * \return 	true si le fichier a bien une extension, false sinon.
	 */
	bool GetFileNameAndExtension(const std::string & filePath, std::string & fileName, std::string & fileExtension);

	/**
	 * Vérification de l'état de commentaire d'une ligne.
	 * \param 	line 			Chaîne de caractères analysée.
	 * \param 	commentSign		Caractère de commentaire recherché.
	 * \return 	true si la ligne est un commentaire, false sinon.
	 * \details Un commentaire est une ligne qui ne contient que des " " ou "\t" avant 
	 * 			le caractère de commentaire. Si les commentaires sont mis après du texte
	 *			dans la ligne ils ne seront pas détectés.
	 */
	bool IsComments(const std::string line, char commentSign);

	/**
	 * Nettoyage d'une chaîne de caractères de tous ses commentaires.
	 * \param 	line 			Chaîne de caractères à nettoyer.
	 * \param	commentSign		Caractère de commentaire recherché.
	 * \return 	Une chaîne de caractères similaire à line mais nettoyée
	 *			de ses commentaires.
	 * \details	Tout ce qui se trouve après commentSign n'est pas retenu
	 *			ainsi que les espaces entre commentSign et le dernier caractère
	 *			différent de " " ou "\t".
	 */
	std::string WithoutComments(const std::string line, char commentSign);

	/**
	 * Nettoyage d'une chaîne de caractères d'un caractère particulier.
	 * \param 	str 	Chaîne de caractères à nettoyer.
	 * \param 	c 		Caractère à ne pas retenir.
	 * \return 	Une chaîne de caractère nettoyée des caractères égaux à c.
	 */
	std::string WithoutChar(const std::string & str, char c);

	/**
	 * Nettoyage d'une chaîne de caractères de ses espaces du début.
	 * \param 	str 	Chaîne de caractères à nettoyer.
	 * \return 	Une chaîne de caractères nettoyée de ses espaces du début.
	 */
	std::string WithoutFrontSpace(const std::string & str);

	/**
	 * Nettoyage d'une chaîne de caractères de ses espaces de fin.
	 * \param 	str 	Chaîne de caractères à nettoyer.
	 * \return 	Une chaîne de caractères nettoyée de ses espaces de fin.
	 */
	std::string WithoutBackSpace(const std::string & str);

	/**
	 * Nettoyage d'une chaîne de caractères de ses espaces.
	 * \param 	str 	Chaîne de caractères à nettoyer.
	 * \return 	Une chaîne de caractères nettoyée de ses espaces.
	 */
	std::string WithoutSpace(const std::string & str);

}

#endif
