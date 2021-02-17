#include "../../headers/cub.h"

static	void	init_image_header(t_bitmap_image *bih, t_cub *cub,
int file_size)
{
	int ppm;

	ppm = 96 * 39.375;
	bih->size_header = sizeof(t_bitmap_image);
	bih->width = cub->parse.res.w;
	bih->height = -cub->parse.res.h;
	bih->planes = 1;
	bih->bit_count = 32;
	bih->compression = 0;
	bih->image_size = file_size;
	bih->ppm_x = ppm;
	bih->ppm_y = ppm;
	bih->clr_used = 0;
	bih->clr_important = 0;
}

static	void	init_file_header(t_bitmap_file *bfh, int file_size)
{
	ft_memcpy(&bfh->bitmap_type, "BM", 2);
	bfh->file_size = file_size;
	bfh->reserved1 = 0;
	bfh->reserved2 = 0;
	bfh->offset_bits = 0;
}

void			save(t_cub *cub)
{
	int				fd;
	t_bitmap_file	bfh;
	t_bitmap_image	bih;
	int				image_size;
	int				file_size;

	image_size = cub->parse.res.w * cub->parse.res.h;
	file_size = HEADER_SIZE + (4 * image_size);
	init_file_header(&bfh, file_size);
	init_image_header(&bih, cub, file_size);
	fd = open("save.bmp",
	O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR);
	write(fd, &bfh, sizeof(bfh) - 2);
	write(fd, &bih, sizeof(bih));
	write(fd, cub->image.data, image_size * 4);
	close(fd);
	ft_putstr_fd("File saved successfully\n", 1);
	clear_game(cub);
	exit(0);
}