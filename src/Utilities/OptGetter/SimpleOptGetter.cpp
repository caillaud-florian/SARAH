#include "SimpleOptGetter.hpp"

namespace optg
{

	SimpleOptGetter::SimpleOptGetter(int argc, char ** argv, std::vector<PType> pVectType, int pNbRequiredOpt):
		mParameters(argc - 1)
	{
		if(pNbRequiredOpt < 0)
			pNbRequiredOpt = pVectType.size();

		if(argc - 1 > (int)pVectType.size()){
			std::cerr << "ERROR : In SimpleOptGetter, the type vector's size is inferior to the arguments number." << std::endl;
			exit(-1);
		}

		if(pNbRequiredOpt > (int)pVectType.size()){
			std::cerr << "ERROR : In SimpleOptGetter, the type vector's size is inferior to the required arguments number." << std::endl;
			exit(-1);
		}

		if(argc - 1 < pNbRequiredOpt){
			std::cerr << "ERROR : In SimpleOptGetter, the following program require at least " << pNbRequiredOpt << " arguments." << std::endl;
			std::clog << "\tYou need to call it as : " << argv[0];
			for(int i = 0; i < pNbRequiredOpt; ++i)
				std::clog << " [" << GetTypeName(pVectType[i]) << "]";
			for(unsigned int i = 0; i < pVectType.size() - pNbRequiredOpt; ++i)
				std::clog << " [" << GetTypeName(pVectType[i]) << "(optional)]";
			std::cout << std::endl;
			exit(-1);
		}
		
		for(int i = 0; i < argc - 1; ++i){
			mParameters[i] = new CommentedParameter(argv[i + 1], pVectType[i]);
		}
#ifdef VERBOSE_OPT
		Print();
#endif
	}

	SimpleOptGetter::SimpleOptGetter(int argc, char ** argv, std::vector<ParameterLabel> pVectType, int pNbRequiredOpt):
		mParameters(argc - 1)
	{
		if(pNbRequiredOpt < 0)
			pNbRequiredOpt = pVectType.size();

		if(argc - 1 > (int)pVectType.size()){
			std::cerr << "ERROR : In SimpleOptGetter, the type vector's size is inferior to the arguments number." << std::endl;
			exit(-1);
		}

		if(pNbRequiredOpt > (int)pVectType.size()){
			std::cerr << "ERROR : In SimpleOptGetter, the type vector's size is inferior to the required arguments number." << std::endl;
			exit(-1);
		}

		if(argc - 1 < pNbRequiredOpt){
			std::cerr << "ERROR : In SimpleOptGetter, the following program require at least " << pNbRequiredOpt << " arguments." << std::endl;
			std::clog << "\tYou need to call it as : " << argv[0];
			for(int i = 0; i < pNbRequiredOpt; ++i)
				std::clog << " " << pVectType[i].mName << "[" << GetTypeName(pVectType[i].mPType) << "]";
			for(unsigned int i = 0; i < pVectType.size() - pNbRequiredOpt; ++i)
				std::clog << " " << pVectType[i].mName << "[" << GetTypeName(pVectType[i].mPType) << "(optional)]";
			std::cout << std::endl;
			exit(-1);
		}
		
		for(int i = 0; i < argc - 1; ++i){
			mParameters[i] = new CommentedParameter(argv[i + 1], pVectType[i].mPType, pVectType[i].mName, pVectType[i].mComment);
		}
#ifdef VERBOSE_OPT
		Print();
#endif
	}

	SimpleOptGetter::~SimpleOptGetter()
	{
		for(std::vector<CommentedParameter *>::iterator it = mParameters.begin(); it != mParameters.end(); ++it)
			delete (*it);
	}

	CommentedParameter SimpleOptGetter::GetParameter(int pInd)
	{
		return *mParameters[pInd];
	}

	CommentedParameter SimpleOptGetter::operator [](int pInd)
	{
		return *mParameters[pInd];
	}

	void SimpleOptGetter::Print()
	{
		std::cout << "===== SimpleOptGetter =====" << std::endl << std::endl;
		for(unsigned int i = 0; i < mParameters.size(); ++i){
			std::cout << "Param n°" << i << " : ";
			mParameters[i]->Print();
			std::cout << std::endl;
		}
		std::cout << std::endl << "===========================" << std::endl;
	}

}
