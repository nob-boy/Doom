#pragma once
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

ALLEGRO_BITMAP* teste = NULL;

void declara_devs() {
	teste = al_load_bitmap("./creditos/teste.jpg");
}

void devs() {

	al_draw_bitmap(teste, 0, 0, 0);

}

void destroi_devs() {

}