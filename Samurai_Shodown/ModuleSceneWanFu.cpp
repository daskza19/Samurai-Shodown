#include "ModuleSceneWanFu.h"
#include "Application.h"
#include "ModuleCollision.h"
#include "ModulePlayer2.h"

ModuleSceneWanFu::ModuleSceneWanFu()
{
	//background animation
	{
		background.PushBack({ 0,78,512,333 }, 0.08f);
		background.PushBack({ 512,78,512,333 }, 0.08f);
		background.PushBack({ 0,527,512,333 }, 0.08f);
		background.PushBack({ 512,527,512,333 }, 0.08f);
	}
}

ModuleSceneWanFu::~ModuleSceneWanFu()
{}

// Load assets
bool ModuleSceneWanFu::Start()
{
	LOG("Loading Kyoshiro Scene");
	bool ret = true;

	graphics = App->textures->Load("Assets/Textures/KyoshiroScene.png");
	music = App->audio->LoadMusic("Assets/Audio/Music/Kyoshiro.ogg");
	App->audio->PlayMusic(music, NULL);
	App->player->Enable();
	App->player2->Enable();

	//Colliders for the screen borders


	return ret;
}

// Load assets
bool ModuleSceneWanFu::CleanUp()
{
	LOG("Unloading Kyoshiro stage");
	App->player->Disable();
	App->player2->Disable();
	App->textures->Unload(graphics);
	Mix_FadeOutMusic(1250);
	App->audio->UnLoadMusic(music);
	App->collision->CleanUp();
	//App->audio->CleanUp();
	return true;
}

update_status ModuleSceneWanFu::Update()
{
	SDL_Rect b;
	// Draw everything --------------------------------------	
	b = background.GetCurrentFrame();
	App->render->Blit(graphics, -60, -100, &b,SDL_FLIP_NONE, 0.75f);
	if (App->input->keyboard[SDL_SCANCODE_F3] == KEY_DOWN)
	{
		App->fade->FadeToBlack((Module*)App->scene_wanfu, (Module*)App->scene_congrats, 2.5);
	}
	if ((App->input->keyboard[SDL_SCANCODE_F2] == KEY_DOWN))
	{
		App->fade->FadeToBlack((Module*)App->scene_wanfu, (Module*)App->scene_haohmaru, 1.5f);
	}

	return UPDATE_CONTINUE;
}