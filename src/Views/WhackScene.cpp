// Brittle Sample Game "Carver" - Whack Scene Implementation

#include "CarverPch.h"
#include "Views/WhackScene.h"
#include "Models/WhackDomain.h"
#include <Brittle/Ui/Panel.h>


///////////////////////////////////////////////////////////////////////////////
//
// Whack Scene
//

WhackScene::WhackScene( WhackDomainPtr domain )
    : m_panel( nullptr )
    , m_mole( nullptr )
    , m_domain( std::move( domain ))
{
    m_domain->LinkEventTarget( m_events );
}


void WhackScene::OnEnterScene()
{
    m_panel = Panel::Create( "layout/whack-scene.json" );
    this->addChild( m_panel );


    // Create a mole and put it on the hidden position.

    m_mole = Sprite::create( "texture/mole.png" );
    m_mole->setScale( 0.5 );
    m_mole->setPosition( 320, 200 );
    this->addChild( m_mole );


    // Create the hay stack.

    auto hayStack = Sprite::create( "texture/hay-stack.png" );
    hayStack->setPosition( 320, 200 );
    this->addChild( hayStack );
}


void WhackScene::OnExitScene()
{
}


///////////////////////////////////////////////////////////////////////////////
