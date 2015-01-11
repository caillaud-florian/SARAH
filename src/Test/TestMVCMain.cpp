#include "Utilities/Message/Msg.hpp"

#include "Reader/IniConfigReader.hpp"

#include "Kernel/ControlerHandler.hpp"
#include "Kernel/ModelHandler.hpp"
#include "Kernel/GraphicHandler.hpp"
#include "Kernel/EventBinder.hpp"

typedef Sarah::IO::IniConfigReader                          IniConfigReader; 
typedef Sarah::Kernel::WindowConfig                         WindowConfig;
typedef Sarah::Kernel::GeneralConfig                        GeneralConfig;
typedef Sarah::Kernel::EventBinder                          EventBinder;
typedef Sarah::Kernel::ModelHandler                         ModelHandler;
typedef Sarah::Kernel::GraphicHandler                       GraphicHandler;

typedef Sarah::Kernel::ControlerHandler<ModelHandler, GraphicHandler, EventBinder>      ControlerHandler;

int main()
{
    msg::Msg_Spe(msg::MSG_FLAG_ENUM::GREEN, "#############  TEST MVC  #############\n");

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

    msg::Msg_Spe(msg::MSG_FLAG_ENUM::GREEN, "\n######################################");

    return EXIT_SUCCESS;
}