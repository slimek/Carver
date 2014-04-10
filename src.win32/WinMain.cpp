// Brittle Sample Game "Carver" - Win32 Main Entry

#include "CarverPch.h"

#include "CarverApp.h"
#include <Windows.h>

#if defined( _DEBUG )
//#include <vld.h>
#endif


int APIENTRY wWinMain(
    HINSTANCE instance, HINSTANCE prevInstance, WCHAR* cmdLine, int cmdShow )
{
    GameAppSettings s;
    s.initialSceneId = SCENE_MENU;

    CarverApp app;

    return app.Run( s );
}
        