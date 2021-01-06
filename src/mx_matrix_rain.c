#include "matrix.h"

void mx_matrix_rain(WINDOW *mainwin, int argc, char *argv[]) {
	int SPEED = 10;
	int rows_size;
	int column_size;
	int color = 2;

	getmaxyx(mainwin, column_size, rows_size);

	start_color();
	init_pair(1, COLOR_WHITE, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(4, COLOR_RED, COLOR_BLACK);
	init_pair(5, COLOR_CYAN, COLOR_BLACK);
	init_pair(6, COLOR_BLUE, COLOR_BLACK);
	init_pair(7, COLOR_MAGENTA, COLOR_BLACK);

	curs_set(false);
	noecho();

	t_display *matrix = (t_display *) malloc(sizeof(t_display) * rows_size);
	
	for (int index = 0; index < rows_size; index++) {
		matrix[index].arr = (wchar_t *) malloc(sizeof(wchar_t) * column_size);

		for (int jndex = 0; jndex < column_size; jndex++)
			matrix[index].arr[jndex] = mx_get_random_japanese_unicode();

		matrix[index].length = rand() % column_size;
		matrix[index].start = 0 - matrix[index].length - matrix[index].length;
		matrix[index].finish = 0 - matrix[index].length;
	}

	wbkgd(mainwin, COLOR_PAIR(color));

	wclear(mainwin);

	if (argc != 2 || (argc == 2 && mx_strcmp(argv[1], "-s") != 0))
		mx_print_text(mainwin, column_size, rows_size);

	for (int index = 0; index < rows_size; index++)
		for (int jndex = 0; jndex < column_size; jndex++)
			matrix[index].arr[jndex] = mx_get_random_japanese_unicode();

	while(true) {
		wtimeout(mainwin, 60 / SPEED * 10);

		switch(getch()) {
			case '+':
				if (SPEED > 20)
					SPEED -= 10;
				break;
			case '-':
				if (SPEED < 180)
					SPEED += 10;
				break;
			case '1':
				color = 1;
				break;
			case '2':
				color = 2;
				break;
			case '3':
				color = 3;
				break;
			case '4':
				color = 4;
				break;
			case '5':
				color = 5;
				break;
			case '6':
				color = 6;
				break;
			case '7':
				color = 7;
				break;
			case 'q':
				exit(0);
		}

		wclear(mainwin);

		for (int index = 0; index < rows_size; index++) {
			for (int jndex = 0; jndex < column_size; jndex++) {
				if (jndex >= matrix[index].start && jndex <= matrix[index].finish ) {
					if (jndex == matrix[index].finish) {
						attroff(COLOR_PAIR(color));
						attron(COLOR_PAIR(1));
					}

					mvprintw(jndex, index * 2, "%lc", matrix[index].arr[jndex]);

					if (jndex == matrix[index].finish) {
						attroff(COLOR_PAIR(1));
						attron(COLOR_PAIR(color));
					}
					if (jndex == matrix[index].start)
						matrix[index].arr[jndex] = mx_get_random_japanese_unicode();
					if (jndex == matrix[index].finish)
						matrix[index].arr[jndex] = mx_get_random_japanese_unicode();
				}
			}

			matrix[index].start++;
			matrix[index].finish++;
			
			if (matrix[index].start > column_size) {
				matrix[index].length = rand() % column_size;
				matrix[index].start = 0 - matrix[index].length - matrix[index].length;
				matrix[index].finish = 0 - matrix[index].length;
			} 
		}

		refresh();
	}

	for(int index = 0; index < column_size; index++)
		free(matrix[index].arr);
	
	free(matrix);
	matrix = NULL;
}
