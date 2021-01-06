#include "matrix.h"

void mx_print_text(WINDOW *mainwin, int colums, int rows) {
    init_pair(3, COLOR_GREEN, COLOR_BLACK);
	wbkgd(mainwin, COLOR_PAIR(3));

    if (colums > 16 && rows > 32) {
        int x_position = colums / 8;
        int y_position = rows / 64;

        usleep(15000);

        char first[] = "Wake up , Neo..";
        char second[] = "The Matrix has you..";
        char third[] = "Follow the white rabbit";
        char fourth[] = "Knock, knock, Neo";

        wclear(mainwin);

        for (int index = 0; index < 15; index++) {
            mvwaddch(mainwin, y_position, x_position + index, first[index]);
            refresh();
            usleep(170000);
        }

        wclear(mainwin);
        usleep(100000);

        for (int index = 0; index < 20; index++) {
            mvwaddch(mainwin, y_position, x_position + index, second[index]);
            refresh();
            usleep(170000);
        }

        wclear(mainwin);
        usleep(100000);

        for (int index = 0; index < 23; index++) {
            mvwaddch(mainwin, y_position, x_position + index, third[index]);
            refresh();
            usleep(170000);
        }

        wclear(mainwin);
        usleep(100000);

        for (int index = 0; index < 17; index++) {
            mvwaddch(mainwin, y_position, x_position + index, fourth[index]);
            refresh();
            usleep(170000);
        }
    }
}
