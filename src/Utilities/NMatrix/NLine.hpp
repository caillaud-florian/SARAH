/**
 * \file		NLine.hpp
 * \author		fcaillaud
 * \version 	1.0
 * \date     	2 Avril 2014
 * \brief     	Fichier décrivant la classe NLine.
 * \details		Classe utilisée pour représenter une ligne ou colonne de matrice (plus ou moins un vecteur).
 * \todo 		Réfléchir à une meilleure approche pour toute la classe.
 */

#ifndef NMATRIX_NLINE
#define NMATRIX_NLINE

#include <vector>

#include <stdlib.h>

/**
 * \namespace 	alg
 * \brief 		Nom de domaine tertiaire, partie utilitaire.
 * \todo 		Migrer vers le namespace gu.
 */
namespace alg
{

	/**
	 * \enum 	LineState
	 * \brief 	Type de vecteur, soit ligne, soit colonne.
	 */
	enum LineState
	{
		LS_ROW,		/*!< Vecteur de type ligne. */
		LS_COLUMN 	/*!< Vecteur de type colonne. */
	};

	/**
	 * \class 	NLine
	 * \brief 	Classe représentant un vecteur de matrice (soit ligne, soit colonne).
	 * \details Classe template avec le type Mtype qui sera le type des valeurs contenues dans le vecteur.
	 */
	template<class MType = double>
	class NLine
	{

		public:

			/**
			 * Constructeur par défaut.
			 * \details 	Construit un vecteur de taille 0.
			 */
			NLine():
				mSize(),
				mLine(),
				mHasToBeAllDeleted(false)
			{
				//EMPTY
			}

			/**
			 * Constructeur paramétré.
			 * \param 	pSize 	La taille du vecteur voulu.
			 * \details Construit un vecteur de taille pSize.
			 */
			NLine(unsigned int pSize):
				mSize(pSize),
				mLine(new MType *[pSize]),
				mHasToBeAllDeleted(true)
			{
				for(unsigned int i = 0; i < mSize; ++i)
					mLine[i] = new MType();
			}

			/**
			 * Constructeur par copie.
			 * \param 	pLine 	Le vecteur à copier.
			 */
			NLine(const NLine & pLine):
				mSize(pLine.mSize),
				mLine(new MType *[pLine.mSize]),
				mHasToBeAllDeleted(false)
			{
				for(unsigned int i = 0; i < mSize; ++i)
					mLine[i] = pLine.mLine[i];
			}

			/**
			 * Constructeur par copie.
			 * \param 	pMatrixData 	La matrice cotenant le vecteur à copier.
			 * \param 	pInd		 	L'indice de la ligne ou de la colonne dans la matrice.
			 * \param 	pSize			Les dimensions de la matrice à copier.
			 * \param 	pLineState	 	Le type de vecteur à copier (ligne ou colonne).
			 * \todo 	Enlever pSize, pas besoin, utiliser les dimensions de la matrice à copier.
			 */
			NLine(MType * pMatrixData, int pInd, std::pair<unsigned int, unsigned int> pSize, LineState pLineState):
				mSize(),
				mLine(),
				mHasToBeAllDeleted(false)
			{
				if(pLineState == LS_ROW){
					mSize = pSize.first;
					mLine = new MType *[mSize];
					for(unsigned int i = 0; i < mSize; ++i)
						mLine[i] = pMatrixData + (pInd * pSize.first + i);
				}else{
					mSize = pSize.second;
					mLine = new MType *[mSize];
					for(unsigned int i = 0; i < mSize; ++i)
						mLine[i] = pMatrixData + (i * pSize.first + pInd);
				}
			}

			/**
			 * Destructeur
			 * \details 	Si mHasToBeAllDeleted est à false, il n'efface pas les pointeurs 
			 *				sur les valeurs stockées.
			 */
			~NLine()
			{
				if(mHasToBeAllDeleted)
					for(unsigned int i = 0; i < mSize; ++i)
						delete mLine[i];

				delete [] mLine;
			}

			/**
			 * Récupération de la valeur à l'indice souhaité.
			 * \param 	pInd 	L'indice de la valeur à récupérer dans le vecteur.
			 * \return 	La valeur à l'indice pInd dans le vecteur.
			 */
			const MType GetAt(int pInd)
			{
				return *mLine[pInd];
			}

			/**
			 * Change la valeur à l'indice souhaité.
			 * \param 	pInd 	L'indice de la valeur à changer dans le vecteur.
			 * \param 	pData 	La nouvelle valeur.
			 */
			void SetAt(int pInd, MType pData)
			{
				*mLine[pInd] = pData;
			}

			/**
			 * Récupération de la valeur à l'indice souhaité.
			 * \param 	pInd 	L'indice de la valeur à récupérer dans le vecteur.
			 * \return 	La valeur à l'indice pInd dans le vecteur.
			 */
			MType operator[] (int pInd)
			{
				return *mLine[pInd];
			}

			/**
			 * Addition de deux vecteurs.
			 * \param 	pLine 	L'autre vecteur à additionner.
			 * \return 	Le vecteur résultant de l'addition.
			 * \details	Additionne valeur par valeur.
			 */
			NLine operator+ (NLine pLine)
			{
				if(mSize != pLine.mSize){
					std::cerr << "ERROR : In NLine +, the addition between two lines with different size (" << mSize << ", " << pLine.mSize << ") can't be done." << std::endl;
					exit(-1);
				}

				NLine<MType> vLine(mSize);
				for(unsigned int i = 0; i < mSize; ++i)
					*(vLine.mLine[i]) = *mLine[i] + pLine[i];

				return vLine;
			}

			/**
			 * Soustraction de deux vecteurs.
			 * \param 	pLine 	Le vecteur que l'on soustrait.
			 * \return 	Le vecteur résultant de la soustraction.
			 * \details	Soustrait valeur par valeur.
			 */
			NLine operator- (NLine pLine)
			{
				if(mSize != pLine.mSize){
					std::cerr << "ERROR : In NLine -, the substraction between two lines with different size (" << mSize << ", " << pLine.mSize << ") can't be done." << std::endl;
					exit(-1);
				}

				NLine<MType> vLine(mSize);
				for(unsigned int i = 0; i < mSize; ++i)
					*(vLine.mLine[i]) = *mLine[i] - pLine[i];

				return vLine;
			}

			/**
			 * Multiplication de deux vecteurs.
			 * \param 	pLine 	L'autre vecteur à multiplier.
			 * \return 	Le vecteur résultant de la multiplication.
			 * \details	Multiplie valeur par valeur.
			 */
			double operator* (NLine pLine)
			{
				unsigned int vSize = pLine.mSize;
				double vRes = 0.0;

				if(mSize != vSize){
					std::cerr << "ERROR : In NLine *, the substraction between two lines with different size (" << mSize << ", " << pLine.mSize << ") can't be done." << std::endl;
					exit(-1);
				}

				for(unsigned int i = 0; i < vSize; ++i)
					vRes += (*mLine[i]) * (*(pLine.mLine[i]));
				
				return vRes;
			}

			/**
			 * Récupère la taille du vecteur.
			 * \return 	La taille du vecteur.
			 * \todo 	Changer le nom de la fonction pour GetSize(), plus cohérent.
			 */
			unsigned int Size()
			{
				return mSize;
			}

			/**
			 * Récupère le pointeur sur les éléments du vecteur.
			 * \return 	Le pointeur sur les éléments du vecteur.
			 */
			MType ** SData()
			{
				return mLine;
			}

			/**
			 * Ajout d'un pointeur sur valeur dans le vecteur.
			 * \param 	pData 	Le pointeur sur valeur à ajouter.
			 * \details	Le vecteur s'agrandit et sa taille s'incrémente.
			 */
			void Add(MType * pData)
			{
				mSize++;
				mLine = (MType *) realloc(mLine, mSize * sizeof(MType *));
				mLine[mSize - 1] = pData;
			}

			/**
			 * Affichage du vecteur.
			 * \details Affiche sur la sortie standard les valeurs du vecteur.
			 * \todo 	Utiliser Msg (dans les autres fonction également) ET
			 *			différencier l'affichage en colonne et en ligne.
			 */
			void Print()
			{
				for(unsigned int i = 0; i < mSize; ++i)
					std::cout << *mLine[i] << " ";
			}

		private:

			/**
			 * \brief 	Taille du vecteur.
			 */
			unsigned int mSize;

			/**
			 * \brief 	Tableau des pointeurs sur les valeurs.
			 */
			MType ** mLine;

			/**
			 * \brief 	État de suppression des pointeurs sur les valeurs.
			 */
			bool mHasToBeAllDeleted;

	};

}

#endif
