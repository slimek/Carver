// Brittle Sample Game "Carver" - Clock Scene Header

#ifndef __CARVER_VIEWS_CLOCK_SCENE_H
#define __CARVER_VIEWS_CLOCK_SCENE_H
#pragma once

#include "CarverDefs.h"
#include <Brittle/Core/FrameClock.h>
#include <Brittle/Core/SimpleScene.h>
#include <Brittle/Ui/UiTypes.h>
#include <Caramel/Chrono/SecondClock.h>
#include <Caramel/Chrono/TimedBool.h>


///////////////////////////////////////////////////////////////////////////////
//
// Clock Scene
//

class ClockScene : public SimpleScene
{
public:

    ClockScene();

private:

    /// Scene Events ///

    void OnEnterScene() override;
    void OnUpdate() override;


    /// UI Componsnets ///

    Panel* m_panel;

    ui::Text*   m_labelSecondClock;
    ui::Text*   m_labelFrameClock;

    SecondPoint m_secondClockStart;
    FrameTime   m_frameClockStart;

    TimedBool< SecondClock > m_labelsTimer;
};


///////////////////////////////////////////////////////////////////////////////

#endif // __CARVER_VIEWS_CLOCK_SCENE_H

