#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/keyboard.h>
#include "iniciacao.h"
#include "creditos.h"
#include "radio.h"
#include "menu.h"
#include "jogo.h"

#define SCREEN_WIDTH 1000
#define SCREEN_HEIGHT 1000
bool keys[ALLEGRO_KEY_MAX] = { false };

int main() {
    bool play = true;
    int tempo = 0;
    bool mostra_menu = false;
    bool mostra_devs = false;
    int frame = 0;
    int seg = 0;
    int seg_jogo = 0;
    bool janela = true;
    bool jogando = false;

    Player player = { 3.0, 3.0, -1.0, 0.0, 0.0, 0.66 }; // Defina o player

    al_init();
    al_init_font_addon();
    al_init_image_addon();
    al_install_audio();
    al_init_acodec_addon();
    al_reserve_samples(1);
    al_install_keyboard();
    al_init_primitives_addon();

    ALLEGRO_DISPLAY* display = al_create_display(SCREEN_WIDTH, SCREEN_HEIGHT);
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

        // Captura eventos de teclado
        if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
            keys[event.keyboard.keycode] = true;
        }
        if (event.type == ALLEGRO_EVENT_KEY_UP) {
            keys[event.keyboard.keycode] = false;
        }

        al_clear_to_color(al_map_rgb(0, 0, 0));

        if (tempo % 60 == 0) {
            seg++;
        }

        if (seg < 10) {
            introducao(&seg);
        }
        else {
            iniciar_menu(&seg);

            if (jogando) {
                if (tempo % 60 == 0) {
                    seg_jogo++;
                }
                radio(&seg_jogo);
                doom(&player, keys);

                if (mostra_devs) {
                    devs();
                }
                if (keys[ALLEGRO_KEY_ESCAPE]) {
                    mostra_devs = false;
                    mostra_menu = true;
                }
            }

            if (mostra_menu) {
                if (keys[ALLEGRO_KEY_S]) {
                    frame = (frame + 1) % 6;
                }
                if (keys[ALLEGRO_KEY_W]) {
                    frame = (frame + 5) % 6;
                }
                Menu(&frame);

                if (keys[ALLEGRO_KEY_ENTER]) {
                    switch (frame) {
                    case 0: // Iniciar jogo
                        jogando = true;
                        mostra_menu = false;
                        break;
                    case 2: // Sair do jogo
                        janela = false;
                        break;
                    case 4: // Mostrar desenvolvedores
                        mostra_devs = true;
                        mostra_menu = false;
                        break;
                    default:
                        break;
                    }
                }
            }

            if (keys[ALLEGRO_KEY_SPACE]) {
                mostra_menu = true;
            }
        }

        // Atualiza a tela
        al_flip_display();

        if (event.type == ALLEGRO_EVENT_TIMER) {
            tempo++;
        }
    }

    // Libera os recursos
    destroi_devs();
    destroi_menu();
    destroi_introducao();
    destroi_musica();
    al_destroy_display(display);
    al_destroy_event_queue(event_queue);
    al_destroy_timer(timer);

    return 0;
}
