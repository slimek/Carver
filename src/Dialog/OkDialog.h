// Brittle Sample Game "Carver" - Ok Dialog Header

#ifndef __CARVER_DIALOG_OK_DIALOG_H
#define __CARVER_DIALOG_OK_DIALOG_H
#pragma once

#include "CarverDefs.h"
#include <Brittle/Nodes/ScreenCover.h>
#include <Caramel/Task/Promise.h>


///////////////////////////////////////////////////////////////////////////////
//
// Ok Dialog
//

class OkDialog : public ScreenCover
{
public:

    static OkDialog* Create( SimpleScene* scene );

    Task< void > Show();


private:

    Bool Init( SimpleScene* scene );

    void OnOkButton_Click( Ref* );

    Promise< void > m_closePromise;

    ui::Layout* m_layout { nullptr };
};


///////////////////////////////////////////////////////////////////////////////

#endif // __CARVER_DIALOG_OK_DIALOG_H
