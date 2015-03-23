// Brittle Sample Game "Carver" - Menu Scene Header

#ifndef __CARVER_MENU_MENU_SCENE_H
#define __CARVER_MENU_MENU_SCENE_H
#pragma once

#include "CarverDefs.h"
#include <Brittle/Core/SimpleScene.h>
#include <Brittle/Ui/UiTypes.h>


///////////////////////////////////////////////////////////////////////////////
//
// Menu Scene
//

class MenuScene : public SimpleScene
{
public:

    MenuScene();

private:

    /// Scene Events ///

    void OnCreate() override;


    /// UI Events ///

    void OnEnterButton_Click( Ref* sender );


    /// UI Components ///

    Panel* m_panel;

    ui::ImageView*  m_aliceImage;
    ui::Text*       m_labelRaw;
    ui::TextBMFont* m_labelFont;
};


///////////////////////////////////////////////////////////////////////////////

#endif // __CARVER_MENU_MENU_SCENE_H
