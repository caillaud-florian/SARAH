#ifndef NMATRIX_NLINE
#define NMATRIX_NLINE

#include <vector>

#include <stdlib.h>

namespace alg
{


	enum LineState
	{
		LS_ROW,
		LS_COLUMN
	};

	template<class MType = double>
	class NLine
	{

		public:

			NLine():
				mSize(),
				mLine(),
				mHasToBeAllDeleted(false)
			{
				//EMPTY
			}

			NLine(unsigned int pSize):
				mSize(pSize),
				mLine(new MType *[pSize]),
				mHasToBeAllDeleted(true)
			{
				for(unsigned int i = 0; i < mSize; ++i)
					mLine[i] = new MType();
			}

			NLine(const NLine & pLine):
				mSize(pLine.mSize),
				mLine(new MType *[pLine.mSize]),
				mHasToBeAllDeleted(false)
			{
				for(unsigned int i = 0; i < mSize; ++i)
					mLine[i] = pLine.mLine[i];
			}

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

			~NLine()
			{
				if(mHasToBeAllDeleted)
					for(unsigned int i = 0; i < mSize; ++i)
						delete mLine[i];

				delete [] mLine;
			}

			const MType GetAt(int pInd)
			{
				return *mLine[pInd];
			}

			void SetAt(int pInd, MType pData)
			{
				*mLine[pInd] = pData;
			}

			MType operator[] (int pInd)
			{
				return *mLine[pInd];
			}

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

			unsigned int Size()
			{
				return mSize;
			}

			MType ** SData()
			{
				return mLine;
			}

			void Add(MType * pData)
			{
				mSize++;
				mLine = (MType *) realloc(mLine, mSize * sizeof(MType *));
				mLine[mSize - 1] = pData;
			}

			void Print()
			{
				for(unsigned int i = 0; i < mSize; ++i)
					std::cout << *mLine[i] << " ";
			}


		private:

			unsigned int mSize;
			MType ** mLine;
			bool mHasToBeAllDeleted;

	};

}

#endif