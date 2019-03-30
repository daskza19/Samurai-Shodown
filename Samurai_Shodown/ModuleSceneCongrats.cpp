#include "Globals.h"
#include "Application.h"
#include "ModuleSceneCongrats.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"

ModuleSceneCongrats::ModuleSceneCongrats()
{

}

ModuleSceneCongrats::~ModuleSceneCongrats()
{

}

// Load assets
bool ModuleSceneCongrats::Start()
{
	LOG("Loading background assets");
	bool ret = true;
	graphics = App->textures->Load("");

	// TODO 1: Enable (and properly disable) the player module
	App->player->Enable();
	return ret;
}

// Load assets
bool ModuleSceneCongrats::CleanUp()
{
	LOG("Unloading Congrats stage");
	App->player->Disable();
	return true;
}

// Update: draw background
update_status ModuleSceneCongrats::Update()
{
	// Draw everything --------------------------------------	
	App->render->Blit(graphics, 0, 160, &ground);

	// TODO 2: make so pressing SPACE the KEN stage is loaded

	return UPDATE_CONTINUE;
}