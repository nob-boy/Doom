#pragma once
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/keyboard.h>

ALLEGRO_BITMAP* menu = NULL;
ALLEGRO_BITMAP* iniciar_animacao = NULL;
ALLEGRO_BITMAP* iniciar = NULL;

void itens_menu() {
    iniciar_animacao = al_load_bitmap("./menu/iniciar.jpg");
    menu = al_load_bitmap("./menu/menu.png");
    iniciar = al_load_bitmap("./menu/inic.jpg");
}

void iniciar_menu(ALLEGRO_TIMER* timer) {
    int frame;
    int timer_count = al_get_timer_count(timer);

    if (timer_count < 2500) {
        frame = (timer_count - 1700) / 20;
        al_draw_bitmap_region(iniciar_animacao, frame * 1000, 0, 1000, 1000, 0, 0, 0);
    }
    if (timer_count > 1800) {
        al_draw_bitmap(iniciar, 0, 0, 0);
    }
}

void Menu(int* frame) {
    int current_x = (*frame % 2) * 1000;  // Controle horizontal (2 sprites por linha)
    int current_y = (*frame / 2) * 1000;  // Controle vertical (3 linhas)

    al_draw_bitmap_region(menu, current_x, current_y, 1000, 1000, 0, 0, 0);
}

void destroi_menu() {
    al_destroy_bitmap(menu);
    al_destroy_bitmap(iniciar_animacao);
    al_destroy_bitmap(iniciar);
}
