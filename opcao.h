#pragma once
#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

ALLEGRO_BITMAP* opcao = NULL;

void declara_opcao() {
	opcao = al_load_bitmap("./opcoes.jpg");
}

void opcoes() {

	al_draw_bitmap(opcao, 0, 0, 0);

}

void destroi_opcao() {
	al_destroy_bitmap(opcao);
}