// Brittle Sample Game "Carver" - Dialog Scene Implementation

#include "CarverPch.h"
#include "Dialog/DialogScene.h"
#include "Dialog/OkDialog.h"
#include <Brittle/Layout/Align.h>
#include <Brittle/Layout/Locate.h>
#include <Brittle/Layout/Stretch.h>
#include <Brittle/Nodes/Listen.h>
#include <Brittle/Nodes/NodeExtensions.h>
#include <Brittle/Nodes/ScreenCover.h>
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
        .Title( "Open", { 24, Color4B::BLACK } )
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

    auto dialog = OkDialog::Create( this );
    dialog->Show().Then(
    [] ( const AnyEvent& event )
    {
        TraceInfo( "Dialog closing" );
    });
}


///////////////////////////////////////////////////////////////////////////////
