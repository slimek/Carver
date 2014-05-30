// Brittle Sample Game "Carver" - Menu Scene Implementation

#include "CarverPch.h"
#include "Views/MenuScene.h"
#include <Brittle/Ui/Panel.h>
#include <Brittle/Utils/Geometry.h>
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

    m_panel->SetClickHandler( "enterButton", &MenuScene::OnEnterButton_Click, this );
    m_panel->SetClickHandler( "menuWhack", &MenuScene::OnMenuWhack_Click, this );

    CARAMEL_TRACE_INFO( "Scene Size: %s", ToString( this->getContentSize() ));
    CARAMEL_TRACE_INFO( "Panel Size: %s", ToString( m_panel->getContentSize() ));

    Panel* menu = nullptr;
    m_panel->GetChild( "menuPanel", menu );

    CARAMEL_TRACE_INFO( "Menu Size: %s", ToString( menu->getContentSize() ));
    CARAMEL_TRACE_INFO( "Menu Pos : %s", ToString( menu->getPosition() ));
}


void MenuScene::OnEnterButton_Click( Ref* sender )
{
    CARAMEL_TRACE_INFO( "Enter Click!" );
}


void MenuScene::OnMenuWhack_Click( Ref* sender )
{
    CARAMEL_TRACE_INFO( "Whack Click!" );

    GameScene::ReplaceScene( SCENE_WHACK );
}


///////////////////////////////////////////////////////////////////////////////
