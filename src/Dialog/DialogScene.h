// Brittle Sample Game "Carver" - Dialog Scene Header

#ifndef __CARVER_DIALOG_DIALOG_SCENE_H
#define __CARVER_DIALOG_DIALOG_SCENE_H
#pragma once

#include "CarverDefs.h"
#include <Brittle/Core/SimpleScene.h>


///////////////////////////////////////////////////////////////////////////////
//
// Dialog Scene
// - Display a modal dialog which block all the touch events on the screen.
//

class DialogScene : public SimpleScene
{
private:

    /// Scene Events ///

    void OnCreate() override;
    void OnBackKeyPressed() override;


    /// UI Events ///

    Bool OnBackground_TouchBegan( Touch*, Event* );
    void OnOpenButton_Click( Ref* );
    void OnCloseButton_Click( Ref* );
};


///////////////////////////////////////////////////////////////////////////////

#endif // __CARVER_DIALOG_DIALOG_SCENE_H
