// Brittle Sample Game "Carver" - Menu Scene Implementation

#include "CarverPch.h"
#include "Menu/MenuScene.h"
#include <Brittle/Ui/LabelButton.h>
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
    m_panel->SetClickHandler( "menuClock", &MenuScene::OnMenuClock_Click, this );

    m_panel->SetClickHandler( "menuBola", [] ( Ref* ) { SimpleScene::ReplaceScene( SCENE_BOLA ); });
    m_panel->SetClickHandler( "menuGems", [] ( Ref* ) { SimpleScene::ReplaceScene( SCENE_GEMS ); });


    CARAMEL_TRACE_INFO( "Scene Size: %s", ToString( this->getContentSize() ));
    CARAMEL_TRACE_INFO( "Panel Size: %s", ToString( m_panel->getContentSize() ));

    Panel* menu = nullptr;
    m_panel->GetChild( "menuPanel", menu );

    CARAMEL_TRACE_INFO( "Menu Size: %s", ToString( menu->getContentSize() ));
    CARAMEL_TRACE_INFO( "Menu Pos : %s", ToString( menu->getPosition() ));

    LabelButton* clock = nullptr;
    menu->GetChild( "menuClock", clock );

    CARAMEL_TRACE_INFO( "Clock Size: %s", ToString( clock->getContentSize() ));
    CARAMEL_TRACE_INFO( "Clock Pos : %s", ToString( clock->getPosition() ));
}


void MenuScene::OnEnterButton_Click( Ref* sender )
{
    CARAMEL_TRACE_INFO( "Enter Click!" );
}


void MenuScene::OnMenuWhack_Click( Ref* sender )
{
    CARAMEL_TRACE_INFO( "Whack Click!" );

    SimpleScene::ReplaceScene( SCENE_WHACK );
}


void MenuScene::OnMenuClock_Click( Ref* sender )
{
    CARAMEL_TRACE_INFO( "Clock Click!" );

    SimpleScene::ReplaceScene( SCENE_CLOCK );
}


///////////////////////////////////////////////////////////////////////////////
