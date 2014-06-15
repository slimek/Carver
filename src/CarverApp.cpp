// Brittle Sample Game "Carver" - Application Implementation

#include "CarverPch.h"
#include "CarverApp.h"

#include "Models/WhackDomain.h"
#include "Views/ClockScene.h"
#include "Views/MenuScene.h"
#include "Views/WhackScene.h"


void CarverApp::OnLaunch()
{
    auto director = Director::getInstance();

    director->getOpenGLView()->
        setDesignResolutionSize( 640, 1, ResolutionPolicy::FIXED_WIDTH );

    director->setDisplayStats( true );
}


//
// Scene Management
//

SimpleScene* CarverApp::CreateScene( Int sceneId )
{
    switch ( sceneId )
    {
    case SCENE_MENU:  return new MenuScene;
    case SCENE_WHACK: return new WhackScene( std::make_shared< WhackDomain >() );
    case SCENE_CLOCK: return new ClockScene;
    }

    return nullptr;
}
