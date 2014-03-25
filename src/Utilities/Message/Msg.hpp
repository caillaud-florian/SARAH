#ifndef MESSAGE_MSG
#define MESSAGE_MSG

#include <iostream>
#include <string>

namespace msg
{

	enum class MSG_FLAG_ENUM : char
	{
		STANDARD 	= 0,
		TAB			= 1,
		LOG			= 2,
		ERROR 		= 3,
		EVERY_JUMP 	= 4, 
		NO_JUMP 	= 5,
		CONCAT 		= 6,
		RED			= 7,
		GREEN		= 8,
		BLUE		= 9

	};
	
	class Msg
	{

		public:

			Msg()
			{
				std::cout << std::endl;
			}

			template <typename H, typename ...T>
			Msg(H pHead, T... pTail)
			{
				std::cout << pHead << ' ';
				if (sizeof...(pTail))
					Msg(pTail...);
				else
					Msg();
			}

	};

	class Msg_Spe
	{

		public:

			Msg_Spe(): mFlag(MSG_FLAG_ENUM::STANDARD)
			{
				std::cout << std::endl;
			}

			template <typename F, typename H>
			Msg_Spe(F pFlag, H pHead): mFlag(pFlag) 
			{
				switch(pFlag)
				{
					case MSG_FLAG_ENUM::STANDARD:
						std::cout << pHead << std::endl;
						break;
					case MSG_FLAG_ENUM::TAB:
						std::cout << pHead << std::endl;
						break;
					case MSG_FLAG_ENUM::LOG:
						std::clog << pHead << std::endl;
						break;
					case MSG_FLAG_ENUM::ERROR:
						std::cerr << pHead << std::endl;
						break;
					case MSG_FLAG_ENUM::EVERY_JUMP:
						std::cout << pHead << std::endl;
						break;
					case MSG_FLAG_ENUM::NO_JUMP:
						std::cout << pHead << ' ';
						break;
					case MSG_FLAG_ENUM::CONCAT:
						std::cout << pHead << ' ';
						break;
					case MSG_FLAG_ENUM::RED:
						std::cout << "\033[31m" << pHead << "\033[0m" << std::endl;
						break;
					case MSG_FLAG_ENUM::GREEN:
						std::cout << "\033[32m" << pHead << "\033[0m" << std::endl;
						break;
					case MSG_FLAG_ENUM::BLUE:
						std::cout << "\033[34m" << pHead << "\033[0m" << std::endl;
						break;
					default:
						break;
				}
			}

			template <typename F, typename H, typename ...T>
			Msg_Spe(F pFlag, H pHead, T... pTail): mFlag(pFlag)
			{
				switch(pFlag)
				{
					case MSG_FLAG_ENUM::STANDARD:
						std::cout << pHead << ' ';
						break;
					case MSG_FLAG_ENUM::TAB:
						std::cout << pHead << '\t';
						break;
					case MSG_FLAG_ENUM::LOG:
						std::clog << pHead << ' ';
						break;
					case MSG_FLAG_ENUM::ERROR:
						std::cerr << pHead << ' ';
						break;
					case MSG_FLAG_ENUM::EVERY_JUMP:
						std::cout << pHead << std::endl;
						break;
					case MSG_FLAG_ENUM::NO_JUMP:
						std::cout << pHead << ' ';
						break;
					case MSG_FLAG_ENUM::CONCAT:
						std::cout << pHead;
						break;
					case MSG_FLAG_ENUM::RED:
						std::cout << "\033[31m" << pHead << "\033[0m ";
						break;
					case MSG_FLAG_ENUM::GREEN:
						std::cout << "\033[32m" << pHead << "\033[0m ";
						break;
					case MSG_FLAG_ENUM::BLUE:
						std::cout << "\033[34m" << pHead << "\033[0m ";
						break;
					default:
						break;
				}	

				if (sizeof...(pTail))
					Msg_Spe(pFlag, pTail...);
				else
					Msg_Spe(pFlag, pHead);
			}

		private:

			const MSG_FLAG_ENUM mFlag;

	};

}

#endif
