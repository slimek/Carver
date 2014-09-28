// Brittle Sample Game "Carver" - Bola Scene Implementation

#include "CarverPch.h"
#include "Bola/BolaScene.h"

#include <Brittle/Layout/Locate.h>
#include <Brittle/Layout/Stretch.h>


void BolaScene::OnEnterScene()
{
    auto background = Sprite::create( "texture/blue-grid.png" );
    this->addChild( background );

    Stretch( background ).Fill();

    auto ball = Sprite::create( "texture/basketball.png" );
    this->addChild( ball );

    Locate( ball ).Center();
}
