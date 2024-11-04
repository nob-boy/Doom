#pragma once

#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <stdio.h>

ALLEGRO_AUDIO_STREAM* dogma = NULL;
ALLEGRO_AUDIO_STREAM* TheOnly = NULL;
ALLEGRO_AUDIO_STREAM* E1M1 = NULL;
ALLEGRO_AUDIO_STREAM* mainTheme = NULL;
int min = 0;


void declara_musicas() {
	
	TheOnly = al_load_audio_stream("./radio/TheOnly.wav", 4, 1024);
	dogma = al_load_audio_stream("./radio/theme.wav", 4, 1024);
	E1M1 = al_load_audio_stream("./radio/E1M1.wav", 4, 1024);
	mainTheme = al_load_audio_stream("./radio/MainTheme.wav", 4, 1024);

	if (!dogma) {
		printf("erro ao carregar  a musica dogma");
	}
	if (!TheOnly) {
		printf("erro ao carregar  a musica The Only Thing They Fear Is You");
	}
	if (!E1M1) {
		printf("erro ao carregar  a musica E1M1");
	}
	if (!mainTheme) {
		printf("erro ao carregar  a musica Main Theme");
	}
}


void radio(int *seg) {


	//liga o stream no mixer
	if (*seg <= 70) {
			al_attach_audio_stream_to_mixer(dogma, al_get_default_mixer());
			al_set_audio_stream_playmode(dogma, ALLEGRO_PLAYMODE_ONCE);
		
	}
	else if ((*seg > 70) && (*seg <= 417)) {
		// Para o stream anterior (dogma)
			al_detach_audio_stream(dogma); // Para a música anterior
		
			al_attach_audio_stream_to_mixer(TheOnly, al_get_default_mixer());

			al_set_audio_stream_playmode(TheOnly, ALLEGRO_PLAYMODE_ONCE);
		   
	}
	else if ((*seg > 417) && (*seg < 517)) {
		al_detach_audio_stream(TheOnly); // Para a música anterior

		al_attach_audio_stream_to_mixer(E1M1, al_get_default_mixer());

		al_set_audio_stream_playmode(E1M1, ALLEGRO_PLAYMODE_ONCE);
	}
	else if ((*seg > 517) && (*seg < 817)) {
		al_detach_audio_stream(E1M1); // Para a música anterior

		al_attach_audio_stream_to_mixer(mainTheme, al_get_default_mixer());

		al_set_audio_stream_playmode(mainTheme, ALLEGRO_PLAYMODE_ONCE);
	}
	
}



void destroi_musica() {

	al_destroy_audio_stream(dogma);
	al_destroy_audio_stream(E1M1);
	al_destroy_audio_stream(TheOnly);
	al_destroy_audio_stream(mainTheme);
}
