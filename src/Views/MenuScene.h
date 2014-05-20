// Brittle Sample Game "Carver" - Menu Scene Header

#ifndef __BRITTLE_VIEWS_MENU_SCENE_H
#define __BRITTLE_VIEWS_MENU_SCENE_H
#pragma once

#include "CarverDefs.h"
#include <Brittle/Core/GameScene.h>
#include <Brittle/Ui/UiTypes.h>


///////////////////////////////////////////////////////////////////////////////
//
// Menu Scene
//

class MenuScene : public GameScene
{
public:

    MenuScene();

private:

    /// Game Scene Events ///

    void OnEnterScene() override;


    /// UI Events ///

    void OnEnterButton_Click( Ref* sender );


    /// UI Components ///

    Panel* m_panel;

    ui::ImageView*  m_aliceImage;
    ui::Text*       m_labelRaw;
    ui::TextBMFont* m_labelFont;
};


///////////////////////////////////////////////////////////////////////////////

#endif // __BRITTLE_VIEWS_MENU_SCENE_H
