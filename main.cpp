#include <ncurses.h>
#include <string>
#include <cstring>
#include <cstddef>
#include "GameMenu.h"

using namespace std;

int main()
{
    initscr();
    curs_set(0);
    if (has_colors()) start_color();

    const string Title = "The Snake Game";

    init_pair(1, COLOR_BLACK, COLOR_BLUE); // SCREEN
    wbkgd(stdscr, COLOR_PAIR(1));
    // Find out the size of our terminal
    int TermSizeX = getmaxx(stdscr);
    // Enable function special keys
    mvwprintw(stdscr, 0, (TermSizeX - strlen(Title.c_str()))/2, Title.c_str());
    refresh();

    GameMenu* Menu = new GameMenu(stdscr);
    Menu->StartMenu();

    endwin();

    return 0;
}
