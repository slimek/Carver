#include "CarverApp.h"


using namespace Brittle;

void NativeInit( SimpleApp*& app, AppSettings& s )
{
	s.initialSceneId = SCENE_MENU;

	app = new CarverApp();
}
