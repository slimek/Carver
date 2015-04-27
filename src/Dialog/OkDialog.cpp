// Brittle Sample Game "Carver" - Ok Dialog Implementation

#include "CarverPch.h"
#include "Dialog/OkDialog.h"
#include <Brittle/Layout/Locate.h>
#include <Brittle/Nodes/NodeExtensions.h>
#include <Brittle/Ui/UiBuilders.h>
#include <Brittle/Utils/Styling.h>


///////////////////////////////////////////////////////////////////////////////
//
// Ok Dialog
//

//
// Constants
//

static const Float SHOW_DURATION = 0.3f;
static const Float HIDE_DURATION = 0.3f;

// The layout move vector when Show().
static const Vec2 SHOW_MOVE_VEC( 0, 40.f );


//
// Building
//

OkDialog* OkDialog::Create( SimpleScene* scene )
{
    auto dialog = MakeUnique< OkDialog >();

    CARAMEL_CHECK( dialog->Init( scene ));
    return dialog.release();
}


Bool OkDialog::Init( SimpleScene* scene )
{
    if ( ! this->InitWithScene( scene )) { return false; }

    this->setVisible( false );

    this->setColor( Color3B::BLACK );
    this->setOpacity( 0 );

    // Layout

    m_layout = ui::Layout::create();
    m_layout->setBackGroundImage( "texture/panel-background.png" );
    m_layout->setBackGroundImageScale9Enabled( true );
    m_layout->setBackGroundImageCapInsets( Rect( 10, 10, 80, 80 ));
    m_layout->setContentSize( Size( 400, 400 ));
    m_layout->setAnchorPoint( Vec2::ANCHOR_MIDDLE );
    m_layout->setOpacity( 0 );
    m_layout->setCascadeOpacityEnabled( true );
    
    this->addChild( m_layout );
    Locate( m_layout ).FromCenter( - SHOW_MOVE_VEC );

    // Ok Button

    auto okButton = UiButtonBuilder( "texture/button-normal.png" )
        .PressedAction( true )
        .ClickEvent( &OkDialog::OnOkButton_Click, this )
        .Title( "Close", { 24, MakeColor3B( 0x6F1F00 ) } )
        .Build();

    m_layout->addChild( okButton );
    Locate( okButton ).FromBottom( 100 ).CenterX();
    
    return true;
}


//
// Actions
//

AnyEventTask OkDialog::Show()
{
    if ( this->isVisible() ) { return m_closeTask.GetTask(); }

    this->setVisible( true );

    this->runAction(
        FadeTo::create( SHOW_DURATION, 0x7F )
    );

    m_layout->runAction(
        Spawn::create(
            FadeTo::create( SHOW_DURATION, 0xFF ),
            MoveBy::create( SHOW_DURATION, SHOW_MOVE_VEC ),
            nullptr
        )
    );

    return m_closeTask.GetTask();
}


void OkDialog::OnOkButton_Click( Ref* )
{
    this->runAction(
        Sequence::create(
            FadeTo::create( HIDE_DURATION, 0 ),
            RemoveSelf::create(),
            nullptr
        )
    );

    m_layout->runAction(
        Spawn::create(
            ScaleTo::create( HIDE_DURATION, 0.9f ),
            FadeTo::create( HIDE_DURATION, 0 ),
            nullptr
        )
    );

    m_closeTask.RunTask( AnyEvent() );
}


///////////////////////////////////////////////////////////////////////////////
