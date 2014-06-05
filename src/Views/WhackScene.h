// Brittle Sample Game "Carver" - Whack Scene Header

#ifndef __CARVER_VIEWS_WHACK_SCENE_H
#define __CARVER_VIEWS_WHACK_SCENE_H
#pragma once

#include "CarverDefs.h"
#include <Brittle/Core/GameScene.h>
#include <Brittle/Ui/UiTypes.h>
#include <Caramel/Async/AnyEventQueue.h>


///////////////////////////////////////////////////////////////////////////////
//
// Whack Scene
//

class WhackScene : public GameScene
{
public:

    explicit WhackScene( WhackModelPtr model );

private:

    /// Game Scene Events ///

    void OnEnterScene() override;
    void OnExitScene() override;


    /// UI Components ///
    
    Panel* m_panel;    


    /// Moving Sprites ///

    Sprite* m_mole;


    /// MV Components ///

    WhackModelPtr m_model;

    AnyEventQueue m_events;
};


///////////////////////////////////////////////////////////////////////////////

#endif // __CARVER_VIEWS_WHACK_SCENE_H
