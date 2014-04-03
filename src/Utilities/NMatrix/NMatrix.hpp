/**
 * \file		NMatrix.hpp
 * \author		fcaillaud
 * \version 	1.0
 * \date     	2 Avril 2014
 * \brief     	Fichier décrivant la classe NMatrix.
 * \details		Classe représentant une matrice de valeurs de taille (largeur et hauteur) quelconque.
 */

#ifndef NMATRIX_NMATRIX
#define NMATRIX_NMATRIX

#include "NLine.hpp"
#include "Utilities/BasicTypeOperations/BasicNumberOperation.hpp"

/**
 * Passage entre coordonnées 2D et coordonnées 1D, pour plus de confort.
 */
#define MCOORD(i, j) (((j)*(mWidth)) + (i))

/**
 * \namespace 	alg
 * \brief 		Nom de domaine tertiaire, partie utilitaire.
 * \todo 		Migrer vers le namespace gu.
 */
namespace alg
{

	/**
	 * \enum 	MATRIX_COPY_FLAG
	 * \brief 	Type de copie concernant les matrices.
	 */
	enum MATRIX_COPY_FLAG
	{
		M_NO_COPY, 		/*!< Pas de réallocation de pointeurs. */
		M_COPY 			/*!< Réallocation des pointeurs. */
	};

	/**
	 * \enum 	MATRIX_TYPE
	 * \brief 	Type des matrices.
	 */
	enum MATRIX_TYPE
	{
		M_ZERO, 		/*!< Matrice nulle, remplie de 0. */
		M_IDENT 		/*!< Matrice identité, diagonale de 1. */
	};

	/**
	 * \class 	NMatrix
	 * \brief 	Classe représentant une matrice de valeurs de type donné, de dimensions quelconques.
	 * \details	Classe template avec le type des valeurs qu'elle renferme.
	 */
	template<class MType = double>
	class NMatrix
	{

		public:

			/**
			 * Constructeur par défaut.
			 * \details 	Construit une matrice 3x3 de valeurs indéterminées.
			 */
			NMatrix():
				mMat(new MType[3 * 3]),
				mWidth(3),
				mHeight(3)
			{
				//EMPTY
			}

			/**
			 * Constructeur paramétré.
			 * \param 	pDim 	La dimension en largeur et en hauteur de la matrice.
			 * \param 	pType 	Le type de la matrice.
			 * \details Construit une matrice carré de type pType.
			 */
			NMatrix(unsigned int pDim, MATRIX_TYPE pType):
				mMat(new MType[pDim * pDim]),
				mWidth(pDim),
				mHeight(pDim)
			{
				unsigned int vSize = pDim * pDim;
				switch(pType)
				{
					case M_ZERO:
						for(unsigned int i = 0; i < vSize; ++i)
							mMat[i] = 0;
						break;
					case M_IDENT:
						for(unsigned int j = 0; j < pDim; ++j)
							for(unsigned int i = 0; i < pDim; ++i)
								mMat[MCOORD(i, j)] = (i == j)? 1 : 0;
						break;
				}
			}

			/**
			 * Constructeur paramétré.
			 * \param 	pDim 	La dimension en largeur et en hauteur de la matrice.
			 * \details Construit une matrice carré de valeurs indéterminées.
			 */
			NMatrix(unsigned int pDim):
				mMat(new MType[pDim * pDim]),
				mWidth(pDim),
				mHeight(pDim)
			{
				//EMPTY
			}

			/**
			 * Constructeur paramétré.
			 * \param 	pWidth 		La dimension en largeur de la matrice.
			 * \param 	pHeight		La dimension en hauteur de la matrice.
			 * \details Construit une matrice pWidth x pHeight de valeurs indéterminées.
			 */
			NMatrix(unsigned int pWidth, unsigned int pHeight):
				mMat(new MType[pWidth * pHeight]),
				mWidth(pWidth),
				mHeight(pHeight)
			{
				//EMPTY
			}

			/**
			 * Constructeur paramétré.
			 * \param 	pWidth 		La dimension en largeur de la matrice.
			 * \param 	pHeight		La dimension en hauteur de la matrice.
			 * \param 	pType 		Le type de la matrice.
			 * \details Construit une matrice pWidth x pHeight.
			 */
			NMatrix(unsigned int pWidth, unsigned int pHeight, MATRIX_TYPE pType):
				mMat(new MType[pWidth * pHeight]),
				mWidth(pWidth),
				mHeight(pHeight)
			{
				unsigned int vSize = pWidth * pHeight;
				switch(pType)
				{
					case M_ZERO:
						for(unsigned int i = 0; i < vSize; ++i)
							mMat[i] = 0;
						break;
				}
			}

			/**
			 * Constructeur par copie.
			 * \param 	pNMat 	La matrice à copier.
			 * \details Réalloue des pointeurs propre à la matrice.
			 */
			NMatrix(const NMatrix<MType> & pNMat):
				mMat(new MType[pNMat.mWidth * pNMat.mHeight]),
				mWidth(pNMat.mWidth),
				mHeight(pNMat.mHeight)
			{
				for(unsigned int i = 0; i < pNMat.Size(); ++i)
					mMat[i] = pNMat.GetAt(i);
			}

			/**
			 * Constructeur par copie.
			 * \param 	pPMType 	Le pointeurs sur les valeurs à copier.
			 * \param 	pWidth 		La dimension en largeur de la matrice.
			 * \param 	pHeight		La dimension en hauteur de la matrice.
			 * \param 	pFlag 		Le type de copie (avec ou sans réallocation).
			 */
			NMatrix(MType * pPMType, unsigned int pWidth, unsigned int pHeight, MATRIX_COPY_FLAG pFlag = M_NO_COPY):
				mMat(),
				mWidth(pWidth),
				mHeight(pHeight)
			{
				unsigned int vSize = pWidth * pHeight;
				switch(pFlag)
				{
					case M_NO_COPY:
						mMat = pPMType;
						break;
					case M_COPY:
						mMat = new MType[vSize];
						for(unsigned int i = 0; i < vSize; ++i)
								mMat[i] = pPMType[i];
						break;
				}				
			}

			/**
			 * Destructeur.
			 */
			~NMatrix()
			{
				delete [] mMat;
			}

			/**
			 * Récupération de la ligne à l'indice voulu.
			 * \param 	pInd 	L'indice de la ligne voulue.
			 * \return 	La ligne (vecteur) à l'indice pInd dans la matrice.
			 */
			NLine<MType> GetRowAt(int pInd)
			{
				return NLine<MType>(mMat, pInd, std::pair<unsigned int, unsigned int>(mWidth, mHeight), LS_ROW);
			}

			/**
			 * Récupération de la colonne à l'indice voulu.
			 * \param 	pInd 	L'indice de la colonne voulue.
			 * \return 	La colonne (vecteur) à l'indice pInd dans la matrice.
			 */
			NLine<MType> GetColumnAt(int pInd)
			{
				return NLine<MType>(mMat, pInd, std::pair<unsigned int, unsigned int>(mWidth, mHeight), LS_COLUMN);
			}

			/**
			 * Récupération de la valeur à l'indice voulu.
			 * \param 	pInd 	L'indice de la valeur voulue.
			 * \return 	La valeur à l'indice pInd (1D) dans la matrice.
			 */
			const MType GetAt(int pInd) const
			{
				return mMat[pInd];
			}

			/**
			 * Récupération de la valeur aux indices voulus.
			 * \param 	pX 	L'indice de la ligne.
			 * \param 	pY 	L'indice de la colonne.
			 * \return 	La valeur aux indices pX et pY dans la matrice.
			 */
			const MType GetAt(int pX, int pY) const
			{
				return mMat[MCOORD(pX, pY)];
			}

			/**
			 * Changement d'une valeur aux indices voulus.
			 * \param 	pX 		L'indice de la ligne.
			 * \param 	pY 		L'indice de la colonne.
			 * \param 	pData	La nouvelle valeur.
			 */
			void SetAt(int pX, int pY, MType pData)
			{
				mMat[MCOORD(pX, pY)] = pData;
			}

			/**
			 * Récupération de la valeur aux indices voulus.
			 * \param 	pX 	L'indice de la ligne.
			 * \param 	pY 	L'indice de la colonne.
			 * \return 	La valeur aux indices pX et pY dans la matrice.
			 */
			MType & operator() (int pX, int pY)
			{
				return mMat[MCOORD(pX, pY)];
			}

			/**
			 * Récupération de la valeur à l'indice voulu.
			 * \param 	pInd 	L'indice de la valeur voulue.
			 * \return 	La valeur à l'indice pInd (1D) dans la matrice.
			 */
			MType & operator[] (int pInd)
			{
				return mMat[pInd];
			}

			/**
			 * Récupération de la largeur de la matrice.
			 * \return 	La largeur de la matrice.
			 * \todo 	Écrire GetWidth plutôt, plus cohérent.
			 */
			unsigned int Width() const
			{
				return mWidth;
			}

			/**
			 * Récupération de la hauteur de la matrice.
			 * \return 	La hauteur de la matrice.
			 * \todo 	Écrire GetWidth plutôt, plus cohérent.
			 */
			unsigned int Height() const
			{
				return mHeight;
			}

			/**
			 * Récupération de la taille de la matrice (largeur x hauteur).
			 * \return 	La taille de la matrice (largeur x hauteur).
			 * \todo 	Écrire GetWidth plutôt, plus cohérent.
			 */
			unsigned int Size() const
			{
				return mWidth * mHeight;
			}

			/**
			 * Récupération du pointeur sur les éléments de la matrice.
			 * \return 	Le pointeur sur les éléments de la matrice.
			 */
			MType * SData()
			{
				return mMat;
			}

			/**
			 * Addition de la matrice par un double.
			 * \param 	pFactor 	Le double à additionner avec toutes les valeurs de la matrice.
			 * \return 	La matrice résultante de cette addition.
			 * \todo 	Mettre le type du paramètre en MType, logique.
			 */
			NMatrix<MType> operator +(double pFactor)
			{
				NMatrix<MType> vMatrix(mMat, mWidth, mHeight, M_COPY);
				unsigned int vSize = mWidth * mHeight;

				for(unsigned int i = 0; i < vSize; ++i)
					vMatrix[i] += pFactor;

				return vMatrix;
			}

			/**
			 * Addition de la matrice par un double.
			 * \param 	pFactor 	Le double à additionner avec toutes les valeurs de pMatrix.
			 * \param 	pMatrix 	La matrice à additionner.
			 * \return 	La matrice résultante de cette addition.
			 * \todo 	Mettre le type du paramètre en MType, logique.
			 */
			friend NMatrix<MType> operator +(double pFactor, NMatrix<MType> pMatrix)
			{
				unsigned int vSize = pMatrix.Width() * pMatrix.Height();

				for(unsigned int i = 0; i < vSize; ++i)
					pMatrix[i] += pFactor;

				return pMatrix;
			}

			/**
			 * Addition de deux matrices.
			 * \param 	pMatrix 	La matrice à additionner.
			 * \return 	La matrice résultante de cette addition.
			 * \details	Additionne valeur par valeur.
			 */
			NMatrix<MType> operator +(NMatrix<MType> pMatrix)
			{
				if(mWidth != pMatrix.mWidth || mHeight != pMatrix.mHeight){
					std::cerr << "ERROR : You try to sum two matrices with different width or height !" << std::endl;
					exit(-1);
				}

				NMatrix<MType> vMatrix(mMat, mWidth, mHeight, M_COPY);
				unsigned int vSize = mWidth * mHeight;

				for(unsigned int i = 0; i < vSize; ++i)
					vMatrix[i] += pMatrix.GetAt(i);

				return vMatrix;
			}

			/**
			 * Soustraction de la matrice par un double.
			 * \param 	pFactor 	Le double à soustraire sur toutes les valeurs de la matrice.
			 * \return 	La matrice résultante de cette soustraction.
			 * \todo 	Mettre le type du paramètre en MType, logique.
			 */
			NMatrix<MType> operator -(double pFactor)
			{
				NMatrix<MType> vMatrix(mMat, mWidth, mHeight, M_COPY);
				unsigned int vSize = mWidth * mHeight;

				for(unsigned int i = 0; i < vSize; ++i)
					vMatrix[i] -= pFactor;

				return vMatrix;
			}

			/**
			 * Soustraction de la matrice par un double.
			 * \param 	pFactor 	Le double à soustraire sur toutes les valeurs de la matrice.
			 * \param 	pMatrix 	La matrice à soustraire.
			 * \return 	La matrice résultante de cette soustraction.
			 * \todo 	Mettre le type du paramètre en MType, logique. Se demander le sens de cette opération !!!
			 */
			friend NMatrix<MType> operator -(double pFactor, NMatrix<MType> pMatrix)
			{
				unsigned int vSize = pMatrix.Width() * pMatrix.Height();

				for(unsigned int i = 0; i < vSize; ++i)
					pMatrix[i] -= pFactor;

				return pMatrix;
			}

			/**
			 * Soustraction de deux matrices.
			 * \param 	pMatrix 	La matrice à soustraire.
			 * \return 	La matrice résultante de cette soustraction.
			 * \details	Soustrait valeur par valeur.
			 */
			NMatrix<MType> operator -(NMatrix<MType> pMatrix)
			{
				if(mWidth != pMatrix.mWidth || mHeight != pMatrix.mHeight){
					std::cerr << "ERROR : You try to substract two matrices with different width or height !" << std::endl;
					exit(-1);
				}

				NMatrix<MType> vMatrix(mMat, mWidth, mHeight, M_COPY);
				unsigned int vSize = mWidth * mHeight;

				for(unsigned int i = 0; i < vSize; ++i)
					vMatrix[i] -= pMatrix.GetAt(i);

				return vMatrix;
			}

			/**
			 * Multiplication de la matrice par un double.
			 * \param 	pFactor 	Le double à multiplier à toutes les valeurs de la matrice.
			 * \return 	La matrice résultante de cette multiplication.
			 * \todo 	Mettre le type du paramètre en MType, logique.
			 */
			NMatrix<MType> operator *(double pFactor)
			{
				NMatrix<MType> vMatrix(mMat, mWidth, mHeight, M_COPY);
				unsigned int vSize = mWidth * mHeight;

				for(unsigned int i = 0; i < vSize; ++i)
					vMatrix[i] *= pFactor;

				return vMatrix;
			}

			/**
			 * Multiplication de la matrice par un double.
			 * \param 	pFactor 	Le double à multiplier à toutes les valeurs de la matrice.
			 * \param 	pMatrix 	La matrice à multiplier.
			 * \return 	La matrice résultante de cette multiplication.
			 * \todo 	Mettre le type du paramètre en MType, logique.
			 */
			friend NMatrix<MType> operator *(double pFactor, NMatrix<MType> pMatrix)
			{
				unsigned int vSize = pMatrix.Width() * pMatrix.Height();

				for(unsigned int i = 0; i < vSize; ++i)
					pMatrix[i] *= pFactor;

				return pMatrix;
			}

			/**
			 * Multiplication de deux matrices.
			 * \param 	pMatrix 	La matrice à multiplier.
			 * \return 	La matrice résultante de cette multiplication.
			 * \details	Il s'agit d'une multiplication de matrice, cela ne multiplie par valeur par valeur.
			 * \todo 	Pourquoi cela ne multiplie pas valeur par valeur.
			 */
			NMatrix<MType> operator *(NMatrix<MType> pMatrix)
			{
				if(mWidth != pMatrix.mHeight || mHeight != pMatrix.mWidth){
					std::cerr << "ERROR : You try to multiply two matrices with wrong proportions !" << std::endl;
					exit(-1);
				}

				NMatrix<MType> vMatrix(mMat, mWidth, mHeight, M_COPY);
				unsigned int vSize = std::min(mWidth, mHeight);

				for(unsigned int j = 0; j < vSize; ++j)
					for(unsigned int i = 0; i < vSize; ++i)
						vMatrix.SetAt(i, j, GetRowAt(j) * pMatrix.GetColumnAt(i));

				return vMatrix;
			}

			/**
			 * Affichage d'une matrice.
			 * \param 	pNbTruncatedDigit 	Le nombre de chiffres après la virgule souhaités lors de l'affichage.
			 * \details Affiche sur la sortie standard les valeurs de la matrice.
			 * \todo 	Utiliser Msg (dans les autres fonction également)
			 */
			void Print(unsigned int pNbTruncatedDigit = 0) const
			{
				unsigned int vMaxNbAlpha = 0;
				std::vector<unsigned int> vNbDigitVect;
				for(unsigned int i = 0; i < Size(); ++i){
					vNbDigitVect.push_back(gu::NbAlpha(gu::Truncate(mMat[i], pNbTruncatedDigit)));
					vMaxNbAlpha = std::max(vMaxNbAlpha, vNbDigitVect[i]);
				}


				for(unsigned int j = 0; j < mHeight; ++j){
					for(unsigned int i = 0; i < mWidth; ++i){
						//front
						for(unsigned int k = 0; k < ceil((vMaxNbAlpha - vNbDigitVect[MCOORD(i, j)]) / 2.0); ++k)
							std::cout << " ";
						//value
						std::cout << " " << gu::Truncate(mMat[MCOORD(i, j)], pNbTruncatedDigit) << " ";

						//back
						for(unsigned int k = 0; k < floor((vMaxNbAlpha - vNbDigitVect[MCOORD(i, j)]) / 2.0); ++k)
							std::cout << " ";
					}
					std::cout << std::endl;
				}
			}

		private:

			/**
			 * \brief 	Tableau des pointeurs sur les valeurs.
			 */
			MType * mMat;

			/**
			 * \brief 	Largeur de la matrice.
			 */
			unsigned int mWidth

			/**
			 * \brief 	Hauteur de la matrice.
			 */
			unsigned int mHeight;

	};

}

#endif
