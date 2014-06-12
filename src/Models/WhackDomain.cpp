// Brittle Sample Game "Carver" - Whack Domain Implementation

#include "CarverPch.h"
#include "Models/WhackDomain.h"


///////////////////////////////////////////////////////////////////////////////
//
// Whack Domain
//

enum WhackState
{
    WHACK_STATE_HIDDEN,
    WHACK_STATE_APPEARED,
};


WhackDomain::WhackDomain()
    : Machine( "WhackDomain" )
{
    m_machine.AddState( WHACK_STATE_HIDDEN )
             .EnterAction( [=] { this->Hidden_Enter(); } );

    m_machine.AddState( WHACK_STATE_APPEARED )
             .EnterAction( [=] { this->Appeared_Enter(); } );

    m_machine.Initiate( WHACK_STATE_HIDDEN );
}


void WhackDomain::Hidden_Enter()
{
}


void WhackDomain::Appeared_Enter()
{
}


///////////////////////////////////////////////////////////////////////////////
