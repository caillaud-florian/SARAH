#include "Reader/IniConfigReader.hpp"

#include "Kernel/ControlerHandler.hpp"
#include "Kernel/EventBinder.hpp"

#include "MyApplication/MyEventBinder.hpp"
#include "MyApplication/MyModelHandler.hpp"
#include "MyApplication/MyGraphicHandler.hpp"

typedef Sarah::IO::IniConfigReader                          IniConfigReader; 
typedef Sarah::Kernel::WindowConfig                         WindowConfig;
typedef Sarah::Kernel::GeneralConfig                        GeneralConfig;
typedef Sarah::Kernel::EventBinder                          EventBinder;
typedef Sarah::MyEventBinder                                MyEventBinder;
typedef Sarah::MyModelHandler                               MyModelHandler;
typedef Sarah::MyGraphicHandler                             MyGraphicHandler;

typedef Sarah::Kernel::ControlerHandler<MyModelHandler, MyGraphicHandler, MyEventBinder>      ControlerHandler;

int main()
{
    ///////////////// Initialisation /////////////////////

    IniConfigReader iniReader("../resources/Configuration/WindowConfig.ini");
    
    iniReader.Read();

    std::map<std::string, std::map<std::string, std::string> > config = iniReader.GetConfig();

    ///////////////////////////////////////////
    // HANDLERS INIT
    ///////////////////////////////////////////
    ControlerHandler vHandler(config);
    vHandler.Init();

    // ///////////////////////////////////////////
    // // APPLICATION MAIN LOOP
    // ///////////////////////////////////////////
    vHandler.MainLoop();

    return EXIT_SUCCESS;
}
