// Brittle Sample Game "Carver" - Application Implementation

#include "CarverPch.h"
#include "CarverApp.h"

#include "Bola/BolaScene.h"
#include "Clock/ClockScene.h"
#include "Gems/GemsScene.h"
#include "Menu/MenuScene.h"
#include "Whack/WhackScene.h"
#include "Flappy/FlappyScene.h"
#include "Dialog/DialogScene.h"


CarverApp::CarverApp()
    : SimpleApp( { 640, 1024, SCENE_MENU } )  // aspect ratio 5 : 8
{}


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
    case SCENE_DIALOG: return SimpleScene::Create< DialogScene >();
    }

    return nullptr;
}
