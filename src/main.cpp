#include <iostream>
#include <ctime>
#include <vector>
#include "raylib.h"
using namespace std;

int main(){
    SetConfigFlags(FLAG_WINDOW_HIGHDPI);
    InitWindow(500, 500, "Snake");
    SetTargetFPS(60);
    srand(time(NULL));

    vector<Vector2> snake = {{13, 13}, {12, 13}, {11, 13}};
    int a_cord_x = (rand() % 25);
    int a_cord_y = (rand() % 25);
    int dir_x = 1; //0 = nil, 1 = left, -1 = right
    int dir_y = 0; //0 = nil, 1 = up, -1 = down
    int frame = 0;
    bool game_over = false; 
    
    while (!WindowShouldClose() && !game_over) {
        if ((IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) && dir_x != -1) {dir_x = 1; dir_y = 0;}
        if ((IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) && dir_x != 1) {dir_x = -1; dir_y = 0;}
        if ((IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)) && dir_y != -1) {dir_x = 0; dir_y = 1;}
        if ((IsKeyDown(KEY_UP) || IsKeyDown(KEY_W)) && dir_y != 1) {dir_x = 0; dir_y = -1;}

        frame++;
        if (frame >= 10){
            frame = 0;

            if (snake[0].x < 0 || snake[0].x > 24 || snake[0].y < 0 || snake[0].y > 24){
                game_over = true;
            }

            for (int i = 1; i < snake.size(); i++) {
                if (snake[0].x == snake[i].x && snake[0].y == snake[i].y) {
                    game_over = true;
                }
            }

            if (a_cord_x == snake[0].x && a_cord_y == snake[0].y){
                a_cord_x = (rand() % 24) + 1;
                a_cord_y = (rand() % 24) + 1;
            } 
            else {
                snake.pop_back();
            }
            
            Vector2 newHead = {snake[0].x + dir_x, snake[0].y + dir_y};
            snake.insert(snake.begin(), newHead);
        }
        BeginDrawing();
        ClearBackground(BLACK);
        DrawRectangleLines(0, 0, 500, 500, WHITE);
        DrawRectangle((int)a_cord_x * 20, (int)a_cord_y * 20, 20, 20, RED);

        for (int i = 0; i < snake.size(); i++){
            DrawRectangle(snake[i].x * 20, snake[i].y * 20, 20, 20, GREEN);
        }

        

        EndDrawing();
    }

    CloseWindow();
    return 0;
}