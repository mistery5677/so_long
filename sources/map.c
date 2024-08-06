#include "so_long.h"

void read_map(t_data *data, char *path)
{
        int fd;
        char *backup;
        char *str;

        backup = ft_strdup("");
        fd = open(path, O_RDONLY);
        str = get_next_line(fd);
        while(str != NULL)
        {
                backup = ft_strjoin_gnl(backup, str);
                free(str);
                str = get_next_line(fd);
        }
        data->map = ft_split(backup, '\n');
        printf("data %s\n", data->map[0]);
        free(backup);
        free(str);
        close(fd);
}

void free_map(t_data *data)
{
        int i;

        i = 0;
        while(data->map[i])
        {
                free(data->map[i]);
                i++;
        }
        free(data->map);
}
