#include "so_long.h"

void read_map(int fd, t_data *data)
{
    char *line;
    char *line_accumulator = NULL;

    while (line = get_next_line(fd) != '\0')
    {
        if (line_accumulator == NULL)
            line_accumulator = ft_strdup(line);
        else
            line_accumulator = ft_strjoin(line_accumulator, line)

        free (line);
    }
    
	if (!line_accumulator)
		return_error(2, &data);

	if (!new_line_check(line_accumulator))
	{
		free(line_accumulator);
		return_error(3, &data);
	}

	data->map = ft_split(line_accumulator, '\n');
	free(line_accumulator);

	map_checker(data)
}