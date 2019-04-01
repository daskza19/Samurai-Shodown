#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"


ModulePlayer::ModulePlayer()
{
	position.x = 100;
	position.y = 220;

	//idle animation
	{
		idle.PushBack({ 16,22,71,109 },0.5f);
		idle.PushBack({ 92,22,72,109 },0.5f);
		idle.PushBack({ 168,22,71,109 },0.5f);
		idle.PushBack({ 245,20,72,111 },0.5f);
		idle.PushBack({ 322,18,72,113 },0.5f);
		idle.PushBack({ 399,19,72,112 },0.5f);
		idle.PushBack({ 476,19,74,112 }, 0.5f);
		idle.PushBack({ 554,19,74,112 }, 0.5f);
		idle.PushBack({ 630,19,73,112 }, 0.5f);
		idle.PushBack({ 245,20,72,111 }, 0.5f);
		idle.PushBack({ 322,18,72,113 }, 0.5f);
		idle.PushBack({ 399,19,72,112 }, 0.5f);

	}

	//forward animation
	{
		forward.PushBack({ 15,496,70,112 }, 0.4f);
		forward.PushBack({ 89,496,70,112 }, 0.4f);
		forward.PushBack({ 163,499,76,109 }, 0.4f);
		forward.PushBack({ 243,499,76,109 }, 0.4f);
		forward.PushBack({ 322,499,76,109 }, 0.4f);
		forward.PushBack({ 402,496,69,112 }, 0.4f);
		forward.PushBack({ 475,496,69,112 }, 0.4f);
		forward.PushBack({ 548,496,69,112 }, 0.4f);
		forward.PushBack({ 621,492,59,116 }, 0.4f);
		forward.PushBack({ 684,492,59,116 }, 0.4f);
		forward.PushBack({ 747,492,59,116 }, 0.4f);
		forward.PushBack({ 810,492,57,116 }, 0.4f);
		forward.PushBack({ 871,490,57,118 }, 0.4f);
		forward.PushBack({ 933,490,56,118 }, 0.4f);
		forward.PushBack({ 994,490,61,118 }, 0.4f);
		forward.PushBack({ 1060,492,61,116 }, 0.4f);
		forward.PushBack({ 1126,492,61,116 }, 0.4f);
	}

	//backward animation
	{
		backward.PushBack({ 624,608,82,121 },0.4f);//9
		backward.PushBack({ 711,608,82,121 },0.4f);//10
		backward.PushBack({ 798,608,82,121 },0.4f);//11
		backward.PushBack({ 884,608,82,121 },0.4f);//12
		backward.PushBack({ 15,614,74,114 },0.4f); //1
		backward.PushBack({ 94,614,74,114 },0.4f); //2
		backward.PushBack({ 173,614,74,114 }, 0.4f); //3 
		backward.PushBack({ 264,610,68,118 }, 0.4f); //4
		backward.PushBack({ 337,610,68,118 }, 0.4f); //5
		backward.PushBack({ 410,612,68,117 }, 0.4f); //6
		backward.PushBack({ 482,609,67,121 }, 0.4f);//7
		backward.PushBack({ 553,608,67,121 }, 0.4f);//8
		backward.PushBack({ 971,608,69,122 }, 0.4f);//13
		backward.PushBack({ 1045,608,69,121 }, 0.4f);//14
		backward.PushBack({ 1119,608,69,120 }, 0.4f);//15
		backward.PushBack({ 1193,614,74,114 }, 0.4f);//16
		backward.PushBack({ 1272,614,74,114 }, 0.4f);//17
		backward.PushBack({ 1351,614,74,114 }, 0.4f);//18
	}

	//jump animation
	{
		jump.PushBack({ 15, 371, 60, 112 }, 0.2f); //1
		jump.PushBack({ 80, 371, 60, 112 }, 0.2f);
		jump.PushBack({ 145, 371, 60, 112 }, 0.2f);
		jump.PushBack({ 209, 371, 75, 92 }, 0.2f);
		jump.PushBack({ 288, 371, 75, 92 }, 0.2f);
		jump.PushBack({ 367, 371, 75, 92 }, 0.2f);
		jump.PushBack({ 446, 371, 78, 83 }, 0.2f);
		jump.PushBack({ 209, 371, 75, 92 }, 0.2f);
		jump.PushBack({ 288, 371, 75, 92 }, 0.2f);
		jump.PushBack({ 367, 371, 75, 92 }, 0.2f);
		jump.PushBack({ 15, 371, 60, 112 }, 0.2f); //1
		jump.PushBack({ 80, 371, 60, 112 }, 0.2f);
		jump.PushBack({ 145, 371, 60, 112 }, 0.2f);
		jump.PushBack({ 527, 371, 68, 112 }, 0.2f); //8
		jump.PushBack({ 601, 371, 68, 112 }, 0.2f); //9
		jump.PushBack({ 674, 371, 68, 112 }, 0.2f); //10
	}

	//punch animation
	{
		punch.PushBack({ 14, 236, 69, 127 }, 0.2f);
		punch.PushBack({ 87, 236, 69, 127 }, 0.2f);
		punch.PushBack({ 160, 266, 79, 97 }, 0.2f);
		punch.PushBack({ 243, 269, 79, 96 }, 0.2f);
		punch.PushBack({ 327, 267, 79, 97 }, 0.2f);
		punch.PushBack({ 410, 270, 129, 93 }, 0.2f);
		punch.PushBack({ 545, 277, 130, 86 }, 0.2f);
		punch.PushBack({ 679, 280, 130, 83 }, 0.2f);
		punch.PushBack({ 814, 280, 129, 95 }, 0.2f); //9
		punch.PushBack({ 946, 280, 130, 95 }, 0.2f);
		punch.PushBack({ 1081, 280, 130, 95 }, 0.2f);
		punch.PushBack({ 1213, 280, 120, 95 }, 0.2f);
		punch.PushBack({ 1337, 280, 120, 95 }, 0.2f);
		punch.PushBack({ 1461, 280, 83, 95 }, 0.4f);
		punch.PushBack({ 1548, 280, 83, 95 }, 0.4f);
		punch.PushBack({ 1635, 280, 83, 95 }, 0.4f); //16
		punch.loop = false;

	}

	//kick animation
	{
		kick.PushBack({ 16,137,66,95 }, 0.3f); //initial kick frames
		kick.PushBack({ 87,137,66,95 }, 0.3f);
		kick.PushBack({ 158,137,66,95 }, 0.3f);
		kick.PushBack({ 229,134,86,98 }, 0.3f); //final kick frames
		kick.PushBack({ 320,134,86,98 }, 0.1f);
		kick.PushBack({ 411,134,86,98 }, 0.1f);
		kick.PushBack({ 16,137,66,95 }, 0.3f); //initial kick frames
		kick.PushBack({ 87,137,66,95 }, 0.3f);
		kick.PushBack({ 158,137,66,95 }, 0.3f);
		kick.loop = false;
	}
}

ModulePlayer::~ModulePlayer(){

}

// Load assets
bool ModulePlayer::Start()
{
	bool ret = true;
	LOG("Loading player textures");

	graphics = App->textures->Load("Assets/Sprites/Characters/Haohmaru/Haohmaru.png");

	state = IDLE;
	current_animation = &idle;

	return ret;
}

update_status ModulePlayer::PreUpdate()
{

	player_input.pressing_A = App->input->keyboard[SDL_SCANCODE_A] == KEY_REPEAT;
	player_input.pressing_D = App->input->keyboard[SDL_SCANCODE_D] == KEY_REPEAT;
	player_input.pressing_J = App->input->keyboard[SDL_SCANCODE_J] == KEY_DOWN;
	player_input.pressing_U = App->input->keyboard[SDL_SCANCODE_U] == KEY_DOWN;
	player_input.pressing_W = App->input->keyboard[SDL_SCANCODE_W] == KEY_DOWN;
	
	if (state == IDLE) {
		if (player_input.pressing_A)
			state = BACKWARD;
		if (player_input.pressing_D)
			state = FORWARD;
		if (player_input.pressing_J)
			state = KICK;
		if (player_input.pressing_U)
			state = PUNCH;
		if (player_input.pressing_W)
			state = JUMP;
	}
	if (state == BACKWARD) {
		if (!player_input.pressing_A)
			state = IDLE;
	}
	if (state == FORWARD) {
		if (!player_input.pressing_D)
			state = IDLE;
	}
	if (state == KICK) {
		if (current_animation->Finished()) {
			state = IDLE;
			kick.Reset();
		}
	}
	if (state == PUNCH) {

		if (current_animation->Finished()) {
			state = IDLE;
			punch.Reset();
		}
	}
	if (state == JUMP)
	{
		if (current_animation==&jump && current_animation->Finished())
		{
			state = IDLE;
		}
	}

	return UPDATE_CONTINUE;
}

// Update: draw background
update_status ModulePlayer::Update()
{
	switch (state)
	{
	case IDLE:
		current_animation = &idle;
		break;
	case PUNCH:
		current_animation = &punch;
		break;
	case JUMP:
		current_animation = &jump;
		if (position.y == 160) {
			mult = -1;
		}
		else if (position.y == 220)
		{
			mult = 1;
			state = IDLE;
		}
		position.y -= 2*speed * mult;
		
		break;
	case KICK:
		current_animation = &kick;
		break;
	case FORWARD:
		current_animation = &forward;
		position.x += speed;
		break;
	case BACKWARD:
		current_animation = &backward;
		position.x -= speed;
		break;
	default:
		LOG("No state found :(");
		break;
	}
	//Draw everything
	SDL_Rect r = current_animation->GetCurrentFrame();

	App->render->Blit(graphics, position.x, position.y - r.h, &r);
	
	
	return UPDATE_CONTINUE;
}

bool ModulePlayer::CleanUp() {
	LOG("Unloading player");
	App->textures->Unload(graphics);
	return true;
}