#include "CarverApp.h"
#include <jni.h>

void cocos_android_app_init( JNIEnv* evn, jobject thiz )
{
	Brittle::AppSettings s;
	s.initialSceneId = SCENE_MENU;

	auto app = new CarverApp;
	app->Launch( s );
}
