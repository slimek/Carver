// Brittle Sample Game "Carver" - Flappy Scene Header

#ifndef __CARVER_FLAPPY_FLAPPY_SCENE_H
#define __CARVER_FLAPPY_FLAPPY_SCENE_H
#pragma once

#include "CarverDefs.h"
#include <Brittle/Core/SimpleScene.h>


///////////////////////////////////////////////////////////////////////////////
//
// Flappy Scene
// - This scene mimics the famous "Flappy Bird".
//

class FlappyScene : public SimpleScene
{
private:

    /// Scene Events ///

    void OnEnterScene() override;
    void OnBackKeyPressed() override;

};


///////////////////////////////////////////////////////////////////////////////

#endif // __CARVER_FLAPPY_FLAPPY_SCENE_H
