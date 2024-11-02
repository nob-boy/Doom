#pragma once
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>

ALLEGRO_BITMAP* menu = NULL;
ALLEGRO_BITMAP* iniciar_animacao = NULL;
ALLEGRO_BITMAP* iniciar = NULL;

void itens_menu() {
	iniciar_animacao = al_load_bitmap("./menu/iniciar.jpg");
	menu = al_load_bitmap("./menu/menu.png");
	iniciar = al_load_bitmap("./menu/inic.jpg");
}

void iniciar_menu(ALLEGRO_TIMER* timer) {
	
	int pos_x = 0;
	int pos_y = 0;
	int frame;
	int timer_count = al_get_timer_count(timer);

	if (timer_count < 2500) {
		frame = (timer_count - 1700) / 20; // Calcula qual sprite deve ser desenhado
		al_draw_bitmap_region(iniciar_animacao, frame * 1000, 0, 1000, 1000, 0, 0, 0);
	}
	if (timer_count > 1800) {
		al_draw_bitmap(iniciar, 0, 0, 0);
	}
}

void Menu() {
	al_draw_bitmap(menu, 0, 0, 0);
}

void destroi_menu() {
	al_destroy_bitmap(menu);
	al_destroy_bitmap(iniciar_animacao);
	al_destroy_bitmap(iniciar);
}