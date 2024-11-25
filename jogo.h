#pragma once
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include "doom_slayer.h"
#include <math.h>

#define SCREEN_WIDTH 1000
#define SCREEN_HEIGHT 1000


typedef struct {
    float x, y; 
    float dirX, dirY;
    float planeX, planeY; 
} Player;


#define MAPA_WIDTH 27
#define MAPA_HEIGHT 40

int mapa[MAPA_WIDTH][MAPA_HEIGHT] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1},
    {1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0},
    {1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 0, 1, 1},
    {1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1},
    {1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1},
    {1, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 0, 1, 0, 1, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 0, 1, 1, 1, 1, 0, 1},
    {1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1, 0, 1, 1, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 0, 1},
    {1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1},
    {1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 0, 1, 1, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 1, 1, 1, 1},
    {1, 0, 1, 1, 1, 1, 0, 0, 1, 0, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1, 1, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 0, 1},
    {1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1},
    {1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 1, 1, 1},
    {1, 0, 1, 1, 1, 0, 0, 0, 1, 0, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1},
    {1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 1, 0, 1, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1},
    {1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1}
};

// Posição pra chegar
float posiX = 27.0, posiY = 38.0;

// verifica posição
bool colisao(Player* player, float X, float Y) {
    int mapaX = (int)X;
    int mapaY = (int)Y;

   //limite mapa
    if (mapaX < 0 || mapaX >= MAPA_WIDTH || mapaY < 0 || mapaY >= MAPA_HEIGHT) {
        return true; 
    }
    return mapa[mapaX][mapaY] == 1; 
}

// andar 
void move_player(Player* player, bool* keys, float moveSpeed, float rotSpeed) {
    float X = player->x;
    float Y = player->y;

    //anda para frente
    if (keys[ALLEGRO_KEY_W]) {
        X += player->dirX * moveSpeed;
        Y += player->dirY * moveSpeed;
        if (!colisao(player, X,Y)) { 
            player->x = X;
            player->y = Y;
        }
    }
    // anda pra tras
    if (keys[ALLEGRO_KEY_S]) {
        X -= player->dirX * moveSpeed;
        Y -= player->dirY * moveSpeed;
        if (!colisao(player, X, Y)) {
            player->x = X; 
            player->y = Y;
        }
    }
    // Rotaciona para a direita
    if (keys[ALLEGRO_KEY_D]) {
        float DirX2 = player->dirX;
        player->dirX = player->dirX * cos(-rotSpeed) - player->dirY * sin(-rotSpeed);
        player->dirY = DirX2 * sin(-rotSpeed) + player->dirY * cos(-rotSpeed);

        float PlaneX2 = player->planeX;
        player->planeX = player->planeX * cos(-rotSpeed) - player->planeY * sin(-rotSpeed);
        player->planeY = PlaneX2 * sin(-rotSpeed) + player->planeY * cos(-rotSpeed);
    }
    // Rotaciona para a esquerda
    if (keys[ALLEGRO_KEY_A]) {
        float DirX2 = player->dirX;
        player->dirX = player->dirX * cos(rotSpeed) - player->dirY * sin(rotSpeed);
        player->dirY = DirX2 * sin(rotSpeed) + player->dirY * cos(rotSpeed);

        float PlaneX2 = player->planeX;
        player->planeX = player->planeX * cos(rotSpeed) - player->planeY * sin(rotSpeed);
        player->planeY = PlaneX2 * sin(rotSpeed) + player->planeY * cos(rotSpeed);
    }
}

int largura_p = 3;

// linha verticalparede
void verticaL_parede(int x, int altura_p, ALLEGRO_COLOR cor) {
    int comecoY = (SCREEN_HEIGHT - altura_p) / 2;
    int fimY = comecoY + altura_p;
    al_draw_filled_rectangle(x - largura_p / 2, comecoY, x + largura_p / 2, fimY, cor);
}

ALLEGRO_BITMAP* inicio = NULL;
ALLEGRO_BITMAP* venceu = NULL;
ALLEGRO_BITMAP* perdeu = NULL;
ALLEGRO_BITMAP* acabou = NULL;

void declara_jogo() {
    inicio = al_load_bitmap("./iniciojogo.jpg");
    venceu = al_load_bitmap("./passoujogo.jpg");
    perdeu = al_load_bitmap("./perdeujogo.jpg");
    acabou = al_load_bitmap("./imagefinal.jpg");
}

bool continua = true;
int seg_fim = 0;
bool temp = true;

// Função de raycasting
void doom(Player* player, bool* keys, int* seg_jogo, bool *final, bool *jogar) {

    if (*seg_jogo < 5) {
        al_draw_bitmap(inicio, 0, 0, 0);
    }

    else {
        al_clear_to_color(al_map_rgb(0, 0, 0)); 

        float velo_movi = 0.05; 
        float velo_rot = 0.03;  

        move_player(player, keys, velo_movi, velo_rot);

        if (temp) {

            if (*seg_jogo > 60 * 2) {

                al_draw_bitmap(perdeu, 0, 0, 0);

                if (*seg_jogo >= (60*2) + 5) {

                    al_draw_bitmap(acabou, 0, 0, 0);

                }
                *jogar = false;


                if (keys[ALLEGRO_KEY_SPACE]) {

                    *final = true;

                }

            }
        }

        // ve se deu boa de chegar na saida
        else if (fabs(player->x - posiX) < 0.5 && fabs(player->y - posiY) < 0.5) {
         
            al_draw_bitmap(venceu, 0, 0, 0);

            *jogar = false;
            temp = false;

            if (keys[ALLEGRO_KEY_SPACE]) {
                *final = true;
            }
        }

        if (*jogar) {

            // Raycasting para renderizar as paredes
            for (int x = 0; x < SCREEN_WIDTH; x++) {

                double cameraX = 2 * x / (double)SCREEN_WIDTH - 1;
                double rayDirX = player->dirX + player->planeX * cameraX;
                double rayDirY = player->dirY + player->planeY * cameraX;

                int mapX = (int)player->x;
                int mapY = (int)player->y;

                double deltaDistX = fabs(1 / rayDirX);
                double deltaDistY = fabs(1 / rayDirY);

                double lado_DistX, lado_DistY;
                int stepX, stepY;
                int hit = 0; 
                int lado;   

                if (rayDirX < 0) {
                    stepX = -1;
                    lado_DistX = (player->x - mapX) * deltaDistX;
                }
                else {
                    stepX = 1;
                    lado_DistX = (mapX + 1.0 - player->x) * deltaDistX;
                }
                if (rayDirY < 0) {
                    stepY = -1;
                    lado_DistY = (player->y - mapY) * deltaDistY;
                }
                else {
                    stepY = 1;
                    lado_DistY = (mapY + 1.0 - player->y) * deltaDistY;
                }

                while (!hit) {
                    // anda pra proxima posição
                    if (lado_DistX < lado_DistY) {
                        lado_DistX += deltaDistX;
                        mapX += stepX;
                        lado = 0;
                    }
                    else {
                        lado_DistY += deltaDistY;
                        mapY += stepY;
                        lado = 1;
                    }
                    // ve se bateu na parede
                    if (mapa[mapX][mapY] > 0) hit = 1;
                }

                double dist_p;
                if (lado == 0)
                    dist_p = (mapX - player->x + (1 - stepX) / 2) / rayDirX;
                else
                    dist_p = (mapY - player->y + (1 - stepY) / 2) / rayDirY;

                // altura da linha na tela
                int altura_l = (int)(SCREEN_HEIGHT / dist_p);

                ALLEGRO_COLOR cor;
                if (lado == 0) {
                    cor = al_map_rgb(200, 0, 0);
                }
                else {
                    cor = al_map_rgb(128, 0, 0);
                }
                
                verticaL_parede(x, altura_l, cor);
            }

            al_flip_display();
        }
    }
}

void destroi_jogo() {
    al_destroy_bitmap(acabou);
    al_destroy_bitmap(inicio);
    al_destroy_bitmap(venceu);
    al_destroy_bitmap(perdeu);
}
