#ifndef _MODULE_UI
#define _MODULE_UI
#include "Module.h"
#include "Animation.h"
#include "SDL/include/SDL_rect.h"
#include "ModuleAudio.h"
struct SDL_Texture;

class ModuleUI : public Module 
{
public:
	ModuleUI();
	~ModuleUI();

	bool Start();
	update_status Update();
	bool CleanUp();

	void UpdateBars();
	void VictorySprite();


public:
	SDL_Texture * ui_png = nullptr;
	SDL_Texture* column = nullptr;

	Animation animKO;
	bool animKO_active = false;
	
	SDL_Rect* en_garde_rect = nullptr;

	//BARS
	int max_capacity = 0;
	int max_width = 128;
	//player1
	int target_life1 = 0;
	int current_life1 = 0;
	int currentW_player1 = 0;
	bool decrease_player1 = false;
	SDL_Rect life_1{ 8,32,128,9 };
	//player2
	int target_life2 = 0;
	int current_life2 = 0;
	int currentW_player2 = 0;
	bool decrease_player2 = false;
	SDL_Rect life_2{ 8,32,128,9 };
	//transitions
	SDL_Rect up_black_rect{ 0 ,0,SCREEN_WIDTH,0 };
	SDL_Rect down_black_rect{ 0,SCREEN_HEIGHT,SCREEN_WIDTH, SCREEN_HEIGHT / 2 };
	SDL_Rect left_black_rect{ 0 ,0,SCREEN_WIDTH / 2,SCREEN_HEIGHT };
	SDL_Rect right_black_rect{ SCREEN_WIDTH / 2 ,0,SCREEN_WIDTH / 2,SCREEN_HEIGHT };
	bool VerticalTransition();
	bool HorizontalTransition();
	bool round_end = false;
	bool victory = false;
	bool vtransition = false;
	bool htransition = false;
	Mix_Chunk *ippon_fx;
	Mix_Chunk *victory_fx;
	Mix_Chunk *begin_fx;
	Mix_Chunk *iza_fx;
	Mix_Chunk *ipponme_fx;
	Mix_Chunk *jinjoni_fx;
	Mix_Chunk *round_03_fx;
	float start_time = 0.0f;
	int font_point_numbers = 0;
	int timer_font = 0;
	int player1_point = 0;
	int player2_point = 0;
	int player1_wins=0;
	int player2_wins=0;
	int draw=0;
	char point_text1[10];
	char point_text2[10];
	uint time_fight = 96;
	char time_text[10];
	char point_gain_life[10];
	char char_points[10];
	char char_time[10];
	char char_total[10];
	char char_hit_percentatge[10];
	void timer();
	void ResetScene();
	bool die_scene = false;
	SDL_Texture* finish_round = nullptr;
	void DieScene();
	Animation ippon;
	float ippon_time = 0;
	Animation haohmaru;
	float haohmaru_time = 0;
	bool ippon_finished = false;
	float rest_time = 0;
	bool haomaru_finished = false;
	Animation victory_anim;
	Animation well_done;
	Animation bar_anim1;
	Animation bar_anim2;
	Animation en_garde;
	bool points_done = false;
	int points_life_gain = 0;
	int time_points = 0;
	Mix_Chunk* points_fx = nullptr;
	int points_hit = 0;
	float points_first_wait = 0;
	float points_second_wait = 0;
	Animation begin;
	bool begin_finish = false;
	bool show_ui=false;
	bool is_draw = false;
	bool player1_win = false;
	Animation draw_anim;
	Animation time_up_anim;
	bool player2_win = false;
	bool time_up = false;
	float time_up_wait = 0;
	bool time_count = false;
	bool life_done = false;
	bool time_done = false;
	bool hit_percent_done = false;
	int total_points = 0;
	bool en_garde_bool = false;
	bool play_ipponme=true;
	bool play_begin = false;
	bool play_jinjoni = true;
	bool play_victory = true;
	bool play_ippon = false;
	bool play_iza = true;
	int animtime = 0;
	Animation* current_duel_anim = nullptr;
	Animation duel_1;
	Animation duel_2;
	Animation duel_3;
	bool duel = true;
};

#endif // !_MODULE_UI

