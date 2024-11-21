#pragma once
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <stdio.h>

ALLEGRO_BITMAP* winchester = NULL;
ALLEGRO_SAMPLE* tiro = NULL;
bool atirando = false; 
int quadro_atual = 0; 
double tempo_ultimo_quadro = 0.0; 
#define NUM_QUADROS 16 

void declara_slayer() {
    winchester = al_load_bitmap("./arma1.png");
    if (!winchester) {
        printf("erro ao carregar winchester\n");
    }
    tiro = al_load_sample("./tiro.wav");
    if (!tiro) {
        printf("erro ao carregar tiro");
        al_destroy_bitmap(winchester);
    }
}

float escala_x = 5.0f;
float escala_y = 5.0f;
int pos_x = 500;
int pos_y = 600;


void armado(bool* keys) {
    double tempo_atual = al_get_time(); 

    if (keys[ALLEGRO_KEY_SPACE]) {
        if (!atirando) { 
            atirando = true;
            quadro_atual = 0;
            tempo_ultimo_quadro = tempo_atual; 
            al_play_sample(tiro, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL); 
        }
    }

    if (atirando) {
        if (tempo_atual - tempo_ultimo_quadro >= 0.1) { 
            quadro_atual++;
            tempo_ultimo_quadro = tempo_atual; 

            if (quadro_atual >= NUM_QUADROS) {
                quadro_atual = 0;
                atirando = false; 
            }
        }
    }

    al_draw_scaled_bitmap(
        winchester,
        quadro_atual * 95, 0, 95, 89, 
        pos_x, pos_y, 95 * escala_x, 89 * escala_y,
        0
    );
}

void destroi_doom_slayer() {
    al_destroy_bitmap(winchester);
    al_destroy_sample(tiro);
}
