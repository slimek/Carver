// Brittle Sample Game "Carver" - Gems Scene Implementation

#include "CarverPch.h"
#include "Gems/GemsScene.h"

#include <Brittle/Actions/IntervalActions.h>
#include <Brittle/Layout/Locate.h>
#include <Brittle/Layout/Stretch.h>


void GemsScene::OnEnterScene()
{
    auto background = Sprite::create( "texture/blue-grid.png" );
    this->addChild( background );

    Stretch( background ).Fill();


    /// Place Gems ///

    m_ruby = Sprite::create( "texture/ruby.png" );
    this->addChild( m_ruby );

    Locate( m_ruby ).FromTop( 160 ).FromLeft( 160 );

    m_sapphire = Sprite::create( "texture/sapphire.png" );
    this->addChild( m_sapphire );

    Locate( m_sapphire ).FromTop( 160 ).FromRight( 160 );

    m_emerald = Sprite::create( "texture/emerald.png" );
    this->addChild( m_emerald );

    Locate( m_emerald ).FromBottom( 200 ).FromLeft( 160 );

    m_diamond = Sprite::create( "texture/diamond.png" );
    this->addChild( m_diamond );

    Locate( m_diamond ).FromBottom( 200 ).FromRight( 160 );

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

    auto actions = [] ( Node* target )
    {
        return
        (
            ( Bta::ScaleTo( 1, 1 ) + Bta::RotateBy( 1, 360 ) ) >>
            Bta::ScaleTo( 0, 1 )
        )
        .Target( target );
    };

    this->runAction(
        actions( m_ruby ) >> actions( m_sapphire ) >>
        actions( m_emerald ) >> actions( m_diamond )
    );
}
