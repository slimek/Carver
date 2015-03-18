// Brittle Sample Game "Carver" - Application Header

#ifndef __CARVER_CARVER_APP_H
#define __CARVER_CARVER_APP_H
#pragma once

#include "CarverDefs.h"
#include <Brittle/Core/SimpleApp.h>


class CarverApp : public SimpleApp
{
public:

    CarverApp();


    /// Scene Management ///

    SimpleScene* CreateScene( Int sceneId ) override;
};


#endif // __CARVER_CARVER_APP_H
