#pragma once
#include <allegro5/allegro.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <stdio.h>
#include "menu.h"

ALLEGRO_AUDIO_STREAM* dogma = NULL;
ALLEGRO_AUDIO_STREAM* TheOnly = NULL;
ALLEGRO_AUDIO_STREAM* bfg = NULL;


void declara_musicas() {
	
	TheOnly = al_load_audio_stream("./radio/TheOnly.wav", 4, 1024);
	dogma = al_load_audio_stream("./radio/theme.wav", 4, 1024);
	bfg = al_load_audio_stream("./radio/bfg.ogg", 4, 1024);
	
}

float volume = 0.5f;

void radio(int* seg_jogo) {

	if (*seg_jogo < 70) {
		al_detach_audio_stream(E1M1); // Para a música anterior
		al_attach_audio_stream_to_mixer(dogma, al_get_default_mixer());
		al_set_audio_stream_playmode(dogma, ALLEGRO_PLAYMODE_ONCE);
		al_set_audio_stream_gain(dogma, volume);
	}

	else if ((*seg_jogo > 70) && (*seg_jogo <= 509)) {
		al_detach_audio_stream(dogma); // Para a música anterior
		al_attach_audio_stream_to_mixer(bfg, al_get_default_mixer());
		al_set_audio_stream_playmode(bfg, ALLEGRO_PLAYMODE_ONCE);
		al_set_audio_stream_gain(bfg, volume);
	}
	else if ((*seg_jogo > 509) && (*seg_jogo <= 919)) {
		al_detach_audio_stream(dogma); // Para a música anterior
		al_attach_audio_stream_to_mixer(TheOnly, al_get_default_mixer());
		al_set_audio_stream_playmode(TheOnly, ALLEGRO_PLAYMODE_ONCE);
		al_set_audio_stream_gain(TheOnly, volume);

	}
}


void destroi_musica() {

	al_destroy_audio_stream(dogma);
	al_destroy_audio_stream(TheOnly);
	al_destroy_audio_stream(bfg);

}


