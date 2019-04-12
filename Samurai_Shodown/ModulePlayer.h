#ifndef __ModulePlayer_H__
#define __ModulePlayer_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "p2Point.h"
#include "ModuleParticles.h"
#include "ModuleAudio.h"

struct SDL_Texture;

enum States
{
	IDLE,
	FORWARD,
	BACKWARD,
	CROUCH_UP,
	CROUCH_DOWN,
	CROUCH_KICK,
	CROUCH_PUNCH,
	JUMP_NEUTRAL,
	JUMP_FORWARD,
	JUMP_BACKWARD,
	KICK,
	PUNCH,
	TWISTER
};

struct PlayerInput {

	bool pressing_A;
	bool pressing_D;
	bool pressing_U;
	bool pressing_J;
	bool pressing_W;
	bool pressing_S;
	bool pressing_K;
	bool pressing_F5;
};

class ModulePlayer : public Module
{
public:
	ModulePlayer();
	~ModulePlayer();

	bool Start();
	update_status PreUpdate();
	update_status Update();
	bool CleanUp();
	void OnCollision(Collider* c1, Collider* c2);

public:

	SDL_Texture * graphics = nullptr;
	SDL_Texture* haohmaruSpreadsheet = nullptr;
	Animation idle;
	Animation forward;
	Animation backward;
	Animation punch;
	Animation kick;
	Animation hit;
	Animation hit2;
	Animation jump_neutral;
	Animation jump_forward;
	Animation jump_backward;
	Animation crouch_up;
	Animation crouch_down;
	Animation crouch_punch;
	Animation crouch_kick;
	Animation twister;
	Animation twisterAlone;
	iPoint position;
	iPoint lposition;
	Collider *collider_player_up = nullptr;
	Collider *collider_player_down = nullptr;
	Collider *collider_player_extra = nullptr;
	int mult = 1;
	int initial_y = 215;
	Animation* current_animation = nullptr;
	PlayerInput player_input;
	States state;
	float speed = 2;
	bool is_tornado_created = false;
	Mix_Chunk* light_attack_fx;
	Mix_Chunk* light_kick_fx;
	Mix_Chunk* twister_fx;
};

#endif // __ModulePlayer_H__