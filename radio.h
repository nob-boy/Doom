#pragma once

#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <stdio.h>

ALLEGRO_SAMPLE* dogma = NULL;

void declara_musicas() {
	
	dogma = al_load_sample("./radio/theme.wav");
	if (!dogma) {
		printf("erro ao carregar");
	}
}


void radio() {

		al_play_sample(dogma, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL);
	
}

void destroi_musica() {

	al_destroy_sample(dogma);
}