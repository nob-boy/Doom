#pragma once
#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

ALLEGRO_BITMAP* tut = NULL;

void declara_tuto() {
	tut = al_load_bitmap("./tutorial.jpg");
	if (!tut) {
		printf("ERRO AO INICIAR CREDITO");
	}
}

void tutorial() {

	al_draw_bitmap(tut, 0, 0, 0);

}

void destroi_tuto() {
	al_destroy_bitmap(tut);
}