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
        data->width = ft_strlen(data->map[0]);
        free(backup);
        free(str);
        close(fd);
}
