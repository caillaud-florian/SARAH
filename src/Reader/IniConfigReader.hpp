/**
 * \file		IniConfigReader.hpp
 * \author		fcaillaud
 * \version 	0.1
 * \date     	28 Octobre 2013
 * \brief     	Fichier implémentant un lecteur de fichiers INI.
 * \detail 		Ce lecteur a été implémenté pour répondre à la base strict du format INI. Néanmoins,
 * 				il permet également de sauter des lignes, de mettre des commentaires (# et ;) pleine ligne
 *				ou à la fin d'une ligne. Voir la fonction Read() de la classe pour plus de détails.
 */

#ifndef INICONFIGREADER
#define INICONFIGREADER

#include <map>
#include <vector>
#include <string>

#include "BaseReader.hpp"

/**
 * \namespace 	Nom de domaine principal.
 */	
namespace Sarah
{
/**
 * \namespace 	Nom de domaine secondaire, partie entrées/sorties.
 */	
namespace IO
{

	/**
	 * \class 	Classe représentant un lecteur de fichiers INI
	 */
	class IniConfigReader : public BaseReader
	{
			/**
			 * \typedef 	Un dictionnaire de noms associés à des valeur est une \a Section
			 */
			typedef std::map<std::string, std::string> 	Section;
			/**
			 * \typedef 	Un dictionnaire de noms associés à une section est une \a Config décrite par le fichier INI
			 */
			typedef std::map<std::string, Section>  	Config;

		public:

			/**
			 * \fn 		Constructeur paramétré
			 * \param 	p_filePath 	Chemin du fichier servant à construire le BaseReader
			 */
			IniConfigReader(std::string);

			/**
			 * \fn 		Redefinition de la fonction purement virtuelle Read() de BaseReader
			 * \return 	true si la lecture c'est bien passée, false sinon.
			 */
			virtual bool Read();

			/**
			 * \fn 		Accesseur renvoyant la configuration
			 * \detail 	Avant la fonction Read(), \a m_config est vide, après, si une erreur est apparue,
			 * 			elle sera incomplète, si la lecture s'est bien passée, elle sera complète et contiendra
			 * 			les informations décrites dans le fichier INI.
			 * \return 	La configuration de l'objet IniConfigReader.
			 */
			Config GetConfig() const;

		private:

			/**
			 * \brief 	La configuration à remplir gràce à la fonction Read().
			 */
			Config m_config;

	};
	
}
}

#endif
