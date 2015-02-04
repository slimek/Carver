// Brittle Sample Game "Carver" - Flappy Scene Implementation

#include "CarverPch.h"
#include "Flappy/FlappyScene.h"

#include <Brittle/Layout/Stretch.h>


void FlappyScene::OnEnterScene()
{
    auto background = Sprite::create( "texture/flappy/sky.png" );
    this->addChild( background );

    Stretch( background ).Fill();
}


void FlappyScene::OnBackKeyPressed()
{
    SimpleScene::ReplaceScene( SCENE_MENU );
}
