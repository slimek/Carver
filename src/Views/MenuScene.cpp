// Brittle Sample Game "Carver" - Menu Scene Implementation

#include "CarverPch.h"
#include "Views/MenuScene.h"


///////////////////////////////////////////////////////////////////////////////
//
// Menu Scene
//

void MenuScene::OnEnterScene()
{
    auto alice = Sprite::create( "texture/alice.png" );
    alice->setPositionX( 270 );
    alice->setPositionY( 360 );
    this->addChild( alice );
}


///////////////////////////////////////////////////////////////////////////////
