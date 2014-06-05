// Brittle Sample Game "Carver" - Application Implementation

#include "CarverPch.h"
#include "CarverApp.h"

#include "Models/WhackModel.h"
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

GameScene* CarverApp::CreateScene( Int sceneId )
{
    switch ( sceneId )
    {
    case SCENE_MENU:  return new MenuScene;
    case SCENE_WHACK: return new WhackScene( std::make_shared< WhackModel >() );
    }

    return nullptr;
}
