#include <ncurses.h>
#include <stdlib.h>
bool MAX_CORDSX(int x)
{
    if(x==(getmaxx(stdscr)-2))
        return true;
    else
        return false;
}
bool MAX_CORDSY(int y)
{
     if(y==(getmaxy(stdscr)-2))
        return true;
    else
        return false;
}

void movement(int z,int *b,int *a)
{
    switch (z){
        case KEY_LEFT://a
            if(*a>2)
           mvprintw(*b,(*a)-=2,"%s","O");
           else
            mvprintw(*b,*a,"%s","O");
           break;

        case KEY_RIGHT: //d
            if(!MAX_CORDSX(*a))
           mvprintw(*b,(*a)+=2,"%s","O");
           else
            mvprintw(*b,*a,"%s","O");
           break;

        case KEY_UP: //w
            if(*b>2)
           mvprintw((*b)-=2,*a,"%s","O");
           else
            mvprintw(*b,*a,"%s","O");
           break;

        case KEY_DOWN: //s
            if(!MAX_CORDSY(*b))
           mvprintw((*b)+=2,*a,"%s","O");
           else
            mvprintw(*b,*a,"%s","O");
           break;
         default:
           mvprintw(*b,*a,"%s","O");
    }
}
int main()
{
    initscr();
    keypad(stdscr,true);
    curs_set(FALSE);
    cbreak();
    noecho();
    int a=getmaxx(stdscr)/2;
    int b=getmaxy(stdscr)/2;
    int flag=true;
    attron(A_BOLD|A_REVERSE);
    while(flag){
        int z=getch();
        if(z==KEY_F(1))
        {   clear();
            break;
        }
        clear();
        movement(z,&b,&a);
    }
    attroff(A_BOLD|A_REVERSE);
    printw("Press any key to exit\n");
    getch();
    refresh();
    endwin();

}

