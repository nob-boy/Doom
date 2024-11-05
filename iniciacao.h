#pragma once
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

ALLEGRO_BITMAP* devspng = NULL; // declara as imagens
ALLEGRO_BITMAP* doompng = NULL;
ALLEGRO_BITMAP* cursopng = NULL;
ALLEGRO_BITMAP* uepgpng = NULL;
ALLEGRO_AUDIO_STREAM* mainTheme = NULL;

void introducao_itens() {
    devspng = al_load_bitmap("./intro/devs.png");
    doompng = al_load_bitmap("./intro/inidoom.jpg");
    cursopng = al_load_bitmap("./intro/disc.png");
    uepgpng = al_load_bitmap("./intro/uepg.png");
    mainTheme = al_load_audio_stream("./intro/MainTheme.wav", 4, 1024);
}

void introducao(int* seg) {
    al_attach_audio_stream_to_mixer(mainTheme, al_get_default_mixer());
    al_set_audio_stream_playmode(mainTheme, ALLEGRO_PLAYMODE_LOOP);

    if (*seg < 2) {
        al_draw_bitmap(doompng, 0, 0, 0);
    }
    else if (*seg < 4) {
        al_draw_bitmap(devspng, 0, 0, 0);
    }
    else if (*seg < 6) {
        al_draw_bitmap(cursopng, 0, 0, 0);
    }
    else if (*seg < 10) {
        int frame_index = (*seg - 6) % 5; // Calcula qual sprite deve ser desenhado
        al_draw_bitmap_region(uepgpng, frame_index * 1000, 0, 1000, 1000, 0, 0, 0);
    }
}

void destroi_introducao() {
    al_destroy_bitmap(doompng);
    al_destroy_bitmap(devspng);
    al_destroy_bitmap(cursopng);
    al_destroy_bitmap(uepgpng);
    al_destroy_audio_stream(mainTheme);
}
