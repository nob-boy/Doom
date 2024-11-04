#pragma once
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>



ALLEGRO_BITMAP* devspng = NULL; // declara as imagem
ALLEGRO_BITMAP* doompng = NULL;
ALLEGRO_BITMAP* cursopng = NULL;
ALLEGRO_BITMAP* uepgpng = NULL;



void introducao_itens() {
    devspng = al_load_bitmap("./intro/devs.png");
    doompng = al_load_bitmap("./intro/inidoom.jpg");
    cursopng = al_load_bitmap("./intro/disc.png");
    uepgpng = al_load_bitmap("./intro/uepg.png");
    
}

void introducao(int *seg) {

    //int timer_count = al_get_timer_count(timer); // Obtém o tempo atual

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
}
