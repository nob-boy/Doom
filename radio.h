#pragma once

#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

ALLEGRO_SAMPLE* MainTheme = NULL;
ALLEGRO_SAMPLE_ID theme_id;
bool tocar = false;

void musicas() {
	MainTheme = al_load_sample("./radio/MainTheme.wav");
}


void radio() {

	if (!tocar) {
		al_play_sample(MainTheme, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, &theme_id);
		tocar = true;
	}
}

void pausar_musica() {

	if (tocar) {
		al_stop_sample(&theme_id);
		tocar = false;
	}
}

void destroi_musica() {
	al_destroy_sample(MainTheme);
}