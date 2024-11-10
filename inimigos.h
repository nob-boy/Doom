#pragma once
#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>

ALLEGRO_BITMAP* inimigo = NULL;

int pos_X = 400;
int pos_Y = 0;

void declara_inimigo() {
	inimigo = al_load_bitmap("./inimigo.png");
	if (!inimigo) {
		printf("erro ao carregar inimigo");
	}
}
int i = 0;

void desenha_inimigo(int *seg_jogo) {
	al_draw_bitmap(inimigo, pos_X, pos_Y, 0);

	
	if (pos_Y < 600) {
		pos_Y += 1;  // Move o inimigo para baixo
	}
	
}

void destroi_inimigo() {
	al_destroy_bitmap(inimigo);
}