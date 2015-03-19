// Brittle Sample Game "Carver" - Bola Scene Header

#ifndef __CARVER_BOLA_BOLA_SCENE_H
#define __CARVER_BOLA_BOLA_SCENE_H
#pragma once

#include "CarverDefs.h"
#include <Brittle/Core/SimpleScene.h>


///////////////////////////////////////////////////////////////////////////////
//
// Bola Scene
// - This scene has a ball (or bola in Spanish).
//   1. You may touch the ball and move it.
//   2. If you swipe the screen, the ball would bounce to the direction.
//

class BolaScene : public SimpleScene
{
private:

    /// Scene Events ///

    void OnCreate() override;
    void OnBackKeyPressed() override;

    /// Touch Events ///

    Bool OnTouchBegan( Touch* touch, Event* event );
    void OnTouchMoved( Touch* touch, Event* event );

    /// Members ///

    Sprite* m_ball { nullptr };
    Bool m_ballTouched { false };
    Vec2 m_ballStartPosition;
};


///////////////////////////////////////////////////////////////////////////////

#endif // __CARVER_BOLA_BOLA_SCENE_H
