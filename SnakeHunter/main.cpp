#include <bits/stdc++.h>
#include "mylid.h"
#define MAX 100

using namespace std;

int toadoX[MAX] = {0};
int toadoY[MAX] = {0};
int sl = 4;

void khoi_tao_ran();
void drawSnake();
void drawWall();
void dichuyen(int x, int y);
void play();
bool gameOver();

void main()
{
    play();
    srand(time(NULL)); //tao hat giong
    for (int i = 1; i<= 10; i++){
        int b = rand() % (20 - 10 + 1) + 10;
        // b = rand() % (b - a + 1) + a;
        cout << b << endl;
    }
    _getch();
}

void play(){

     ShowCur(0);
     SetColor(11);
     drawWall();
     khoi_tao_ran();
     int x = toadoX[0];
     int y = toadoY[0];
     int check = 2;//0 di xuong
                  //1 di len
                  //2 qua phai
                  //3 qua trai
     while (true){
        gotoXY(toadoX[sl], toadoY[sl]);
            cout << " ";
        drawSnake();
        if (_kbhit()){
            char c = _getch();
            if (c == -32){
                c = _getch();
                if (c == 72 && check != 0){
                    check = 1;
                }
                else if (c == 80 && check != 1){
                    check  = 0;
                }
                else if (c == 75 && check != 2){
                    check = 3;
                }
                else if (c = 77 && check != 3){
                    check = 2;
                }
            }
        }
        if (check == 0){
            y++;
        }
        else if (check == 1){
            y--;
        }
        else if (check == 2){
            x++;
        }
        else if (check == 3){
            x--;
        }
        if (gameOver()){
            break;
        }
        dichuyen(x, y);
        Sleep(100);
     }
}

//ve tuong
void drawWall(){
     for (int x = 10; x <= 95; x++){
         gotoXY(x, 1);
         cout << "+";
         gotoXY(x, 25);
         cout << "+";
     }
     for (int y = 1; y <= 25; y++){
        gotoXY(10, y);
        cout << "+";
        gotoXY(95, y);
        cout << "+";
     }
}

void khoi_tao_ran(){
     int x_khoi_tao = 50;
     int y_khoi_tao = 13;
     for (int i = 0; i < sl; i++){
        toadoX[i] = x_khoi_tao;
        toadoY[i] = y_khoi_tao;
        x_khoi_tao--;
     }
}

void drawSnake(){
     for (int i = 0; i < sl; i++){
        gotoXY(toadoX[i], toadoY[i]);
        if (i == 0){
            cout << "O";
        }
        else cout << "o";
     }
}

void add(int a[], int n, int vt, int x){

      n++;
}

void dichuyen(int x, int y){
    //them x,y vao dau toadox, toadoy
    for (int i = sl; i > 0; i--){
        toadoX[i] = toadoX[i - 1];
        toadoY[i] = toadoY[i - 1];
      }
      toadoX[0] = x;
      toadoY[0] = y;
}

bool gameOver(){
     if (toadoX[0] == 10 || toadoX[0] == 95 || toadoY[0] == 1 || toadoY[0] == 25){
        return true;
     }
     return false;
}
