#include "Utils/StringOperation.hpp"

namespace Utils
{
	
	std::vector<std::string> Split(const std::string & stringToSplit, char delim) 
	{
	    std::vector<std::string> elems;
	    std::stringstream ss(stringToSplit);
	    std::string item;

	    while (std::getline(ss, item, delim))
	        elems.push_back(item);

	    return elems;
	}

	bool GetFileNameAndExtension(const std::string & filePath, std::string & fileName, std::string & fileExtension)
	{
		std::vector<std::string> pathVect = Split(filePath, FILE_DELIMITOR);
		std::vector<std::string> nameVect = Split(pathVect.back(), EXTENSION_SEPARATOR);
		
		fileName = nameVect[0];

		if(nameVect.size() <= 1)
			return false;

		fileExtension = nameVect[1];
		return true;
	}

}