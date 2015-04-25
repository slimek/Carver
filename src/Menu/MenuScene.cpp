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
    
    m_panel->SetClickHandler( "menuWhack",  [] ( Ref* ) { SimpleScene::ReplaceScene( SCENE_WHACK ); });
    m_panel->SetClickHandler( "menuClock",  [] ( Ref* ) { SimpleScene::ReplaceScene( SCENE_CLOCK ); });
    m_panel->SetClickHandler( "menuBola",   [] ( Ref* ) { SimpleScene::ReplaceScene( SCENE_BOLA ); });
    m_panel->SetClickHandler( "menuGems",   [] ( Ref* ) { SimpleScene::ReplaceScene( SCENE_GEMS ); });
    m_panel->SetClickHandler( "menuFlappy", [] ( Ref* ) { SimpleScene::ReplaceScene( SCENE_FLAPPY ); });
    m_panel->SetClickHandler( "menuDialog", [] ( Ref* ) { SimpleScene::ReplaceScene( SCENE_DIALOG ); });


    TraceInfo( "Scene Size: {0}", this->getContentSize() );
    TraceInfo( "Panel Size: {0}", m_panel->getContentSize() );

    Panel* menu = nullptr;
    m_panel->GetChild( "menuPanel", menu );

    TraceInfo( "Menu Size: {0}", menu->getContentSize() );
    TraceInfo( "Menu Pos : {0}", menu->getPosition() );

    LabelButton* clock = nullptr;
    menu->GetChild( "menuClock", clock );

    TraceInfo( "Clock Size: {0}", clock->getContentSize() );
    TraceInfo( "Clock Pos : {0}", clock->getPosition() );
}


void MenuScene::OnEnterButton_Click( Ref* sender )
{
    TraceInfo( "Enter Click!" );
}


///////////////////////////////////////////////////////////////////////////////
