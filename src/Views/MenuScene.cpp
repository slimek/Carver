// Brittle Sample Game "Carver" - Menu Scene Implementation

#include "CarverPch.h"
#include "Views/MenuScene.h"
#include <Brittle/Ui/Panel.h>
#include <ui/UIImageView.h>
#include <ui/UIText.h>
#include <ui/UITextBMFont.h>


///////////////////////////////////////////////////////////////////////////////
//
// Menu Scene
//

MenuScene::MenuScene()
    : m_panel( nullptr )
    , m_aliceImage( nullptr )
    , m_labelRaw( nullptr )
    , m_labelFont( nullptr )
{
}


void MenuScene::OnEnterScene()
{
    m_panel = Panel::Create( "layout/menu-scene.json" );
    this->addChild( m_panel );

    m_panel->GetChild( "aliceImage", m_aliceImage );
    m_panel->GetChild( "labelRaw", m_labelRaw );
    m_panel->GetChild( "labelFont", m_labelFont );
}


///////////////////////////////////////////////////////////////////////////////
