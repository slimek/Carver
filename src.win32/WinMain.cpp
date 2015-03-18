// Brittle Sample Game "Carver" - Win32 Main Entry

#include "CarverPch.h"

#include "CarverApp.h"
#include <Caramel/String/ToString.h>
#include <Windows.h>

#if defined( _DEBUG )
#include <vld.h>
#endif


int APIENTRY wWinMain(
    HINSTANCE instance, HINSTANCE prevInstance, WCHAR* cmdLine, int cmdShow )
{
    AppSettings s;

    s.enableDisplayStats = true;

    DesktopSettings& ds = s.desktop;

    ds.frameWidth = 540;
    ds.frameHeight = 720;
    ds.frameTitle = "Brittle Sample \"Carver\" - "
                  + ToString( ds.frameWidth ) + " x " + ToString( ds.frameHeight );
    ds.assetsPath = "assets";

    CarverApp app;

    return app.Run( s );
}
        