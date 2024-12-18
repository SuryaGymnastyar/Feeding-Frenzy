#include "loadingawal.h"
#include <ncurses/curses.h>
#include <windows.h>

void loadingawal() {
    system("color 3F");
    initscr();
    
    curs_set(0);
    
    for (int i = 2; i <= COLS - 2; i++) {
        mvprintw(4, i, "o");
        mvprintw(LINES - 7, i, "o");
        mvprintw(8, i, "o");
        mvprintw(LINES - 10, i, "o");
        refresh();
        Sleep(20);
    }
    
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLUE);
    init_pair(2, COLOR_WHITE, COLOR_CYAN);

    attron(COLOR_PAIR(2));
    mvprintw(12, 50, "     LOGGED IN      ");
    mvprintw(13, 50, " ------------------ ");
    mvprintw(14, 50, "|                  |");
    mvprintw(15, 50, " ------------------ ");
    
    int load = 1;
    
    for (int j = 1; j <= 100; j++) {
        if (j % 6 == 0) load++;
        attron(COLOR_PAIR(1));
        mvprintw(14, 50 + load, " ");
        attron(COLOR_PAIR(2));
        mvprintw(16, 54, "Loading ");
        mvprintw(16, 63, "  %%", j);
        mvprintw(16, 62, "%d", j);
        refresh();
        Sleep(50);
    }
    
    endwin();  
}
