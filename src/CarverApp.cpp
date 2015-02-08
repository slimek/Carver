// Brittle Sample Game "Carver" - Application Implementation

#include "CarverPch.h"
#include "CarverApp.h"

#include "Bola/BolaScene.h"
#include "Clock/ClockScene.h"
#include "Gems/GemsScene.h"
#include "Menu/MenuScene.h"
#include "Whack/WhackScene.h"
#include "Flappy/FlappyScene.h"


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
    case SCENE_MENU:   return SimpleScene::Create< MenuScene >();
    case SCENE_WHACK:  return SimpleScene::Create< WhackScene >();
    case SCENE_CLOCK:  return SimpleScene::Create< ClockScene >();
    case SCENE_BOLA:   return SimpleScene::Create< BolaScene >();
    case SCENE_GEMS:   return SimpleScene::Create< GemsScene >();
    case SCENE_FLAPPY: return SimpleScene::CreateWithPhysics< FlappyScene >();
    }

    return nullptr;
}
