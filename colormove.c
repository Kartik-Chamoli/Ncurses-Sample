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
{   static int ch=33;
    static unsigned char count=0;
    ++count;
    if(count==93)
    {
        ch=33;
        count=0;
    }
    switch (z){
        case KEY_LEFT://a
            if(*a>2)
           mvprintw(*b,(*a)-=2,"%c",ch++);
           else
            mvprintw(*b,*a,"%c",ch++);
           break;

        case KEY_RIGHT: //d
            if(!MAX_CORDSX(*a))
           mvprintw(*b,(*a)+=2,"%c",ch++);
           else
            mvprintw(*b,*a,"%c",ch++);
           break;

        case KEY_UP: //w
            if(*b>2)
           mvprintw((*b)-=2,*a,"%c",ch++);
           else
            mvprintw(*b,*a,"%c",ch++);
           break;

        case KEY_DOWN: //s
            if(!MAX_CORDSY(*b))
           mvprintw((*b)+=2,*a,"%c",ch++);
           else
            mvprintw(*b,*a,"%c",ch++);
           break;
         default:
           mvprintw(*b,*a,"%c",ch++);
    }
}
int main()
{
    initscr();
    start_color();
    keypad(stdscr,true);

    curs_set(FALSE);
    init_color(8,1000,1000,175);
    init_color(9 ,95,1000,215);
    init_color(10,0,1000,1000);
    init_color(11,215,1000,215);
    init_color(12,1000,0,175);
    
    init_color(13,215,1000,95);
    init_color(14,175,1000,0);
    init_color(15,135,0,1000);
    init_color(16,1000,0,1000);

    cbreak();
    noecho();
    int a=getmaxx(stdscr)/2;
    int b=getmaxy(stdscr)/2;
    int flag=true;
    int pair=1;
    while(flag){
        int z=getch();
        if(z==KEY_F(1))
        {   clear();
            break;
        }
        if(pair==17){pair=1;}
        init_pair(1,pair++,COLOR_BLACK);
        attron(COLOR_PAIR(1));
        movement(z,&b,&a);
    }
    printw("Press any key to exit\n");
    getch();
    refresh();
    endwin();

}

