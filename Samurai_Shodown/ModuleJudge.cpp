#include "ModuleJudge.h"
#include "ModuleTextures.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include "ModuleRender.h"

ModuleJudge::ModuleJudge() {
	//animations
	{
		//idle
		{
			idle.PushBack({ 455, 267, 58, 70 }, 0.5f);
			idle.loop = true;
		}


		//move right
		{
			move_right.PushBack({ 44, 268, 58, 69 }, 0.3f);
			move_right.PushBack({ 122, 267, 58, 70 }, 0.3f);
			move_right.PushBack({ 201, 267, 58, 70 }, 0.3f);
			move_right.PushBack({ 286, 271, 66, 66 }, 0.3f);
			move_right.PushBack({ 369, 270, 60, 67 }, 0.3f);
			move_right.PushBack({ 455, 267, 58, 70 }, 0.3f);
			move_right.loop = true;
		}


		//move left
		{
			move_left.PushBack({ 44, 268, 58, 69 }, 0.3f);
			move_left.PushBack({ 723, 267, 58, 70 }, 0.3f);
			move_left.PushBack({ 798, 267, 58, 70 }, 0.3f);
			move_left.PushBack({ 455, 267, 58, 70 }, 0.3f);
			move_left.loop = true;
		}


		//begin
		{
			begin_j.PushBack({ 29, 78, 72, 123 }, 0.2f);
			begin_j.PushBack({ 102, 78, 72, 123 }, 0.2f);
			begin_j.PushBack({ 175, 78, 72, 123 }, 0.2f);
			begin_j.PushBack({ 247, 78, 72, 123 }, 0.2f);
			begin_j.PushBack({ 337, 78, 72, 123 }, 0.2f);
			begin_j.PushBack({ 247, 78, 72, 123 }, 0.2f);
			begin_j.PushBack({ 175, 78, 72, 123 }, 0.2f);
			begin_j.PushBack({ 102, 78, 72, 123 }, 0.2f);
			begin_j.PushBack({ 29, 78, 72, 123 }, 0.2f);
			begin_j.PushBack({ 664, 78, 72, 123 }, 0.2f);
			begin_j.PushBack({ 750, 78, 72, 123 }, 0.2f);
			begin_j.PushBack({ 843, 78, 72, 123 }, 0.2f);
			begin_j.PushBack({ 942, 78, 72, 123 }, 0.2f);
			begin_j.PushBack({ 750, 78, 72, 123 }, 0.2f);
			begin_j.PushBack({ 1128, 78, 72, 123 }, 0.2f);
			begin_j.PushBack({ 1218, 78, 72, 123 }, 0.2f);
			begin_j.PushBack({ 1309, 78, 72, 123 }, 0.2f);
			begin_j.PushBack({ 1399, 78, 72, 123 }, 0.2f);
			begin_j.PushBack({ 1474, 78, 72, 123 }, 0.2f);
			begin_j.PushBack({ 1548, 78, 72, 123 }, 0.2f);
			begin_j.PushBack({ 1630, 78, 72, 123 }, 0.2f);
			begin_j.PushBack({ 1711, 78, 72, 123 }, 0.2f);
			begin_j.PushBack({ 1801, 78, 72, 123 }, 0.2f);
			begin_j.PushBack({ 1886, 78, 72, 123 }, 0.2f);
			begin_j.PushBack({ 1958, 78, 72, 123 }, 0.2f);
			begin_j.loop = false;
			
		}


		//player1 hit
		{
			hit1.PushBack({ 1013, 245, 51, 94 }, 0.5f);
			hit1.PushBack({ 1083, 245, 51, 94 }, 0.5f);
			hit1.PushBack({ 1146, 245, 81, 94 }, 0.5f);
			hit1.PushBack({ 1232, 245, 78, 94 }, 0.5f);
			hit1.PushBack({ 1316, 245, 73, 94 }, 0.5f);
			hit1.PushBack({ 1394, 245, 70, 94 }, 0.5f);
			hit1.loop = false;
		}


		//player2 hit
		{
			hit2.PushBack({ 1530, 245, 51, 94 }, 0.5f);
			hit2.PushBack({ 1594, 245, 51, 94 }, 0.5f);
			hit2.PushBack({ 1661, 245, 81, 94 }, 0.5f);
			hit2.PushBack({ 1749, 245, 78, 94 }, 0.5f);
			hit2.PushBack({ 1833, 245, 73, 94 }, 0.5f);
			hit2.PushBack({ 1920, 245, 70, 94 }, 0.5f);
			hit2.loop = false;
		}


		//finish animation
		{
			finish.PushBack({ 1059, 114, 72, 86 }, 0.5f);
			finish.PushBack({ 125, 378, 42, 75 }, 0.5f);
			finish.PushBack({ 188, 368, 32, 85 }, 0.5f);
			finish.PushBack({ 248, 368, 38, 85 }, 0.5f);
			finish.PushBack({ 188, 368, 32, 85 }, 0.5f);
			finish.PushBack({ 248, 368, 38, 85 }, 0.5f);
			finish.PushBack({ 188, 368, 32, 85 }, 0.5f);
			finish.PushBack({ 248, 368, 38, 85 }, 0.5f);
			finish.PushBack({ 45, 125, 40, 76 }, 0.5f);
			finish.PushBack({ 106, 128, 38, 73 }, 0.5f);
			finish.PushBack({ 161, 137, 38, 64 }, 0.5f);
			finish.PushBack({ 221, 143, 36, 58 }, 0.5f);
			finish.PushBack({ 286, 143, 34, 58 }, 0.5f);
			finish.PushBack({ 221, 143, 36, 58 }, 0.5f);
			finish.PushBack({ 161, 137, 38, 64 }, 0.5f);
			finish.PushBack({ 106, 128, 38, 73 }, 0.5f);
			finish.PushBack({ 45, 125, 40, 76 }, 0.5f);
			finish.loop = false;
		}
	}

}

ModuleJudge::~ModuleJudge(){}

bool ModuleJudge::Start() {
	bool ret = true;
	LOG("Loading Judge\n");
	position_x = SCREEN_WIDTH/2-35;
	position_y = 110;
	judge_tex = App->textures->Load("Assets/Sprites/Characters/Judge/Judge.png");
	state_j = IDLE_J;
	current_animation = &idle;
	return ret;
}

bool ModuleJudge::CleanUp() {
	LOG("Unloading Judge\n");
	App->textures->Unload(judge_tex);
	return true;
}

update_status ModuleJudge::PreUpdate() {
	if (!App->is_paused)
	{
		if (state_j == BEGIN_J)
		{
			if (current_animation->Finished())
			{
				state_j = IDLE_J;
				begin_j.Reset();
			}
		}
		if (state_j == HIT1_J)
		{
			if (current_animation->Finished())
			{
				state_j = IDLE_J;
				hit1.Reset();
			}
		}
		if (state_j == HIT2_J)
		{
			if (current_animation->Finished())
			{
				state_j = IDLE_J;
				hit2.Reset();
			}
		}
		if (state_j == FINISH_J)
		{
			if (current_animation->Finished())
			{
				state_j = IDLE_J;
				finish.Reset();
			}
		}
		if ((state_j != BEGIN_J)&&(state_j != HIT1_J) && (state_j != HIT2_J)&&(state_j != FINISH_J))
		{
			Move();
		}
	}
	return UPDATE_CONTINUE;
}

update_status ModuleJudge::Update() {
	if (!App->is_paused)
	{
		switch (state_j)
		{
		case IDLE_J:
			current_animation = &idle;
			break;
		case MOVE_LEFT_J:
			current_animation = &move_left;
			break;
		case MOVE_RIGHT_J:
			current_animation = &move_right;
			break;
		case BEGIN_J:
			current_animation = &begin_j;
			break;
		case HIT1_J:
			current_animation = &hit1;
			break;
		case HIT2_J:
			current_animation = &hit2;
			break;
		case FINISH_J:
			current_animation = &finish;
			break;
		default:
			break;
		}
	}
	if (current_animation == &begin_j)
	{
		App->render->Blit(judge_tex, position_x-6.5, position_y-53, &current_animation->GetCurrentFrame());
	}
	else
	{
		App->render->Blit(judge_tex, position_x, position_y , &current_animation->GetCurrentFrame());
	}
	return UPDATE_CONTINUE;
}

void ModuleJudge::Move() {

	int player_1_position;
	int player_2_position;
	int middle;

	player_1_position = App->player->position.x;
	player_2_position = App->player2->position.x;

	if (player_1_position < player_2_position)
	{
		middle = player_1_position + (player_2_position - player_1_position) / 2;
	}
	else
	{
		middle = player_2_position + (player_1_position - player_2_position) / 2;
	}
	if (position_x < middle - 30)
	{
		moving = true;
		state_j = MOVE_RIGHT_J;
	}
	else if (position_x > middle + 30)
	{
		moving = true;
		state_j = MOVE_LEFT_J;
	}
	if (moving == true)
	{
		if ((position_x == middle) || (position_x == middle + 1))
		{
			moving = false;
			state_j = IDLE_J;
		}
		else if (position_x < middle)
		{
			position_x += speed;
		}
		else if (position_x > middle)
		{
			position_x -= speed;
		}
	}

	
}