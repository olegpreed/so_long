#include "so_long.h"
void map_to_string(t_root *game)
{
	game->symbolsize.x = 0;
	game->symbolsize.y = 0;
	int k = 1;
	int fd = 0;
	char *string1;
	char *string2;

	fd = open("map.ber", O_RDONLY);
	game->map = get_next_line(fd);
	while(k)
	{
		string1 = game->map;
		string2 = get_next_line(fd);
		if (string2)
		{
			game->map = ft_strjoin(game->map, string2);
			free(string1);
			free(string2);
		}
		else
			k = 0;
		game->symbolsize.y++;
	}
	game->symbolsize.x = ft_strlen_n(game->map);
}
void count_map(t_root *game)
{	
	game->pixelsize.x = game->symbolsize.x * game->grass.size.x;
	game->pixelsize.y = game->symbolsize.y * game->grass.size.y;
	printf("x = %d;\ny = %d;\n", game->pixelsize.x, game->pixelsize.y); 
}

void playerlocation(t_root *game)
{
	int xy;

	xy  = ft_strchr(game->map, 'P') - game->map;
	game->ash.symbol_location.y = xy / (game->symbolsize.x + 1);
	game->ash.symbol_location.x = xy % (game->symbolsize.x + 1);
	game->ash.pixel_location.y = game->ash.symbol_location.y * game->grass.size.y;
	game->ash.pixel_location.x = game->ash.symbol_location.x * game->grass.size.x;
	//printf("xy = %d\nXash = %d\nYash = %d\n",xy, game->ash.symbol_location.x, game->ash.symbol_location.y);
}

void sprites_init(t_root *game)
{
	game->grass.path = "./images/grass.xpm";
	game->grass.reference = mlx_xpm_file_to_image(game->mlx, game->grass.path, &(game->grass.size.x), &(game->grass.size.y));
	game->wall.path = "./images/wall.xpm";
	game->wall.reference = mlx_xpm_file_to_image(game->mlx, game->wall.path, &(game->wall.size.x), &(game->wall.size.y));
	game->ball.path = "./images/pokeball.xpm";
	game->ball.reference = mlx_xpm_file_to_image(game->mlx, game->ball.path, &(game->ball.size.x), &(game->ball.size.y));
	game->pika.path = "./images/pikachu.xpm";
	game->pika.reference = mlx_xpm_file_to_image(game->mlx, game->pika.path, &(game->pika.size.x), &(game->pika.size.y));
	game->ash.path = "./images/ash.xpm";
	game->ash.reference = mlx_xpm_file_to_image(game->mlx, game->ash.path, &(game->ash.size.x), &(game->ash.size.y));
	playerlocation(game);
}

void start(t_root *game)
{
	sprites_init(game);	
	count_map(game);
}