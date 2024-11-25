#pragma once
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include "doom_slayer.h"
#include <math.h>

#define SCREEN_WIDTH 1000
#define SCREEN_HEIGHT 1000
#define MAP_WIDTH 20
#define MAP_HEIGHT 38

typedef struct {
    float x, y; 
    float dirX, dirY;
    float planeX, planeY; 
} Player;


#define MAP_WIDTH 27
#define MAP_HEIGHT 40

int map[MAP_WIDTH][MAP_HEIGHT] = {
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
float targetX = 27.0, targetY = 38.0;

// verifica posição
bool check_collision(Player* player, float newX, float newY) {
    int mapX = (int)newX;
    int mapY = (int)newY;

   //limite mapa
    if (mapX < 0 || mapX >= MAP_WIDTH || mapY < 0 || mapY >= MAP_HEIGHT) {
        return true; 
    }
    return map[mapX][mapY] == 1; 
}

// andar 
void move_player(Player* player, bool* keys, float moveSpeed, float rotSpeed) {
    float newX = player->x;
    float newY = player->y;

    //anda para frente
    if (keys[ALLEGRO_KEY_W]) {
        newX += player->dirX * moveSpeed;
        newY += player->dirY * moveSpeed;
        if (!check_collision(player, newX, newY)) { 
            player->x = newX;
            player->y = newY;
        }
    }
    // anda pra tras
    if (keys[ALLEGRO_KEY_S]) {
        newX -= player->dirX * moveSpeed;
        newY -= player->dirY * moveSpeed;
        if (!check_collision(player, newX, newY)) {
            player->x = newX; 
            player->y = newY;
        }
    }
    // Rotaciona para a direita
    if (keys[ALLEGRO_KEY_D]) {
        float oldDirX = player->dirX;
        player->dirX = player->dirX * cos(-rotSpeed) - player->dirY * sin(-rotSpeed);
        player->dirY = oldDirX * sin(-rotSpeed) + player->dirY * cos(-rotSpeed);

        float oldPlaneX = player->planeX;
        player->planeX = player->planeX * cos(-rotSpeed) - player->planeY * sin(-rotSpeed);
        player->planeY = oldPlaneX * sin(-rotSpeed) + player->planeY * cos(-rotSpeed);
    }
    // Rotaciona para a esquerda
    if (keys[ALLEGRO_KEY_A]) {
        float oldDirX = player->dirX;
        player->dirX = player->dirX * cos(rotSpeed) - player->dirY * sin(rotSpeed);
        player->dirY = oldDirX * sin(rotSpeed) + player->dirY * cos(rotSpeed);

        float oldPlaneX = player->planeX;
        player->planeX = player->planeX * cos(rotSpeed) - player->planeY * sin(rotSpeed);
        player->planeY = oldPlaneX * sin(rotSpeed) + player->planeY * cos(rotSpeed);
    }
}

int wallThickness = 3;

// linha verticalparede
void verticaL_parede(int x, int lineHeight, ALLEGRO_COLOR color) {
    int startY = (SCREEN_HEIGHT - lineHeight) / 2;
    int endY = startY + lineHeight;
    al_draw_filled_rectangle(x - wallThickness / 2, startY, x + wallThickness / 2, endY, color);
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

// Função de raycasting - será chamada pelo main
void doom(Player* player, bool* keys, int* seg_jogo, bool *final, bool *jogar) {

    if (*seg_jogo < 5) {
        al_draw_bitmap(inicio, 0, 0, 0);
    }

    else {
        al_clear_to_color(al_map_rgb(0, 0, 0)); 

        float moveSpeed = 0.05; 
        float rotSpeed = 0.03;  

        move_player(player, keys, moveSpeed, rotSpeed);

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
        else if (fabs(player->x - targetX) < 0.5 && fabs(player->y - targetY) < 0.5) {
         
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

                double sideDistX, sideDistY;
                int stepX, stepY;
                int hit = 0; 
                int side;   

                if (rayDirX < 0) {
                    stepX = -1;
                    sideDistX = (player->x - mapX) * deltaDistX;
                }
                else {
                    stepX = 1;
                    sideDistX = (mapX + 1.0 - player->x) * deltaDistX;
                }
                if (rayDirY < 0) {
                    stepY = -1;
                    sideDistY = (player->y - mapY) * deltaDistY;
                }
                else {
                    stepY = 1;
                    sideDistY = (mapY + 1.0 - player->y) * deltaDistY;
                }

                while (!hit) {
                    // anda pra proxima posição
                    if (sideDistX < sideDistY) {
                        sideDistX += deltaDistX;
                        mapX += stepX;
                        side = 0;
                    }
                    else {
                        sideDistY += deltaDistY;
                        mapY += stepY;
                        side = 1;
                    }
                    // ve se bateu na parede
                    if (map[mapX][mapY] > 0) hit = 1;
                }

                double perpWallDist;
                if (side == 0)
                    perpWallDist = (mapX - player->x + (1 - stepX) / 2) / rayDirX;
                else
                    perpWallDist = (mapY - player->y + (1 - stepY) / 2) / rayDirY;

                // altura da linha na tela
                int lineHeight = (int)(SCREEN_HEIGHT / perpWallDist);

                ALLEGRO_COLOR cor;
                if (side == 0) {
                    cor = al_map_rgb(200, 0, 0);
                }
                else {
                    cor = al_map_rgb(128, 0, 0);
                }
                
                verticaL_parede(x, lineHeight, cor);
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
