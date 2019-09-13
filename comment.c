#include <ncurses.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define FSIZE 20

void f_gets(char *,int );

int main()
{

    char FileName[FSIZE];
    f_gets(FileName,FSIZE);

    FILE *fp;
    fp=fopen(FileName,"r+");

    if(fp==NULL){
    fprintf(stderr,"%s","ERROR OCCURED WHILE OPENING THE FILE");
    exit(EXIT_FAILURE);
    }

    initscr();
    start_color();
    cbreak();
    init_pair(1,COLOR_BLUE,COLOR_BLACK);
    int ch,prev;
    while((ch=fgetc(fp))!=EOF){
        if(prev=='/' && ch=='*'){
            addch(ch);
            attron(COLOR_PAIR(1));
        }
        else if(prev=='*' && ch=='/'){
           attroff(COLOR_PAIR(1));
           move(getcury(stdscr),getcurx(stdscr)-1);
           addch('*');
           addch(ch);
        }
        else
         addch(ch);

        prev=ch;
    }

    refresh();
    getch();
    endwin();
}

void f_gets(char *FileName,int size)
{
    fgets(FileName,size,stdin);
    char *ptr=strchr(FileName,'\n');

    if(ptr)
        *ptr='\0';
    else{
        while(getchar()!='\n')
            continue;
    }
}

