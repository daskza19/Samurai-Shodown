#include "ModuleSceneKyoshiro.h"
#include "Application.h"
#include "ModuleCollision.h"
#include "Application.h"

ModuleSceneKyoshiro::ModuleSceneKyoshiro()
{
	//background animation
	{
		background.PushBack({ 0,78,512,333 }, 0.08f);
		background.PushBack({ 512,78,512,333 }, 0.08f);
		background.PushBack({ 0,527,512,333 }, 0.08f);
		//background.PushBack({ 512,527,512,333 }, 0.08f);
	}
}

ModuleSceneKyoshiro::~ModuleSceneKyoshiro()
{}

// Load assets
bool ModuleSceneKyoshiro::Start()
{
	LOG("Loading Kyoshiro Scene");
	bool ret = true;

	graphics = App->textures->Load("Assets/Textures/KyoshiroScene.png");
	music = App->audio->LoadMusic("Assets/Audio/Music/Kyoshiro.ogg");
	App->audio->PlayMusic(music, NULL);
	App->player->Enable();

	//Colliders for the screen borders
	App->collision->AddCollider({ -110,0,50,1000 }, COLLIDER_WALL);
	//App->collision->AddCollider({ 500,0,50,1000 }, COLLIDER_WALL);

	return ret;
}

// Load assets
bool ModuleSceneKyoshiro::CleanUp()
{
	LOG("Unloading Kyoshiro stage");
	App->player->Disable();
	App->textures->Unload(graphics);
	Mix_FadeOutMusic(1250);
	App->audio->UnLoadMusic(music);
	//App->audio->CleanUp();
	return true;
}

update_status ModuleSceneKyoshiro::Update()
{
	SDL_Rect b;
	// Draw everything --------------------------------------	
	b = background.GetCurrentFrame();
	App->render->Blit(graphics, -60, -100, &b, 0.75f);
	if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_DOWN)
	{
		App->fade->FadeToBlack((Module*)App->scene_kyoshiro, (Module*)App->scene_congrats, 2.5);
	}

	return UPDATE_CONTINUE;
}