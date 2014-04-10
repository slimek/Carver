// Brittle Sample Game "Carver" - Application Header

#ifndef __CARVER_CARVER_APP_H
#define __CARVER_CARVER_APP_H
#pragma once

#include "CarverDefs.h"
#include <Brittle/Core/GameApp.h>


class CarverApp : public GameApp
{
public:

    /// Application Events ///

    void OnLaunch() override;
};


#endif // __CARVER_CARVER_APP_H
