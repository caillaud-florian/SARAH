#ifndef READER
#define READER

#include "Utilities/File/IOFile.hpp"

#include <regex>

namespace IO
{

	enum FileReadState
	{
		NOTOPENED,
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

			bool HasSucceed()
			{
				return m_state == SUCCEED;
			}

			FileReadState GetReadState()
			{
				return m_state;
			}

		private:

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

			gu::IFile m_file;
			FileReadState m_state;
	};
	
}

#endif