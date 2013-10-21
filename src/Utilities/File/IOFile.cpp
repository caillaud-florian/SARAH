#include "Utilities/File/IOFile.hpp"

namespace gu
{

////////////////////////////// FILE ////////////////////////////////

	File::File(std::string filePath){
		m_hasExtension = GetFileNameAndExtension(filePath, m_name, m_extension);
		m_size = GetFileSize(filePath);
	}

	std::string File::GetName() const
	{
		return m_name;
	}

	bool File::HasExtension() const
	{
		return m_hasExtension;
	}

	std::string File::GetExtension() const
	{
		return m_extension;
	}

	unsigned int File::Size() const
	{
		return m_size;
	}

////////////////////////////// IFILE ////////////////////////////////

	IFile::IFile(std::string filePath):
		std::ifstream(filePath),
		File(filePath)
	{

	}

	FileType IFile::GetType() const
	{
		return IFILE;
	}

////////////////////////////// OFILE ////////////////////////////////

	OFile::OFile(std::string filePath):
		std::ofstream(filePath),
		File(filePath)
	{

	}

	FileType OFile::GetType() const
	{
		return OFILE;
	}

////////////////////////////// IOFILE ////////////////////////////////

	IOFile::IOFile(std::string filePath):
		IFile(filePath),
		OFile(filePath)
	{

	}

	FileType IOFile::GetType() const
	{
		return IOFILE;
	}
	
///////////////////////////// OTHERS ////////////////////////////////

	long GetFileSize(std::string FilePath)
	{
		std::ifstream ifs(FilePath);

		if(!ifs)
			return -1;

	    ifs.seekg( 0 , std::ios_base::end );
	    long size = ifs.tellg() ;
	    ifs.close();

	    return size ;
	}
}