// Brittle Sample Game "Carver" - Gems Scene Header

#ifndef __CARVER_GEMS_GEMS_SCENE_H
#define __CARVER_GEMS_GEMS_SCENE_H
#pragma once

#include "CarverDefs.h"
#include <Brittle/Core/SimpleScene.h>


///////////////////////////////////////////////////////////////////////////////
//
// Gems Scene
// - This scene has four gems, slowly appear one by one, 
//   You may touch them to --
//   1. Show up immediately.
//   2. Accelerate the action.
// 

class GemsScene : public SimpleScene
{
private:

    /// Scene Events ///

    void OnEnterScene() override;
    void OnBackKeyPressed() override;


    /// Actions ///

    void StartGemsActions();


    /// Members ///

    Sprite* m_ruby { nullptr };
    Sprite* m_sapphire { nullptr };
    Sprite* m_emerald { nullptr };
    Sprite* m_diamond { nullptr };
};


///////////////////////////////////////////////////////////////////////////////

#endif // __CARVER_GEMS_GEMS_SCENE_H
