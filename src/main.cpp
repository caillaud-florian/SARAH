#include "Kernel/ControlerHandler.hpp"
#include "Reader/IniConfigReader.hpp"

typedef Sarah::IO::IniConfigReader      IniConfigReader; 
typedef Sarah::Kernel::WindowConfig     WindowConfig;
typedef Sarah::Kernel::GeneralConfig    GeneralConfig;
typedef Sarah::Kernel::ControlerHandler ControlerHandler;

int main()
{
    ///////////////// Initialisation /////////////////////

    IniConfigReader iniReader("../resources/WindowConfig.ini");
    
    iniReader.Read();

    std::map<std::string, std::map<std::string, std::string> > config = iniReader.GetConfig();

    ///////////////////////////////////////////
    // HANDLERS INIT
    ///////////////////////////////////////////
    ControlerHandler vHandler(config);
    vHandler.Init();

    ///////////////////////////////////////////
    // APPLICATION MAIN LOOP
    ///////////////////////////////////////////
    vHandler.MainLoop();

    return EXIT_SUCCESS;
}