#include "so_long.h"

int action(int keypress, t_root *game)
{
	static int xx;
	static int yy;
	static int count = 0;
	xx = game->ash.symbol_location.x;
	yy = game->ash.symbol_location.y;
	if ((keypress == W_key || keypress == Up_arrow) && game->map[xx + (game->symbolsize.x + 1) * (yy - 1)] != '1')
	{
		game->ash.symbol_location.y -= 1; 
		game->ash.pixel_location.y -= game->grass.size.y; 
		count++;
	}
	if ((keypress == A_key || keypress == Left_arrow) && game->map[(xx - 1) + (game->symbolsize.x + 1) * yy] != '1' )
	{
		game->ash.pixel_location.x -= game->grass.size.x; 
		game->ash.symbol_location.x -= 1; 
		count++;
	}
	if ((keypress == S_key || keypress == Down_arrow) && game->map[xx + (game->symbolsize.x + 1) * (yy + 1)] != '1')
	{
		game->ash.symbol_location.y += 1; 
		game->ash.pixel_location.y += game->grass.size.y; 
		count++;
	}
	if ((keypress == D_key || keypress == Right_arrow) && game->map[(xx + 1) + (game->symbolsize.x + 1) * yy] != '1')
	{
		game->ash.pixel_location.x += game->grass.size.x;
		game->ash.symbol_location.x += 1; 
		count++;
	} 		
	printf("keypress = %d\n, Xash = %d\nYash = %d\nMove count: %d\n",keypress, xx, yy, count);
	return 0;
}