#include "GameMenu.h"
#include <ncurses.h>
#include <string>
#include <cstring>

using namespace std;

GameMenu::GameMenu(WINDOW* window):
    MAIN_MENU({ "Easy", "Medium", "Hard", "Exit"}),
    MenuTitle("|---- MAIN MENU ----|"),
    choice(0),
    TargetWindow(window),
    MenuWindow(newwin(getmaxy(window)-3, getmaxx(window), 2, 0)),
    WinSizeX(getmaxx(MenuWindow)),
    Exit(false)
{
    keypad(MenuWindow, true);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    wbkgd(MenuWindow, COLOR_PAIR(2));
}

GameMenu::~GameMenu()
{
    delete MenuWindow;
}

const int GameMenu::MiddlePosXForText(const int SizeX, const string Text)
{
    return ( SizeX - strlen(Text.c_str()) ) / 2;
}

void GameMenu::DrawMenu()
{
    box(MenuWindow, 0, 0);
    mvwprintw(MenuWindow, 1, MiddlePosXForText(WinSizeX, MenuTitle), MenuTitle.c_str());
    for (size_t i = 0; i < 4; i++)
    {
        if (i == choice) wattron(MenuWindow, A_REVERSE);
        mvwprintw(MenuWindow, i+2, MiddlePosXForText(WinSizeX, MAIN_MENU[i]), "%s" , MAIN_MENU[i].c_str());
        wattroff(MenuWindow, A_REVERSE);
    }
    wrefresh(MenuWindow);
}

void GameMenu::MenuControll()
{
    int KeyCode = wgetch(MenuWindow);

    wclear(MenuWindow);
    box(MenuWindow, 0, 0);
    // CONTROLS
    switch (KeyCode) {
        case KEY_UP:
            if (choice > 0)
                choice--;
            break;
        case KEY_DOWN:
            if (choice < 3)
                choice++;
            break;
        case 10: // ENTER
            switch (choice)
            {
                case 3: // EXIT
                    Exit = 1;
                    break;
                default:
                    mvwprintw(MenuWindow, 5, 1, "You chosen %s", MAIN_MENU[choice].c_str());
            }
            break;
    }

    wrefresh(MenuWindow);
}

void GameMenu::Update()
{
    DrawMenu();
    MenuControll();
}

void GameMenu::StartMenu()
{
    while (!Exit)
    {
        Update();
        refresh();
    }
}
