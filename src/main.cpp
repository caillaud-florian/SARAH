#include "Kernel/ControlerHandler.hpp"
#include "Reader/IniConfigReader.hpp"

typedef Sarah::IO::IniConfigReader      IniConfigReader; 
typedef Sarah::Kernel::WindowConfig     WindowConfig;
typedef Sarah::Kernel::GeneralConfig    GeneralConfig;
typedef Sarah::Kernel::ControlerHandler ControlerHandler;

int main()
{
    IniConfigReader iniReader("/home/imagine/Bureau/testINI.ini");
    
    iniReader.Read();

    std::map<std::string, std::map<std::string, std::string> > config = iniReader.GetConfig();

    for(auto it = config.begin(); it != config.end(); ++it)
    {
        std::cout << (*it).first << " :" << std::endl;

        for(auto itbis = (*it).second.begin(); itbis != (*it).second.end(); ++itbis)
        {
            std::cout << "\t" << (*itbis).first << " = " << (*itbis).second << std::endl;
        }
    }

    ///////////////////////////////////////////
    // WINDOW CONFIG
    ///////////////////////////////////////////
    WindowConfig * wConf = new WindowConfig();
    wConf->title = "test Config";
    wConf->videoMode = sf::VideoMode(600, 300);
    wConf->contextSettings.depthBits = 32;
    wConf->Print();

    ///////////////////////////////////////////
    // GENERAL CONFIG
    ///////////////////////////////////////////
    GeneralConfig gConf;
    gConf.AddConfig(wConf);

    ///////////////////////////////////////////
    // HANDLERS INIT
    ///////////////////////////////////////////
    ControlerHandler vHandler(gConf);
    vHandler.Init();

    ///////////////////////////////////////////
    // APPLICATION MAIN LOOP
    ///////////////////////////////////////////
    vHandler.MainLoop();

    return EXIT_SUCCESS;
}