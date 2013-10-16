#ifndef READER
#define READER

#include "Utils/IOFile.hpp"

namespace Utils
{

	enum FileReadState
	{
		DONTEXIST,
		CORRUPTED,
		FAILLED,
		SUCCEED,
		UNDEFINED
	};

	class Reader
	{
		public:
			Reader(std::string filePath):
				m_file(filePath),
				m_state(UNDEFINED)
			{

			}

			FileReadState GetState() const;

			virtual bool Read() = 0;

		protected:

			IFile m_file;
			FileReadState m_state;
	};
	
}

#endif