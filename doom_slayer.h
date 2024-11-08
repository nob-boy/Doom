#pragma once
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <stdio.h>

ALLEGRO_BITMAP* winchester = NULL;

void declara_slayer() {
	winchester = al_load_bitmap("./atirandowinchester.png");
	if (!winchester) {
		printf("erro ao carregar winchester");
	}
}
float escala_x = 3.0f;
float escala_y = 3.0f;
int pos_x = 500;
int pos_y = 853;


void armado() {

    // Desenha uma região do bitmap na tela
	al_draw_scaled_bitmap(winchester, 0, 0, 88, 147, 500,600, 88 * escala_x, 147 * escala_y, 0);
}

void destroi_doom_slayer() {
	al_destroy_bitmap(winchester);
}
