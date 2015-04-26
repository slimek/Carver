// Brittle Sample Game "Carver" - Dialog Scene Implementation

#include "CarverPch.h"
#include "Dialog/DialogScene.h"
#include <Brittle/Layout/Align.h>
#include <Brittle/Layout/Locate.h>
#include <Brittle/Layout/Stretch.h>
#include <Brittle/Nodes/Listen.h>
#include <Brittle/Nodes/NodeExtensions.h>
#include <Brittle/Ui/UiBuilders.h>
#include <Brittle/Utils/Geometry.h>
#include <Brittle/Utils/Styling.h>


///////////////////////////////////////////////////////////////////////////////
//
// Scene Events
//

void DialogScene::OnCreate()
{
    /// Background ///
    
    auto background = LayerColor::create( MakeColor4B( 0xCEC8B2CF ));
    background->ignoreAnchorPointForPosition( false );
    Listen( background ).TouchBegan( &DialogScene::OnBackground_TouchBegan, this );
    this->addChild( background );
    Stretch( background ).Auto();

    auto pattern = Sprite::create( "texture/camel-tile.png" );
    this->GetScreen()->addChild( pattern );
    Stretch( pattern ).Repeat();


    /// Button and Label on the Background ///

    auto openButton = UiButtonBuilder( "texture/button-normal.png" )
        .PressedAction( true )
        .ClickEvent( &DialogScene::OnOpenButton_Click, this )
        .Text( UiTextBuilder( "Open" )
            .FontSize( 24 ).Color( Color4B::BLACK ))
        .Build();
    this->addChild( openButton );
    Locate( openButton ).FromTop( 100 ).CenterX();
}


void DialogScene::OnBackKeyPressed()
{
    SimpleScene::ReplaceScene( SCENE_MENU );
}


///////////////////////////////////////////////////////////////////////////////
//
// UI Events
//

Bool DialogScene::OnBackground_TouchBegan( Touch*, Event* )
{
    TraceInfo( "Background touch began" );
    return false;
}


void DialogScene::OnOpenButton_Click( Ref* )
{
    TraceInfo( "Open button clicked" );

    
    /// Show a "Ok Box" Dialog and cover the screen ///

    auto cover = this->CreateScreenCover( Color4B::BLACK );
    cover->setName( "cover" );
    cover->setOpacity( 0 );
    cover->runAction(
        FadeTo::create( 0.3f, 127 )
    );

    auto dialog = ui::Layout::create();
    dialog->setName( "dialog" );
    dialog->setBackGroundImage( "texture/panel-background.png" );
    dialog->setBackGroundImageScale9Enabled( true );
    dialog->setBackGroundImageCapInsets( Rect( 10, 10, 80, 80 ));
    dialog->setContentSize( Size( 400, 400 ));
    dialog->setAnchorPoint( Vec2::ANCHOR_MIDDLE );
    dialog->setOpacity( 0 );
    dialog->setCascadeOpacityEnabled( true );
    cover->addChild( dialog );
    Locate( dialog ).Center();
    TranslateY( dialog, -40 );

    dialog->runAction(
        Spawn::create(
            FadeTo::create( 0.3f, 255 ),
            MoveBy::create( 0.3f, Vec2( 0, 40 )),
            nullptr
        )
    );

    auto closeButton = UiButtonBuilder( "texture/button-normal.png" )
        .PressedAction( true )
        .ClickEvent( &DialogScene::OnCloseButton_Click, this )
        .Text( UiTextBuilder( "Close" )
            .FontSize( 24 ).Color( MakeColor3B( 0x6F1F00 )))
        .Build();
    dialog->addChild( closeButton );
    Locate( closeButton ).FromBottom( 100 ).CenterX();
}


void DialogScene::OnCloseButton_Click( Ref* )
{
    auto cover = this->GetScreen()->getChildByName( "cover" );
    cover->runAction(
        Sequence::create(
            FadeTo::create( 0.3f, 0 ),
            RemoveSelf::create(),
            nullptr
        )
    );

    auto dialog = cover->getChildByName( "dialog" );
    dialog->runAction(
        Sequence::create(
            FadeTo::create( 0.3f, 0 ),
            RemoveSelf::create(),
            nullptr
        )
    );
}


///////////////////////////////////////////////////////////////////////////////
