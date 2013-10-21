#ifndef STRINGOPERATION
#define STRINGOPERATION

#include <string>
#include <sstream>
#include <vector>

#ifdef OS_WINDOWS
	#define FILE_DELIMITOR '\\'
#else
	#define FILE_DELIMITOR '/'
#endif

#define EXTENSION_SEPARATOR '.'

namespace Utils
{

	std::vector<std::string> Split(const std::string &, char);

	bool GetFileNameAndExtension(const std::string &, std::string &, std::string &);

	bool IsComments(std::string, char);

}

#endif	