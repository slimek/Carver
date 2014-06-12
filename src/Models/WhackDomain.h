// Brittle Sample Game "Carver" - Whack Domain Header

#ifndef __CARVER_MODELS_WHACK_DOMAIN_H
#define __CARVER_MODELS_WHACK_DOMAIN_H
#pragma once

#include "CarverDefs.h"
#include <Brittle/Mv/Machine.h>


///////////////////////////////////////////////////////////////////////////////
//
// Whack Domain
//

class WhackDomain : public Machine
                  , public std::enable_shared_from_this< WhackDomain >
{
public:

    WhackDomain();

private:

    void Hidden_Enter();
    void Appeared_Enter();
};


///////////////////////////////////////////////////////////////////////////////

#endif // __CARVER_MODELS_WHACK_DOMAIN_H
