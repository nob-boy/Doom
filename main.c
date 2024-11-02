#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include "iniciacao.h"
#include "radio.h"
#include "menu.h"

int main() {

    bool play = true;
    int tempo = 0;
    bool mostra_menu = false;

    al_init();
    al_init_font_addon();
    al_init_image_addon();
    al_install_audio(); // Inicializa o sistema de áudio
    al_init_acodec_addon(); // Inicializa os codecs de áudio
    al_reserve_samples(1); // Reserva uma amostra de áudio
    al_install_keyboard();//para detectar as teclas

    ALLEGRO_DISPLAY* display = al_create_display(1000, 1000); // Cria uma janela de 1000x1000
    al_set_window_position(display, 200, 30); // Posição inicial da janela

    ALLEGRO_TIMER* timer = al_create_timer(1.0 / 60.0); // Timer para 60 FPS
    ALLEGRO_EVENT_QUEUE* event_queue = al_create_event_queue(); // Fila de eventos
    al_register_event_source(event_queue, al_get_display_event_source(display)); // Eventos de display
    al_register_event_source(event_queue, al_get_timer_event_source(timer)); // Eventos de timer
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_start_timer(timer);  

    musicas();
    introducao_itens();
    itens_menu();


    while (true) {
        ALLEGRO_EVENT event;
        al_wait_for_event(event_queue, &event);

        if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) { // Fecha ao clicar no botão de fechar
            break;
        }

        al_clear_to_color(al_map_rgb(0, 0, 0)); // Limpa a tela

       
        if (tempo < 1700) {
            introducao(timer); //introdução

        }
        else {

                iniciar_menu(timer);   

                if (mostra_menu) {
                    Menu();
                }
                if (event.type == ALLEGRO_EVENT_KEY_DOWN && event.keyboard.keycode == ALLEGRO_KEY_SPACE) {
                    mostra_menu = true;
                }
           
        }
/*
        
        if (play) {
            radio();
        }

        if (event.type == ALLEGRO_EVENT_KEY_DOWN && event.keyboard.keycode == ALLEGRO_KEY_UP) {
            if (play) {
                pausar_musica();
            }
            else {
                radio();
            }
            play = !play; // Alterna o estado de 'play' entre true e false
        }*/
        
        
        al_flip_display(); // Atualiza a tela

        if (event.type == ALLEGRO_EVENT_TIMER) {
            tempo++;
        }
    }

    destroi_menu();
    destroi_introducao();
    destroi_musica();
    al_destroy_display(display);
    al_destroy_event_queue(event_queue);
    al_destroy_timer(timer);

    return 0;
}
