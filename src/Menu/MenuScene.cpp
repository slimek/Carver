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


void MenuScene::OnCreate()
{
    m_panel = Panel::Create( "layout/menu-scene.json" );
    this->addChild( m_panel );

    m_panel->GetChild( "aliceImage", m_aliceImage );
    m_panel->GetChild( "labelRaw", m_labelRaw );
    m_panel->GetChild( "labelFont", m_labelFont );

    m_panel->SetClickHandler( "enterButton", CC_CALLBACK_1( MenuScene::OnEnterButton_Click, this ));
    m_panel->SetClickHandler( "menuWhack", CC_CALLBACK_1( MenuScene::OnMenuWhack_Click, this ));
    m_panel->SetClickHandler( "menuClock", CC_CALLBACK_1( MenuScene::OnMenuClock_Click, this ));

    m_panel->SetClickHandler( "menuBola",   [] ( Ref* ) { SimpleScene::ReplaceScene( SCENE_BOLA ); });
    m_panel->SetClickHandler( "menuGems",   [] ( Ref* ) { SimpleScene::ReplaceScene( SCENE_GEMS ); });
    m_panel->SetClickHandler( "menuFlappy", [] ( Ref* ) { SimpleScene::ReplaceScene( SCENE_FLAPPY ); });


    CARAMEL_TRACE_INFO( "Scene Size: {0}", ToString( this->getContentSize() ));
    CARAMEL_TRACE_INFO( "Panel Size: {0}", ToString( m_panel->getContentSize() ));

    Panel* menu = nullptr;
    m_panel->GetChild( "menuPanel", menu );

    CARAMEL_TRACE_INFO( "Menu Size: {0}", ToString( menu->getContentSize() ));
    CARAMEL_TRACE_INFO( "Menu Pos : {0}", ToString( menu->getPosition() ));

    LabelButton* clock = nullptr;
    menu->GetChild( "menuClock", clock );

    CARAMEL_TRACE_INFO( "Clock Size: {0}", ToString( clock->getContentSize() ));
    CARAMEL_TRACE_INFO( "Clock Pos : {0}", ToString( clock->getPosition() ));
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
