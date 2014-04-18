// Brittle Sample Game "Carver" - Menu Scene Implementation

#include "CarverPch.h"
#include "Views/MenuScene.h"
#include <ui/CocosGUI.h>


///////////////////////////////////////////////////////////////////////////////
//
// Menu Scene
//

void MenuScene::OnEnterScene()
{
    auto alice = Sprite::create( "texture/alice.png" );
    alice->setPositionX( 270 );
    alice->setPositionY( 360 );
    this->addChild( alice );

    //auto label = ui::TextField::create();
    //label->setText( "Alice" );
    //label->setFontName( "Arial" );
    //label->setFontSize( 30 );
    //label->setPosition( Point( 270, 200 ));
    //this->addChild( label );

    auto label = ui::TextBMFont::create( "Alice", "font/nina.fnt" );
    label->setPosition( Point( 270, 200 ));
    label->setColor( Color3B::YELLOW );
    this->addChild( label );
}


///////////////////////////////////////////////////////////////////////////////
