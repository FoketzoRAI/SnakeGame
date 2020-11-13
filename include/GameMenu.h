#ifndef GAMEMENU_H
#define GAMEMENU_H

#include <ncurses.h>
#include <string>
#include <cstddef>

using namespace std;

class GameMenu
{
    public:
        GameMenu(WINDOW* window);
        ~GameMenu();
        void StartMenu();

    protected:
        string MAIN_MENU[4];
        string MenuTitle;
        size_t choice;
        const int MiddlePosXForText(const int SizeX, const string Text);

    private:
        void Update();
        void DrawMenu();
        void MenuControll();
        WINDOW* TargetWindow;
        WINDOW* MenuWindow;
        int WinSizeX;
        bool Exit = false;
};

#endif // GAMEMENU_H
