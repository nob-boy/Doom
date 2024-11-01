#pragma once
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

ALLEGRO_BITMAP* devspng = NULL; // declara as imagem
ALLEGRO_BITMAP* doompng = NULL;
ALLEGRO_BITMAP* cursopng = NULL;
ALLEGRO_BITMAP* uepgpng = NULL;
ALLEGRO_SAMPLE* theme = NULL;

void introducao_itens() {
    devspng = al_load_bitmap("./devs.png");
    doompng = al_load_bitmap("./doom.jpg");
    cursopng = al_load_bitmap("./disc.png");
    uepgpng = al_load_bitmap("./uepg.png");
    theme = al_load_sample("./theme.wav");
}

void introducao(ALLEGRO_TIMER* timer) {
   
        al_play_sample(theme, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL);
     

    int timer_count = al_get_timer_count(timer); // Obtém o tempo atual

    if (timer_count < 400) {
        al_draw_bitmap(doompng, 0, 0, 0);
    }
    else if (timer_count < 800) {
        al_draw_bitmap(devspng, 0, 0, 0);
    }
    else if (timer_count < 1200) {
        al_draw_bitmap(cursopng, 0, 0, 0);
    }
    else if (timer_count < 1600) {
        int frame_index = (timer_count - 1200) / 100; // Calcula qual sprite deve ser desenhado
        al_draw_bitmap_region(uepgpng, frame_index * 1000, 0, 1000, 1000, 0, 0, 0);
    }
}

void destroi_introducao() {
    al_destroy_sample(theme);
    al_destroy_bitmap(doompng);
    al_destroy_bitmap(devspng);
    al_destroy_bitmap(cursopng);
    al_destroy_bitmap(uepgpng);
}
