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
    SCENE_MENU  = 1,
    SCENE_WHACK = 2,
};


///////////////////////////////////////////////////////////////////////////////
//
// Forwards Declaration
//

// Models
class WhackModel;
typedef std::shared_ptr< WhackModel > WhackModelPtr;

// Views
class MenuScene;
class WhackScene;


///////////////////////////////////////////////////////////////////////////////

#endif // __CARVER_CARVER_DEFS_H
