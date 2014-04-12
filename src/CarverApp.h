// Brittle Sample Game "Carver" - Application Header

#ifndef __CARVER_CARVER_APP_H
#define __CARVER_CARVER_APP_H
#pragma once

#include "CarverDefs.h"
#include <Brittle/Core/GameApp.h>


class CarverApp : public GameApp
{
public:

    ~CarverApp();

    /// Application Events ///

    void OnLaunch() override;


    /// Scene Management ///

    GameScene* CreateScene( Int sceneId ) override;
};


#endif // __CARVER_CARVER_APP_H
