// Brittle Sample Game "Carver" - Basic Defines Header

#ifndef __CARVER_CARVER_DEFS_H
#define __CARVER_CARVER_DEFS_H
#pragma once

#include <Brittle/Setup/BrittleDefs.h>


using namespace Brittle;
using namespace Caramel;


///////////////////////////////////////////////////////////////////////////////
//
// Game Constants
//

enum SceneId
{
    SCENE_MENU   = 1,
    SCENE_WHACK  = 2,
    SCENE_CLOCK  = 3,
    SCENE_BOLA   = 4,
    SCENE_GEMS   = 5,
    SCENE_FLAPPY = 6,
    SCENE_DIALOG = 7,
};


///////////////////////////////////////////////////////////////////////////////
//
// Forwards Declaration
//

// Models
class WhackDomain;
typedef std::shared_ptr< WhackDomain > WhackDomainPtr;

// Views
class MenuScene;
class WhackScene;


///////////////////////////////////////////////////////////////////////////////

#endif // __CARVER_CARVER_DEFS_H
