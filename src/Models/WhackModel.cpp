// Brittle Sample Game "Carver" - Whack Model Implementation

#include "CarverPch.h"
#include "Models/WhackModel.h"


///////////////////////////////////////////////////////////////////////////////
//
// Whack Model
//

enum WhackState
{
    WHACK_STATE_HIDDEN,
    WHACK_STATE_APPEARED,
};


WhackModel::WhackModel()
    : Machine( "WhackModel" )
{
    m_machine.AddState( WHACK_STATE_HIDDEN )
             .EnterAction( [=] { this->Hidden_Enter(); } );

    m_machine.AddState( WHACK_STATE_APPEARED )
             .EnterAction( [=] { this->Appeared_Enter(); } );

    m_machine.Initiate( WHACK_STATE_HIDDEN );
}


void WhackModel::Hidden_Enter()
{
}


void WhackModel::Appeared_Enter()
{
}


///////////////////////////////////////////////////////////////////////////////
