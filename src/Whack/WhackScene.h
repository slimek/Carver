// Brittle Sample Game "Carver" - Whack Scene Header

#ifndef __CARVER_WHACK_WHACK_SCENE_H
#define __CARVER_WHACK_WHACK_SCENE_H
#pragma once

#include "CarverDefs.h"
#include <Brittle/Core/SimpleScene.h>
#include <Brittle/Ui/UiTypes.h>
#include <Caramel/Statechart/StateMachine.h>


///////////////////////////////////////////////////////////////////////////////
//
// Whack Scene
//

class WhackScene : public SimpleScene
{
public:

    WhackScene();

private:

    /// Scene Events ///

    void OnEnterScene() override;
    void OnUpdate() override;
    void OnBackKeyPressed() override;


    /// Actions ///

    void MoleAppear();
    void MoleHide();


    /// UI Components ///
    
    Panel* m_panel;    


    /// Moving Sprites ///

    Sprite* m_mole;


    /// States ///

    void Title_Enter();
    void Title_Exit();
    void Start_Enter();
    void Finish_Enter();
    void Finish_Exit();

    Statechart::StateMachine m_machine;
};


///////////////////////////////////////////////////////////////////////////////

#endif // __CARVER_WHACK_WHACK_SCENE_H
