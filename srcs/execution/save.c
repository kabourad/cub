#include "../../headers/cub.h"

void	save(t_cub *cub)
{
	char	*str;
	int		fd;

	if (!(fd = open("save_file.bmp", O_WRONLY || O_CREAT)))
		quit("\"Save_file.bmp\" could not be opened or created", NULL);
	header_fill(cub);
	header_info_fill(cub);
	ft_putstr("File successfully saved\n");
	exit(0);
}
