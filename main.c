#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/keyboard.h>
#include "iniciacao.h"
#include "creditos.h"
#include "tutorial.h"
#include "opcao.h"
#include "radio.h"
#include "doom_slayer.h"
#include "menu.h"
#include "jogo.h"

#define SCREEN_WIDTH 1000
#define SCREEN_HEIGHT 1000
bool keys[ALLEGRO_KEY_MAX] = { false };

// Função para atualizar o frame do menu, evitando repetições rápidas
void atualizar_frame_menu(int* frame) {
    static bool w_pressionado = false;
    static bool s_pressionado = false;

    if (keys[ALLEGRO_KEY_S] && !s_pressionado) {
        *frame = (*frame + 1) % 6;
        s_pressionado = true;
    }
    else if (!keys[ALLEGRO_KEY_S]) {
        s_pressionado = false;
    }

    if (keys[ALLEGRO_KEY_W] && !w_pressionado) {
        *frame = (*frame - 1 + 6) % 6;
        w_pressionado = true;
    }
    else if (!keys[ALLEGRO_KEY_W]) {
        w_pressionado = false;
    }
}

int main() {
    bool play = true;
    int tempo = 0;
    bool mostra_menu = false;
    bool inicia_menu = true;
    bool mostra_devs = false;
    bool tutori = false;
    int frame = 0;
    int seg = 0;
    int seg_jogo = 0;
    bool janela = true;
    bool jogando = false;
    bool final = false;
    bool jogar = true;
    bool opc = false;

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
    declara_opcao();
    introducao_itens();
    itens_menu();
    declara_tuto();
    declara_credito();
    declara_slayer();
    declara_jogo();

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

        if (event.type == ALLEGRO_EVENT_TIMER) {
            tempo++;
            if (tempo % 60 == 0) {
                seg++;
            }
        }

        if (seg < 10) {
            introducao(&seg);
        }
        else if (mostra_devs) {
            // Exibição dos créditos
            creditos();

            // Voltar ao menu com ESC
            if (keys[ALLEGRO_KEY_ESCAPE]) {
                mostra_devs = false;
                mostra_menu = true;
            }
        }
        else if (tutori) {
            tutorial();

            // Voltar ao menu com ESC
            if (keys[ALLEGRO_KEY_ESCAPE]) {
                tutori = false;
                mostra_menu = true;
            }
        }
        else if (opc) {
            opcoes();

            // Voltar ao menu com ESC
            if (keys[ALLEGRO_KEY_ESCAPE]) {
                opc = false;
                mostra_menu = true;
            }
        }
        else if (jogando) {
            if (tempo % 60 == 0) {
                seg_jogo++;
            }

            al_clear_to_color(al_map_rgb(0, 0, 0));
            radio(&seg_jogo);
            doom(&player, keys, &seg_jogo, &final, &jogar);

            if (final) {
                jogando = false;
                mostra_menu = true;
            }

            if (keys[ALLEGRO_KEY_ESCAPE]) {
                jogando = false;
                mostra_menu = true;
            }
        }

        else if (mostra_menu) {
            atualizar_frame_menu(&frame);
            Menu(&frame);

            if (keys[ALLEGRO_KEY_ENTER]) {
                switch (frame) {
                case 0:
                    jogando = true;
                    jogar = true;
                    mostra_menu = false;
                    break;
                case 1:
                    opc = true;
                    mostra_menu = false;
                    break;
                case 2: // Sair do jogo
                    janela = false;
                    break;
                case 3: // Sair do jogo
                    tutori = true;
                    mostra_menu = false;
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
        else if (inicia_menu) {
            iniciar_menu(&seg);
            if (keys[ALLEGRO_KEY_SPACE]) {
                mostra_menu = true;
                inicia_menu = false;
            }
        }

        // Atualiza a tela
        al_flip_display();
    }

    // Libera os recursos
    destroi_introducao();
    destroi_doom_slayer();
    destroi_opcao();
    destroi_credito();
    destroi_tuto();
    destroi_menu();
    destroi_musica();
    destroi_jogo();
    al_destroy_display(display);
    al_destroy_event_queue(event_queue);
    al_destroy_timer(timer);

    return 0;
}