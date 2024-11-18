#pragma once
#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

ALLEGRO_BITMAP* credito = NULL;

void declara_credito() {
	credito = al_load_bitmap("./cre.jpg");
	if (!credito) {
		printf("ERRO AO INICIAR CREDITO");
	}
}

void creditos() {

	al_draw_bitmap(credito, 0, 0, 0);

}

void destroi_credito() {
	al_destroy_bitmap(credito);
}