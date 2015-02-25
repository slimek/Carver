// Brittle Sample Game "Carver" - Clock Scene Implementation

#include "CarverPch.h"
#include "Clock/ClockScene.h"
#include <Brittle/Ui/Panel.h>
#include <ui/UIText.h>


///////////////////////////////////////////////////////////////////////////////
//
// Clock Scene
//

ClockScene::ClockScene()
    : m_panel( nullptr )
    , m_labelSecondClock( nullptr )
    , m_labelFrameClock( nullptr )
    , m_secondClockStart( SecondClock::Now() )
    , m_frameClockStart( FrameClock::Now() )
    , m_labelsTimer( 0.125 )
{
}


void ClockScene::OnEnterScene()
{
    m_panel = Panel::Create( "layout/clock-scene.json" );
    this->addChild( m_panel );

    m_panel->GetChild( "labelSecondClock", m_labelSecondClock );
    m_panel->GetChild( "labelFrameClock", m_labelFrameClock );

    m_panel->SetClickHandler( "pauseButton", &ClockScene::OnPauseButton_Click, this );
}


void ClockScene::OnUpdate()
{
    if ( m_labelsTimer.TakeAndContinue() )
    {
        Seconds secondClockElapsed = SecondClock::Now() - m_secondClockStart;

        m_labelSecondClock->setString( Format( "Second elapsed: {0}", secondClockElapsed.ToFloat() ));

        Seconds frameClockElapsed = FrameClock::Now() - m_frameClockStart;

        m_labelFrameClock->setString( Format( "Frame elapsed: {0}", frameClockElapsed.ToFloat() ));
    }
}


void ClockScene::OnPauseButton_Click( Ref* )
{
    if ( FrameClock::IsPaused() )
    {
        FrameClock::Resume();
    }
    else
        FrameClock::Pause();
}


///////////////////////////////////////////////////////////////////////////////
