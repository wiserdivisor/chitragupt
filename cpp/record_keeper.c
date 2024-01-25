//  ### NOMAD Commands
//  tn> <text>      (for making todos)
//  to:id> <text>   (for changing todo text) 
//  tm:id           (for marking todos as done)
//  ta:id> <text>   (for appending as a nested todo)
//  td:id           (for deleting todos)
//  ln> <text>      (for making logs)
//  lo:id> <text>   (for changing log text) 
//  lm:id           (for marking logs as done)
//  la:id> <text>   (for appending as a nested log)
//  ld:id           (for deleting logs)
//  r> <id,id,...>  (for generating time-based day todo+log report)
//  s>              (for showing logs and todos)
//  - 24-00,24-11 = 24,13 -> Morn
//  - 24-12,24-16 = 12,08 -> AFTN
//  - 24-17,24-23 = 07,01 -> Even

/*
Flow:
Start
print welcome and quote
fullscreen terminal application that redraws the screen everytime



And with self-pity comes a need to be noticed by others to gain sympathy from them
When one does not gain sympathy they it turns to anger and from anger to a feeling of revenge,
And when you're unable to carry out your revenge you become resentful because if you cannot hurt your enemies in real life you'll try to hurt them in your mind.
But you end up doing is just hurting your own mental health and as a consequence of that even your physical health goes downhill.

When you respect something you pay attention to it,
When you pay attention to something, you observe and understand it's value
After seeing the value in something, 

*/

#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <time.h>

int chat_loop(FILE* fptr){
    // Print the current document
    // Ready for Input
    while(1) {
      char statement[1000];
      scanf("%s",&statement);
      fputs(statement,fptr);
    }
    return 0; 
}

int main(void)
{
    initscr();
    printw("Hello World!");
    refresh();
    getch();
    endwin();

    /*
    char c;
    FILE *fptr_template;
    FILE *fptr_log;

    char filename[23];
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    sprintf(filename, "./%04d-%02d-%02d.md", t->tm_year + 1900, t->tm_mon + 1, t->tm_mday);

    fptr_template = fopen("./template.md", "r");
    fptr_log = fopen(filename, "w");

    if (fptr_template == NULL) {
        fprintf(stderr, "Error: Could not open file 'template.md'\n");
        exit(1);
    }

    if (fptr_log == NULL) {
        fprintf(stderr, "Error: Could not open file '%s'\n",filename);
        exit(1);
    }

    while((c = getc(fptr_template)) != EOF){
      printf("%c",c);
      putc(c,fptr_log);
    }

    fclose(fptr_template);
    
    chat_loop(fptr_log);

    fclose(fptr_log);

    printf("Wrote input to file '%s'\n", filename);
    */
    return 0;
}
