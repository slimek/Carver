// Brittle Sample Game "Carver" - Whack Model Header

#ifndef __CARVER_MODELS_WHACK_MODEL_H
#define __CARVER_MODELS_WHACK_MODEL_H
#pragma once

#include "CarverDefs.h"
#include <Brittle/Mv/Machine.h>


///////////////////////////////////////////////////////////////////////////////
//
// Whack Model
//

class WhackModel : public Machine
                 , public std::enable_shared_from_this< WhackModel >
{
public:

    WhackModel();

private:

    void Hidden_Enter();
    void Appeared_Enter();
};


///////////////////////////////////////////////////////////////////////////////

#endif // __CARVER_MODELS_WHACK_MODEL_H
