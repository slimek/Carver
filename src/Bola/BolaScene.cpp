// Brittle Sample Game "Carver" - Bola Scene Implementation

#include "CarverPch.h"
#include "Bola/BolaScene.h"

#include <Brittle/Layout/Locate.h>
#include <Brittle/Layout/Stretch.h>


void BolaScene::OnCreate()
{
    /// Background - Repeat the Tile ///

    auto background = Sprite::create( "texture/blue-tile.png" );
    m_screen->addChild( background );

    Stretch( background ).Repeat();


    /// Put the Ball at the center ///

    m_ball = Sprite::create( "texture/basketball.png" );
    this->addChild( m_ball );

    Locate( m_ball ).Center();


    /// Touch Events ///

    auto listener = EventListenerTouchOneByOne::create();
    listener->setSwallowTouches( true );
    listener->onTouchBegan = CC_CALLBACK_2( BolaScene::OnTouchBegan, this );
    listener->onTouchMoved = CC_CALLBACK_2( BolaScene::OnTouchMoved, this );
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority( listener, m_ball );
}


void BolaScene::OnBackKeyPressed()
{
    SimpleScene::ReplaceScene( SCENE_MENU );
}


Bool BolaScene::OnTouchBegan( Touch* touch, Event* event )
{
    const Float radius = m_ball->getContentSize().width / 2;

    m_ballTouched = ( m_ball->getPosition().distance( touch->getLocation() ) < radius );
    if ( m_ballTouched )
    {
        m_ballStartPosition = m_ball->getPosition();
    }
    return true;
}


void BolaScene::OnTouchMoved( Touch* touch, Event* event )
{
    if ( m_ballTouched )
    {
        const auto offset = touch->getLocation() - touch->getStartLocation();
        m_ball->setPosition( m_ballStartPosition + offset );
    }
}
