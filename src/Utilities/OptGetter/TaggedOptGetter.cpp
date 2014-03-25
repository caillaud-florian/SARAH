#include "TaggedOptGetter.hpp"

namespace optg
{

	TaggedOptGetter::TaggedOptGetter(int argc, char ** argv, std::vector<std::pair<std::string, PType> > pVectType)
	{
		if((argc - 1)/ 2 > (int)pVectType.size()){
			std::cerr << "ERROR : In TaggedOptGetter, the type vector's size is inferior to the arguments number." << std::endl;
			exit(-1);
		}

		bool vContinue;

		for(int i = 1; i < argc - 1; i = i + 2){
			vContinue = true;
			for(unsigned int j = 0; j < pVectType.size() && vContinue; ++j){
				if(std::string("-" + pVectType[j].first).compare(argv[i]) == 0){
					mParameters[pVectType[j].first] = new CommentedParameter(argv[i + 1], pVectType[j].second);
					vContinue = false;
				}
			}
			if(vContinue){
				std::cerr << "ERROR : In TaggedOptGetter, the option " << argv[i] << " is not or not yet handled." << std::endl;
				exit(-1);
			}
		}
#ifdef VERBOSE_OPT
		Print();
#endif
	}

	TaggedOptGetter::TaggedOptGetter(int argc, char ** argv, std::vector<TaggedParameterLabel> pVectType)
	{
		if((argc - 1)/ 2 > (int)pVectType.size()){
			std::cerr << "ERROR : In TaggedOptGetter, the type vector's size is inferior to the arguments number." << std::endl;
			exit(-1);
		}

		bool vContinue;
		std::vector<bool> vVectRequired(pVectType.size(), true);

		for(int i = 1; i < argc - 1; i = i + 2){
			vContinue = true;
			for(unsigned int j = 0; j < pVectType.size() && vContinue; ++j){
				if(std::string("-" + pVectType[j].mTag).compare(argv[i]) == 0){
					mParameters[pVectType[j].mTag] = new CommentedParameter(argv[i + 1], pVectType[j].mPType, pVectType[j].mName, pVectType[j].mComment);
					vVectRequired[j] = false;
					vContinue = false;
				}
			}
			if(vContinue){
				std::cerr << "ERROR : In TaggedOptGetter, the option " << argv[i] << " is not or not yet handled." << std::endl;
				exit(-1);
			}
		}

		for(unsigned int i = 0; i < vVectRequired.size(); ++i){
			if(vVectRequired[i] && pVectType[i].mRequire){
				std::cerr << "ERROR : In TaggedOptGetter, the following program require some essential arguments." << std::endl;
				std::clog << "\tYou need to call it as : " << argv[0];
				for(unsigned int j = 0; j < pVectType.size(); ++j){
					if(pVectType[j].mRequire)
						std::clog << " -" << pVectType[j].mTag << " " << pVectType[j].mName << "[" << GetTypeName(pVectType[j].mPType) << "]";
					else
						std::clog << " -" << pVectType[j].mTag << " " << pVectType[j].mName << "[" << GetTypeName(pVectType[j].mPType) << "(optional)]";
				}
				std::cout << std::endl;
				exit(-1);
			}
		}
#ifdef VERBOSE_OPT
		Print();
#endif
	}

	TaggedOptGetter::~TaggedOptGetter()
	{
		for(std::map<std::string, CommentedParameter *>::iterator it = mParameters.begin(); it != mParameters.end(); ++it)
			delete (*it).second;
	}

	CommentedParameter TaggedOptGetter::GetParameter(int pInd)
	{
		int vInd = 0;

		for(std::map<std::string, CommentedParameter *>::iterator it = mParameters.begin(); it != mParameters.end(); ++it){
			if(vInd == pInd)
				return *((*it).second);
			vInd++;
		}

		std::cerr << "ERROR : In GetParameter, the option map do not have " << pInd << " parameters." << std::endl;
		exit(-1);
	}

	CommentedParameter TaggedOptGetter::GetParameter(std::string pKey)
	{
		return *mParameters[pKey];
	}


	CommentedParameter TaggedOptGetter::operator [](int pInd)
	{
		int vInd = 0;

		for(std::map<std::string, CommentedParameter *>::iterator it = mParameters.begin(); it != mParameters.end(); ++it){
			if(vInd == pInd)
				return *((*it).second);
			vInd++;
		}

		std::cerr << "ERROR : In GetParameter, the option map do not have " << pInd << " parameters." << std::endl;
		exit(-1);
	}

	CommentedParameter TaggedOptGetter::operator [](std::string pKey)
	{
		return *mParameters[pKey];
	}

	void TaggedOptGetter::Print()
	{
		std::cout << "===== TaggedOptGetter =====" << std::endl << std::endl;
		for(std::map<std::string, CommentedParameter *>::iterator it = mParameters.begin(); it != mParameters.end(); ++it){
			std::cout << "Param -" << (*it).first << " : ";
			(*it).second->Print();
			std::cout << std::endl;
		}
		std::cout << std::endl << "===========================" << std::endl;
	}

}
