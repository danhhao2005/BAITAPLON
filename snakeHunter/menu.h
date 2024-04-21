
#pragma once
#include <iostream>
#include "myLib.h"

#ifndef TEXT_H_
#define TEXT_H_

using namespace std;

int ShowMenu(SDL_Renderer* g_screen,
    const string& menu1,
    const string& menu2,
    const string& img_name);

class Text
{
public:
    Text(void);
    ~Text(void);

    enum TextColor
    {
        RED_TEXT = 0,
        WHITE_TEXT = 1,
        BLACK_TEXT = 2,
    };

    bool loadFromRenderedText(TTF_Font* gFont, SDL_Renderer* screen);
    void Free();

    void setColor(Uint32 red, Uint32 green, Uint32 blue);
    void setColor(int type);

    void RenderText(SDL_Renderer* screen, int x, int y);

    int getWidth() const { return width_; }
    int getHeight() const { return height_; }
    void SetText(const string& text) { str_val_ = text; }
    string GetText() const { return str_val_; }


private:
    string str_val_;
    SDL_Color text_color_;
    SDL_Texture* texture_;
    int width_;
    int height_;

};

#endif



