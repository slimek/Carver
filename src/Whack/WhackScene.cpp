// Brittle Sample Game "Carver" - Whack Scene Implementation

#include "CarverPch.h"
#include "Whack/WhackScene.h"
#include <Brittle/Actions/IntervalActions.h>
#include <Brittle/Core/Async.h>
#include <Brittle/Ui/Panel.h>


///////////////////////////////////////////////////////////////////////////////
//
// Whack Scene
//

enum WhackState
{ 
    WHACK_STATE_TITLE,      // wait
    WHACK_STATE_START,      // transit
    WHACK_STATE_PLAYING,    // running
    WHACK_STATE_FINISH,     // transit + wait
};

enum WhackEvent
{
    WHACK_EVENT_NEXT,
};


WhackScene::WhackScene()
    : m_panel( nullptr )
    , m_mole( nullptr )
    , m_machine( "WhackScene", Async::RenderExecutor() )
{
    m_machine.AddState( WHACK_STATE_TITLE )
             .EnterAction( [=] { this->Title_Enter(); } )
             .ExitAction( [=] { this->Title_Exit(); } )
             .Transition( WHACK_EVENT_NEXT, WHACK_STATE_START );

    m_machine.AddState( WHACK_STATE_START )
             .EnterAction( [=] { this->Start_Enter(); } )
             .Transition( WHACK_EVENT_NEXT, WHACK_STATE_PLAYING );

    m_machine.AddState( WHACK_STATE_PLAYING )
             .Transition( WHACK_EVENT_NEXT, WHACK_STATE_FINISH );

    m_machine.AddState( WHACK_STATE_FINISH )
             .EnterAction( [=] { this->Finish_Enter(); } )
             .ExitAction( [=] { this->Finish_Exit(); } )
             .Transition( WHACK_EVENT_NEXT, WHACK_STATE_START );
}


void WhackScene::OnEnterScene()
{
    auto title = Sprite::create( "texture/whack-title.png" );
    this->addChild( title, 1 );
    
    m_panel = Panel::Create( "layout/whack-scene.json" );
    this->addChild( m_panel );


    // Create a mole and put it on the hidden position.

    m_mole = Sprite::create( "texture/mole.png" );
    m_mole->setScale( 0.5 );
    m_mole->setPosition( 320, 200 );
    this->addChild( m_mole );


    // Create the hay stack.

    auto hayStack = Sprite::create( "texture/hay-stack.png" );
    hayStack->setPosition( 320, 200 );
    this->addChild( hayStack );


    m_machine.Initiate( WHACK_STATE_TITLE );
}


void WhackScene::OnUpdate()
{
}


void WhackScene::OnBackKeyPressed()
{
    SimpleScene::ReplaceScene( SCENE_MENU );
}


void WhackScene::Title_Enter()
{
}


void WhackScene::Title_Exit()
{
}


void WhackScene::Start_Enter()
{
}


void WhackScene::Finish_Enter()
{
}


void WhackScene::Finish_Exit()
{
}


void WhackScene::MoleAppear()
{
    CARAMEL_TRACE_INFO( "Appear" );

    m_mole->runAction(
        Bta::MoveTo( 1, 320, 400 ));
}


void WhackScene::MoleHide()
{
    CARAMEL_TRACE_INFO( "Hide" );

    m_mole->runAction(
        Bta::MoveTo( 1, 320, 200 ));
}


///////////////////////////////////////////////////////////////////////////////
