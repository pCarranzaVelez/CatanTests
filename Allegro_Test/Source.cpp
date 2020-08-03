#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/bitmap.h>
#include <allegro5/allegro_native_dialog.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

using namespace std;

# define M_PI           3.14159265358979323846  /* pi */

#define ToRadians(angleDegrees) (angleDegrees * M_PI / 180.0)

// medidas del display
#define WIDTH 1025
#define HEIGHT 700
#define MOUSE_LEFT_BUTTON 1
#define FPS 1

#define ANY_PORT 0
#define BRICK_PORT 1
#define GRAIN_PORT 2
#define STONE_PORT 3
#define WOOD_PORT 4
#define WOOL_PORT 5

#define BRICK1 0
#define GRAIN1 1
#define ORE1 2
#define LUMBER1 3
#define WOOL1 4
#define DESERT1 5

#define TERRAIN_HEXES 19

#define HEX_WIDTH 221
#define HEX_HEIGHT 257

#define FRAME_WIDTH 810
#define FRAME_HEIGHT 240

#define NUM2 0
#define NUM3 1
#define NUM4 2
#define NUM5 3
#define NUM6 4
#define NUM8 5
#define NUM9 6
#define NUM10 7
#define NUM11 8
#define NUM12 9

#define TOKENS 10

#define PLAYER 0
#define OPPONENT 1

enum AL_ERROR { INIT_ERROR, DIS_ERROR, TIMER_ERROR, EV_Q_ERROR, NONE };

typedef struct
{
	char name[255];
	unsigned int longName;

}nameInfo;


int main()
{
	ALLEGRO_EVENT_QUEUE* event_queue = NULL;
	ALLEGRO_DISPLAY* display = NULL;
	ALLEGRO_EVENT event;
	ALLEGRO_TIMER* timer = NULL;
	ALLEGRO_FONT* font = NULL;
	AL_ERROR error;

	ALLEGRO_BITMAP* Title;


	if (!al_init())	//inicializo allegro
	{
		error = INIT_ERROR;
	}
	else
	{
		timer = al_create_timer(1.0 / FPS);
		if (!timer)
		{
			error = TIMER_ERROR;
		}
		else
		{
			display = al_create_display(WIDTH, HEIGHT);	//creo el display
			if (!display)	//testeo el display
			{
				error = DIS_ERROR;
			}
			else
			{
				event_queue = al_create_event_queue();	//creo la cola de eventos
				if (!event_queue)
				{
					error = EV_Q_ERROR;
				}
				else
				{
					al_register_event_source(event_queue, al_get_display_event_source(display));	//registra los eventos del display
					al_register_event_source(event_queue, al_get_timer_event_source(timer));	//registra los eventos del timer
					if (al_install_mouse() && al_install_keyboard())
					{
						al_register_event_source(event_queue, al_get_mouse_event_source());	//registra los eventos del mouse
						al_register_event_source(event_queue, al_get_keyboard_event_source());
						al_start_timer(timer);
						error = NONE;
						al_clear_to_color(al_map_rgb(0, 0, 0));
						al_init_font_addon();
						al_init_ttf_addon();
						font = al_load_ttf_font("Files/RINGM___.ttf", 15, 0);

						if (font == NULL)
						{
							cout << "FONT NOT WORKING" << endl;
						}
					}
				}
			}
		}
	}

	if (al_init_primitives_addon())
	{
		const float points[12] = { WIDTH * 0.35, HEIGHT * 0.15, WIDTH * 0.65, HEIGHT * 0.15, WIDTH * 0.775, HEIGHT * 0.5, WIDTH * 0.65, HEIGHT * 0.85, WIDTH * 0.35, HEIGHT * 0.85, WIDTH * 0.225, HEIGHT * 0.5 };
		al_draw_polygon(points, 6, ALLEGRO_LINE_JOIN_MITER, al_map_rgb(0, 0, 0), 1, 1);
	}
	al_init_image_addon();

	al_flip_display();

	Title = al_load_bitmap("Files/settlers_title.png");

	string name = "";
	bool exit = false;
	int i = 0;
	al_draw_scaled_rotated_bitmap(Title, al_get_bitmap_width(Title) / 2.0, al_get_bitmap_height(Title) / 2.0, WIDTH * 0.5, HEIGHT * 0.2, (0.3 * WIDTH) / 800, (0.3 * WIDTH) / 800, 0.0, NULL);
	while (exit == false)
	{
		if (i > 254)
		{
			exit = true;
		}
		else if (al_get_next_event(event_queue, &event))
		{
			if (event.type == ALLEGRO_EVENT_KEY_DOWN)
			{
				switch (event.keyboard.keycode)
				{
				case ALLEGRO_KEY_A:
					name += 'A';
					i++;
					break;

				case ALLEGRO_KEY_B:
					name += 'B';
					i++;
					break;

				case ALLEGRO_KEY_C:
					name += 'C';
					i++;
					break;

				case ALLEGRO_KEY_D:
					name += 'D';
					i++;
					break;

				case ALLEGRO_KEY_E:
					name += 'E';
					i++;
					break;

				case ALLEGRO_KEY_F:
					name += 'F';
					i++;
					break;

				case ALLEGRO_KEY_G:
					name += 'G';
					i++;
					break;

				case ALLEGRO_KEY_H:
					name += 'H';
					i++;
					break;

				case ALLEGRO_KEY_I:
					name += 'I';
					i++;
					break;

				case ALLEGRO_KEY_J:
					name += 'J';
					i++;
					break;

				case ALLEGRO_KEY_K:
					name += 'K';
					i++;
					break;

				case ALLEGRO_KEY_L:
					name += 'L';
					i++;
					break;

				case ALLEGRO_KEY_M:
					name += 'M';
					i++;
					break;

				case ALLEGRO_KEY_N:
					name += 'N';
					i++;
					break;

				case ALLEGRO_KEY_O:
					name += 'O';
					i++;
					break;

				case ALLEGRO_KEY_P:
					name += 'P';
					i++;
					break;

				case ALLEGRO_KEY_Q:
					name += 'Q';
					i++;
					break;

				case ALLEGRO_KEY_R:
					name += 'R';
					i++;
					break;

				case ALLEGRO_KEY_S:
					name += 'S';
					i++;
					break;

				case ALLEGRO_KEY_T:
					name += 'T';
					i++;
					break;

				case ALLEGRO_KEY_U:
					name += 'U';
					i++;
					break;

				case ALLEGRO_KEY_V:
					name += 'V';
					i++;
					break;

				case ALLEGRO_KEY_W:
					name += 'W';
					i++;
					break;

				case ALLEGRO_KEY_X:
					name += 'X';
					i++;
					break;

				case ALLEGRO_KEY_Y:
					name += 'Y';
					i++;
					break;
				case ALLEGRO_KEY_Z:
					name += 'Z';
					i++;
					break;

				case ALLEGRO_KEY_ENTER:
					exit = true;
					break;

				case ALLEGRO_KEY_BACKSPACE:
					if (i > 0)
					{
						name.pop_back();
						i--;
					}
					break;

				default: break;
				}

			}
		}
		al_draw_text(font, al_map_rgb(255, 255, 255), WIDTH * 0.3, HEIGHT * 0.4, ALLEGRO_ALIGN_LEFT, "What's your name?");
		al_draw_filled_rectangle(WIDTH * 0.3, HEIGHT * 0.45, WIDTH * 0.7, HEIGHT * 0.55, al_map_rgb(255, 255, 255)); // esto está bien
		al_draw_rounded_rectangle(WIDTH * 0.3, HEIGHT * 0.45, WIDTH * 0.7, HEIGHT * 0.55, 10.0, 10.0, al_map_rgb(0, 0, 0), 5.0);
		al_draw_rounded_rectangle(WIDTH * 0.3, HEIGHT * 0.45, WIDTH * 0.7, HEIGHT * 0.55, 10.0, 10.0, al_map_rgb(255, 255, 255), 3.0);
		al_draw_text(font, al_map_rgb(0, 0, 0), WIDTH * 0.33, HEIGHT * 0.48, ALLEGRO_ALIGN_LEFT, name.c_str());
		al_flip_display();
	}


	ALLEGRO_BITMAP** Frames;
	ALLEGRO_BITMAP** Hexes;
	ALLEGRO_BITMAP** Tokens;
	ALLEGRO_BITMAP** Dices;
	ALLEGRO_BITMAP** ResourceCards;

	ALLEGRO_BITMAP** Houses;
	ALLEGRO_BITMAP** Settlements;
	ALLEGRO_BITMAP** Roads;

	ALLEGRO_BITMAP* ButtonMain;
	ALLEGRO_BITMAP* ButtonClick;

	ALLEGRO_BITMAP* Color_Nodes;
	ALLEGRO_BITMAP* Color_Roads;
	ALLEGRO_BITMAP* Color_Buttons1;
	ALLEGRO_BITMAP* Color_Buttons2;

	Hexes = new ALLEGRO_BITMAP * [6];

	Frames = new ALLEGRO_BITMAP * [6];

	Tokens = new ALLEGRO_BITMAP * [TOKENS];

	Dices = new ALLEGRO_BITMAP * [6];

	ResourceCards = new ALLEGRO_BITMAP * [5];

	Houses = new ALLEGRO_BITMAP * [2];
	Settlements = new ALLEGRO_BITMAP * [2];
	Roads = new ALLEGRO_BITMAP * [2];

	Color_Nodes = al_load_bitmap("Files/Clicks/nodes.png");
	Color_Roads = al_load_bitmap("Files/Clicks/roads.png");
	Color_Buttons1 = al_load_bitmap("Files/Clicks/buttons.png");
	Color_Buttons2 = al_load_bitmap("Files/Clicks/buttons2.png");

	Frames[ANY_PORT] = al_load_bitmap("Files/SeaFrames/ANY_PORT.png");
	Frames[BRICK_PORT] = al_load_bitmap("Files/SeaFrames/BRICK_PORT.png");
	Frames[WOOD_PORT] = al_load_bitmap("Files/SeaFrames/WOOD_PORT.png");
	Frames[WOOL_PORT] = al_load_bitmap("Files/SeaFrames/WOOL_PORT.png");
	Frames[STONE_PORT] = al_load_bitmap("Files/SeaFrames/STONE_PORT.png");
	Frames[GRAIN_PORT] = al_load_bitmap("Files/SeaFrames/GRAIN_PORT.png");

	Hexes[DESERT1] = al_load_bitmap("Files/Hexes/DESERT.png");
	Hexes[BRICK1] = al_load_bitmap("Files/Hexes/BRICK.png");
	Hexes[GRAIN1] = al_load_bitmap("Files/Hexes/GRAIN.png");
	Hexes[LUMBER1] = al_load_bitmap("Files/Hexes/LUMBER.png");
	Hexes[ORE1] = al_load_bitmap("Files/Hexes/ORE.png");
	Hexes[WOOL1] = al_load_bitmap("Files/Hexes/WOOL.png");

	Tokens[NUM2] = al_load_bitmap("Files/Tokens/NUM2.png");
	Tokens[NUM3] = al_load_bitmap("Files/Tokens/NUM3.png");
	Tokens[NUM4] = al_load_bitmap("Files/Tokens/NUM4.png");
	Tokens[NUM5] = al_load_bitmap("Files/Tokens/NUM5.png");
	Tokens[NUM6] = al_load_bitmap("Files/Tokens/NUM6.png");
	Tokens[NUM8] = al_load_bitmap("Files/Tokens/NUM8.png");
	Tokens[NUM9] = al_load_bitmap("Files/Tokens/NUM9.png");
	Tokens[NUM10] = al_load_bitmap("Files/Tokens/NUM10.png");
	Tokens[NUM11] = al_load_bitmap("Files/Tokens/NUM11.png");
	Tokens[NUM12] = al_load_bitmap("Files/Tokens/NUM12.png");

	Dices[0] = al_load_bitmap("Files/Dices/Dice1.png");
	Dices[1] = al_load_bitmap("Files/Dices/Dice2.png");
	Dices[2] = al_load_bitmap("Files/Dices/Dice3.png");
	Dices[3] = al_load_bitmap("Files/Dices/Dice4.png");
	Dices[4] = al_load_bitmap("Files/Dices/Dice5.png");
	Dices[5] = al_load_bitmap("Files/Dices/Dice6.png");

	ResourceCards[BRICK1] = al_load_bitmap("Files/Cards/BRICK_CARD.png");
	ResourceCards[GRAIN1] = al_load_bitmap("Files/Cards/GRAIN_CARD.png");
	ResourceCards[WOOL1] = al_load_bitmap("Files/Cards/WOOL_CARD.png");
	ResourceCards[LUMBER1] = al_load_bitmap("Files/Cards/LUMBER_CARD.png");
	ResourceCards[ORE1] = al_load_bitmap("Files/Cards/STONE_CARD.png");

	Houses[PLAYER] = al_load_bitmap("Files/BoardPieces/House1.png");
	Houses[OPPONENT] = al_load_bitmap("Files/BoardPieces/House2.png");
	Settlements[PLAYER] = al_load_bitmap("Files/BoardPieces/Settlement1.png");
	Settlements[OPPONENT] = al_load_bitmap("Files/BoardPieces/Settlement2.png");
	Roads[PLAYER] = al_load_bitmap("Files/BoardPieces/Road1.png");
	Roads[OPPONENT] = al_load_bitmap("Files/BoardPieces/Road2.png");

	ButtonMain = al_load_bitmap("Files/Button/ButtonMain.png");
	ButtonClick = al_load_bitmap("Files/Button/ButtonClick.png");


	srand(time(NULL));

	al_clear_to_color(al_map_rgb(185, 180, 135));

	al_draw_text(font, al_map_rgb(0, 0, 0), 0.05 * WIDTH, 0.05 * HEIGHT, ALLEGRO_ALIGN_LEFT, name.c_str());

	const float points[12] = { WIDTH * 0.35, HEIGHT * 0.15, WIDTH * 0.65, HEIGHT * 0.15, WIDTH * 0.775, HEIGHT * 0.5, WIDTH * 0.65, HEIGHT * 0.85, WIDTH * 0.35, HEIGHT * 0.85, WIDTH * 0.225, HEIGHT * 0.5 };
	al_draw_polygon(points, 6, ALLEGRO_LINE_JOIN_MITER, al_map_rgb(0, 0, 0), 1, 1);

	al_flip_display();

	for (int i = 0; i < 6; i++)
	{

		float middle_x = al_get_bitmap_width(Frames[i]) / 2.0;
		float middle_y = al_get_bitmap_height(Frames[i]) / 2.0;

		float x_scale = (0.3 * WIDTH) / 810;
		float y_scale = (0.3 * WIDTH) / 810;

		float angle = ToRadians(((i * 60.0) + 180.0));

		float dx = 0, dy = 0;
		//depende de que posicion sea es donde se dibuja
		switch (('0' + i))
		{
		case '0':
		{
			dx = 0.45 * WIDTH; //OK!
			dy = 0.15 * HEIGHT; //OK!
		}break;
		case '1':
		{
			dx = 0.686 * WIDTH;
			dy = 0.263 * HEIGHT;
		}break;
		case '2':
		{
			dx = 0.736 * WIDTH;
			dy = 0.619 * HEIGHT;
		}break;
		case '3':
		{
			dx = 0.549 * WIDTH; //OK!
			dy = 0.8586 * HEIGHT; //OK!
		}break;
		case '4':
		{
			dx = 0.312 * WIDTH;
			dy = 0.7429 * HEIGHT;
		}break;
		case '5':
		{
			dx = 0.265 * WIDTH;
			dy = 0.39 * HEIGHT;
		}break;
		default: break;
		}

		//el puerto define que imagen es
		/*switch (board->all_the_sea_frames[i].getPorts().port1.port)
		{
		case ports::ANY:
		{
			img = ANY_PORT;
		}break;
		case ports::BRICK:
		{
			img = BRICK_PORT;
		}break;
		case ports::GRAIN:
		{
			img = GRAIN_PORT;
		}break;
		case ports::LUMBER:
		{
			img = WOOD_PORT;
		}break;
		case ports::ORE:
		{
			img = STONE_PORT;
		}break;
		case ports::WOOL:
		{
			img = WOOL_PORT;
		}break;
		default:
		{

		}break;
		}*/

		al_draw_scaled_rotated_bitmap(Frames[i], middle_x, middle_y, dx, dy, x_scale, y_scale, angle, NULL);
		al_flip_display();

	}

	for (int i = 0; i < TERRAIN_HEXES; i++)
	{


		float middle_x = HEX_WIDTH / 2.0;
		float middle_y = HEX_HEIGHT / 2.0;

		float x_scale = 102.5 / HEX_WIDTH;
		float y_scale = 112.5 / HEX_HEIGHT;

		float dx = 0, dy = 0;
		//depende de que posicion sea es donde se dibuja
		switch ('A' + i)
		{
		case 'A':
		{
			dx = 0.5 * WIDTH - 103.0;
			dy = 0.15 * HEIGHT + 0.295 * FRAME_HEIGHT;
		}break;
		case 'B':
		{
			dx = 0.5 * WIDTH;
			dy = 0.15 * HEIGHT + 0.295 * FRAME_HEIGHT;
		}break;
		case 'C':
		{
			dx = 0.5 * WIDTH + 103.0;
			dy = 0.15 * HEIGHT + 0.295 * FRAME_HEIGHT;
		}break;
		case 'D':
		{
			dx = ((0.5 * WIDTH - 2.0 * 102.5) + (0.5 * WIDTH - 103.0)) / 2.0;
			dy = ((0.15 * HEIGHT + 0.295 * FRAME_HEIGHT) + (0.5 * HEIGHT + 3.0)) / 2.0;
		}break;
		case 'E':
		{
			dx = ((0.5 * WIDTH - 103.0) + 0.5 * WIDTH) / 2.0;
			dy = ((0.15 * HEIGHT + 0.295 * FRAME_HEIGHT) + (0.5 * HEIGHT + 3.0)) / 2.0;
		}break;
		case 'F':
		{
			dx = (0.5 * WIDTH + (0.5 * WIDTH + 103.0)) / 2.0;
			dy = ((0.15 * HEIGHT + 0.295 * FRAME_HEIGHT) + (0.5 * HEIGHT + 3.0)) / 2.0;
		}break;
		case 'G':
		{
			dx = ((0.5 * WIDTH + 103.0) + (0.5 * WIDTH + 2.0 * 102.5)) / 2.0;
			dy = ((0.15 * HEIGHT + 0.295 * FRAME_HEIGHT) + (0.5 * HEIGHT + 3.0)) / 2.0;
		}break;
		case 'H':
		{
			dx = 0.5 * WIDTH - 2.0 * 102.5;
			dy = 0.5 * HEIGHT + 3.0;
		}break;
		case 'I':
		{
			dx = 0.5 * WIDTH - 103.0;
			dy = 0.5 * HEIGHT + 3.0;
		}break;
		case 'J':
		{
			dx = 0.5 * WIDTH;
			dy = 0.5 * HEIGHT + 3.0;
		}break;
		case 'K':
		{
			dx = 0.5 * WIDTH + 103.0;
			dy = 0.5 * HEIGHT + 3.0;
		}break;
		case 'L':
		{
			dx = 0.5 * WIDTH + 2.0 * 102.5;
			dy = 0.5 * HEIGHT + 3.0;
		}break;
		case 'M':
		{
			dx = ((0.5 * WIDTH - 2.0 * 102.5) + (0.5 * WIDTH - 103.0)) / 2.0;
			dy = ((0.5 * HEIGHT + 3.0) + (0.8586 * HEIGHT - 1 * (0.295 * FRAME_HEIGHT))) / 2.0;
		}break;
		case 'N':
		{
			dx = ((0.5 * WIDTH - 103.0) + 0.5 * WIDTH) / 2.0;
			dy = ((0.5 * HEIGHT + 3.0) + (0.8586 * HEIGHT - 1 * (0.295 * FRAME_HEIGHT))) / 2.0;
		}break;
		case 'O':
		{
			dx = (0.5 * WIDTH + (0.5 * WIDTH + 103.0)) / 2.0;
			dy = ((0.5 * HEIGHT + 3.0) + (0.8586 * HEIGHT - 1 * (0.295 * FRAME_HEIGHT))) / 2.0;
		}break;
		case 'P':
		{
			dx = ((0.5 * WIDTH + 103.0) + (0.5 * WIDTH + 2.0 * 102.5)) / 2.0;
			dy = ((0.5 * HEIGHT + 3.0) + (0.8586 * HEIGHT - 1 * (0.295 * FRAME_HEIGHT))) / 2.0;
		}break;
		case 'Q':
		{
			dx = 0.5 * WIDTH - 103.0;
			dy = 0.8586 * HEIGHT - 1 * (0.295 * FRAME_HEIGHT);
		}break;
		case 'R':
		{
			dx = 0.5 * WIDTH;
			dy = 0.8586 * HEIGHT - 1 * (0.295 * FRAME_HEIGHT);
		}break;
		case 'S':
		{
			dx = 0.5 * WIDTH + 103.0;
			dy = 0.8586 * HEIGHT - 1 * (0.295 * FRAME_HEIGHT);
		}break;
		default: break;
		}

		int img = 0;
		//el recurso define que imagen es
		/*switch (board->all_the_hexes[i].getResource())
		{
		case DESERT:
		{
			img = DESERT1;
		}break;
		case ORE:
		{
			img = ORE1;
		}break;
		case GRAIN:
		{
			img = GRAIN1;
		}break;
		case LUMBER:
		{
			img = LUMBER1;
		}break;
		case WOOL:
		{
			img = WOOL1;
		}break;
		case BRICK:
		{
			img = BRICK1;
		}break;
		default:
		{

		}break;
		}*/

		img = rand() % 6;

		al_draw_scaled_rotated_bitmap(Hexes[img], middle_x, middle_y, dx, dy, x_scale, y_scale, 0.0, NULL);

		int img2 = rand() % 10;

		al_draw_scaled_rotated_bitmap(Tokens[img2], al_get_bitmap_width(Tokens[img2]) / 2.0, al_get_bitmap_height(Tokens[img2]) / 2.0, dx, dy, 1.0 / 4.0, 1.0 / 4.0, 0.0, NULL);

		al_flip_display();
	}

	unsigned int dice1 = rand() % 6 + 1;
	unsigned int dice2 = rand() % 6 + 1;

	float dx1, dy1, dx2, dy2;

	dx1 = 0.9 * WIDTH - 5.0 - al_get_bitmap_width(Dices[dice1 - 1]) / 2.0;
	dx2 = 0.9 * WIDTH + 5.0 + al_get_bitmap_width(Dices[dice1 - 1]) / 2.0;

	dy1 = 0.65 * HEIGHT;
	dy2 = dy1;

	dice1 = rand() % 6 + 1;
	dice2 = rand() % 6 + 1;

	al_draw_scaled_rotated_bitmap(Dices[dice1 - 1], al_get_bitmap_width(Dices[dice1 - 1]) / 2.0, al_get_bitmap_height(Dices[dice1 - 1]) / 2.0, dx1, dy1, 1.0, 1.0, 0.0, NULL);
	al_draw_scaled_rotated_bitmap(Dices[dice2 - 1], al_get_bitmap_width(Dices[dice2 - 1]) / 2.0, al_get_bitmap_height(Dices[dice2 - 1]) / 2.0, dx2, dy2, 1.0, 1.0, 0.0, NULL);

	al_flip_display();

	float cx = al_get_bitmap_width(ResourceCards[0]) / 2.0;
	float cy = al_get_bitmap_height(ResourceCards[0]) / 2.0;

	float dx = 0.06 * WIDTH;
	float dy = 0.2 * HEIGHT;
	for (int i = 0; i < 5; i++)
	{
		al_draw_scaled_rotated_bitmap(ResourceCards[i], cx, cy, dx, dy + i * cx * 1.25, 0.4, 0.4, 0.0, NULL);

		al_draw_filled_circle(dx + cx * 0.6, dy + i * cx * 1.25, 10, al_map_rgb(255, 243, 154));
		al_draw_circle(dx + cx * 0.6, dy + i * cx * 1.25, 10, al_map_rgb(0, 0, 0), 3);
		switch (i)
		{
		case ORE1:
		{
			al_draw_text(font, al_map_rgb(0, 0, 0), dx + cx * 0.6 - 5.0, dy + i * cx * 1.25 - 9.0, ALLEGRO_ALIGN_LEFT, to_string(i).c_str());
		}break;
		case GRAIN1:
		{
			al_draw_text(font, al_map_rgb(0, 0, 0), dx + cx * 0.6 - 5.0, dy + i * cx * 1.25 - 9.0, ALLEGRO_ALIGN_LEFT, to_string(i).c_str());
		}break;
		case WOOL1:
		{
			al_draw_text(font, al_map_rgb(0, 0, 0), dx + cx * 0.6 - 5.0, dy + i * cx * 1.25 - 9.0, ALLEGRO_ALIGN_LEFT, to_string(i).c_str());
		}break;
		case LUMBER1:
		{
			al_draw_text(font, al_map_rgb(0, 0, 0), dx + cx * 0.6 - 5.0, dy + i * cx * 1.25 - 9.0, ALLEGRO_ALIGN_LEFT, to_string(i).c_str());
		}break;
		case BRICK1:
		{
			al_draw_text(font, al_map_rgb(0, 0, 0), dx + cx * 0.6 - 5.0, dy + i * cx * 1.25 - 9.0, ALLEGRO_ALIGN_LEFT, to_string(i).c_str());
		}break;
		default:break;
		}
	}
	al_flip_display();


	float cx_road = al_get_bitmap_width(Roads[PLAYER]) / 2.0;
	float cy_road = al_get_bitmap_height(Roads[PLAYER]) / 2.0;

	float cx_city = al_get_bitmap_width(Settlements[PLAYER]) / 2.0;
	float cy_city = al_get_bitmap_height(Settlements[PLAYER]) / 2.0;

	float cx_settlement = al_get_bitmap_width(Houses[PLAYER]) / 2.0;
	float cy_settlement = al_get_bitmap_height(Houses[PLAYER]) / 2.0;


	al_draw_scaled_rotated_bitmap(Roads[PLAYER], cx_road, cy_road, 0.06 * WIDTH, 0.925 * HEIGHT, 0.15, 0.15, 0.0, NULL);
	al_draw_filled_circle(0.06 * WIDTH, 0.86 * HEIGHT, 10, al_map_rgb(255, 243, 154));
	al_draw_circle(0.06 * WIDTH, 0.86 * HEIGHT, 10, al_map_rgb(0, 0, 0), 3);
	al_draw_text(font, al_map_rgb(0, 0, 0), 0.06 * WIDTH - 5.0, 0.86 * HEIGHT - 9.0, ALLEGRO_ALIGN_LEFT, to_string(1).c_str());

	al_draw_scaled_rotated_bitmap(Settlements[PLAYER], cx_city, cy_city, 0.06 * WIDTH + 0.5 * (cx_settlement + cx_city), 0.925 * HEIGHT, 0.15, 0.15, 0.0, NULL);
	al_draw_filled_circle(0.06 * WIDTH + 0.5 * (cx_settlement + cx_city), 0.86 * HEIGHT, 10, al_map_rgb(255, 243, 154));
	al_draw_circle(0.06 * WIDTH + 0.5 * (cx_settlement + cx_city), 0.86 * HEIGHT, 10, al_map_rgb(0, 0, 0), 3);
	al_draw_text(font, al_map_rgb(0, 0, 0), 0.06 * WIDTH + 0.5 * (cx_settlement + cx_city) - 5.0, 0.86 * HEIGHT - 9.0, ALLEGRO_ALIGN_LEFT, to_string(1).c_str());


	al_draw_scaled_rotated_bitmap(Houses[PLAYER], cx_settlement, cy_settlement, 0.06 * WIDTH + cx_settlement * 0.5, 0.925 * HEIGHT, 0.15, 0.15, 0.0, NULL);
	al_draw_filled_circle(0.06 * WIDTH + cx_settlement * 0.5, 0.86 * HEIGHT, 10, al_map_rgb(255, 243, 154));
	al_draw_circle(0.06 * WIDTH + cx_settlement * 0.5, 0.86 * HEIGHT, 10, al_map_rgb(0, 0, 0), 3);
	al_draw_text(font, al_map_rgb(0, 0, 0), 0.06 * WIDTH + cx_settlement * 0.5 - 5.0, 0.86 * HEIGHT - 9.0, ALLEGRO_ALIGN_LEFT, to_string(1).c_str());

	al_draw_text(font, al_map_rgb(0, 0, 0), 0.775 * WIDTH, 0.75 * HEIGHT, ALLEGRO_ALIGN_LEFT, "PEPITO");

	al_draw_scaled_rotated_bitmap(Roads[OPPONENT], cx_road, cy_road, 0.75 * WIDTH, 0.925 * HEIGHT, 0.15, 0.15, 0.0, NULL);
	al_draw_filled_circle(0.75 * WIDTH, 0.86 * HEIGHT, 10, al_map_rgb(255, 243, 154));
	al_draw_circle(0.75 * WIDTH, 0.86 * HEIGHT, 10, al_map_rgb(0, 0, 0), 3);
	al_draw_text(font, al_map_rgb(0, 0, 0), 0.75 * WIDTH - 5.0, 0.86 * HEIGHT - 9.0, ALLEGRO_ALIGN_LEFT, to_string(1).c_str());

	al_flip_display();

	al_draw_scaled_rotated_bitmap(Settlements[OPPONENT], cx_city, cy_city, 0.75 * WIDTH + 0.5 * (cx_settlement + cx_city), 0.925 * HEIGHT, 0.15, 0.15, 0.0, NULL);
	al_draw_filled_circle(0.75 * WIDTH + 0.5 * (cx_settlement + cx_city), 0.86 * HEIGHT, 10, al_map_rgb(255, 243, 154));
	al_draw_circle(0.75 * WIDTH + 0.5 * (cx_settlement + cx_city), 0.86 * HEIGHT, 10, al_map_rgb(0, 0, 0), 3);
	al_draw_text(font, al_map_rgb(0, 0, 0), 0.75 * WIDTH + 0.5 * (cx_settlement + cx_city) - 5.0, 0.86 * HEIGHT - 9.0, ALLEGRO_ALIGN_LEFT, to_string(1).c_str());

	al_draw_scaled_rotated_bitmap(Houses[OPPONENT], cx_settlement, cy_settlement, 0.75 * WIDTH + cx_settlement * 0.5, 0.925 * HEIGHT, 0.15, 0.15, 0.0, NULL);
	al_draw_filled_circle(0.75 * WIDTH + cx_settlement * 0.5, 0.86 * HEIGHT, 10, al_map_rgb(255, 243, 154));
	al_draw_circle(0.75 * WIDTH + cx_settlement * 0.5, 0.86 * HEIGHT, 10, al_map_rgb(0, 0, 0), 3);
	al_draw_text(font, al_map_rgb(0, 0, 0), 0.75 * WIDTH + cx_settlement * 0.5 - 5.0, 0.86 * HEIGHT - 9.0, ALLEGRO_ALIGN_LEFT, to_string(1).c_str());

	al_flip_display();

	float cx_button, cy_button, dx_button, dy_button;
	cx_button = al_get_bitmap_width(ButtonMain) / 2.0;
	cy_button = al_get_bitmap_height(ButtonMain) / 2.0;

	dx_button = 0.9 * WIDTH;
	dy_button = 0.075 * HEIGHT;

	al_draw_scaled_rotated_bitmap(ButtonMain, cx_button, cy_button, dx_button, dy_button, 0.75, 0.75, 0, NULL);
	al_draw_text(font, al_map_rgb(0, 100, 95), dx_button - 25, dy_button - 7.5, ALLEGRO_ALIGN_LEFT, "Trade");
	//chequear cuanto va a ocupar la palabra con ese font
	al_draw_scaled_rotated_bitmap(ButtonMain, cx_button, cy_button, dx_button, dy_button + al_get_bitmap_height(ButtonMain), 0.75, 0.75, 0, NULL);
	al_draw_text(font, al_map_rgb(0, 100, 95), dx_button - 25, dy_button + al_get_bitmap_height(ButtonMain) - 7.5, ALLEGRO_ALIGN_LEFT, "Pass");

	al_draw_scaled_rotated_bitmap(ButtonMain, cx_button, cy_button, dx_button, dy_button + 2 * al_get_bitmap_height(ButtonMain), 0.75, 0.75, 0, NULL);
	al_draw_text(font, al_map_rgb(0, 100, 95), dx_button - 25, dy_button + 2 * al_get_bitmap_height(ButtonMain) - 7.5, ALLEGRO_ALIGN_LEFT, "Build");

	al_draw_scaled_rotated_bitmap(ButtonMain, cx_button, cy_button, dx_button, dy_button + 3 * al_get_bitmap_height(ButtonMain), 0.75, 0.75, 0, NULL);
	al_draw_text(font, al_map_rgb(0, 100, 95), dx_button - 25, dy_button + 3 * al_get_bitmap_height(ButtonMain) - 7.5, ALLEGRO_ALIGN_LEFT, "Exit");
	al_flip_display();

	exit = false;
	string click = "";
	unsigned char r;
	unsigned char g;
	unsigned char b;
	ALLEGRO_BITMAP* chosen = Color_Buttons1;

	while (exit == false)
	{
		if (al_get_next_event(event_queue, &event))
		{

			if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
			{
				if (chosen == Color_Buttons1)
				{
					al_unmap_rgb(al_get_pixel(chosen, event.mouse.x, event.mouse.y), &r, &g, &b);
					switch (r)
					{
						case 'T': //trade
						{
							al_draw_scaled_rotated_bitmap(ButtonClick, cx_button, cy_button, dx_button, dy_button, 0.75, 0.75, 0, NULL);
							al_draw_text(font, al_map_rgb(0, 200, 195), dx_button - 25, dy_button - 7.5, ALLEGRO_ALIGN_LEFT, "Trade");
							al_flip_display();
							Sleep(100);
							al_draw_scaled_rotated_bitmap(ButtonMain, cx_button, cy_button, dx_button, dy_button, 0.75, 0.75, 0, NULL);
							al_draw_text(font, al_map_rgb(0, 100, 95), dx_button - 25, dy_button - 7.5, ALLEGRO_ALIGN_LEFT, "Trade");
							al_flip_display();
							//AGREGAR CON LA FSM Y NETWORKING
						} break;
						case 'P': //pass
						{
							al_draw_scaled_rotated_bitmap(ButtonClick, cx_button, cy_button, dx_button, dy_button + al_get_bitmap_height(ButtonMain), 0.75, 0.75, 0, NULL);
							al_draw_text(font, al_map_rgb(0, 200, 195), dx_button - 25, dy_button + al_get_bitmap_height(ButtonMain) - 7.5, ALLEGRO_ALIGN_LEFT, "Pass");
							al_flip_display();
							Sleep(100);
							al_draw_scaled_rotated_bitmap(ButtonMain, cx_button, cy_button, dx_button, dy_button + al_get_bitmap_height(ButtonMain), 0.75, 0.75, 0, NULL);
							al_draw_text(font, al_map_rgb(0, 100, 95), dx_button - 25, dy_button + al_get_bitmap_height(ButtonMain) - 7.5, ALLEGRO_ALIGN_LEFT, "Pass");
							al_flip_display();
							//AGREGAR CON LA FSM Y NETWORKING
						} break;
						case 'B': //build
						{
							al_draw_scaled_rotated_bitmap(ButtonClick, cx_button, cy_button, dx_button, dy_button + 2 * al_get_bitmap_height(ButtonMain), 0.75, 0.75, 0, NULL);
							al_draw_text(font, al_map_rgb(0, 200, 195), dx_button - 25, dy_button + 2 * al_get_bitmap_height(ButtonMain) - 7.5, ALLEGRO_ALIGN_LEFT, "Build");
							al_flip_display();
							Sleep(100);
							al_draw_scaled_rotated_bitmap(ButtonMain, cx_button, cy_button, dx_button, dy_button + 2 * al_get_bitmap_height(ButtonMain), 0.75, 0.75, 0, NULL);
							al_draw_text(font, al_map_rgb(0, 100, 95), dx_button - 25, dy_button + 2 * al_get_bitmap_height(ButtonMain) - 7.5, ALLEGRO_ALIGN_LEFT, "Build");
							al_flip_display();
							//meter en la fsm en la parte de build
							al_draw_text(font, al_map_rgb(255, 255, 255), WIDTH * 0.3, HEIGHT * 0.4, ALLEGRO_ALIGN_LEFT, "What do you wish to build?");
							al_draw_filled_rectangle(WIDTH * 0.3, HEIGHT * 0.3, WIDTH * 0.7, HEIGHT * 0.7, al_map_rgb(255, 253, 208)); // esto está bien
							al_draw_rounded_rectangle(WIDTH * 0.3, HEIGHT * 0.3, WIDTH * 0.7, HEIGHT * 0.7, 10.0, 10.0, al_map_rgb(0, 0, 0), 5.0);
							al_draw_rounded_rectangle(WIDTH * 0.3, HEIGHT * 0.3, WIDTH * 0.7, HEIGHT * 0.7, 10.0, 10.0, al_map_rgb(255, 253, 208), 3.0);
							al_draw_text(font, al_map_rgb(0, 0, 0), WIDTH * 0.33, HEIGHT * 0.48, ALLEGRO_ALIGN_LEFT, "Road");
							al_draw_text(font, al_map_rgb(0, 0, 0), WIDTH * 0.46, HEIGHT * 0.48, ALLEGRO_ALIGN_LEFT, "Settlement");
							al_draw_text(font, al_map_rgb(0, 0, 0), WIDTH * 0.63, HEIGHT * 0.48, ALLEGRO_ALIGN_LEFT, "City");
							al_draw_text(font, al_map_rgb(0, 0, 0), WIDTH * 0.63, HEIGHT * 0.65, ALLEGRO_ALIGN_LEFT, "Cancel");
							al_flip_display();
							chosen = Color_Buttons2;

						}break;
						case 'E': //exit
						{
							al_draw_scaled_rotated_bitmap(ButtonClick, cx_button, cy_button, dx_button, dy_button + 3 * al_get_bitmap_height(ButtonMain), 0.75, 0.75, 0, NULL);
							al_draw_text(font, al_map_rgb(0, 200, 195), dx_button - 25, dy_button + 3 * al_get_bitmap_height(ButtonMain) - 7.5, ALLEGRO_ALIGN_LEFT, "Exit");
							al_flip_display();
							Sleep(100);
							al_draw_scaled_rotated_bitmap(ButtonMain, cx_button, cy_button, dx_button, dy_button + 3 * al_get_bitmap_height(ButtonMain), 0.75, 0.75, 0, NULL);
							al_draw_text(font, al_map_rgb(0, 100, 95), dx_button - 25, dy_button + 3 * al_get_bitmap_height(ButtonMain) - 7.5, ALLEGRO_ALIGN_LEFT, "Exit");
							al_flip_display();
							exit = true;
						} break;
						default:break;
					}
				}
				else if (chosen == Color_Buttons2)
				{

					al_unmap_rgb(al_get_pixel(chosen, event.mouse.x, event.mouse.y), &r, &g, &b);
					switch (r)
					{
					case 'R':
						al_draw_text(font, al_map_rgb(255, 255, 255), WIDTH * 0.33, HEIGHT * 0.48, ALLEGRO_ALIGN_LEFT, "Road");
						al_flip_display();
						Sleep(100);
						//redraw display
						al_clear_to_color(al_map_rgb(185, 180, 135));
					{
							//draw board
						for (int i = 0; i < 6; i++)
						{

							float middle_x = al_get_bitmap_width(Frames[i]) / 2.0;
							float middle_y = al_get_bitmap_height(Frames[i]) / 2.0;

							float x_scale = (0.3 * WIDTH) / 810;
							float y_scale = (0.3 * WIDTH) / 810;

							float angle = ToRadians(((i * 60.0) + 180.0));

							float dx = 0, dy = 0;
							//depende de que posicion sea es donde se dibuja
							switch (('0' + i))
							{
							case '0':
							{
								dx = 0.45 * WIDTH; //OK!
								dy = 0.15 * HEIGHT; //OK!
							}break;
							case '1':
							{
								dx = 0.686 * WIDTH;
								dy = 0.263 * HEIGHT;
							}break;
							case '2':
							{
								dx = 0.736 * WIDTH;
								dy = 0.619 * HEIGHT;
							}break;
							case '3':
							{
								dx = 0.549 * WIDTH; //OK!
								dy = 0.8586 * HEIGHT; //OK!
							}break;
							case '4':
							{
								dx = 0.312 * WIDTH;
								dy = 0.7429 * HEIGHT;
							}break;
							case '5':
							{
								dx = 0.265 * WIDTH;
								dy = 0.39 * HEIGHT;
							}break;
							default: break;
							}

							//el puerto define que imagen es
							/*switch (board->all_the_sea_frames[i].getPorts().port1.port)
							{
							case ports::ANY:
							{
								img = ANY_PORT;
							}break;
							case ports::BRICK:
							{
								img = BRICK_PORT;
							}break;
							case ports::GRAIN:
							{
								img = GRAIN_PORT;
							}break;
							case ports::LUMBER:
							{
								img = WOOD_PORT;
							}break;
							case ports::ORE:
							{
								img = STONE_PORT;
							}break;
							case ports::WOOL:
							{
								img = WOOL_PORT;
							}break;
							default:
							{

							}break;
							}*/

							al_draw_scaled_rotated_bitmap(Frames[i], middle_x, middle_y, dx, dy, x_scale, y_scale, angle, NULL);
							al_flip_display();

						}

						for (int i = 0; i < TERRAIN_HEXES; i++)
						{


							float middle_x = HEX_WIDTH / 2.0;
							float middle_y = HEX_HEIGHT / 2.0;

							float x_scale = 102.5 / HEX_WIDTH;
							float y_scale = 112.5 / HEX_HEIGHT;

							float dx = 0, dy = 0;
							//depende de que posicion sea es donde se dibuja
							switch ('A' + i)
							{
							case 'A':
							{
								dx = 0.5 * WIDTH - 103.0;
								dy = 0.15 * HEIGHT + 0.295 * FRAME_HEIGHT;
							}break;
							case 'B':
							{
								dx = 0.5 * WIDTH;
								dy = 0.15 * HEIGHT + 0.295 * FRAME_HEIGHT;
							}break;
							case 'C':
							{
								dx = 0.5 * WIDTH + 103.0;
								dy = 0.15 * HEIGHT + 0.295 * FRAME_HEIGHT;
							}break;
							case 'D':
							{
								dx = ((0.5 * WIDTH - 2.0 * 102.5) + (0.5 * WIDTH - 103.0)) / 2.0;
								dy = ((0.15 * HEIGHT + 0.295 * FRAME_HEIGHT) + (0.5 * HEIGHT + 3.0)) / 2.0;
							}break;
							case 'E':
							{
								dx = ((0.5 * WIDTH - 103.0) + 0.5 * WIDTH) / 2.0;
								dy = ((0.15 * HEIGHT + 0.295 * FRAME_HEIGHT) + (0.5 * HEIGHT + 3.0)) / 2.0;
							}break;
							case 'F':
							{
								dx = (0.5 * WIDTH + (0.5 * WIDTH + 103.0)) / 2.0;
								dy = ((0.15 * HEIGHT + 0.295 * FRAME_HEIGHT) + (0.5 * HEIGHT + 3.0)) / 2.0;
							}break;
							case 'G':
							{
								dx = ((0.5 * WIDTH + 103.0) + (0.5 * WIDTH + 2.0 * 102.5)) / 2.0;
								dy = ((0.15 * HEIGHT + 0.295 * FRAME_HEIGHT) + (0.5 * HEIGHT + 3.0)) / 2.0;
							}break;
							case 'H':
							{
								dx = 0.5 * WIDTH - 2.0 * 102.5;
								dy = 0.5 * HEIGHT + 3.0;
							}break;
							case 'I':
							{
								dx = 0.5 * WIDTH - 103.0;
								dy = 0.5 * HEIGHT + 3.0;
							}break;
							case 'J':
							{
								dx = 0.5 * WIDTH;
								dy = 0.5 * HEIGHT + 3.0;
							}break;
							case 'K':
							{
								dx = 0.5 * WIDTH + 103.0;
								dy = 0.5 * HEIGHT + 3.0;
							}break;
							case 'L':
							{
								dx = 0.5 * WIDTH + 2.0 * 102.5;
								dy = 0.5 * HEIGHT + 3.0;
							}break;
							case 'M':
							{
								dx = ((0.5 * WIDTH - 2.0 * 102.5) + (0.5 * WIDTH - 103.0)) / 2.0;
								dy = ((0.5 * HEIGHT + 3.0) + (0.8586 * HEIGHT - 1 * (0.295 * FRAME_HEIGHT))) / 2.0;
							}break;
							case 'N':
							{
								dx = ((0.5 * WIDTH - 103.0) + 0.5 * WIDTH) / 2.0;
								dy = ((0.5 * HEIGHT + 3.0) + (0.8586 * HEIGHT - 1 * (0.295 * FRAME_HEIGHT))) / 2.0;
							}break;
							case 'O':
							{
								dx = (0.5 * WIDTH + (0.5 * WIDTH + 103.0)) / 2.0;
								dy = ((0.5 * HEIGHT + 3.0) + (0.8586 * HEIGHT - 1 * (0.295 * FRAME_HEIGHT))) / 2.0;
							}break;
							case 'P':
							{
								dx = ((0.5 * WIDTH + 103.0) + (0.5 * WIDTH + 2.0 * 102.5)) / 2.0;
								dy = ((0.5 * HEIGHT + 3.0) + (0.8586 * HEIGHT - 1 * (0.295 * FRAME_HEIGHT))) / 2.0;
							}break;
							case 'Q':
							{
								dx = 0.5 * WIDTH - 103.0;
								dy = 0.8586 * HEIGHT - 1 * (0.295 * FRAME_HEIGHT);
							}break;
							case 'R':
							{
								dx = 0.5 * WIDTH;
								dy = 0.8586 * HEIGHT - 1 * (0.295 * FRAME_HEIGHT);
							}break;
							case 'S':
							{
								dx = 0.5 * WIDTH + 103.0;
								dy = 0.8586 * HEIGHT - 1 * (0.295 * FRAME_HEIGHT);
							}break;
							default: break;
							}

							int img = 0;
							//el recurso define que imagen es
							/*switch (board->all_the_hexes[i].getResource())
							{
							case DESERT:
							{
								img = DESERT1;
							}break;
							case ORE:
							{
								img = ORE1;
							}break;
							case GRAIN:
							{
								img = GRAIN1;
							}break;
							case LUMBER:
							{
								img = LUMBER1;
							}break;
							case WOOL:
							{
								img = WOOL1;
							}break;
							case BRICK:
							{
								img = BRICK1;
							}break;
							default:
							{

							}break;
							}*/

							img = rand() % 6;

							al_draw_scaled_rotated_bitmap(Hexes[img], middle_x, middle_y, dx, dy, x_scale, y_scale, 0.0, NULL);

							int img2 = rand() % 10;

							al_draw_scaled_rotated_bitmap(Tokens[img2], al_get_bitmap_width(Tokens[img2]) / 2.0, al_get_bitmap_height(Tokens[img2]) / 2.0, dx, dy, 1.0 / 4.0, 1.0 / 4.0, 0.0, NULL);

							al_flip_display();
						}

						//draw dices
						unsigned int dice1 = rand() % 6 + 1;
						unsigned int dice2 = rand() % 6 + 1;

						float dx1, dy1, dx2, dy2;

						dx1 = 0.9 * WIDTH - 5.0 - al_get_bitmap_width(Dices[dice1 - 1]) / 2.0;
						dx2 = 0.9 * WIDTH + 5.0 + al_get_bitmap_width(Dices[dice1 - 1]) / 2.0;

						dy1 = 0.65 * HEIGHT;
						dy2 = dy1;

						dice1 = rand() % 6 + 1;
						dice2 = rand() % 6 + 1;

						al_draw_scaled_rotated_bitmap(Dices[dice1 - 1], al_get_bitmap_width(Dices[dice1 - 1]) / 2.0, al_get_bitmap_height(Dices[dice1 - 1]) / 2.0, dx1, dy1, 1.0, 1.0, 0.0, NULL);
						al_draw_scaled_rotated_bitmap(Dices[dice2 - 1], al_get_bitmap_width(Dices[dice2 - 1]) / 2.0, al_get_bitmap_height(Dices[dice2 - 1]) / 2.0, dx2, dy2, 1.0, 1.0, 0.0, NULL);

						al_flip_display();

						//draw player
						float cx = al_get_bitmap_width(ResourceCards[0]) / 2.0;
						float cy = al_get_bitmap_height(ResourceCards[0]) / 2.0;

						float dx = 0.06 * WIDTH;
						float dy = 0.2 * HEIGHT;
						for (int i = 0; i < 5; i++)
						{
							al_draw_scaled_rotated_bitmap(ResourceCards[i], cx, cy, dx, dy + i * cx * 1.25, 0.4, 0.4, 0.0, NULL);

							al_draw_filled_circle(dx + cx * 0.6, dy + i * cx * 1.25, 10, al_map_rgb(255, 243, 154));
							al_draw_circle(dx + cx * 0.6, dy + i * cx * 1.25, 10, al_map_rgb(0, 0, 0), 3);
							switch (i)
							{
							case ORE1:
							{
								al_draw_text(font, al_map_rgb(0, 0, 0), dx + cx * 0.6 - 5.0, dy + i * cx * 1.25 - 9.0, ALLEGRO_ALIGN_LEFT, to_string(i).c_str());
							}break;
							case GRAIN1:
							{
								al_draw_text(font, al_map_rgb(0, 0, 0), dx + cx * 0.6 - 5.0, dy + i * cx * 1.25 - 9.0, ALLEGRO_ALIGN_LEFT, to_string(i).c_str());
							}break;
							case WOOL1:
							{
								al_draw_text(font, al_map_rgb(0, 0, 0), dx + cx * 0.6 - 5.0, dy + i * cx * 1.25 - 9.0, ALLEGRO_ALIGN_LEFT, to_string(i).c_str());
							}break;
							case LUMBER1:
							{
								al_draw_text(font, al_map_rgb(0, 0, 0), dx + cx * 0.6 - 5.0, dy + i * cx * 1.25 - 9.0, ALLEGRO_ALIGN_LEFT, to_string(i).c_str());
							}break;
							case BRICK1:
							{
								al_draw_text(font, al_map_rgb(0, 0, 0), dx + cx * 0.6 - 5.0, dy + i * cx * 1.25 - 9.0, ALLEGRO_ALIGN_LEFT, to_string(i).c_str());
							}break;
							default:break;
							}
						}
						al_flip_display();


						float cx_road = al_get_bitmap_width(Roads[PLAYER]) / 2.0;
						float cy_road = al_get_bitmap_height(Roads[PLAYER]) / 2.0;

						float cx_city = al_get_bitmap_width(Settlements[PLAYER]) / 2.0;
						float cy_city = al_get_bitmap_height(Settlements[PLAYER]) / 2.0;

						float cx_settlement = al_get_bitmap_width(Houses[PLAYER]) / 2.0;
						float cy_settlement = al_get_bitmap_height(Houses[PLAYER]) / 2.0;


						al_draw_scaled_rotated_bitmap(Roads[PLAYER], cx_road, cy_road, 0.06 * WIDTH, 0.925 * HEIGHT, 0.15, 0.15, 0.0, NULL);
						al_draw_filled_circle(0.06 * WIDTH, 0.86 * HEIGHT, 10, al_map_rgb(255, 243, 154));
						al_draw_circle(0.06 * WIDTH, 0.86 * HEIGHT, 10, al_map_rgb(0, 0, 0), 3);
						al_draw_text(font, al_map_rgb(0, 0, 0), 0.06 * WIDTH - 5.0, 0.86 * HEIGHT - 9.0, ALLEGRO_ALIGN_LEFT, to_string(1).c_str());

						al_draw_scaled_rotated_bitmap(Settlements[PLAYER], cx_city, cy_city, 0.06 * WIDTH + 0.5 * (cx_settlement + cx_city), 0.925 * HEIGHT, 0.15, 0.15, 0.0, NULL);
						al_draw_filled_circle(0.06 * WIDTH + 0.5 * (cx_settlement + cx_city), 0.86 * HEIGHT, 10, al_map_rgb(255, 243, 154));
						al_draw_circle(0.06 * WIDTH + 0.5 * (cx_settlement + cx_city), 0.86 * HEIGHT, 10, al_map_rgb(0, 0, 0), 3);
						al_draw_text(font, al_map_rgb(0, 0, 0), 0.06 * WIDTH + 0.5 * (cx_settlement + cx_city) - 5.0, 0.86 * HEIGHT - 9.0, ALLEGRO_ALIGN_LEFT, to_string(1).c_str());


						al_draw_scaled_rotated_bitmap(Houses[PLAYER], cx_settlement, cy_settlement, 0.06 * WIDTH + cx_settlement * 0.5, 0.925 * HEIGHT, 0.15, 0.15, 0.0, NULL);
						al_draw_filled_circle(0.06 * WIDTH + cx_settlement * 0.5, 0.86 * HEIGHT, 10, al_map_rgb(255, 243, 154));
						al_draw_circle(0.06 * WIDTH + cx_settlement * 0.5, 0.86 * HEIGHT, 10, al_map_rgb(0, 0, 0), 3);
						al_draw_text(font, al_map_rgb(0, 0, 0), 0.06 * WIDTH + cx_settlement * 0.5 - 5.0, 0.86 * HEIGHT - 9.0, ALLEGRO_ALIGN_LEFT, to_string(1).c_str());

						//draw opponent
						al_draw_text(font, al_map_rgb(0, 0, 0), 0.775 * WIDTH, 0.75 * HEIGHT, ALLEGRO_ALIGN_LEFT, "PEPITO");

						al_draw_scaled_rotated_bitmap(Roads[OPPONENT], cx_road, cy_road, 0.75 * WIDTH, 0.925 * HEIGHT, 0.15, 0.15, 0.0, NULL);
						al_draw_filled_circle(0.75 * WIDTH, 0.86 * HEIGHT, 10, al_map_rgb(255, 243, 154));
						al_draw_circle(0.75 * WIDTH, 0.86 * HEIGHT, 10, al_map_rgb(0, 0, 0), 3);
						al_draw_text(font, al_map_rgb(0, 0, 0), 0.75 * WIDTH - 5.0, 0.86 * HEIGHT - 9.0, ALLEGRO_ALIGN_LEFT, to_string(1).c_str());

						al_flip_display();

						al_draw_scaled_rotated_bitmap(Settlements[OPPONENT], cx_city, cy_city, 0.75 * WIDTH + 0.5 * (cx_settlement + cx_city), 0.925 * HEIGHT, 0.15, 0.15, 0.0, NULL);
						al_draw_filled_circle(0.75 * WIDTH + 0.5 * (cx_settlement + cx_city), 0.86 * HEIGHT, 10, al_map_rgb(255, 243, 154));
						al_draw_circle(0.75 * WIDTH + 0.5 * (cx_settlement + cx_city), 0.86 * HEIGHT, 10, al_map_rgb(0, 0, 0), 3);
						al_draw_text(font, al_map_rgb(0, 0, 0), 0.75 * WIDTH + 0.5 * (cx_settlement + cx_city) - 5.0, 0.86 * HEIGHT - 9.0, ALLEGRO_ALIGN_LEFT, to_string(1).c_str());

						al_draw_scaled_rotated_bitmap(Houses[OPPONENT], cx_settlement, cy_settlement, 0.75 * WIDTH + cx_settlement * 0.5, 0.925 * HEIGHT, 0.15, 0.15, 0.0, NULL);
						al_draw_filled_circle(0.75 * WIDTH + cx_settlement * 0.5, 0.86 * HEIGHT, 10, al_map_rgb(255, 243, 154));
						al_draw_circle(0.75 * WIDTH + cx_settlement * 0.5, 0.86 * HEIGHT, 10, al_map_rgb(0, 0, 0), 3);
						al_draw_text(font, al_map_rgb(0, 0, 0), 0.75 * WIDTH + cx_settlement * 0.5 - 5.0, 0.86 * HEIGHT - 9.0, ALLEGRO_ALIGN_LEFT, to_string(1).c_str());

						al_flip_display();
					}

						//draw buttons
						al_draw_scaled_rotated_bitmap(ButtonMain, cx_button, cy_button, dx_button, dy_button, 0.75, 0.75, 0, NULL);
						al_draw_text(font, al_map_rgb(0, 100, 95), dx_button - 25, dy_button - 7.5, ALLEGRO_ALIGN_LEFT, "Trade");
						//chequear cuanto va a ocupar la palabra con ese font
						al_draw_scaled_rotated_bitmap(ButtonMain, cx_button, cy_button, dx_button, dy_button + al_get_bitmap_height(ButtonMain), 0.75, 0.75, 0, NULL);
						al_draw_text(font, al_map_rgb(0, 100, 95), dx_button - 25, dy_button + al_get_bitmap_height(ButtonMain) - 7.5, ALLEGRO_ALIGN_LEFT, "Pass");

						al_draw_scaled_rotated_bitmap(ButtonMain, cx_button, cy_button, dx_button, dy_button + 2 * al_get_bitmap_height(ButtonMain), 0.75, 0.75, 0, NULL);
						al_draw_text(font, al_map_rgb(0, 100, 95), dx_button - 25, dy_button + 2 * al_get_bitmap_height(ButtonMain) - 7.5, ALLEGRO_ALIGN_LEFT, "Build");

						al_draw_scaled_rotated_bitmap(ButtonMain, cx_button, cy_button, dx_button, dy_button + 3 * al_get_bitmap_height(ButtonMain), 0.75, 0.75, 0, NULL);
						al_draw_text(font, al_map_rgb(0, 100, 95), dx_button - 25, dy_button + 3 * al_get_bitmap_height(ButtonMain) - 7.5, ALLEGRO_ALIGN_LEFT, "Exit");
						chosen = Color_Roads;
						
						al_flip_display();
					break;
					case 'S': 
						al_draw_text(font, al_map_rgb(255, 255, 255), WIDTH * 0.46, HEIGHT * 0.48, ALLEGRO_ALIGN_LEFT, "Settlement");
						al_flip_display();
						Sleep(100);
						//redraw display
						{
							//draw board
							for (int i = 0; i < 6; i++)
							{

								float middle_x = al_get_bitmap_width(Frames[i]) / 2.0;
								float middle_y = al_get_bitmap_height(Frames[i]) / 2.0;

								float x_scale = (0.3 * WIDTH) / 810;
								float y_scale = (0.3 * WIDTH) / 810;

								float angle = ToRadians(((i * 60.0) + 180.0));

								float dx = 0, dy = 0;
								//depende de que posicion sea es donde se dibuja
								switch (('0' + i))
								{
								case '0':
								{
									dx = 0.45 * WIDTH; //OK!
									dy = 0.15 * HEIGHT; //OK!
								}break;
								case '1':
								{
									dx = 0.686 * WIDTH;
									dy = 0.263 * HEIGHT;
								}break;
								case '2':
								{
									dx = 0.736 * WIDTH;
									dy = 0.619 * HEIGHT;
								}break;
								case '3':
								{
									dx = 0.549 * WIDTH; //OK!
									dy = 0.8586 * HEIGHT; //OK!
								}break;
								case '4':
								{
									dx = 0.312 * WIDTH;
									dy = 0.7429 * HEIGHT;
								}break;
								case '5':
								{
									dx = 0.265 * WIDTH;
									dy = 0.39 * HEIGHT;
								}break;
								default: break;
								}

								//el puerto define que imagen es
								/*switch (board->all_the_sea_frames[i].getPorts().port1.port)
								{
								case ports::ANY:
								{
									img = ANY_PORT;
								}break;
								case ports::BRICK:
								{
									img = BRICK_PORT;
								}break;
								case ports::GRAIN:
								{
									img = GRAIN_PORT;
								}break;
								case ports::LUMBER:
								{
									img = WOOD_PORT;
								}break;
								case ports::ORE:
								{
									img = STONE_PORT;
								}break;
								case ports::WOOL:
								{
									img = WOOL_PORT;
								}break;
								default:
								{

								}break;
								}*/

								al_draw_scaled_rotated_bitmap(Frames[i], middle_x, middle_y, dx, dy, x_scale, y_scale, angle, NULL);
								al_flip_display();

							}

							for (int i = 0; i < TERRAIN_HEXES; i++)
							{


								float middle_x = HEX_WIDTH / 2.0;
								float middle_y = HEX_HEIGHT / 2.0;

								float x_scale = 102.5 / HEX_WIDTH;
								float y_scale = 112.5 / HEX_HEIGHT;

								float dx = 0, dy = 0;
								//depende de que posicion sea es donde se dibuja
								switch ('A' + i)
								{
								case 'A':
								{
									dx = 0.5 * WIDTH - 103.0;
									dy = 0.15 * HEIGHT + 0.295 * FRAME_HEIGHT;
								}break;
								case 'B':
								{
									dx = 0.5 * WIDTH;
									dy = 0.15 * HEIGHT + 0.295 * FRAME_HEIGHT;
								}break;
								case 'C':
								{
									dx = 0.5 * WIDTH + 103.0;
									dy = 0.15 * HEIGHT + 0.295 * FRAME_HEIGHT;
								}break;
								case 'D':
								{
									dx = ((0.5 * WIDTH - 2.0 * 102.5) + (0.5 * WIDTH - 103.0)) / 2.0;
									dy = ((0.15 * HEIGHT + 0.295 * FRAME_HEIGHT) + (0.5 * HEIGHT + 3.0)) / 2.0;
								}break;
								case 'E':
								{
									dx = ((0.5 * WIDTH - 103.0) + 0.5 * WIDTH) / 2.0;
									dy = ((0.15 * HEIGHT + 0.295 * FRAME_HEIGHT) + (0.5 * HEIGHT + 3.0)) / 2.0;
								}break;
								case 'F':
								{
									dx = (0.5 * WIDTH + (0.5 * WIDTH + 103.0)) / 2.0;
									dy = ((0.15 * HEIGHT + 0.295 * FRAME_HEIGHT) + (0.5 * HEIGHT + 3.0)) / 2.0;
								}break;
								case 'G':
								{
									dx = ((0.5 * WIDTH + 103.0) + (0.5 * WIDTH + 2.0 * 102.5)) / 2.0;
									dy = ((0.15 * HEIGHT + 0.295 * FRAME_HEIGHT) + (0.5 * HEIGHT + 3.0)) / 2.0;
								}break;
								case 'H':
								{
									dx = 0.5 * WIDTH - 2.0 * 102.5;
									dy = 0.5 * HEIGHT + 3.0;
								}break;
								case 'I':
								{
									dx = 0.5 * WIDTH - 103.0;
									dy = 0.5 * HEIGHT + 3.0;
								}break;
								case 'J':
								{
									dx = 0.5 * WIDTH;
									dy = 0.5 * HEIGHT + 3.0;
								}break;
								case 'K':
								{
									dx = 0.5 * WIDTH + 103.0;
									dy = 0.5 * HEIGHT + 3.0;
								}break;
								case 'L':
								{
									dx = 0.5 * WIDTH + 2.0 * 102.5;
									dy = 0.5 * HEIGHT + 3.0;
								}break;
								case 'M':
								{
									dx = ((0.5 * WIDTH - 2.0 * 102.5) + (0.5 * WIDTH - 103.0)) / 2.0;
									dy = ((0.5 * HEIGHT + 3.0) + (0.8586 * HEIGHT - 1 * (0.295 * FRAME_HEIGHT))) / 2.0;
								}break;
								case 'N':
								{
									dx = ((0.5 * WIDTH - 103.0) + 0.5 * WIDTH) / 2.0;
									dy = ((0.5 * HEIGHT + 3.0) + (0.8586 * HEIGHT - 1 * (0.295 * FRAME_HEIGHT))) / 2.0;
								}break;
								case 'O':
								{
									dx = (0.5 * WIDTH + (0.5 * WIDTH + 103.0)) / 2.0;
									dy = ((0.5 * HEIGHT + 3.0) + (0.8586 * HEIGHT - 1 * (0.295 * FRAME_HEIGHT))) / 2.0;
								}break;
								case 'P':
								{
									dx = ((0.5 * WIDTH + 103.0) + (0.5 * WIDTH + 2.0 * 102.5)) / 2.0;
									dy = ((0.5 * HEIGHT + 3.0) + (0.8586 * HEIGHT - 1 * (0.295 * FRAME_HEIGHT))) / 2.0;
								}break;
								case 'Q':
								{
									dx = 0.5 * WIDTH - 103.0;
									dy = 0.8586 * HEIGHT - 1 * (0.295 * FRAME_HEIGHT);
								}break;
								case 'R':
								{
									dx = 0.5 * WIDTH;
									dy = 0.8586 * HEIGHT - 1 * (0.295 * FRAME_HEIGHT);
								}break;
								case 'S':
								{
									dx = 0.5 * WIDTH + 103.0;
									dy = 0.8586 * HEIGHT - 1 * (0.295 * FRAME_HEIGHT);
								}break;
								default: break;
								}

								int img = 0;
								//el recurso define que imagen es
								/*switch (board->all_the_hexes[i].getResource())
								{
								case DESERT:
								{
									img = DESERT1;
								}break;
								case ORE:
								{
									img = ORE1;
								}break;
								case GRAIN:
								{
									img = GRAIN1;
								}break;
								case LUMBER:
								{
									img = LUMBER1;
								}break;
								case WOOL:
								{
									img = WOOL1;
								}break;
								case BRICK:
								{
									img = BRICK1;
								}break;
								default:
								{

								}break;
								}*/

								img = rand() % 6;

								al_draw_scaled_rotated_bitmap(Hexes[img], middle_x, middle_y, dx, dy, x_scale, y_scale, 0.0, NULL);

								int img2 = rand() % 10;

								al_draw_scaled_rotated_bitmap(Tokens[img2], al_get_bitmap_width(Tokens[img2]) / 2.0, al_get_bitmap_height(Tokens[img2]) / 2.0, dx, dy, 1.0 / 4.0, 1.0 / 4.0, 0.0, NULL);

								al_flip_display();
							}

							//draw dices
							unsigned int dice1 = rand() % 6 + 1;
							unsigned int dice2 = rand() % 6 + 1;

							float dx1, dy1, dx2, dy2;

							dx1 = 0.9 * WIDTH - 5.0 - al_get_bitmap_width(Dices[dice1 - 1]) / 2.0;
							dx2 = 0.9 * WIDTH + 5.0 + al_get_bitmap_width(Dices[dice1 - 1]) / 2.0;

							dy1 = 0.65 * HEIGHT;
							dy2 = dy1;

							dice1 = rand() % 6 + 1;
							dice2 = rand() % 6 + 1;

							al_draw_scaled_rotated_bitmap(Dices[dice1 - 1], al_get_bitmap_width(Dices[dice1 - 1]) / 2.0, al_get_bitmap_height(Dices[dice1 - 1]) / 2.0, dx1, dy1, 1.0, 1.0, 0.0, NULL);
							al_draw_scaled_rotated_bitmap(Dices[dice2 - 1], al_get_bitmap_width(Dices[dice2 - 1]) / 2.0, al_get_bitmap_height(Dices[dice2 - 1]) / 2.0, dx2, dy2, 1.0, 1.0, 0.0, NULL);

							al_flip_display();

							//draw player
							float cx = al_get_bitmap_width(ResourceCards[0]) / 2.0;
							float cy = al_get_bitmap_height(ResourceCards[0]) / 2.0;

							float dx = 0.06 * WIDTH;
							float dy = 0.2 * HEIGHT;
							for (int i = 0; i < 5; i++)
							{
								al_draw_scaled_rotated_bitmap(ResourceCards[i], cx, cy, dx, dy + i * cx * 1.25, 0.4, 0.4, 0.0, NULL);

								al_draw_filled_circle(dx + cx * 0.6, dy + i * cx * 1.25, 10, al_map_rgb(255, 243, 154));
								al_draw_circle(dx + cx * 0.6, dy + i * cx * 1.25, 10, al_map_rgb(0, 0, 0), 3);
								switch (i)
								{
								case ORE1:
								{
									al_draw_text(font, al_map_rgb(0, 0, 0), dx + cx * 0.6 - 5.0, dy + i * cx * 1.25 - 9.0, ALLEGRO_ALIGN_LEFT, to_string(i).c_str());
								}break;
								case GRAIN1:
								{
									al_draw_text(font, al_map_rgb(0, 0, 0), dx + cx * 0.6 - 5.0, dy + i * cx * 1.25 - 9.0, ALLEGRO_ALIGN_LEFT, to_string(i).c_str());
								}break;
								case WOOL1:
								{
									al_draw_text(font, al_map_rgb(0, 0, 0), dx + cx * 0.6 - 5.0, dy + i * cx * 1.25 - 9.0, ALLEGRO_ALIGN_LEFT, to_string(i).c_str());
								}break;
								case LUMBER1:
								{
									al_draw_text(font, al_map_rgb(0, 0, 0), dx + cx * 0.6 - 5.0, dy + i * cx * 1.25 - 9.0, ALLEGRO_ALIGN_LEFT, to_string(i).c_str());
								}break;
								case BRICK1:
								{
									al_draw_text(font, al_map_rgb(0, 0, 0), dx + cx * 0.6 - 5.0, dy + i * cx * 1.25 - 9.0, ALLEGRO_ALIGN_LEFT, to_string(i).c_str());
								}break;
								default:break;
								}
							}
							al_flip_display();


							float cx_road = al_get_bitmap_width(Roads[PLAYER]) / 2.0;
							float cy_road = al_get_bitmap_height(Roads[PLAYER]) / 2.0;

							float cx_city = al_get_bitmap_width(Settlements[PLAYER]) / 2.0;
							float cy_city = al_get_bitmap_height(Settlements[PLAYER]) / 2.0;

							float cx_settlement = al_get_bitmap_width(Houses[PLAYER]) / 2.0;
							float cy_settlement = al_get_bitmap_height(Houses[PLAYER]) / 2.0;


							al_draw_scaled_rotated_bitmap(Roads[PLAYER], cx_road, cy_road, 0.06 * WIDTH, 0.925 * HEIGHT, 0.15, 0.15, 0.0, NULL);
							al_draw_filled_circle(0.06 * WIDTH, 0.86 * HEIGHT, 10, al_map_rgb(255, 243, 154));
							al_draw_circle(0.06 * WIDTH, 0.86 * HEIGHT, 10, al_map_rgb(0, 0, 0), 3);
							al_draw_text(font, al_map_rgb(0, 0, 0), 0.06 * WIDTH - 5.0, 0.86 * HEIGHT - 9.0, ALLEGRO_ALIGN_LEFT, to_string(1).c_str());

							al_draw_scaled_rotated_bitmap(Settlements[PLAYER], cx_city, cy_city, 0.06 * WIDTH + 0.5 * (cx_settlement + cx_city), 0.925 * HEIGHT, 0.15, 0.15, 0.0, NULL);
							al_draw_filled_circle(0.06 * WIDTH + 0.5 * (cx_settlement + cx_city), 0.86 * HEIGHT, 10, al_map_rgb(255, 243, 154));
							al_draw_circle(0.06 * WIDTH + 0.5 * (cx_settlement + cx_city), 0.86 * HEIGHT, 10, al_map_rgb(0, 0, 0), 3);
							al_draw_text(font, al_map_rgb(0, 0, 0), 0.06 * WIDTH + 0.5 * (cx_settlement + cx_city) - 5.0, 0.86 * HEIGHT - 9.0, ALLEGRO_ALIGN_LEFT, to_string(1).c_str());


							al_draw_scaled_rotated_bitmap(Houses[PLAYER], cx_settlement, cy_settlement, 0.06 * WIDTH + cx_settlement * 0.5, 0.925 * HEIGHT, 0.15, 0.15, 0.0, NULL);
							al_draw_filled_circle(0.06 * WIDTH + cx_settlement * 0.5, 0.86 * HEIGHT, 10, al_map_rgb(255, 243, 154));
							al_draw_circle(0.06 * WIDTH + cx_settlement * 0.5, 0.86 * HEIGHT, 10, al_map_rgb(0, 0, 0), 3);
							al_draw_text(font, al_map_rgb(0, 0, 0), 0.06 * WIDTH + cx_settlement * 0.5 - 5.0, 0.86 * HEIGHT - 9.0, ALLEGRO_ALIGN_LEFT, to_string(1).c_str());

							//draw opponent
							al_draw_text(font, al_map_rgb(0, 0, 0), 0.775 * WIDTH, 0.75 * HEIGHT, ALLEGRO_ALIGN_LEFT, "PEPITO");

							al_draw_scaled_rotated_bitmap(Roads[OPPONENT], cx_road, cy_road, 0.75 * WIDTH, 0.925 * HEIGHT, 0.15, 0.15, 0.0, NULL);
							al_draw_filled_circle(0.75 * WIDTH, 0.86 * HEIGHT, 10, al_map_rgb(255, 243, 154));
							al_draw_circle(0.75 * WIDTH, 0.86 * HEIGHT, 10, al_map_rgb(0, 0, 0), 3);
							al_draw_text(font, al_map_rgb(0, 0, 0), 0.75 * WIDTH - 5.0, 0.86 * HEIGHT - 9.0, ALLEGRO_ALIGN_LEFT, to_string(1).c_str());

							al_flip_display();

							al_draw_scaled_rotated_bitmap(Settlements[OPPONENT], cx_city, cy_city, 0.75 * WIDTH + 0.5 * (cx_settlement + cx_city), 0.925 * HEIGHT, 0.15, 0.15, 0.0, NULL);
							al_draw_filled_circle(0.75 * WIDTH + 0.5 * (cx_settlement + cx_city), 0.86 * HEIGHT, 10, al_map_rgb(255, 243, 154));
							al_draw_circle(0.75 * WIDTH + 0.5 * (cx_settlement + cx_city), 0.86 * HEIGHT, 10, al_map_rgb(0, 0, 0), 3);
							al_draw_text(font, al_map_rgb(0, 0, 0), 0.75 * WIDTH + 0.5 * (cx_settlement + cx_city) - 5.0, 0.86 * HEIGHT - 9.0, ALLEGRO_ALIGN_LEFT, to_string(1).c_str());

							al_draw_scaled_rotated_bitmap(Houses[OPPONENT], cx_settlement, cy_settlement, 0.75 * WIDTH + cx_settlement * 0.5, 0.925 * HEIGHT, 0.15, 0.15, 0.0, NULL);
							al_draw_filled_circle(0.75 * WIDTH + cx_settlement * 0.5, 0.86 * HEIGHT, 10, al_map_rgb(255, 243, 154));
							al_draw_circle(0.75 * WIDTH + cx_settlement * 0.5, 0.86 * HEIGHT, 10, al_map_rgb(0, 0, 0), 3);
							al_draw_text(font, al_map_rgb(0, 0, 0), 0.75 * WIDTH + cx_settlement * 0.5 - 5.0, 0.86 * HEIGHT - 9.0, ALLEGRO_ALIGN_LEFT, to_string(1).c_str());

							al_flip_display();
						}

						//draw buttons
						al_draw_scaled_rotated_bitmap(ButtonMain, cx_button, cy_button, dx_button, dy_button, 0.75, 0.75, 0, NULL);
						al_draw_text(font, al_map_rgb(0, 100, 95), dx_button - 25, dy_button - 7.5, ALLEGRO_ALIGN_LEFT, "Trade");
						//chequear cuanto va a ocupar la palabra con ese font
						al_draw_scaled_rotated_bitmap(ButtonMain, cx_button, cy_button, dx_button, dy_button + al_get_bitmap_height(ButtonMain), 0.75, 0.75, 0, NULL);
						al_draw_text(font, al_map_rgb(0, 100, 95), dx_button - 25, dy_button + al_get_bitmap_height(ButtonMain) - 7.5, ALLEGRO_ALIGN_LEFT, "Pass");

						al_draw_scaled_rotated_bitmap(ButtonMain, cx_button, cy_button, dx_button, dy_button + 2 * al_get_bitmap_height(ButtonMain), 0.75, 0.75, 0, NULL);
						al_draw_text(font, al_map_rgb(0, 100, 95), dx_button - 25, dy_button + 2 * al_get_bitmap_height(ButtonMain) - 7.5, ALLEGRO_ALIGN_LEFT, "Build");

						al_draw_scaled_rotated_bitmap(ButtonMain, cx_button, cy_button, dx_button, dy_button + 3 * al_get_bitmap_height(ButtonMain), 0.75, 0.75, 0, NULL);
						al_draw_text(font, al_map_rgb(0, 100, 95), dx_button - 25, dy_button + 3 * al_get_bitmap_height(ButtonMain) - 7.5, ALLEGRO_ALIGN_LEFT, "Exit");

						chosen = Color_Nodes;
					break;
					case 'C':
						al_draw_text(font, al_map_rgb(255, 255, 255), WIDTH * 0.63, HEIGHT * 0.48, ALLEGRO_ALIGN_LEFT, "City");
						al_flip_display();
						Sleep(100);
						//redraw display
						al_clear_to_color(al_map_rgb(185, 180, 135));
						{
							for (int i = 0; i < 6; i++)
							{

								float middle_x = al_get_bitmap_width(Frames[i]) / 2.0;
								float middle_y = al_get_bitmap_height(Frames[i]) / 2.0;

								float x_scale = (0.3 * WIDTH) / 810;
								float y_scale = (0.3 * WIDTH) / 810;

								float angle = ToRadians(((i * 60.0) + 180.0));

								float dx = 0, dy = 0;
								//depende de que posicion sea es donde se dibuja
								switch (('0' + i))
								{
								case '0':
								{
									dx = 0.45 * WIDTH; //OK!
									dy = 0.15 * HEIGHT; //OK!
								}break;
								case '1':
								{
									dx = 0.686 * WIDTH;
									dy = 0.263 * HEIGHT;
								}break;
								case '2':
								{
									dx = 0.736 * WIDTH;
									dy = 0.619 * HEIGHT;
								}break;
								case '3':
								{
									dx = 0.549 * WIDTH; //OK!
									dy = 0.8586 * HEIGHT; //OK!
								}break;
								case '4':
								{
									dx = 0.312 * WIDTH;
									dy = 0.7429 * HEIGHT;
								}break;
								case '5':
								{
									dx = 0.265 * WIDTH;
									dy = 0.39 * HEIGHT;
								}break;
								default: break;
								}

								//el puerto define que imagen es
								/*switch (board->all_the_sea_frames[i].getPorts().port1.port)
								{
								case ports::ANY:
								{
									img = ANY_PORT;
								}break;
								case ports::BRICK:
								{
									img = BRICK_PORT;
								}break;
								case ports::GRAIN:
								{
									img = GRAIN_PORT;
								}break;
								case ports::LUMBER:
								{
									img = WOOD_PORT;
								}break;
								case ports::ORE:
								{
									img = STONE_PORT;
								}break;
								case ports::WOOL:
								{
									img = WOOL_PORT;
								}break;
								default:
								{

								}break;
								}*/

								al_draw_scaled_rotated_bitmap(Frames[i], middle_x, middle_y, dx, dy, x_scale, y_scale, angle, NULL);
								al_flip_display();

							}

							for (int i = 0; i < TERRAIN_HEXES; i++)
							{


								float middle_x = HEX_WIDTH / 2.0;
								float middle_y = HEX_HEIGHT / 2.0;

								float x_scale = 102.5 / HEX_WIDTH;
								float y_scale = 112.5 / HEX_HEIGHT;

								float dx = 0, dy = 0;
								//depende de que posicion sea es donde se dibuja
								switch ('A' + i)
								{
								case 'A':
								{
									dx = 0.5 * WIDTH - 103.0;
									dy = 0.15 * HEIGHT + 0.295 * FRAME_HEIGHT;
								}break;
								case 'B':
								{
									dx = 0.5 * WIDTH;
									dy = 0.15 * HEIGHT + 0.295 * FRAME_HEIGHT;
								}break;
								case 'C':
								{
									dx = 0.5 * WIDTH + 103.0;
									dy = 0.15 * HEIGHT + 0.295 * FRAME_HEIGHT;
								}break;
								case 'D':
								{
									dx = ((0.5 * WIDTH - 2.0 * 102.5) + (0.5 * WIDTH - 103.0)) / 2.0;
									dy = ((0.15 * HEIGHT + 0.295 * FRAME_HEIGHT) + (0.5 * HEIGHT + 3.0)) / 2.0;
								}break;
								case 'E':
								{
									dx = ((0.5 * WIDTH - 103.0) + 0.5 * WIDTH) / 2.0;
									dy = ((0.15 * HEIGHT + 0.295 * FRAME_HEIGHT) + (0.5 * HEIGHT + 3.0)) / 2.0;
								}break;
								case 'F':
								{
									dx = (0.5 * WIDTH + (0.5 * WIDTH + 103.0)) / 2.0;
									dy = ((0.15 * HEIGHT + 0.295 * FRAME_HEIGHT) + (0.5 * HEIGHT + 3.0)) / 2.0;
								}break;
								case 'G':
								{
									dx = ((0.5 * WIDTH + 103.0) + (0.5 * WIDTH + 2.0 * 102.5)) / 2.0;
									dy = ((0.15 * HEIGHT + 0.295 * FRAME_HEIGHT) + (0.5 * HEIGHT + 3.0)) / 2.0;
								}break;
								case 'H':
								{
									dx = 0.5 * WIDTH - 2.0 * 102.5;
									dy = 0.5 * HEIGHT + 3.0;
								}break;
								case 'I':
								{
									dx = 0.5 * WIDTH - 103.0;
									dy = 0.5 * HEIGHT + 3.0;
								}break;
								case 'J':
								{
									dx = 0.5 * WIDTH;
									dy = 0.5 * HEIGHT + 3.0;
								}break;
								case 'K':
								{
									dx = 0.5 * WIDTH + 103.0;
									dy = 0.5 * HEIGHT + 3.0;
								}break;
								case 'L':
								{
									dx = 0.5 * WIDTH + 2.0 * 102.5;
									dy = 0.5 * HEIGHT + 3.0;
								}break;
								case 'M':
								{
									dx = ((0.5 * WIDTH - 2.0 * 102.5) + (0.5 * WIDTH - 103.0)) / 2.0;
									dy = ((0.5 * HEIGHT + 3.0) + (0.8586 * HEIGHT - 1 * (0.295 * FRAME_HEIGHT))) / 2.0;
								}break;
								case 'N':
								{
									dx = ((0.5 * WIDTH - 103.0) + 0.5 * WIDTH) / 2.0;
									dy = ((0.5 * HEIGHT + 3.0) + (0.8586 * HEIGHT - 1 * (0.295 * FRAME_HEIGHT))) / 2.0;
								}break;
								case 'O':
								{
									dx = (0.5 * WIDTH + (0.5 * WIDTH + 103.0)) / 2.0;
									dy = ((0.5 * HEIGHT + 3.0) + (0.8586 * HEIGHT - 1 * (0.295 * FRAME_HEIGHT))) / 2.0;
								}break;
								case 'P':
								{
									dx = ((0.5 * WIDTH + 103.0) + (0.5 * WIDTH + 2.0 * 102.5)) / 2.0;
									dy = ((0.5 * HEIGHT + 3.0) + (0.8586 * HEIGHT - 1 * (0.295 * FRAME_HEIGHT))) / 2.0;
								}break;
								case 'Q':
								{
									dx = 0.5 * WIDTH - 103.0;
									dy = 0.8586 * HEIGHT - 1 * (0.295 * FRAME_HEIGHT);
								}break;
								case 'R':
								{
									dx = 0.5 * WIDTH;
									dy = 0.8586 * HEIGHT - 1 * (0.295 * FRAME_HEIGHT);
								}break;
								case 'S':
								{
									dx = 0.5 * WIDTH + 103.0;
									dy = 0.8586 * HEIGHT - 1 * (0.295 * FRAME_HEIGHT);
								}break;
								default: break;
								}

								int img = 0;
								//el recurso define que imagen es
								/*switch (board->all_the_hexes[i].getResource())
								{
								case DESERT:
								{
									img = DESERT1;
								}break;
								case ORE:
								{
									img = ORE1;
								}break;
								case GRAIN:
								{
									img = GRAIN1;
								}break;
								case LUMBER:
								{
									img = LUMBER1;
								}break;
								case WOOL:
								{
									img = WOOL1;
								}break;
								case BRICK:
								{
									img = BRICK1;
								}break;
								default:
								{

								}break;
								}*/

								img = rand() % 6;

								al_draw_scaled_rotated_bitmap(Hexes[img], middle_x, middle_y, dx, dy, x_scale, y_scale, 0.0, NULL);

								int img2 = rand() % 10;

								al_draw_scaled_rotated_bitmap(Tokens[img2], al_get_bitmap_width(Tokens[img2]) / 2.0, al_get_bitmap_height(Tokens[img2]) / 2.0, dx, dy, 1.0 / 4.0, 1.0 / 4.0, 0.0, NULL);

								al_flip_display();
							}

							unsigned int dice1 = rand() % 6 + 1;
							unsigned int dice2 = rand() % 6 + 1;

							float dx1, dy1, dx2, dy2;

							dx1 = 0.9 * WIDTH - 5.0 - al_get_bitmap_width(Dices[dice1 - 1]) / 2.0;
							dx2 = 0.9 * WIDTH + 5.0 + al_get_bitmap_width(Dices[dice1 - 1]) / 2.0;

							dy1 = 0.65 * HEIGHT;
							dy2 = dy1;

							dice1 = rand() % 6 + 1;
							dice2 = rand() % 6 + 1;

							al_draw_scaled_rotated_bitmap(Dices[dice1 - 1], al_get_bitmap_width(Dices[dice1 - 1]) / 2.0, al_get_bitmap_height(Dices[dice1 - 1]) / 2.0, dx1, dy1, 1.0, 1.0, 0.0, NULL);
							al_draw_scaled_rotated_bitmap(Dices[dice2 - 1], al_get_bitmap_width(Dices[dice2 - 1]) / 2.0, al_get_bitmap_height(Dices[dice2 - 1]) / 2.0, dx2, dy2, 1.0, 1.0, 0.0, NULL);

							al_flip_display();

							float cx = al_get_bitmap_width(ResourceCards[0]) / 2.0;
							float cy = al_get_bitmap_height(ResourceCards[0]) / 2.0;

							float dx = 0.06 * WIDTH;
							float dy = 0.2 * HEIGHT;
							for (int i = 0; i < 5; i++)
							{
								al_draw_scaled_rotated_bitmap(ResourceCards[i], cx, cy, dx, dy + i * cx * 1.25, 0.4, 0.4, 0.0, NULL);

								al_draw_filled_circle(dx + cx * 0.6, dy + i * cx * 1.25, 10, al_map_rgb(255, 243, 154));
								al_draw_circle(dx + cx * 0.6, dy + i * cx * 1.25, 10, al_map_rgb(0, 0, 0), 3);
								switch (i)
								{
								case ORE1:
								{
									al_draw_text(font, al_map_rgb(0, 0, 0), dx + cx * 0.6 - 5.0, dy + i * cx * 1.25 - 9.0, ALLEGRO_ALIGN_LEFT, to_string(i).c_str());
								}break;
								case GRAIN1:
								{
									al_draw_text(font, al_map_rgb(0, 0, 0), dx + cx * 0.6 - 5.0, dy + i * cx * 1.25 - 9.0, ALLEGRO_ALIGN_LEFT, to_string(i).c_str());
								}break;
								case WOOL1:
								{
									al_draw_text(font, al_map_rgb(0, 0, 0), dx + cx * 0.6 - 5.0, dy + i * cx * 1.25 - 9.0, ALLEGRO_ALIGN_LEFT, to_string(i).c_str());
								}break;
								case LUMBER1:
								{
									al_draw_text(font, al_map_rgb(0, 0, 0), dx + cx * 0.6 - 5.0, dy + i * cx * 1.25 - 9.0, ALLEGRO_ALIGN_LEFT, to_string(i).c_str());
								}break;
								case BRICK1:
								{
									al_draw_text(font, al_map_rgb(0, 0, 0), dx + cx * 0.6 - 5.0, dy + i * cx * 1.25 - 9.0, ALLEGRO_ALIGN_LEFT, to_string(i).c_str());
								}break;
								default:break;
								}
							}
							al_flip_display();


							float cx_road = al_get_bitmap_width(Roads[PLAYER]) / 2.0;
							float cy_road = al_get_bitmap_height(Roads[PLAYER]) / 2.0;

							float cx_city = al_get_bitmap_width(Settlements[PLAYER]) / 2.0;
							float cy_city = al_get_bitmap_height(Settlements[PLAYER]) / 2.0;

							float cx_settlement = al_get_bitmap_width(Houses[PLAYER]) / 2.0;
							float cy_settlement = al_get_bitmap_height(Houses[PLAYER]) / 2.0;


							al_draw_scaled_rotated_bitmap(Roads[PLAYER], cx_road, cy_road, 0.06 * WIDTH, 0.925 * HEIGHT, 0.15, 0.15, 0.0, NULL);
							al_draw_filled_circle(0.06 * WIDTH, 0.86 * HEIGHT, 10, al_map_rgb(255, 243, 154));
							al_draw_circle(0.06 * WIDTH, 0.86 * HEIGHT, 10, al_map_rgb(0, 0, 0), 3);
							al_draw_text(font, al_map_rgb(0, 0, 0), 0.06 * WIDTH - 5.0, 0.86 * HEIGHT - 9.0, ALLEGRO_ALIGN_LEFT, to_string(1).c_str());

							al_draw_scaled_rotated_bitmap(Settlements[PLAYER], cx_city, cy_city, 0.06 * WIDTH + 0.5 * (cx_settlement + cx_city), 0.925 * HEIGHT, 0.15, 0.15, 0.0, NULL);
							al_draw_filled_circle(0.06 * WIDTH + 0.5 * (cx_settlement + cx_city), 0.86 * HEIGHT, 10, al_map_rgb(255, 243, 154));
							al_draw_circle(0.06 * WIDTH + 0.5 * (cx_settlement + cx_city), 0.86 * HEIGHT, 10, al_map_rgb(0, 0, 0), 3);
							al_draw_text(font, al_map_rgb(0, 0, 0), 0.06 * WIDTH + 0.5 * (cx_settlement + cx_city) - 5.0, 0.86 * HEIGHT - 9.0, ALLEGRO_ALIGN_LEFT, to_string(1).c_str());


							al_draw_scaled_rotated_bitmap(Houses[PLAYER], cx_settlement, cy_settlement, 0.06 * WIDTH + cx_settlement * 0.5, 0.925 * HEIGHT, 0.15, 0.15, 0.0, NULL);
							al_draw_filled_circle(0.06 * WIDTH + cx_settlement * 0.5, 0.86 * HEIGHT, 10, al_map_rgb(255, 243, 154));
							al_draw_circle(0.06 * WIDTH + cx_settlement * 0.5, 0.86 * HEIGHT, 10, al_map_rgb(0, 0, 0), 3);
							al_draw_text(font, al_map_rgb(0, 0, 0), 0.06 * WIDTH + cx_settlement * 0.5 - 5.0, 0.86 * HEIGHT - 9.0, ALLEGRO_ALIGN_LEFT, to_string(1).c_str());

							al_draw_text(font, al_map_rgb(0, 0, 0), 0.775 * WIDTH, 0.75 * HEIGHT, ALLEGRO_ALIGN_LEFT, "PEPITO");

							al_draw_scaled_rotated_bitmap(Roads[OPPONENT], cx_road, cy_road, 0.75 * WIDTH, 0.925 * HEIGHT, 0.15, 0.15, 0.0, NULL);
							al_draw_filled_circle(0.75 * WIDTH, 0.86 * HEIGHT, 10, al_map_rgb(255, 243, 154));
							al_draw_circle(0.75 * WIDTH, 0.86 * HEIGHT, 10, al_map_rgb(0, 0, 0), 3);
							al_draw_text(font, al_map_rgb(0, 0, 0), 0.75 * WIDTH - 5.0, 0.86 * HEIGHT - 9.0, ALLEGRO_ALIGN_LEFT, to_string(1).c_str());

							al_flip_display();

							al_draw_scaled_rotated_bitmap(Settlements[OPPONENT], cx_city, cy_city, 0.75 * WIDTH + 0.5 * (cx_settlement + cx_city), 0.925 * HEIGHT, 0.15, 0.15, 0.0, NULL);
							al_draw_filled_circle(0.75 * WIDTH + 0.5 * (cx_settlement + cx_city), 0.86 * HEIGHT, 10, al_map_rgb(255, 243, 154));
							al_draw_circle(0.75 * WIDTH + 0.5 * (cx_settlement + cx_city), 0.86 * HEIGHT, 10, al_map_rgb(0, 0, 0), 3);
							al_draw_text(font, al_map_rgb(0, 0, 0), 0.75 * WIDTH + 0.5 * (cx_settlement + cx_city) - 5.0, 0.86 * HEIGHT - 9.0, ALLEGRO_ALIGN_LEFT, to_string(1).c_str());

							al_draw_scaled_rotated_bitmap(Houses[OPPONENT], cx_settlement, cy_settlement, 0.75 * WIDTH + cx_settlement * 0.5, 0.925 * HEIGHT, 0.15, 0.15, 0.0, NULL);
							al_draw_filled_circle(0.75 * WIDTH + cx_settlement * 0.5, 0.86 * HEIGHT, 10, al_map_rgb(255, 243, 154));
							al_draw_circle(0.75 * WIDTH + cx_settlement * 0.5, 0.86 * HEIGHT, 10, al_map_rgb(0, 0, 0), 3);
							al_draw_text(font, al_map_rgb(0, 0, 0), 0.75 * WIDTH + cx_settlement * 0.5 - 5.0, 0.86 * HEIGHT - 9.0, ALLEGRO_ALIGN_LEFT, to_string(1).c_str());

							al_flip_display();

							float cx_button, cy_button, dx_button, dy_button;
							cx_button = al_get_bitmap_width(ButtonMain) / 2.0;
							cy_button = al_get_bitmap_height(ButtonMain) / 2.0;

							dx_button = 0.9 * WIDTH;
							dy_button = 0.075 * HEIGHT;

							al_draw_scaled_rotated_bitmap(ButtonMain, cx_button, cy_button, dx_button, dy_button, 0.75, 0.75, 0, NULL);
							al_draw_text(font, al_map_rgb(0, 100, 95), dx_button - 25, dy_button - 7.5, ALLEGRO_ALIGN_LEFT, "Trade");
							//chequear cuanto va a ocupar la palabra con ese font
							al_draw_scaled_rotated_bitmap(ButtonMain, cx_button, cy_button, dx_button, dy_button + al_get_bitmap_height(ButtonMain), 0.75, 0.75, 0, NULL);
							al_draw_text(font, al_map_rgb(0, 100, 95), dx_button - 25, dy_button + al_get_bitmap_height(ButtonMain) - 7.5, ALLEGRO_ALIGN_LEFT, "Pass");

							al_draw_scaled_rotated_bitmap(ButtonMain, cx_button, cy_button, dx_button, dy_button + 2 * al_get_bitmap_height(ButtonMain), 0.75, 0.75, 0, NULL);
							al_draw_text(font, al_map_rgb(0, 100, 95), dx_button - 25, dy_button + 2 * al_get_bitmap_height(ButtonMain) - 7.5, ALLEGRO_ALIGN_LEFT, "Build");

							al_draw_scaled_rotated_bitmap(ButtonMain, cx_button, cy_button, dx_button, dy_button + 3 * al_get_bitmap_height(ButtonMain), 0.75, 0.75, 0, NULL);
							al_draw_text(font, al_map_rgb(0, 100, 95), dx_button - 25, dy_button + 3 * al_get_bitmap_height(ButtonMain) - 7.5, ALLEGRO_ALIGN_LEFT, "Exit");
							al_flip_display();
						}
						al_draw_scaled_rotated_bitmap(ButtonMain, cx_button, cy_button, dx_button, dy_button, 0.75, 0.75, 0, NULL);
						al_draw_text(font, al_map_rgb(0, 100, 95), dx_button - 25, dy_button - 7.5, ALLEGRO_ALIGN_LEFT, "Trade");
						//chequear cuanto va a ocupar la palabra con ese font
						al_draw_scaled_rotated_bitmap(ButtonMain, cx_button, cy_button, dx_button, dy_button + al_get_bitmap_height(ButtonMain), 0.75, 0.75, 0, NULL);
						al_draw_text(font, al_map_rgb(0, 100, 95), dx_button - 25, dy_button + al_get_bitmap_height(ButtonMain) - 7.5, ALLEGRO_ALIGN_LEFT, "Pass");

						al_draw_scaled_rotated_bitmap(ButtonMain, cx_button, cy_button, dx_button, dy_button + 2 * al_get_bitmap_height(ButtonMain), 0.75, 0.75, 0, NULL);
						al_draw_text(font, al_map_rgb(0, 100, 95), dx_button - 25, dy_button + 2 * al_get_bitmap_height(ButtonMain) - 7.5, ALLEGRO_ALIGN_LEFT, "Build");

						al_draw_scaled_rotated_bitmap(ButtonMain, cx_button, cy_button, dx_button, dy_button + 3 * al_get_bitmap_height(ButtonMain), 0.75, 0.75, 0, NULL);
						al_draw_text(font, al_map_rgb(0, 100, 95), dx_button - 25, dy_button + 3 * al_get_bitmap_height(ButtonMain) - 7.5, ALLEGRO_ALIGN_LEFT, "Exit");
						al_flip_display();
						chosen = Color_Nodes;
					break;
					case 'X':
						//redraw display
						al_clear_to_color(al_map_rgb(185, 180, 135));
						{
							for (int i = 0; i < 6; i++)
							{

								float middle_x = al_get_bitmap_width(Frames[i]) / 2.0;
								float middle_y = al_get_bitmap_height(Frames[i]) / 2.0;

								float x_scale = (0.3 * WIDTH) / 810;
								float y_scale = (0.3 * WIDTH) / 810;

								float angle = ToRadians(((i * 60.0) + 180.0));

								float dx = 0, dy = 0;
								//depende de que posicion sea es donde se dibuja
								switch (('0' + i))
								{
								case '0':
								{
									dx = 0.45 * WIDTH; //OK!
									dy = 0.15 * HEIGHT; //OK!
								}break;
								case '1':
								{
									dx = 0.686 * WIDTH;
									dy = 0.263 * HEIGHT;
								}break;
								case '2':
								{
									dx = 0.736 * WIDTH;
									dy = 0.619 * HEIGHT;
								}break;
								case '3':
								{
									dx = 0.549 * WIDTH; //OK!
									dy = 0.8586 * HEIGHT; //OK!
								}break;
								case '4':
								{
									dx = 0.312 * WIDTH;
									dy = 0.7429 * HEIGHT;
								}break;
								case '5':
								{
									dx = 0.265 * WIDTH;
									dy = 0.39 * HEIGHT;
								}break;
								default: break;
								}

								//el puerto define que imagen es
								/*switch (board->all_the_sea_frames[i].getPorts().port1.port)
								{
								case ports::ANY:
								{
									img = ANY_PORT;
								}break;
								case ports::BRICK:
								{
									img = BRICK_PORT;
								}break;
								case ports::GRAIN:
								{
									img = GRAIN_PORT;
								}break;
								case ports::LUMBER:
								{
									img = WOOD_PORT;
								}break;
								case ports::ORE:
								{
									img = STONE_PORT;
								}break;
								case ports::WOOL:
								{
									img = WOOL_PORT;
								}break;
								default:
								{

								}break;
								}*/

								al_draw_scaled_rotated_bitmap(Frames[i], middle_x, middle_y, dx, dy, x_scale, y_scale, angle, NULL);
								al_flip_display();

							}

							for (int i = 0; i < TERRAIN_HEXES; i++)
							{


								float middle_x = HEX_WIDTH / 2.0;
								float middle_y = HEX_HEIGHT / 2.0;

								float x_scale = 102.5 / HEX_WIDTH;
								float y_scale = 112.5 / HEX_HEIGHT;

								float dx = 0, dy = 0;
								//depende de que posicion sea es donde se dibuja
								switch ('A' + i)
								{
								case 'A':
								{
									dx = 0.5 * WIDTH - 103.0;
									dy = 0.15 * HEIGHT + 0.295 * FRAME_HEIGHT;
								}break;
								case 'B':
								{
									dx = 0.5 * WIDTH;
									dy = 0.15 * HEIGHT + 0.295 * FRAME_HEIGHT;
								}break;
								case 'C':
								{
									dx = 0.5 * WIDTH + 103.0;
									dy = 0.15 * HEIGHT + 0.295 * FRAME_HEIGHT;
								}break;
								case 'D':
								{
									dx = ((0.5 * WIDTH - 2.0 * 102.5) + (0.5 * WIDTH - 103.0)) / 2.0;
									dy = ((0.15 * HEIGHT + 0.295 * FRAME_HEIGHT) + (0.5 * HEIGHT + 3.0)) / 2.0;
								}break;
								case 'E':
								{
									dx = ((0.5 * WIDTH - 103.0) + 0.5 * WIDTH) / 2.0;
									dy = ((0.15 * HEIGHT + 0.295 * FRAME_HEIGHT) + (0.5 * HEIGHT + 3.0)) / 2.0;
								}break;
								case 'F':
								{
									dx = (0.5 * WIDTH + (0.5 * WIDTH + 103.0)) / 2.0;
									dy = ((0.15 * HEIGHT + 0.295 * FRAME_HEIGHT) + (0.5 * HEIGHT + 3.0)) / 2.0;
								}break;
								case 'G':
								{
									dx = ((0.5 * WIDTH + 103.0) + (0.5 * WIDTH + 2.0 * 102.5)) / 2.0;
									dy = ((0.15 * HEIGHT + 0.295 * FRAME_HEIGHT) + (0.5 * HEIGHT + 3.0)) / 2.0;
								}break;
								case 'H':
								{
									dx = 0.5 * WIDTH - 2.0 * 102.5;
									dy = 0.5 * HEIGHT + 3.0;
								}break;
								case 'I':
								{
									dx = 0.5 * WIDTH - 103.0;
									dy = 0.5 * HEIGHT + 3.0;
								}break;
								case 'J':
								{
									dx = 0.5 * WIDTH;
									dy = 0.5 * HEIGHT + 3.0;
								}break;
								case 'K':
								{
									dx = 0.5 * WIDTH + 103.0;
									dy = 0.5 * HEIGHT + 3.0;
								}break;
								case 'L':
								{
									dx = 0.5 * WIDTH + 2.0 * 102.5;
									dy = 0.5 * HEIGHT + 3.0;
								}break;
								case 'M':
								{
									dx = ((0.5 * WIDTH - 2.0 * 102.5) + (0.5 * WIDTH - 103.0)) / 2.0;
									dy = ((0.5 * HEIGHT + 3.0) + (0.8586 * HEIGHT - 1 * (0.295 * FRAME_HEIGHT))) / 2.0;
								}break;
								case 'N':
								{
									dx = ((0.5 * WIDTH - 103.0) + 0.5 * WIDTH) / 2.0;
									dy = ((0.5 * HEIGHT + 3.0) + (0.8586 * HEIGHT - 1 * (0.295 * FRAME_HEIGHT))) / 2.0;
								}break;
								case 'O':
								{
									dx = (0.5 * WIDTH + (0.5 * WIDTH + 103.0)) / 2.0;
									dy = ((0.5 * HEIGHT + 3.0) + (0.8586 * HEIGHT - 1 * (0.295 * FRAME_HEIGHT))) / 2.0;
								}break;
								case 'P':
								{
									dx = ((0.5 * WIDTH + 103.0) + (0.5 * WIDTH + 2.0 * 102.5)) / 2.0;
									dy = ((0.5 * HEIGHT + 3.0) + (0.8586 * HEIGHT - 1 * (0.295 * FRAME_HEIGHT))) / 2.0;
								}break;
								case 'Q':
								{
									dx = 0.5 * WIDTH - 103.0;
									dy = 0.8586 * HEIGHT - 1 * (0.295 * FRAME_HEIGHT);
								}break;
								case 'R':
								{
									dx = 0.5 * WIDTH;
									dy = 0.8586 * HEIGHT - 1 * (0.295 * FRAME_HEIGHT);
								}break;
								case 'S':
								{
									dx = 0.5 * WIDTH + 103.0;
									dy = 0.8586 * HEIGHT - 1 * (0.295 * FRAME_HEIGHT);
								}break;
								default: break;
								}

								int img = 0;
								//el recurso define que imagen es
								/*switch (board->all_the_hexes[i].getResource())
								{
								case DESERT:
								{
									img = DESERT1;
								}break;
								case ORE:
								{
									img = ORE1;
								}break;
								case GRAIN:
								{
									img = GRAIN1;
								}break;
								case LUMBER:
								{
									img = LUMBER1;
								}break;
								case WOOL:
								{
									img = WOOL1;
								}break;
								case BRICK:
								{
									img = BRICK1;
								}break;
								default:
								{

								}break;
								}*/

								img = rand() % 6;

								al_draw_scaled_rotated_bitmap(Hexes[img], middle_x, middle_y, dx, dy, x_scale, y_scale, 0.0, NULL);

								int img2 = rand() % 10;

								al_draw_scaled_rotated_bitmap(Tokens[img2], al_get_bitmap_width(Tokens[img2]) / 2.0, al_get_bitmap_height(Tokens[img2]) / 2.0, dx, dy, 1.0 / 4.0, 1.0 / 4.0, 0.0, NULL);

								al_flip_display();
							}

							unsigned int dice1 = rand() % 6 + 1;
							unsigned int dice2 = rand() % 6 + 1;

							float dx1, dy1, dx2, dy2;

							dx1 = 0.9 * WIDTH - 5.0 - al_get_bitmap_width(Dices[dice1 - 1]) / 2.0;
							dx2 = 0.9 * WIDTH + 5.0 + al_get_bitmap_width(Dices[dice1 - 1]) / 2.0;

							dy1 = 0.65 * HEIGHT;
							dy2 = dy1;

							dice1 = rand() % 6 + 1;
							dice2 = rand() % 6 + 1;

							al_draw_scaled_rotated_bitmap(Dices[dice1 - 1], al_get_bitmap_width(Dices[dice1 - 1]) / 2.0, al_get_bitmap_height(Dices[dice1 - 1]) / 2.0, dx1, dy1, 1.0, 1.0, 0.0, NULL);
							al_draw_scaled_rotated_bitmap(Dices[dice2 - 1], al_get_bitmap_width(Dices[dice2 - 1]) / 2.0, al_get_bitmap_height(Dices[dice2 - 1]) / 2.0, dx2, dy2, 1.0, 1.0, 0.0, NULL);

							al_flip_display();

							float cx = al_get_bitmap_width(ResourceCards[0]) / 2.0;
							float cy = al_get_bitmap_height(ResourceCards[0]) / 2.0;

							float dx = 0.06 * WIDTH;
							float dy = 0.2 * HEIGHT;
							for (int i = 0; i < 5; i++)
							{
								al_draw_scaled_rotated_bitmap(ResourceCards[i], cx, cy, dx, dy + i * cx * 1.25, 0.4, 0.4, 0.0, NULL);

								al_draw_filled_circle(dx + cx * 0.6, dy + i * cx * 1.25, 10, al_map_rgb(255, 243, 154));
								al_draw_circle(dx + cx * 0.6, dy + i * cx * 1.25, 10, al_map_rgb(0, 0, 0), 3);
								switch (i)
								{
								case ORE1:
								{
									al_draw_text(font, al_map_rgb(0, 0, 0), dx + cx * 0.6 - 5.0, dy + i * cx * 1.25 - 9.0, ALLEGRO_ALIGN_LEFT, to_string(i).c_str());
								}break;
								case GRAIN1:
								{
									al_draw_text(font, al_map_rgb(0, 0, 0), dx + cx * 0.6 - 5.0, dy + i * cx * 1.25 - 9.0, ALLEGRO_ALIGN_LEFT, to_string(i).c_str());
								}break;
								case WOOL1:
								{
									al_draw_text(font, al_map_rgb(0, 0, 0), dx + cx * 0.6 - 5.0, dy + i * cx * 1.25 - 9.0, ALLEGRO_ALIGN_LEFT, to_string(i).c_str());
								}break;
								case LUMBER1:
								{
									al_draw_text(font, al_map_rgb(0, 0, 0), dx + cx * 0.6 - 5.0, dy + i * cx * 1.25 - 9.0, ALLEGRO_ALIGN_LEFT, to_string(i).c_str());
								}break;
								case BRICK1:
								{
									al_draw_text(font, al_map_rgb(0, 0, 0), dx + cx * 0.6 - 5.0, dy + i * cx * 1.25 - 9.0, ALLEGRO_ALIGN_LEFT, to_string(i).c_str());
								}break;
								default:break;
								}
							}
							al_flip_display();


							float cx_road = al_get_bitmap_width(Roads[PLAYER]) / 2.0;
							float cy_road = al_get_bitmap_height(Roads[PLAYER]) / 2.0;

							float cx_city = al_get_bitmap_width(Settlements[PLAYER]) / 2.0;
							float cy_city = al_get_bitmap_height(Settlements[PLAYER]) / 2.0;

							float cx_settlement = al_get_bitmap_width(Houses[PLAYER]) / 2.0;
							float cy_settlement = al_get_bitmap_height(Houses[PLAYER]) / 2.0;


							al_draw_scaled_rotated_bitmap(Roads[PLAYER], cx_road, cy_road, 0.06 * WIDTH, 0.925 * HEIGHT, 0.15, 0.15, 0.0, NULL);
							al_draw_filled_circle(0.06 * WIDTH, 0.86 * HEIGHT, 10, al_map_rgb(255, 243, 154));
							al_draw_circle(0.06 * WIDTH, 0.86 * HEIGHT, 10, al_map_rgb(0, 0, 0), 3);
							al_draw_text(font, al_map_rgb(0, 0, 0), 0.06 * WIDTH - 5.0, 0.86 * HEIGHT - 9.0, ALLEGRO_ALIGN_LEFT, to_string(1).c_str());

							al_draw_scaled_rotated_bitmap(Settlements[PLAYER], cx_city, cy_city, 0.06 * WIDTH + 0.5 * (cx_settlement + cx_city), 0.925 * HEIGHT, 0.15, 0.15, 0.0, NULL);
							al_draw_filled_circle(0.06 * WIDTH + 0.5 * (cx_settlement + cx_city), 0.86 * HEIGHT, 10, al_map_rgb(255, 243, 154));
							al_draw_circle(0.06 * WIDTH + 0.5 * (cx_settlement + cx_city), 0.86 * HEIGHT, 10, al_map_rgb(0, 0, 0), 3);
							al_draw_text(font, al_map_rgb(0, 0, 0), 0.06 * WIDTH + 0.5 * (cx_settlement + cx_city) - 5.0, 0.86 * HEIGHT - 9.0, ALLEGRO_ALIGN_LEFT, to_string(1).c_str());


							al_draw_scaled_rotated_bitmap(Houses[PLAYER], cx_settlement, cy_settlement, 0.06 * WIDTH + cx_settlement * 0.5, 0.925 * HEIGHT, 0.15, 0.15, 0.0, NULL);
							al_draw_filled_circle(0.06 * WIDTH + cx_settlement * 0.5, 0.86 * HEIGHT, 10, al_map_rgb(255, 243, 154));
							al_draw_circle(0.06 * WIDTH + cx_settlement * 0.5, 0.86 * HEIGHT, 10, al_map_rgb(0, 0, 0), 3);
							al_draw_text(font, al_map_rgb(0, 0, 0), 0.06 * WIDTH + cx_settlement * 0.5 - 5.0, 0.86 * HEIGHT - 9.0, ALLEGRO_ALIGN_LEFT, to_string(1).c_str());

							al_draw_text(font, al_map_rgb(0, 0, 0), 0.775 * WIDTH, 0.75 * HEIGHT, ALLEGRO_ALIGN_LEFT, "PEPITO");

							al_draw_scaled_rotated_bitmap(Roads[OPPONENT], cx_road, cy_road, 0.75 * WIDTH, 0.925 * HEIGHT, 0.15, 0.15, 0.0, NULL);
							al_draw_filled_circle(0.75 * WIDTH, 0.86 * HEIGHT, 10, al_map_rgb(255, 243, 154));
							al_draw_circle(0.75 * WIDTH, 0.86 * HEIGHT, 10, al_map_rgb(0, 0, 0), 3);
							al_draw_text(font, al_map_rgb(0, 0, 0), 0.75 * WIDTH - 5.0, 0.86 * HEIGHT - 9.0, ALLEGRO_ALIGN_LEFT, to_string(1).c_str());

							al_flip_display();

							al_draw_scaled_rotated_bitmap(Settlements[OPPONENT], cx_city, cy_city, 0.75 * WIDTH + 0.5 * (cx_settlement + cx_city), 0.925 * HEIGHT, 0.15, 0.15, 0.0, NULL);
							al_draw_filled_circle(0.75 * WIDTH + 0.5 * (cx_settlement + cx_city), 0.86 * HEIGHT, 10, al_map_rgb(255, 243, 154));
							al_draw_circle(0.75 * WIDTH + 0.5 * (cx_settlement + cx_city), 0.86 * HEIGHT, 10, al_map_rgb(0, 0, 0), 3);
							al_draw_text(font, al_map_rgb(0, 0, 0), 0.75 * WIDTH + 0.5 * (cx_settlement + cx_city) - 5.0, 0.86 * HEIGHT - 9.0, ALLEGRO_ALIGN_LEFT, to_string(1).c_str());

							al_draw_scaled_rotated_bitmap(Houses[OPPONENT], cx_settlement, cy_settlement, 0.75 * WIDTH + cx_settlement * 0.5, 0.925 * HEIGHT, 0.15, 0.15, 0.0, NULL);
							al_draw_filled_circle(0.75 * WIDTH + cx_settlement * 0.5, 0.86 * HEIGHT, 10, al_map_rgb(255, 243, 154));
							al_draw_circle(0.75 * WIDTH + cx_settlement * 0.5, 0.86 * HEIGHT, 10, al_map_rgb(0, 0, 0), 3);
							al_draw_text(font, al_map_rgb(0, 0, 0), 0.75 * WIDTH + cx_settlement * 0.5 - 5.0, 0.86 * HEIGHT - 9.0, ALLEGRO_ALIGN_LEFT, to_string(1).c_str());

							al_flip_display();

							float cx_button, cy_button, dx_button, dy_button;
							cx_button = al_get_bitmap_width(ButtonMain) / 2.0;
							cy_button = al_get_bitmap_height(ButtonMain) / 2.0;

							dx_button = 0.9 * WIDTH;
							dy_button = 0.075 * HEIGHT;

							al_draw_scaled_rotated_bitmap(ButtonMain, cx_button, cy_button, dx_button, dy_button, 0.75, 0.75, 0, NULL);
							al_draw_text(font, al_map_rgb(0, 100, 95), dx_button - 25, dy_button - 7.5, ALLEGRO_ALIGN_LEFT, "Trade");
							//chequear cuanto va a ocupar la palabra con ese font
							al_draw_scaled_rotated_bitmap(ButtonMain, cx_button, cy_button, dx_button, dy_button + al_get_bitmap_height(ButtonMain), 0.75, 0.75, 0, NULL);
							al_draw_text(font, al_map_rgb(0, 100, 95), dx_button - 25, dy_button + al_get_bitmap_height(ButtonMain) - 7.5, ALLEGRO_ALIGN_LEFT, "Pass");

							al_draw_scaled_rotated_bitmap(ButtonMain, cx_button, cy_button, dx_button, dy_button + 2 * al_get_bitmap_height(ButtonMain), 0.75, 0.75, 0, NULL);
							al_draw_text(font, al_map_rgb(0, 100, 95), dx_button - 25, dy_button + 2 * al_get_bitmap_height(ButtonMain) - 7.5, ALLEGRO_ALIGN_LEFT, "Build");

							al_draw_scaled_rotated_bitmap(ButtonMain, cx_button, cy_button, dx_button, dy_button + 3 * al_get_bitmap_height(ButtonMain), 0.75, 0.75, 0, NULL);
							al_draw_text(font, al_map_rgb(0, 100, 95), dx_button - 25, dy_button + 3 * al_get_bitmap_height(ButtonMain) - 7.5, ALLEGRO_ALIGN_LEFT, "Exit");
							al_flip_display();
						}
						al_draw_scaled_rotated_bitmap(ButtonMain, cx_button, cy_button, dx_button, dy_button, 0.75, 0.75, 0, NULL);
						al_draw_text(font, al_map_rgb(0, 100, 95), dx_button - 25, dy_button - 7.5, ALLEGRO_ALIGN_LEFT, "Trade");
						//chequear cuanto va a ocupar la palabra con ese font
						al_draw_scaled_rotated_bitmap(ButtonMain, cx_button, cy_button, dx_button, dy_button + al_get_bitmap_height(ButtonMain), 0.75, 0.75, 0, NULL);
						al_draw_text(font, al_map_rgb(0, 100, 95), dx_button - 25, dy_button + al_get_bitmap_height(ButtonMain) - 7.5, ALLEGRO_ALIGN_LEFT, "Pass");

						al_draw_scaled_rotated_bitmap(ButtonMain, cx_button, cy_button, dx_button, dy_button + 2 * al_get_bitmap_height(ButtonMain), 0.75, 0.75, 0, NULL);
						al_draw_text(font, al_map_rgb(0, 100, 95), dx_button - 25, dy_button + 2 * al_get_bitmap_height(ButtonMain) - 7.5, ALLEGRO_ALIGN_LEFT, "Build");

						al_draw_scaled_rotated_bitmap(ButtonMain, cx_button, cy_button, dx_button, dy_button + 3 * al_get_bitmap_height(ButtonMain), 0.75, 0.75, 0, NULL);
						al_draw_text(font, al_map_rgb(0, 100, 95), dx_button - 25, dy_button + 3 * al_get_bitmap_height(ButtonMain) - 7.5, ALLEGRO_ALIGN_LEFT, "Exit");
						al_flip_display();
						chosen = Color_Buttons1;
					default: break;
					}
				}
				else if (chosen == Color_Nodes)
				{					
					click = "";
					al_unmap_rgb(al_get_pixel(chosen, event.mouse.x, event.mouse.y), &r, &g, &b);
					click += r;
					click += g;
					click += b;
					al_draw_filled_circle(event.mouse.x, event.mouse.y, 20, al_map_rgb(255, 255, 255));
					al_draw_text(font, al_map_rgb(0, 0, 0), event.mouse.x - 10, event.mouse.y - 5, ALLEGRO_ALIGN_LEFT, click.c_str());
					al_flip_display();
					chosen = Color_Buttons1;
				}
				else if (chosen == Color_Roads)
				{
					click = "";
					al_unmap_rgb(al_get_pixel(chosen, event.mouse.x, event.mouse.y), &r, &g, &b);
					click += r;
					click += g;
					click += b;
					al_draw_filled_circle(event.mouse.x, event.mouse.y, 20, al_map_rgb(0, 0, 0));
					al_draw_text(font, al_map_rgb(255, 255, 255), event.mouse.x - 10, event.mouse.y - 5, ALLEGRO_ALIGN_LEFT, click.c_str());
					al_flip_display();
					chosen = Color_Buttons1;
				}
			}
			if (event.type == ALLEGRO_EVENT_KEY_DOWN)
			{
				switch (event.keyboard.keycode)
				{
				case ALLEGRO_KEY_ENTER:
					exit = true;
					break;

				default: break;
				}

			}
		}
	}

	delete[] Frames;
	delete[] Hexes;
	delete[] Tokens;
	delete[] Dices;
	delete[] ResourceCards;
	delete[] Houses;
	delete[] Settlements;
	delete[] Roads;

	al_destroy_bitmap(Color_Nodes);
	al_uninstall_mouse();
	al_uninstall_keyboard();

	al_destroy_timer(timer);
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);
	al_destroy_font(font);

	return 0;
}