#include "Kernel/Handler.hpp"
#include "Reader/IniConfigReader.hpp"

typedef Sarah::IO::IniConfigReader      IniConfigReader; 
typedef Sarah::Kernel::WindowConfig     WindowConfig;
typedef Sarah::Kernel::GeneralConfig    GeneralConfig;
typedef Sarah::Kernel::Handler          Handler;

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
    // HANDLER INIT
    ///////////////////////////////////////////
    Handler vHandler(gConf);
    vHandler.Init();

    ///////////////////////////////////////////
    // HANDLER MESH LOADING
    ///////////////////////////////////////////
    GLfloat cube[] =
    {
        // positions    // colors (r, g, b, a)
        -50, -50, -50,  0, 0, 1, 1,
        -50,  50, -50,  0, 0, 1, 1,
        -50, -50,  50,  0, 0, 1, 1,
        -50, -50,  50,  0, 0, 1, 1,
        -50,  50, -50,  0, 0, 1, 1,
        -50,  50,  50,  0, 0, 1, 1,

         50, -50, -50,  0, 1, 0, 1,
         50,  50, -50,  0, 1, 0, 1,
         50, -50,  50,  0, 1, 0, 1,
         50, -50,  50,  0, 1, 0, 1,
         50,  50, -50,  0, 1, 0, 1,
         50,  50,  50,  0, 1, 0, 1,

        -50, -50, -50,  1, 0, 0, 1,
         50, -50, -50,  1, 0, 0, 1,
        -50, -50,  50,  1, 0, 0, 1,
        -50, -50,  50,  1, 0, 0, 1,
         50, -50, -50,  1, 0, 0, 1,
         50, -50,  50,  1, 0, 0, 1,

        -50,  50, -50,  0, 1, 1, 1,
         50,  50, -50,  0, 1, 1, 1,
        -50,  50,  50,  0, 1, 1, 1,
        -50,  50,  50,  0, 1, 1, 1,
         50,  50, -50,  0, 1, 1, 1,
         50,  50,  50,  0, 1, 1, 1,

        -50, -50, -50,  1, 0, 1, 1,
         50, -50, -50,  1, 0, 1, 1,
        -50,  50, -50,  1, 0, 1, 1,
        -50,  50, -50,  1, 0, 1, 1,
         50, -50, -50,  1, 0, 1, 1,
         50,  50, -50,  1, 0, 1, 1,

        -50, -50,  50,  1, 1, 0, 1,
         50, -50,  50,  1, 1, 0, 1,
        -50,  50,  50,  1, 1, 0, 1,
        -50,  50,  50,  1, 1, 0, 1,
         50, -50,  50,  1, 1, 0, 1,
         50,  50,  50,  1, 1, 0, 1,
    };

    vHandler.Load(cube);

    ///////////////////////////////////////////
    // APPLICATION MAIN LOOP
    ///////////////////////////////////////////
    vHandler.MainLoop();

    return EXIT_SUCCESS;
}