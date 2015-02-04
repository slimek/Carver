// Brittle Sample Game "Carver" - Flappy Scene Implementation

#include "CarverPch.h"
#include "Flappy/FlappyScene.h"

#include <Brittle/Layout/Locate.h>
#include <Brittle/Layout/Stretch.h>


void FlappyScene::OnEnterScene()
{
    auto background = Sprite::create( "texture/flappy/sky.png" );
    this->addChild( background );

    Stretch( background ).Fill();

    const auto scale = background->getScaleX();


    /// Put the Bird at the center ///

    auto bird = Sprite::create( "texture/flappy/bird-0.png" );
    bird->setScale( scale );
    bird->getTexture()->setAliasTexParameters();
    this->addChild( bird );

    Locate( bird ).Center();
}


void FlappyScene::OnBackKeyPressed()
{
    SimpleScene::ReplaceScene( SCENE_MENU );
}
