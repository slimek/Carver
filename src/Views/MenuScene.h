// Brittle Sample Game "Carver" - Menu Scene Header

#ifndef __BRITTLE_VIEWS_MENU_SCENE_H
#define __BRITTLE_VIEWS_MENU_SCENE_H
#pragma once

#include "CarverDefs.h"
#include <Brittle/Core/GameScene.h>


///////////////////////////////////////////////////////////////////////////////
//
// Menu Scene
//

class MenuScene : public GameScene
{
private:

    /// Game Scene Events ///

    void OnEnterScene() override;


    /// UI Components ///
};


///////////////////////////////////////////////////////////////////////////////

#endif // __BRITTLE_VIEWS_MENU_SCENE_H
