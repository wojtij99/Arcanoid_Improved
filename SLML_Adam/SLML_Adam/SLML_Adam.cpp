#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include "Paddle.h"
#include "Block.h"
#include "Ball.h"

using namespace std;
using namespace sf;

bool IsCollision(GShape *gs0, GShape* gs1)
{
    if (gs0->shape.getGlobalBounds().intersects(gs1->shape.getGlobalBounds())) return true;
    return false;
}

int main()
{
    srand(time(NULL));
    RenderWindow window(VideoMode{ 1260,760 }, "Arcanoide");
    window.setFramerateLimit(60);
    Event ev;
    SoundBuffer buffer;
    buffer.loadFromFile("sound/Sound.wav");
    Sound sound;
    sound.setBuffer(buffer);

    Ball ball;
    Paddle paddle;
    vector<Block> blocks;

    GShape* gs0 = &paddle;
    GShape* gs1 = &ball;

    bool col = false;

    for (int i = 15; i > 0; i--)
    {
        for (int j = 0; j < 22; j++)
        {
            bool x = rand() % 2;
            if (x)
            {
                blocks.emplace_back((j + 1) * (50 + 5), (i + 2) * (20 + 3));
            }
        }
    }
    
    while (true)
    {
        window.pollEvent(ev);
        if (ev.type == Event::Closed)
        {
            window.close();
            break;
        }
        window.clear(Color(0,0,0));

        //Update
        paddle.update();

        gs0 = &paddle;
        if (IsCollision(gs0,gs1))
        {
           ball.update(true);
           col = true;
        }
        
        int it = 0;
        for (auto& block : blocks) //for (int i = 0; i < blocks.size(); i++) 
        {
            gs0 = &block; // gs0 = &blocks[i];
            if (!col && IsCollision(gs0, gs1))
            {
                ball.update(true);
                blocks.erase(blocks.begin() + it);
                sound.play();
                col = true;
                gs0 = nullptr;
                break;
            }
            it++;
        }

        if (!col) 
        {
            if (!ball.update(false))
            {
                //obsługa zdechnięcia
                cout << "GAME OVER" << endl;
                ball.reset();
            }
            else if(blocks.size() == 0)
            {
                cout << "WIN" << endl;
            }
        }

        col = false;

        //Draw
        window.draw(paddle);
        window.draw(ball);
        for (auto& block : blocks) window.draw(block);

        window.display();
    }
}