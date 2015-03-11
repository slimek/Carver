// Brittle Sample Game "Carver" - Flappy Scene Implementation

#include "CarverPch.h"
#include "Flappy/FlappyScene.h"

#include <Brittle/Animation/FlipbookAnimation.h>
#include <Brittle/Layout/Locate.h>
#include <Brittle/Layout/Stretch.h>
#include <Brittle/Nodes/HorizontalScrolling.h>
#include <Brittle/Utils/Geometry.h>


///////////////////////////////////////////////////////////////////////////////
//
// Constants
//

// Original size, would be scaled.
static const Float BIRD_HEIGHT = 12;

// Forces
static const Float GRAVITY = -300;  // More powerful than the default.

// Background
static const Float SCROLL_VELOCITY = -50;


///////////////////////////////////////////////////////////////////////////////
//
// Build the Scene
//

void FlappyScene::OnEnterScene()
{
    /// Background ///

    auto background = HorizontalScrolling::Create( { "texture/flappy/sky.png" } );
    this->addChild( background );

    Stretch( background ).Fill();
    background->Start( SCROLL_VELOCITY );

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


    /// Place the Floor at the bottom ///

    auto floor = Sprite::create( "texture/flappy/floor.png" );
    floor->setScale( scale );
    this->addChild( floor );

    Locate( floor ).CenterX().FromBottom( 0 );


    /// Physics Settings ///

    this->getPhysicsWorld()->setGravity( Vec2( 0, GRAVITY ));

    auto birdBody = PhysicsBody::createCircle( BIRD_HEIGHT * scale / 2 );
    bird->setPhysicsBody( birdBody );

    auto floorBody = PhysicsBody::createBox( floor->getBoundingBox().size );
    floorBody->setDynamic( false );
    floor->setPhysicsBody( floorBody );
}


void FlappyScene::OnBackKeyPressed()
{
    SimpleScene::ReplaceScene( SCENE_MENU );
}
