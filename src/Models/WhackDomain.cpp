// Brittle Sample Game "Carver" - Whack Domain Implementation

#include "CarverPch.h"
#include "Models/WhackDomain.h"
#include <Brittle/Core/FrameClock.h>


///////////////////////////////////////////////////////////////////////////////
//
// Whack Domain
//

enum WhackState
{
    WHACK_STATE_HIDDEN,
    WHACK_STATE_APPEARED,
};

enum WhackInnerEvent
{
    WHACK_EVENT_TIMER,
};


WhackDomain::WhackDomain()
    : Machine( "WhackDomain" )
{
    m_machine.AddState( WHACK_STATE_HIDDEN )
             .EnterAction( [=] { this->Hidden_Enter(); } )
             .Transition( WHACK_EVENT_TIMER, WHACK_STATE_APPEARED );

    m_machine.AddState( WHACK_STATE_APPEARED )
             .EnterAction( [=] { this->Appeared_Enter(); } )
             .Transition( WHACK_EVENT_TIMER, WHACK_STATE_HIDDEN );

    m_machine.Initiate( WHACK_STATE_HIDDEN );
}


void WhackDomain::Hidden_Enter()
{
    this->DispatchEvent( WHACK_EVENT_HIDE );

    m_machine.StartTimer( Seconds( 3 ), WHACK_EVENT_TIMER );
}


void WhackDomain::Appeared_Enter()
{
    this->DispatchEvent( WHACK_EVENT_APPEAR );

    m_machine.StartTimer( Seconds( 3 ), WHACK_EVENT_TIMER );
}


///////////////////////////////////////////////////////////////////////////////
