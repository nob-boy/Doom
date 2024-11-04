#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/keyboard.h>
#include "iniciacao.h"
#include "creditos.h"
#include "radio.h"
#include "menu.h"

int main() {

    bool play = true;
    int tempo = 0;
    bool mostra_menu = false;
    bool mostra_devs = false;
    int frame = 0; 

    int seg = 0;

    bool janela = true;

    al_init();
    al_init_font_addon();
    al_init_image_addon();
    al_install_audio();
    al_init_acodec_addon();
    al_reserve_samples(1);
    al_install_keyboard();

    ALLEGRO_DISPLAY* display = al_create_display(1000, 1000);
    al_set_window_position(display, 200, 30);

    ALLEGRO_TIMER* timer = al_create_timer(1.0 / 60.0);
    ALLEGRO_EVENT_QUEUE* event_queue = al_create_event_queue();
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_start_timer(timer);

    declara_musicas();
    introducao_itens();
    itens_menu();
    declara_devs();

    while (janela) {
        ALLEGRO_EVENT event;
        al_wait_for_event(event_queue, &event);

        if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            break;
        }

        al_clear_to_color(al_map_rgb(0, 0, 0));

        radio(&seg);

        if (tempo % 60 == 0) {
            seg++;
        }

        if (seg < 10) {
            introducao(&seg);
        }
        else {
                iniciar_menu(&seg);

                if (mostra_devs) {
                    devs();
                }
                if (event.type == ALLEGRO_EVENT_KEY_DOWN && event.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
                    mostra_devs = false; 
                    mostra_menu = true;
                }
           
            if (mostra_menu) {
                

                if (event.type == ALLEGRO_EVENT_KEY_DOWN && event.keyboard.keycode == ALLEGRO_KEY_S) {
                    frame = (frame + 1) % 6; 
                }
                if (event.type == ALLEGRO_EVENT_KEY_DOWN && event.keyboard.keycode == ALLEGRO_KEY_W) {
                    frame = (frame - 1) % 6;
                }
            
                    Menu(&frame);

                    if (event.keyboard.keycode == ALLEGRO_KEY_ENTER) {

                        switch (frame)
                        {
                        case 0:
                            break;
                        case 1:
                            break;
                        case 2:
                            janela = false;
                            break;
                        case 3:
                            break;
                        case 4:
                            mostra_devs = true;
                            mostra_menu = false;
                            break;
                        default:
                            break;
                        }
                    }
               
            }


            if (event.type == ALLEGRO_EVENT_KEY_DOWN && event.keyboard.keycode == ALLEGRO_KEY_SPACE) {

                mostra_menu = true;   
            }

        }

        al_flip_display();

        if (event.type == ALLEGRO_EVENT_TIMER) {
            tempo++;
        }
    }

    destroi_devs();
    destroi_menu();
    destroi_introducao();
    destroi_musica();
    al_destroy_display(display);
    al_destroy_event_queue(event_queue);
    al_destroy_timer(timer);

    return 0;
}
