// Brittle Sample Game "Carver" - Ok Dialog Header

#ifndef __CARVER_DIALOG_OK_DIALOG_H
#define __CARVER_DIALOG_OK_DIALOG_H
#pragma once

#include "CarverDefs.h"
#include <Brittle/Nodes/ScreenCover.h>
#include <Caramel/Async/AnyEventTask.h>
#include <Caramel/Task/TaskCompletionSource.h>


///////////////////////////////////////////////////////////////////////////////
//
// Ok Dialog
//

class OkDialog : public ScreenCover
{
public:

    static OkDialog* Create( SimpleScene* scene );

    AnyEventTask Show();


private:

    Bool Init( SimpleScene* scene );

    void OnOkButton_Click( Ref* );

    TaskCompletionSource< AnyEvent > m_closeTask;

    ui::Layout* m_layout { nullptr };
};


///////////////////////////////////////////////////////////////////////////////

#endif // __CARVER_DIALOG_OK_DIALOG_H
