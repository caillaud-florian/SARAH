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

//TODO : mettre une option pour les commentaires pleine ligne, les commentaires fin de ligne, etc.

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

			bool getLine(std::string & p_line, unsigned int p_readingSize = 256)
			{
				char * vLine = new char[p_readingSize];
				if(!m_file.getline (vLine, p_readingSize)){
					delete vLine;
					return false;
				}else{
					p_line = std::string(vLine);
					delete vLine;
					return true;
				}
			}

		protected:

			IFile m_file;
			FileReadState m_state;
	};
	
}

#endif