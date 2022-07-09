#include "game_screen.h"
#include <thread>
void func1()
{
    GameScreen *temp = GameScreen::get_game_screen_instance();
    temp->disply();
}

void func2()
{
    GameScreen *temp = GameScreen::get_game_screen_instance();
    temp->setWidth(200);
    temp->disply();
}

int main()
{
    GameScreen *game = GameScreen::get_game_screen_instance();
    game->disply();

    game->setDepth(23);
    game->setHeight(100);

    std::thread t1(func1);
    std::thread t2(func2);

    t1.join();
    t2.join();

    std::cout << std::endl;
    return EXIT_SUCCESS;
}