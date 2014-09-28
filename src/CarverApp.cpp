// Brittle Sample Game "Carver" - Application Implementation

#include "CarverPch.h"
#include "CarverApp.h"

#include "Bola/BolaScene.h"
#include "Clock/ClockScene.h"
#include "Gems/GemsScene.h"
#include "Menu/MenuScene.h"
#include "Whack/WhackScene.h"


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
    case SCENE_WHACK: return new WhackScene;
    case SCENE_CLOCK: return new ClockScene;
    case SCENE_BOLA:  return new BolaScene;
    case SCENE_GEMS:  return new GemsScene;
    }

    return nullptr;
}
