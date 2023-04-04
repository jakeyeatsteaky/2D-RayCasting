#include <iostream>

#include "SDL.h"

#include "App.h"
#include "QuadTree.h"
#include "Obstacle.h"
#include "DataStructures.h"
#include "util.h"


bool App::IsRunning()
{
    return running;
}

void App::Setup()
{
    SeedRandom();
    running = Graphics::CreateWindow();

    gameState = new GameState(); 

    Obstacle* boundary = new Obstacle(Vec2<float>(50,50), Vec2<float>(100,100));

    gameState->addObstacle(boundary);

}

void App::Input()
{
   SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                running = false;
                break;
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym) {
                    break;
                }
                if (event.key.keysym.sym == SDLK_ESCAPE)
                    running = false;
                break;
            default:
                break;
        }
    }

}

void App::Update()
{
    int timeToWait = MS_PER_FRAME - (SDL_GetTicks() - timePrevFrame);
    if (timeToWait > 0)
        SDL_Delay(timeToWait);

    float  deltaTime = (SDL_GetTicks() - timePrevFrame) / 1000.0f;
    if (deltaTime > 0.05)
        deltaTime = 0.05;
    timePrevFrame = SDL_GetTicks();

    //rotate(getGameState()->getObstacles().at(0));

}

void App::Render()
{
    Graphics::ClearScreen(0xFF000000);

    Obstacle* boundary = getGameState()->getObstacles().at(0);

    Graphics::DrawLine(boundary->getStartPoint(), boundary->getEndPoint(), 0xFFFFFFFF);

    Graphics::RenderFrame();
}

void App::Destroy()
{

}
