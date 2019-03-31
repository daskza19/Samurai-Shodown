#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "Globals.h"


#define NUM_MODULES 11

class ModuleWindow;
class ModuleInput;
class ModuleTextures;
class ModuleRender;
class ModulePlayer;
class ModuleAudio;
class ModuleFadeToBlack;
class Module;
class ModuleSceneWelcome;
class ModuleSceneHaohmaru;
class ModuleSceneKyoshiro;
class ModuleSceneCongrats;

class Application
{
public:

	Module * modules[NUM_MODULES] = { nullptr };
	ModuleWindow* window = nullptr;
	ModuleRender* render = nullptr;
	ModuleInput* input = nullptr;
	ModuleTextures* textures = nullptr;
	ModulePlayer* player = nullptr;
	ModuleAudio* audio = nullptr;
	ModuleFadeToBlack*	fade = nullptr;
	ModuleSceneWelcome* scene_welcome = nullptr;
	ModuleSceneHaohmaru* scene_haohmaru = nullptr;
	ModuleSceneKyoshiro* scene_kyoshiro = nullptr;
	ModuleSceneCongrats* scene_congrats = nullptr;

public:

	Application();
	~Application();

	bool Init();
	update_status Update();
	bool CleanUp();

};

// Global var made extern for Application ---
extern Application* App;

#endif // __APPLICATION_H__