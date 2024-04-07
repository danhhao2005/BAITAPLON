#include <iostream>
#include <SDL.h>
#include <SDL_timer.h>
#include <SDL_image.h>
#include <vector>
#include <ctime>

#ifdef _WIN32
#undef main
#endif

using namespace std;

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int CELL_SIZE = 20;
const int GRID_WIDTH = SCREEN_WIDTH / CELL_SIZE;
const int GRID_HEIGHT = SCREEN_HEIGHT / CELL_SIZE;

struct Point {
    int x, y;
    Point() : x(0), y(0) {}
    Point(int _x, int _y) : x(_x), y(_y) {}
};

enum Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT
};

class SnakeGame {
public:
    SnakeGame();
    ~SnakeGame();

    void run();

private:
    void handleInput();
    void update();
    void render();
    void placeFood();
    bool checkCollision(Point p);
    void gameOver();

    SDL_Window *window;
    SDL_Renderer *renderer;
    vector<Point> snake;
    Point food;
    Direction dir;
    bool isRunning;
};

SnakeGame::SnakeGame() {
    SDL_Init(SDL_INIT_VIDEO);

    window = SDL_CreateWindow("Snake Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    snake.push_back(Point(GRID_WIDTH / 2, GRID_HEIGHT / 2));
    placeFood();

    dir = RIGHT;
    isRunning = true;
}

SnakeGame::~SnakeGame() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void SnakeGame::run() {
    while (isRunning) {
        handleInput();
        update();
        render();
        SDL_Delay(100);
    }
}

void SnakeGame::handleInput() {
    SDL_Event event;
    if (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            isRunning = false;
        }
        else if (event.type == SDL_KEYDOWN) {
            switch (event.key.keysym.sym) {
                case SDLK_UP:
                    if (dir != DOWN)
                        dir = UP;
                    break;
                case SDLK_DOWN:
                    if (dir != UP)
                        dir = DOWN;
                    break;
                case SDLK_LEFT:
                    if (dir != RIGHT)
                        dir = LEFT;
                    break;
                case SDLK_RIGHT:
                    if (dir != LEFT)
                        dir = RIGHT;
                    break;
                default:
                    break;
            }
        }
    }
}

void SnakeGame::update() {
    // Move the snake
    Point next = snake.front();
    switch (dir) {
        case UP:
            next.y -= 1;
            break;
        case DOWN:
            next.y += 1;
            break;
        case LEFT:
            next.x -= 1;
            break;
        case RIGHT:
            next.x += 1;
            break;
    }

    // Check if snake collides with itself or wall
    if (next.x < 0 || next.x >= GRID_WIDTH || next.y < 0 || next.y >= GRID_HEIGHT || checkCollision(next)) {
        gameOver();
        return;
    }

    snake.insert(snake.begin(), next);

    // Check if snake eats food
    if (next.x == food.x && next.y == food.y) {
        placeFood();
    } else {
        snake.pop_back();
    }
}

void SnakeGame::render() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    // Render snake
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    for (Point const &p : snake) {
        SDL_Rect rect = { p.x * CELL_SIZE, p.y * CELL_SIZE, CELL_SIZE, CELL_SIZE };
        SDL_RenderFillRect(renderer, &rect);
    }

    // Render food
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_Rect rect = { food.x * CELL_SIZE, food.y * CELL_SIZE, CELL_SIZE, CELL_SIZE };
    SDL_RenderFillRect(renderer, &rect);

    SDL_RenderPresent(renderer);
}

void SnakeGame::placeFood() {
    srand(time(NULL));
    bool valid = false;
    while (!valid) {
        food.x = rand() % GRID_WIDTH;
        food.y = rand() % GRID_HEIGHT;
        valid = true;
        for (Point const &p : snake) {
            if (p.x == food.x && p.y == food.y) {
                valid = false;
                break;
            }
        }
    }
}

bool SnakeGame::checkCollision(Point p) {
    for (size_t i = 1; i < snake.size(); ++i) {
        if (snake[i].x == p.x && snake[i].y == p.y) {
            return true;
        }
    }
    return false;
}

void SnakeGame::gameOver() {
    cout << "Game Over!" << endl;
    isRunning = false;
}

int main() {
    SnakeGame game;
    game.run();
    return 0;
}
