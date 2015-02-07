// Brittle Sample Game "Carver" - Flappy Scene Implementation

#include "CarverPch.h"
#include "Flappy/FlappyScene.h"

#include <Brittle/Animation/FlipbookAnimation.h>
#include <Brittle/Layout/Locate.h>
#include <Brittle/Layout/Stretch.h>


void FlappyScene::OnEnterScene()
{
    auto background = Sprite::create( "texture/flappy/sky.png" );
    this->addChild( background );

    Stretch( background ).Fill();

    const auto scale = background->getScaleX();


    /// Put the Bird at the center, with animation ///

    auto bird = Sprite::create();
    bird->setScale( scale );
    this->addChild( bird );

    Locate( bird ).Center();

    auto birdAnim = FlipbookAnimationBuilder()
                   .Files( "texture/flappy/bird-{0}.png", 3 )
                   .Indexes( { 0, 1, 0, 2 } )
                   .DelayPerUnit( 0.1f )
                   .UseAliasTexParameters()
                   .Build();

    bird->runAction( RepeatForever::create( Animate::create( birdAnim )));
}


void FlappyScene::OnBackKeyPressed()
{
    SimpleScene::ReplaceScene( SCENE_MENU );
}
