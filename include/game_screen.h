#ifndef __GAME_SCREEN_H
#define __GAME_SCREEN_H

#include "log_timestamp.h"
#include <mutex>

std::mutex _gameScreenMtx;

class GameScreen
{
    static GameScreen *_instence;
    int _height;
    int _width;
    int _depth;

    GameScreen() : _height(10), _width(4), _depth(1)
    {
        Log1 << "New Instance of GameScreen created";
    }

public:
    static GameScreen *get_game_screen_instance()
    {
        if (_instence == nullptr)
        {
            _gameScreenMtx.lock();
            if (_instence == nullptr)
                _instence = new GameScreen;
            _gameScreenMtx.unlock();
        }
        return _instence;
    };

    void disply()
    {
        Log1 << "H: " << _height << " W: " << _width << " D: " << _depth;
    }

    void setHeight(const int height)
    {
        _height = height;
    }

    void setWidth(const int width)
    {
        _width = width;
    }

    void setDepth(const int depth)
    {
        _depth = depth;
    }
};

GameScreen *GameScreen::_instence;

#endif //__GAME_SCREEN_H