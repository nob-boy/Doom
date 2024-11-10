#pragma once
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include "doom_slayer.h"
#include <math.h>

// Definir as dimensões da tela e do mapa (você pode ajustar conforme sua necessidade)
#define SCREEN_WIDTH 1000
#define SCREEN_HEIGHT 1000
#define MAP_WIDTH 20
#define MAP_HEIGHT 20


// Estrutura para o jogador
typedef struct {
    float x, y;  // Posição do jogador
    float dirX, dirY; // Direção que o jogador está olhando
    float planeX, planeY; // Plano da câmera (para projeção 2.5D)
} Player;

// Definição do mapa (0 = espaço vazio, 1 = parede)
int map[MAP_WIDTH][MAP_HEIGHT] = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 1},
        {1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1},
        {1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 1},
        {1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1},
        {1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

// Função para verificar se a nova posição do jogador colide com uma parede
bool check_collision(Player* player, float newX, float newY) {
    int mapX = (int)newX;
    int mapY = (int)newY;

    // Certifique-se de que o jogador está dentro dos limites do mapa
    if (mapX < 0 || mapX >= MAP_WIDTH || mapY < 0 || mapY >= MAP_HEIGHT) {
        return true; // Colisão com o limite do mapa
    }
    return map[mapX][mapY] == 1; // Retorna verdadeiro se houver uma parede
}

// Função para mover o jogador
void move_player(Player* player, bool* keys, float moveSpeed, float rotSpeed) {
    float newX = player->x;
    float newY = player->y;

    // Movimenta para frente
    if (keys[ALLEGRO_KEY_W]) {
        newX += player->dirX * moveSpeed;
        newY += player->dirY * moveSpeed;
        if (!check_collision(player, newX, newY)) { // Verifica colisão
            player->x = newX; // Atualiza posição se não houver colisão
            player->y = newY;
        }
    }
    // Movimenta para trás
    if (keys[ALLEGRO_KEY_S]) {
        newX -= player->dirX * moveSpeed;
        newY -= player->dirY * moveSpeed;
        if (!check_collision(player, newX, newY)) { // Verifica colisão
            player->x = newX; // Atualiza posição se não houver colisão
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

// Função para desenhar uma linha vertical (parede)
void drawVerticalLine(int x, int lineHeight, ALLEGRO_COLOR color) {
    int startY = (SCREEN_HEIGHT - lineHeight) / 2;
    int endY = startY + lineHeight;
    al_draw_filled_rectangle(x - wallThickness / 2, startY, x + wallThickness / 2, endY, color);
}

// Função de raycasting - será chamada pelo main
void doom(Player* player, bool* keys) {
    al_clear_to_color(al_map_rgb(0, 0, 0)); // Limpar a tela

    float moveSpeed = 0.05; // Velocidade de movimento
    float rotSpeed = 0.03;  // Velocidade de rotação

    // Chama a função que move o jogador
    move_player(player, keys, moveSpeed, rotSpeed);
    

    // Raycasting para renderizar as paredes
    for (int x = 0; x < SCREEN_WIDTH; x++) {
        // Calcular a posição e direção dos raios
        double cameraX = 2 * x / (double)SCREEN_WIDTH - 1;
        double rayDirX = player->dirX + player->planeX * cameraX;
        double rayDirY = player->dirY + player->planeY * cameraX;

        // Posição do jogador em coordenadas do mapa
        int mapX = (int)player->x;
        int mapY = (int)player->y;

        // Distância até as próximas interseções
        double deltaDistX = fabs(1 / rayDirX);
        double deltaDistY = fabs(1 / rayDirY);

        // Distância até encontrar uma parede
        double sideDistX, sideDistY;
        int stepX, stepY;
        int hit = 0; // Foi atingida uma parede?
        int side;    // 0 = eixo X, 1 = eixo Y

        // Determinar a direção do passo (step) e calcular a distância inicial
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

        // DDA (Digital Differential Analyzer) para encontrar a parede
        while (!hit) {
            // Avançar para o próximo quadrado do mapa
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
            // Checar se atingiu uma parede
            if (map[mapX][mapY] > 0) hit = 1;
        }

        
        
        // Distância do raio ao ponto de colisão
        double perpWallDist;
        if (side == 0)
            perpWallDist = (mapX - player->x + (1 - stepX) / 2) / rayDirX;
        else
            perpWallDist = (mapY - player->y + (1 - stepY) / 2) / rayDirY;

        // Calcular a altura da linha na tela
        int lineHeight = (int)(SCREEN_HEIGHT / perpWallDist);

       // Escolher a cor baseada no lado e desenhar a parede
        ALLEGRO_COLOR color;
        if (side == 0) {
            color = al_map_rgb(200, 0, 0); // Cor mais clara para paredes frontais
        }
        else {
            color = al_map_rgb(128, 0, 0); // Cor mais escura para paredes laterais
        }

        drawVerticalLine(x, lineHeight, color); // Desenhar a linha vertical
    }

    al_flip_display(); // Atualizar a tela
}
