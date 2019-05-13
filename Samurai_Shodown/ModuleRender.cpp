#include "Globals.h"
#include "Application.h"
#include "ModuleRender.h"
#include "ModuleWindow.h"
#include "ModuleInput.h"
#include "ModuleCollision.h"
#include "SDL/include/SDL.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include "ModuleSceneHaohmaru.h"
#include "ModuleSceneWanFu.h"

ModuleRender::ModuleRender() : Module()
{
	camera.x = camera.y = 0;
	camera.w = SCREEN_WIDTH;
	camera.h = SCREEN_HEIGHT;
}

// Destructor
ModuleRender::~ModuleRender()
{}

// Called before render is available
bool ModuleRender::Init()
{
	LOG("Creating Renderer context");
	bool ret = true;
	Uint32 flags = 0;

	if (REN_VSYNC == true)
	{
		flags |= SDL_RENDERER_PRESENTVSYNC;
	}

	renderer = SDL_CreateRenderer(App->window->window, -1, flags);

	if (renderer == NULL)
	{
		LOG("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
		ret = false;
	}

	return ret;
}

// Called every draw update
update_status ModuleRender::PreUpdate()
{
	//SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
	SDL_RenderClear(renderer);

	return update_status::UPDATE_CONTINUE;
}

update_status ModuleRender::Update()
{
	int speed = 3;

	//Make the camera move up and down
	if (App->input->keyboard[SDL_SCANCODE_KP_2] == KEY_REPEAT)
		camera.y += speed;

	if (App->input->keyboard[SDL_SCANCODE_KP_5] == KEY_REPEAT)
		camera.y -= speed;

	//Make the camera move left and right
	if (App->input->keyboard[SDL_SCANCODE_KP_3] == KEY_REPEAT)
		camera.x += speed * 0.7f;

	if (App->input->keyboard[SDL_SCANCODE_KP_1] == KEY_REPEAT)
		camera.x -= speed * 0.7f;

	return update_status::UPDATE_CONTINUE;
}

update_status ModuleRender::PostUpdate()
{
	SDL_RenderPresent(renderer);
	return update_status::UPDATE_CONTINUE;
}

// Called before quitting
bool ModuleRender::CleanUp()
{
	LOG("Destroying renderer \n");

	//Destroy window
	if (renderer != NULL)
	{
		SDL_DestroyRenderer(renderer);
	}

	return true;
}

// Blit to screen
bool ModuleRender::Blit(SDL_Texture * texture, int x, int y, const SDL_Rect * section, SDL_RendererFlip flip, float speed, bool use_camera, double angle, int pivot_x, int pivot_y) const
{
	bool ret = true;
	uint scale = (uint)SCREEN_SIZE;

	SDL_Rect rect;
	if (use_camera)
	{
		rect.x = (int)(-camera.x * speed) + x * scale;
		rect.y = (int)(-camera.y * speed) + y * scale;
	}
	else
	{
		rect.x = x * scale;
		rect.y = y * scale;
	}


	if (section != NULL)
	{
		rect.w = section->w;
		rect.h = section->h;
	}
	else
	{
		SDL_QueryTexture(texture, NULL, NULL, &rect.w, &rect.h);
	}

	rect.w *= scale;
	rect.h *= scale;

	SDL_Point* p = NULL;
	SDL_Point pivot;

	if (pivot_x != INT_MAX && pivot_y != INT_MAX)
	{
		pivot.x = pivot_x;
		pivot.y = pivot_y;
		p = &pivot;
	}

	if (SDL_RenderCopyEx(renderer, texture, section, &rect, angle, p, flip) != 0)
	{
		LOG("Cannot blit to screen. SDL_RenderCopy error: %s", SDL_GetError());
		LOG("%s", texture);
		ret = false;
	}

	return ret;
}

bool ModuleRender::DrawQuad(const SDL_Rect& rect, Uint8 r, Uint8 g, Uint8 b, Uint8 a, bool use_camera)
{
	bool ret = true;

	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
	SDL_SetRenderDrawColor(renderer, r, g, b, a);

	SDL_Rect rec(rect);
	if (use_camera)
	{
		rec.x = (int)(-camera.x + rect.x * SCREEN_SIZE);
		rec.y = (int)(-camera.y + rect.y * SCREEN_SIZE);
	}
	else
	{
		rec.x *= SCREEN_SIZE;
		rec.y *= SCREEN_SIZE;
	}

	rec.w *= SCREEN_SIZE;
	rec.h *= SCREEN_SIZE;

	if (SDL_RenderFillRect(renderer, &rec) != 0)
	{
		LOG("Cannot draw quad to screen. SDL_RenderFillRect error: %s", SDL_GetError());
		ret = false;
	}

	return ret;
}

void ModuleRender::MoveCamera()
{

	iPoint player_1 = App->player->position;
	iPoint player_2 = App->player2->position;

	if ((player_1.x < left->rect.x + left->rect.w)) {
		if (player_2.x + 50 < right->rect.x) {
			right->rect.x -= App->player->speed;
			left->rect.x -= App->player->speed;
			camera.x -= App->player->speed * SCREEN_SIZE;
		}
	}
	else if ((player_2.x > right->rect.x - 48)) {
		if (player_1.x > left->rect.x + left->rect.w) {
			right->rect.x += App->player->speed;
			left->rect.x += App->player->speed;
			camera.x += App->player->speed * SCREEN_SIZE;
		}
	}
	if ((player_2.x < left->rect.x + left->rect.w)) {
		if (player_1.x + 50 < right->rect.x) {
			right->rect.x -= App->player->speed;
			left->rect.x -= App->player->speed;
			camera.x -= App->player->speed * SCREEN_SIZE;
		}
	}
	else if ((player_1.x > right->rect.x - 50)) {
		if (player_2.x > left->rect.x + left->rect.w) {
			right->rect.x += App->player->speed;
			left->rect.x += App->player->speed;
			camera.x += App->player->speed * SCREEN_SIZE;
		}
	}
	if (App->scene_haohmaru->IsEnabled()==true)
	{
		if (camera.x + SCREEN_WIDTH > App->scene_haohmaru->right_wall->rect.x + 150)
		{
			camera.x--;
			left->rect.x--;
		}
		if (camera.x < App->scene_haohmaru->left_wall->rect.x - 150)
		{
			camera.x++;
			right->rect.x++;
	}

	}
	else if (App->scene_wanfu->IsEnabled()==true)
	{
		if (camera.x + SCREEN_WIDTH > App->scene_wanfu->right_wall->rect.x + 150)
		{
			camera.x--;
			left->rect.x--;
		}
		if (camera.x < App->scene_wanfu->left_wall->rect.x - 150)
		{
			camera.x++;
			right->rect.x++;
		}
	}
	
}

void ModuleRender::SetCamera()
{
	if ((!left)&&(!right))
	{
		left = App->collision->AddCollider({ -50,0,50,SCREEN_HEIGHT }, COLLIDER_WALL_LEFT);
		right = App->collision->AddCollider({ camera.w,0,50,SCREEN_HEIGHT }, COLLIDER_WALL_RIGHT);
	}
	left->SetPos(-50, 0);
	right->SetPos(camera.w, 0);
}