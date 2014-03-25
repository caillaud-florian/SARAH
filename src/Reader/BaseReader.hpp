/**
 * \file		BaseReader.hpp
 * \author		fcaillaud
 * \version 	0.1
 * \date     	28 Octobre 2013
 * \brief     	Fichier implémentant un lecteur de fichiers génériques abstrait.
 * \todo 		Mettre une option pour les commentaires pleine ligne, les commentaires fin de ligne, etc.
 */

#ifndef READER
#define READER

#include "../Utilities/File/IOFile.hpp"
#include "../Utilities/Message/Msg.hpp"

#include <boost/regex.hpp>

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
	 * \enum 	FileReadState
	 * \detail 	État du de la lecture de fichier
	 */
	enum FileReadState
	{
		NOTOPENED,			/*!< Le fichier n'a pas été ouvert. */
		CORRUPTED,			/*!< Les dernières données lues ont été illégalement changées. */	
		FAILLED,			/*!< Les dernières données n'ont pas réussi à être lues. */
		SUCCEED,			/*!< La lecture s'est bien passée. */
		UNDEFINED			/*!< État à l'initialisation, avant d'appeler la fonction Read(). */
	};

	/**
	 * \class 		Classe représentant un lecteur virtuel de fichiers génériques
	 */
	class BaseReader
	{
		public:

			/**
			 * \fn 		Constructeur paramétré (pas de constructeur par défaut)
			 * \param 	p_filePath 	Le chemin absolu ou relatif vers le fichier à lire
			 */
			BaseReader(std::string p_filePath):
				m_file(p_filePath),
				m_state(UNDEFINED)
			{

			}

			/**
			 * \fn 		Accesseur renvoyant l'état de la lecture du fichier \a m_file
			 * \return 	L'état \a m_state de la lecture.
			 */
			FileReadState GetState() const
			{
				return m_state;
			}

			/**
			 * \fn 		Fonction purement virtuelle de lecture et de traitement de \a m_file
			 * \return 	true si la lecture s'est bien passée, false sinon.
			 */
			virtual bool Read() = 0;

			/**
			 * \fn 		Fonction de lecture de la ligne courante du fichier
			 * \detail 	Utilisation de la fonction getLine() de la STL, mais avec une gestion plus précise d'erreur.
			 * 			En cas d'erreur la fonction UpdateFileReadState est appelée.
			 * \param 	p_line 	Chaîne de caractère résultat de la lecture de la ligne
			 * \param 	p_readingSize 	Taille en caractères de la ligne à lire (par défault 256)
			 * \return 	true si la lecture de la ligne n'a pas rencontrée d'erreur, false sinon.
			 */
			bool GetLine(std::string & p_line, unsigned int p_readingSize = 256)
			{
				char * vLine = new char[p_readingSize];
				if(m_file.getline (vLine, p_readingSize)){
					p_line = std::string(vLine);
					delete vLine;
					return true;
				}else{
					delete vLine;
					UpdateFileReadState();
					return false;
				}
			}

			/**
			 * \fn 		Fonction déclarant si la lecture s'est bien passée ou pas
			 * \return 	true si la lecture s'est bien passée, false sinon.
			 */
			bool HasSucceed()
			{
				return m_state == SUCCEED;
			}

		private:

			/**
			 * \fn 		Fonction interne (private) mettant à jour l'état de la lecture
			 * \detail 	La fonction vérifie l'état du fichier pour voir s'il n'a pas été ouvert, corrompu,
			 * 			pas pu être lu à un moment, ou au contraire si tout s'est bien passé.
			 */
			void UpdateFileReadState()
			{
				if(!m_file.is_open())
					m_state = NOTOPENED;
				else if(m_file.eof())
					m_state = SUCCEED;
				else if(m_file.bad())
					m_state = CORRUPTED;
				else
					m_state = FAILLED;
			}

		protected:

			/**
			 * \brief 	Le fichier à lire (de type gu::IFile héritant de std::ifstream).
			 */
			gu::IFile m_file;
			/**
			 * \brief 	L'état de lecture du fichier \a m_file.
			 */
			FileReadState m_state;
	};
	
}
}

#endif
