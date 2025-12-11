/*
** EPITECH PROJECT, 2025
** G-MUL-100-LYN-1-1-myradar-31 [WSL: Ubuntu-24.04]
** File description:
** get_plane_config.c
*/

#include "../include/my.h"

// static bool fill_coord(config_t *config, char *line, int index)
// {
//     int temp = 0;
//     for (int i = 0; line[i]; i++) {
//         if (line[0] == 'A')
//             config->coord[i] = malloc(sizeof(int) * 7 + 1);
//         if (line[0] == 'T')
//             config->coord[i] = malloc(sizeof(int) * 4 + 1);
//         if (line[i] != ' ')
//             temp++;
//         config->coord[index][0];
//     }
// }

bool get_start_coord(const char *filepath)
{
    char *line = NULL;
    size_t line_buffer_len = 0;
    FILE *file = fopen(filepath, "r");
    // int index = 0;

    if (!file)
        return false;
    while (getline(&line, &line_buffer_len, file) != -1) {
        if (line[my_strlen(line) - 1] == '\n')
            line[my_strlen(line) - 1] = '\0';
        printf("%s\n", line);
        // fill_coord(config, line, index);
        // index++;
    }
    free(line);
    fclose(file);
    return true;
}
