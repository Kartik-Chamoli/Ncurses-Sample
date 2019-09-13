#include <ncurses.h>
WINDOW *new_win(WINDOW *win,int y,int x)
{
    win=newwin(5,20,y,x);
    box(win,0,0);
    wrefresh(win);
    return win;
}

void destroy_win(WINDOW *win)
{   wborder(win,' ',' ',' ',' ',' ',' ',' ',' ');
    wrefresh(win);
    delwin(win);
}
int main()
{
    initscr();
    attrset(COLOR_PAIR(1));
    cbreak();
    noecho();
    keypad(stdscr,TRUE);
    WINDOW *win=newwin(10,5,20,40);
    box(win,0,0);
    int y=30;
    int x=40;
    int a;

    while((a=wgetch(stdscr))!=KEY_F(1)){
    switch (a){

    case KEY_LEFT:
    destroy_win(win);
    win=new_win(win,y,--x);
    break;

    case KEY_RIGHT:
    destroy_win(win);
    win=new_win(win,y,++x);
    break;

    case KEY_UP:
    destroy_win(win);
    win=new_win(win,--y,x);
    break;

    case KEY_DOWN:
    destroy_win(win);
    win=new_win(win,++y,x);
    break;
    }
    }
    printw("OUT OF THE WINDOW");
    wgetch(stdscr);
    endwin();
}

