#ifdef _WIN32
    #define CC_API __declspec(dllimport)
    #define CC_VAR __declspec(dllimport)
    #define EXPORT __declspec(dllexport)
#else
    #define CC_API
    #define CC_VAR
    #define EXPORT __attribute__((visibility("default")))
#endif

#include "src/Chat.h"
#include "src/Game.h"
#include "src/String.h"
#include "src/World.h"
#include "src/Options.h"


/*CREDIT: Rulja1234*/
static void hell_Execute(const cc_string* args, int argsCount) {
	/*Check if arg is empty*/
	if (!argsCount) {
	cc_string Msg = String_FromConst("&e/client hell: &cYou didn't specify true or false.");
    Chat_Add(&Msg);
	return; }
	cc_string ifTrue = String_FromConst("true");
	cc_string ifFalse = String_FromConst("false");
	
	/*Check if arg is false*/
	if (String_Compare(&args[0], &ifFalse) == 0) {
	Env_Reset();
	Env_SetCloudsHeight(66);
	Env_SetEdgeHeight(32);
	cc_string Msg = String_FromConst("&eBrought world back to normal.");
    Chat_Add(&Msg);
	return; }
	
	/*Check if arg is wrong*/
	if (String_Compare(&args[0], &ifTrue) != 0) {
	cc_string Msg = String_FromConst("&e/client hell: &cUnrecognised argument.");
    Chat_Add(&Msg);
	return; }
	
	/*Changes the world*/
	Env_SetEdgeBlock(10);
	Env_SetCloudsSpeed(1000);
	Env_SetWeatherSpeed(-2);
	Env_SetWeather(1);
	Env_SetSkyCol(PackedCol_Make(255, 0, 0, 255));
	Env_SetFogCol(PackedCol_Make(10, 0, 0, 255));
	Env_SetCloudsCol(PackedCol_Make(45, 0, 0, 255));
	Env_SetSkyboxCol(PackedCol_Make(255, 0, 0, 255));
	Env_SetSunCol(PackedCol_Make(138, 45, 1, 255));
	Env_SetShadowCol(PackedCol_Make(50, 0, 0, 255));
 	cc_string Msg = String_FromConst("&4Welcome to Hell!");
    Chat_Add(&Msg);
	return;
}

static struct ChatCommand Hell = {
	"Hell", hell_Execute, false,
	{
		"&a/client hell [true/false]",
		"&btrue: &eTurns your world to hell",
		"&bfalse: &eTurns your world back to normal",
	}
};

static void Hell_Init(void) {
	Commands_Register(&Hell);

}

EXPORT int Plugin_ApiVersion = 1;
EXPORT struct IGameComponent Plugin_Component = { Hell_Init };
