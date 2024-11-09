#pragma once
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <stdio.h>

ALLEGRO_BITMAP* winchester = NULL;
ALLEGRO_SAMPLE* tiro = NULL;
bool atirando = false; // Flag para saber se está atirando
int quadro_atual = 0;   // Índice do quadro atual da animação
double tempo_ultimo_quadro = 0.0; // Tempo do último quadro exibido
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

// Função que desenha a animação de atirar
void armado(bool* keys) {
    double tempo_atual = al_get_time(); // Obtém o tempo atual do sistema

    // Verifica se a tecla espaço foi pressionada
    if (keys[ALLEGRO_KEY_SPACE]) {
        if (!atirando) { // Se não está atirando, começa a animação
            atirando = true;
            quadro_atual = 0; // Reinicia a animação para o primeiro quadro
            tempo_ultimo_quadro = tempo_atual; // Registra o tempo do último quadro
            al_play_sample(tiro, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL); // Toca o som do tiro
        }
    }

    // Se a animação estiver ocorrendo, avança os quadros
    if (atirando) {
        if (tempo_atual - tempo_ultimo_quadro >= 0.1) { // 0.1 segundos de intervalo entre os quadros
            quadro_atual++;
            tempo_ultimo_quadro = tempo_atual; // Atualiza o tempo do último quadro

            // Se a animação terminou, volta para o primeiro quadro
            if (quadro_atual >= NUM_QUADROS) {
                quadro_atual = 0;
                atirando = false; // Finaliza a animação
            }
        }
    }

    // Desenha o quadro atual da animação
    al_draw_scaled_bitmap(
        winchester,
        quadro_atual * 95, 0, 95, 89, // Posição da região no sprite
        pos_x, pos_y, 95 * escala_x, 89 * escala_y, // Posição e escala na tela
        0
    );
}

// Função para destruir a imagem quando não for mais necessária
void destroi_doom_slayer() {
    al_destroy_bitmap(winchester);
    al_destroy_sample(tiro);
}
