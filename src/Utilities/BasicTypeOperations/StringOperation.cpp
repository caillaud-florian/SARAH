#include "Utilities/BasicTypeOperations/StringOperation.hpp"

namespace gu
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

	bool IsComments(const std::string line, char commentSign)
	{
		for(unsigned int i = 0; i < line.size(); ++i)
			if(line[i] != ' ' && line[i] != commentSign)
				return false;
			else if(line[i] == commentSign)
				return true;
		return true;
	}

	std::string WithoutComments(const std::string line, char commentSign)
	{
		std::string outLine;
		for(std::string::const_iterator it = line.begin(); it != line.end(); ++it)
		{
			if((*it) == commentSign)
				return WithoutBackSpace(outLine);
			else
				outLine.push_back(*it);
		}

		return outLine;
	}

	std::string WithoutChar(const std::string & str, char c)
	{
		std::string res;

		for(std::string::const_iterator it = str.begin(); it != str.end(); ++it)
		{
			if((*it) != c)
				res.push_back((*it));
		}

		return res;
	}

	std::string WithoutFrontSpace(const std::string & str)
	{
		bool copy = false;
		std::string res;

		for(std::string::const_iterator it = str.begin(); it != str.end(); ++it)
		{
			if(copy)
				res.push_back((*it));
			else if((*it) != ' ')
			{
				copy = true;
				res.push_back((*it));
			}
		}

		return res;
	}

	std::string WithoutBackSpace(const std::string & str)
	{
		bool copy = false;
		std::string tmp, res;

		for(std::string::const_reverse_iterator it = str.rbegin(); it != str.rend(); ++it)
			if(copy)
				tmp.push_back((*it));
			else if((*it) != ' ')
			{
				copy = true;
				tmp.push_back((*it));
			}

		for(std::string::reverse_iterator it = tmp.rbegin(); it != tmp.rend(); ++it)
			res.push_back((*it));

		return res;
	}

	std::string WithoutSpace(const std::string & str)
	{
		return WithoutChar(str, ' ');
	}

}