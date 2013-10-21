#ifndef NMATRIX_NMATRIX
#define NMATRIX_NMATRIX

#include "NLine.hpp"
#include "BasicNumberOperation.hpp"

#define MCOORD(i, j) (((j)*(mWidth)) + (i))

namespace alg
{

	enum MATRIX_COPY_FLAG
	{
		M_NO_COPY,
		M_COPY
	};

	enum MATRIX_TYPE
	{
		M_ZERO,
		M_IDENT
	};

	template<class MType = double>
	class NMatrix
	{

		public:

			NMatrix():
				mMat(new MType[3 * 3]),
				mWidth(3),
				mHeight(3)
			{
				//EMPTY
			}

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

			NMatrix(unsigned int pDim):
				mMat(new MType[pDim * pDim]),
				mWidth(pDim),
				mHeight(pDim)
			{
				//EMPTY
			}

			NMatrix(unsigned int pWidth, unsigned int pHeight):
				mMat(new MType[pWidth * pHeight]),
				mWidth(pWidth),
				mHeight(pHeight)
			{
				//EMPTY
			}

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

			NMatrix(const NMatrix<MType> & pNMat):
				mMat(new MType[pNMat.mWidth * pNMat.mHeight]),
				mWidth(pNMat.mWidth),
				mHeight(pNMat.mHeight)
			{
				for(unsigned int i = 0; i < pNMat.Size(); ++i)
					mMat[i] = pNMat.GetAt(i);
			}

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

			~NMatrix()
			{
				delete [] mMat;
			}

			NLine<MType> GetRowAt(int pInd)
			{
				return NLine<MType>(mMat, pInd, std::pair<unsigned int, unsigned int>(mWidth, mHeight), LS_ROW);
			}

			NLine<MType> GetColumnAt(int pInd)
			{
				return NLine<MType>(mMat, pInd, std::pair<unsigned int, unsigned int>(mWidth, mHeight), LS_COLUMN);
			}

			const MType GetAt(int pInd) const
			{
				return mMat[pInd];
			}

			const MType GetAt(int pX, int pY) const
			{
				return mMat[MCOORD(pX, pY)];
			}

			void SetAt(int pX, int pY, MType pData)
			{
				mMat[MCOORD(pX, pY)] = pData;
			}

			MType & operator() (int pX, int pY)
			{
				return mMat[MCOORD(pX, pY)];
			}

			MType & operator[] (int pInd)
			{
				return mMat[pInd];
			}

			unsigned int Width() const
			{
				return mWidth;
			}

			unsigned int Height() const
			{
				return mHeight;
			}

			unsigned int Size() const
			{
				return mWidth * mHeight;
			}

			MType * SData()
			{
				return mMat;
			}

			NMatrix<MType> operator +(double pFactor)
			{
				NMatrix<MType> vMatrix(mMat, mWidth, mHeight, M_COPY);
				unsigned int vSize = mWidth * mHeight;

				for(unsigned int i = 0; i < vSize; ++i)
					vMatrix[i] += pFactor;

				return vMatrix;
			}

			friend NMatrix<MType> operator +(double pFactor, NMatrix<MType> pMatrix)
			{
				unsigned int vSize = pMatrix.Width() * pMatrix.Height();

				for(unsigned int i = 0; i < vSize; ++i)
					pMatrix[i] += pFactor;

				return pMatrix;
			}

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

			NMatrix<MType> operator -(double pFactor)
			{
				NMatrix<MType> vMatrix(mMat, mWidth, mHeight, M_COPY);
				unsigned int vSize = mWidth * mHeight;

				for(unsigned int i = 0; i < vSize; ++i)
					vMatrix[i] -= pFactor;

				return vMatrix;
			}

			friend NMatrix<MType> operator -(double pFactor, NMatrix<MType> pMatrix)
			{
				unsigned int vSize = pMatrix.Width() * pMatrix.Height();

				for(unsigned int i = 0; i < vSize; ++i)
					pMatrix[i] -= pFactor;

				return pMatrix;
			}

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

			NMatrix<MType> operator *(double pFactor)
			{
				NMatrix<MType> vMatrix(mMat, mWidth, mHeight, M_COPY);
				unsigned int vSize = mWidth * mHeight;

				for(unsigned int i = 0; i < vSize; ++i)
					vMatrix[i] *= pFactor;

				return vMatrix;
			}

			friend NMatrix<MType> operator *(double pFactor, NMatrix<MType> pMatrix)
			{
				unsigned int vSize = pMatrix.Width() * pMatrix.Height();

				for(unsigned int i = 0; i < vSize; ++i)
					pMatrix[i] *= pFactor;

				return pMatrix;
			}

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

			MType * mMat;
			unsigned int mWidth, mHeight;

	};

}

#endif
