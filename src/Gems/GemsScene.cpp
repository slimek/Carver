// Brittle Sample Game "Carver" - Gems Scene Implementation

#include "CarverPch.h"
#include "Gems/GemsScene.h"

#include <Brittle/Actions/IntervalActions.h>
#include <Brittle/Layout/LayoutJson.h>
#include <Brittle/Layout/Locate.h>
#include <Brittle/Layout/Stretch.h>
#include <Brittle/Nodes/EllipseTouchable.h>


void GemsScene::OnEnterScene()
{
    auto background = Sprite::create( "texture/blue-grid.png" );
    this->addChild( background );

    Stretch( background ).Fill();


    /// Place Gems ///

    /// Part 1 : Locate sprites by JSON layout ///

    LayoutJson layout( "layout/gems-scene.json" );

    m_ruby = layout.AddSprite( this, "ruby" );

    m_rubyTouch = EllipseTouchable::Create();
    m_ruby->addChild( m_rubyTouch );

    m_sapphire = layout.AddSprite( this, "sapphire" );
    

    /// Part 2 : Locat sprites by code ///

    m_emerald = Sprite::create( "texture/emerald.png" );
    this->addChild( m_emerald );

    Locate( m_emerald ).FromLeftBottom( 160, 200 );

    m_diamond = Sprite::create( "texture/diamond.png" );
    this->addChild( m_diamond );

    Locate( m_diamond ).FromRightBottom( 160, 200 );

    // Put all gems on the vector
    m_gems = { m_ruby, m_sapphire, m_emerald, m_diamond };

    this->StartGemsActions();
}


void GemsScene::OnBackKeyPressed()
{
    SimpleScene::ReplaceScene( SCENE_MENU );
}


//
// Actions
//

void GemsScene::StartGemsActions()
{
    for ( auto gem : m_gems )
    {
        gem->setScale( 0 );
    }

    m_rubyTouch->Clear();

    auto actions = [] ( Node* target, EllipseTouchable* touch )
    {
        return
        (
            ( Bta::ScaleTo( 1, 1 ) + Bta::RotateBy( 1, 360 ) ) >>
            Bta::ScaleTo( 0, 1 )
        )
        .Target( target );
    };

    this->runAction(
        actions( m_ruby, m_rubyTouch ) >> actions( m_sapphire, m_rubyTouch ) >>
        actions( m_emerald, m_rubyTouch ) >> actions( m_diamond, m_rubyTouch )
    );
}
