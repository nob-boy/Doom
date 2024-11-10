#pragma once
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/keyboard.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>


ALLEGRO_BITMAP* menu = NULL;
ALLEGRO_BITMAP* iniciar_animacao = NULL;
ALLEGRO_BITMAP* iniciar = NULL;
extern ALLEGRO_AUDIO_STREAM* E1M1 = NULL;

void itens_menu() {
    iniciar_animacao = al_load_bitmap("./menu/iniciar.jpg");
    menu = al_load_bitmap("./menu/menu.png");
    iniciar = al_load_bitmap("./menu/inic.jpg");
    E1M1 = al_load_audio_stream("./menu/E1M1.wav", 4, 1024);
}

void iniciar_menu(int* seg) {
    int frame;

    if (*seg < 15) {

        frame = (*seg - 10) * 2 % 5;
        al_draw_bitmap_region(iniciar_animacao, frame * 1000, 0, 1000, 1000, 0, 0, 0);

    }
    if (*seg > 12) {
        al_draw_bitmap(iniciar, 0, 0, 0);
    }
}

float vol = 0.2f;

void Menu(int* frame) {

    int current_x = (*frame % 2) * 1000;  // Controle horizontal (2 sprites por linha)
    int current_y = (*frame / 2) * 1000;  // Controle vertical (3 linhas)

    al_detach_audio_stream(mainTheme); // Para a música anterior

    // Define e inicia o áudio do menu, com loop e controle de volume
    al_attach_audio_stream_to_mixer(E1M1, al_get_default_mixer());
    al_set_audio_stream_playmode(E1M1, ALLEGRO_PLAYMODE_LOOP);
    al_set_audio_stream_gain(E1M1, vol);

    al_draw_bitmap_region(menu, current_x, current_y, 1000, 1000, 0, 0, 0);
}

void destroi_menu() {
    al_destroy_bitmap(menu);
    al_destroy_bitmap(iniciar_animacao);
    al_destroy_bitmap(iniciar);
    al_destroy_audio_stream(E1M1);
}