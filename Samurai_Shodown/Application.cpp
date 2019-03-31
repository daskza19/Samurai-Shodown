#include "Application.h"
#include "ModuleWindow.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModuleTextures.h"
#include "ModulePlayer.h"
#include "ModuleFadeToBlack.h"
#include "ModuleAudio.h"
#include "ModuleSceneWelcome.h"
#include "ModuleSceneHaohmaru.h"
#include "ModuleSceneKyoshiro.h"
#include "ModuleSceneCongrats.h"

Application::Application()
{
	int i = -1;
	modules[++i] = window = new ModuleWindow();
	modules[++i] = render = new ModuleRender();
	modules[++i] = input = new ModuleInput();
	modules[++i] = audio = new ModuleAudio();
	modules[++i] = textures = new ModuleTextures();
	modules[++i] = scene_welcome = new ModuleSceneWelcome();
	modules[++i] = scene_haohmaru = new ModuleSceneHaohmaru();
	modules[++i] = scene_kyoshiro = new ModuleSceneKyoshiro();
	modules[++i] = scene_congrats = new ModuleSceneCongrats();
	modules[++i] = player = new ModulePlayer();
	modules[++i] = fade = new ModuleFadeToBlack();

}	

Application::~Application()
{
	for (int i = NUM_MODULES - 1; i >= 0; --i)
		delete modules[i];
}

bool Application::Init()
{
	bool ret = true;

	// Player will be enabled on the first update of a new scene
	player->Disable();
	// Disable the map that you do not start with
	//scene_welcome->Disable();
	scene_haohmaru->Disable();
	scene_kyoshiro->Disable();
	scene_congrats->Disable();

	for (int i = 0; i < NUM_MODULES && ret == true; ++i)
		ret = modules[i]->Init();

	for (int i = 0; i < NUM_MODULES && ret == true; ++i)
		ret = modules[i]->IsEnabled() ? modules[i]->Start() : true;

	return ret;
}

update_status Application::Update()
{
	update_status ret = UPDATE_CONTINUE;

	for (int i = 0; i < NUM_MODULES && ret == UPDATE_CONTINUE; ++i)
		ret = modules[i]->IsEnabled() ? modules[i]->PreUpdate() : UPDATE_CONTINUE;

	for (int i = 0; i < NUM_MODULES && ret == UPDATE_CONTINUE; ++i)
		ret = modules[i]->IsEnabled() ? modules[i]->Update() : UPDATE_CONTINUE;

	for (int i = 0; i < NUM_MODULES && ret == UPDATE_CONTINUE; ++i)
		ret = modules[i]->IsEnabled() ? modules[i]->PostUpdate() : UPDATE_CONTINUE;

	return ret;
}

bool Application::CleanUp()
{
	bool ret = true;

	for (int i = NUM_MODULES - 1; i >= 0 && ret == true; --i)
		ret = modules[i]->CleanUp();

	return ret;
}