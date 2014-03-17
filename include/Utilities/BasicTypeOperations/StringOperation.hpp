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

namespace gu
{

	std::vector<std::string> Split(const std::string &, char);

	bool GetFileNameAndExtension(const std::string &, std::string &, std::string &);

	bool IsComments(const std::string, char);

	std::string WithoutComments(const std::string, char);

	std::string WithoutChar(const std::string &, char);

	std::string WithoutFrontSpace(const std::string &);

	std::string WithoutBackSpace(const std::string &);

	std::string WithoutSpace(const std::string &);

}

#endif
