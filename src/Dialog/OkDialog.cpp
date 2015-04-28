// Brittle Sample Game "Carver" - Ok Dialog Implementation

#include "CarverPch.h"
#include "Dialog/OkDialog.h"
#include <Brittle/Actions/ActionVector.h>
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

    m_layout->setLayoutType( ui::Layout::Type::VERTICAL );


    // Add a Margin on top

    auto blank = ui::Widget::create();
    blank->setContentSize( Size( 1, 50 ));
    m_layout->addChild( blank );


    // List of Text

    auto font = FontStyle( 24, MakeColor3B( 0x803010 ));

    auto param = ui::LinearLayoutParameter::create();
    param->setGravity( ui::LinearLayoutParameter::LinearGravity::CENTER_HORIZONTAL );
    param->setMargin( ui::Margin( 0, 30, 0, 0 ));

    auto text1 = UiTextBuilder( "Apple", font ).Build();
    text1->setLayoutParameter( param );
    m_layout->addChild( text1 );

    auto text2 = UiTextBuilder( "Orange", font ).Build();
    text2->setLayoutParameter( param );
    m_layout->addChild( text2 );

    auto text3 = UiTextBuilder( "Banana", font ).Build();
    text3->setLayoutParameter( param );
    m_layout->addChild( text3 );


    // Ok Button

    auto okButton = UiButtonBuilder( "texture/button-normal.png" )
        .PressedAction( true )
        .ClickEvent( &OkDialog::OnOkButton_Click, this )
        .Title( "Close", { 24, MakeColor3B( 0x6F1F00 ) } )
        .Build();

    okButton->setLayoutParameter( param );
    m_layout->addChild( okButton );
    
    return true;
}


//
// Actions
//

Task< void > OkDialog::Show()
{
    if ( this->isVisible() ) { return m_closePromise.GetTask(); }

    this->setVisible( true );

    this->runAction(
        FadeTo::create( SHOW_DURATION, 0x7F )
    );

    m_layout->runAction(
        SpawnOf{
            FadeTo::create( SHOW_DURATION, 0xFF ),
            MoveBy::create( SHOW_DURATION, SHOW_MOVE_VEC )
        }
    );

    return m_closePromise.GetTask();
}


void OkDialog::OnOkButton_Click( Ref* )
{
    this->runAction(
        SequenceOf{
            FadeTo::create( HIDE_DURATION, 0 ),
            CallFunc::create( [=] { m_closePromise.RunTask(); } ),
            RemoveSelf::create()
        }
    );

    m_layout->runAction(
        SpawnOf{
            ScaleTo::create( HIDE_DURATION, 0.9f ),
            FadeTo::create( HIDE_DURATION, 0 )
        }
    );
}


///////////////////////////////////////////////////////////////////////////////
