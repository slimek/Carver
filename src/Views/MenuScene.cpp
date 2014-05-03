// Brittle Sample Game "Carver" - Menu Scene Implementation

#include "CarverPch.h"
#include "Views/MenuScene.h"
#include <Brittle/Ui/Panel.h>
#include <ui/UIImageView.h>


///////////////////////////////////////////////////////////////////////////////
//
// Menu Scene
//

MenuScene::MenuScene()
    : m_panel( nullptr )
    , m_aliceImage( nullptr )
{
}


void MenuScene::OnEnterScene()
{
    auto label = Label::createWithBMFont( "font/nina.fnt", "Alice" );
    label->setPosition( Point( 270, 200 ));
    label->setColor( Color3B::YELLOW );
    this->addChild( label );

    m_panel = Panel::Create( "layout/menu-scene.json" );
    this->addChild( m_panel );

    m_panel->GetChild( "aliceImage", m_aliceImage );
}


///////////////////////////////////////////////////////////////////////////////
