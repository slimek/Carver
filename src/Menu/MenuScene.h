// Brittle Sample Game "Carver" - Menu Scene Header

#ifndef __CARVER_VIEWS_MENU_SCENE_H
#define __CARVER_VIEWS_MENU_SCENE_H
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

    void OnEnterScene() override;


    /// UI Events ///

    void OnEnterButton_Click( Ref* sender );
    void OnMenuWhack_Click( Ref* sender );
    void OnMenuClock_Click( Ref* sender );


    /// UI Components ///

    Panel* m_panel;

    ui::ImageView*  m_aliceImage;
    ui::Text*       m_labelRaw;
    ui::TextBMFont* m_labelFont;
};


///////////////////////////////////////////////////////////////////////////////

#endif // __CARVER_VIEWS_MENU_SCENE_H