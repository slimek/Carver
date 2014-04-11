// Brittle Sample Game "Carver" - Application Implementation

#include "CarverPch.h"
#include "CarverApp.h"

#include "Views/MenuScene.h"


void CarverApp::OnLaunch()
{
    Director::getInstance()->setDisplayStats( true );
}


//
// Scene Management
//

GameScene* CarverApp::CreateScene( Int sceneId )
{
    switch ( sceneId )
    {
    case SCENE_MENU: return new MenuScene;
    }

    return nullptr;
}
