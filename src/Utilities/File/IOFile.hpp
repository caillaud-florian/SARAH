/**
 * \file		IOFile.hpp
 * \author		fcaillaud
 * \version 	1.0
 * \date     	1 Avril 2014
 * \brief     	Fichier décrivant la classe File, IFile, OFile et IOFile.
 * \details		Classe utilisée pour modéliser un fichier et ainsi pouvoir facilement 
 *				l'ouvrir, connaître son status, etc. Utilise la bibliothèque standard
 * 				"iostream" et "fstream".
 */

#ifndef UTILS_IOFILE
#define UTILS_IOFILE

#include <fstream>
#include <iostream>
#include <string>

#include "../BasicTypeOperations/BasicStringOperation.hpp"

/**
 * \namespace 	gu
 * \brief 		Nom de domaine tertiaire, partie utilitaire.
 */
namespace gu
{

	/**
	 * \enum 	FileType
	 * \brief 	Type du fichier : en lecture, en écriture ou en lecture / écriture.
	 */
	enum FileType
	{
		IFILE,		/*!< Fichier en lecture seule. */
		OFILE,		/*!< Fichier en écriture seule. */
		IOFILE 		/*!< Fichier en lecture / écriture. */
	};

	/**
	 * \class 	File
	 * \brief 	Classe mère servant de base à tous les types de fichiers (abstraite).
	 */
	class File
	{

		public:

			/**
			 * Constructeur paramétré (pas de constructeur par défaut).
			 * \param 	filePath 	Chemin du fichier à prendre en charge.
			 * \details Trouve et remplit directement du nom, de l'extension et la taille du fichier.
			 */
			File(std::string);

			/**
			 * Récupération du nom du fichier.
			 * \return 	Le nom du fichier pris en charge.
			 */
			std::string GetName() const;

			/**
			 * Vérification de l'existence d'une extension ou non pour le fichier.
			 * \return 	true si le fichier a une extension, false sinon.
			 */
			bool HasExtension() const;

			/**
			 * Récupération de l'extension du fichier.
			 * \return 	L'extension du fichier pris en charge.
			 */
			std::string GetExtension() const;

			/**
			 * Récupération de la taille du fichier.
			 * \return 	La taille du fichier pris en charge.
			 */
			unsigned int Size() const;

			/**
			 * Récupération du type du fichier.
			 * \return 	Le type du fichier pris en charge (IFILE, OFILE ou IOFILE).
			 */
			virtual FileType GetType() const = 0;

		protected:

			/**
			 * \brief 	Nom du fichier.
			 */
			std::string m_name;

			/**
			 * \brief 	Existence de l'extension du fichier.
			 */
			bool m_hasExtension;

			/**
			 * \brief 	Extension du fichier.
			 */
			std::string m_extension;

			/**
			 * \brief 	Taille du fichier.
			 */
			long m_size;

	};

	/**
	 * \class 	IFile
	 * \brief 	Classe décrivant un fichier en lecture seule.
	 * \details	Hérite de std::ifstream et peut donc être utilisé comme tel.
	 */
	class IFile : public std::ifstream, public File
	{

		public:

			/**
			 * Constructeur paramétré (pas de constructeur par défaut).
			 * \param 	filePath 	Chemin du fichier à prendre en charge.
			 * \details Trouve et remplit directement du nom, de l'extension et la taille du fichier.
			 */
			IFile(std::string);

			/**
			 * Redéfinition de la fonction GetType de File.
			 * \return IFile de type FileType.
			 */
			virtual FileType GetType() const;

	};

	/**
	 * \class 	OFile
	 * \brief 	Classe décrivant un fichier en écriture seule.
	 * \details	Hérite de std::ofstream et peut donc être utilisé comme tel.
	 */
	class OFile : public std::ofstream, public File
	{

		public:

			/**
			 * Constructeur paramétré (pas de constructeur par défaut).
			 * \param 	filePath 	Chemin du fichier à prendre en charge.
			 * \details Trouve et remplit directement du nom, de l'extension et la taille du fichier.
			 */
			OFile(std::string);

			/**
			 * Redéfinition de la fonction GetType de File.
			 * \return OFile de type FileType.
			 */
			virtual FileType GetType() const;

	};

	/**
	 * \class 	IOFile
	 * \brief 	Classe décrivant un fichier en lecture / écriture.
	 * \details	Hérite de IFile et de OFile donc de std::ifstream et 
	 *			de std::ofstream. Elle peut donc être utilisé comme telle.
	 */
	class IOFile : public IFile, public OFile
	{	

		public:

			/**
			 * Constructeur paramétré (pas de constructeur par défaut).
			 * \param 	filePath 	Chemin du fichier à prendre en charge.
			 * \details Trouve et remplit directement du nom, de l'extension et la taille du fichier.
			 */
			IOFile(std::string);

			/**
			 * Redéfinition de la fonction GetType de File.
			 * \return IOFile de type FileType.
			 */
			virtual FileType GetType() const;

	};

	/**
	 * Récupération de la taille d'un fichier.
	 * \param 	filePath 	Chemin du fichier analysé.
	 * \return 	La taille du fichier en octet (caractère).
	 */
	long GetFileSize(std::string filePath);

}

#endif
