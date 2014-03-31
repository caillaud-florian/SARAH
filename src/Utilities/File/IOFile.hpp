#ifndef UTILS_IOFILE
#define UTILS_IOFILE

#include <fstream>
#include <iostream>
#include <string>

#include "../BasicTypeOperations/StringOperation.hpp"

namespace gu
{
	enum FileType
	{
		IFILE,
		OFILE,
		IOFILE
	};

	class File
	{
		public:

			File(std::string);

			std::string GetName() const;

			bool HasExtension() const;

			std::string GetExtension() const;

			unsigned int Size() const;

			virtual FileType GetType() const = 0;

		protected:

			std::string m_name;
			bool m_hasExtension;
			std::string m_extension;
			long m_size;
	};

	class IFile : public std::ifstream, public File
	{
		public:

			IFile(std::string);

			virtual FileType GetType() const;
	};

	class OFile : public std::ofstream, public File
	{
		public:

			OFile(std::string);

			virtual FileType GetType() const;
	};

	class IOFile : public IFile, public OFile
	{	
		public:

			IOFile(std::string);

			virtual FileType GetType() const;

	};

	long GetFileSize(std::string);

}

#endif