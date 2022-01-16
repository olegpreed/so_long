#include "so_long.h"

int action(int keypress, t_root *game)
{
	static int xx;
	static int yy;
	xx = game->ash.symbol_location.x;
	yy = game->ash.symbol_location.y;
	printf("keypress = %d\n, Xash = %d\nYash = %d\n",keypress, xx, yy);
	if ((keypress == W_key || keypress == Up_arrow) && game->map[xx + (game->symbolsize.x + 1) * (yy - 1)] != '1')
	{
		game->ash.symbol_location.y -= 1; 
		game->ash.pixel_location.y -= game->grass.size.y; 
	}
	if ((keypress == A_key || keypress == Left_arrow) && game->map[(xx - 1) + (game->symbolsize.x + 1) * yy] != '1' )
	{
		game->ash.pixel_location.x -= game->grass.size.x; 
		game->ash.symbol_location.x -= 1; 
	}
	if ((keypress == S_key || keypress == Down_arrow) && game->map[xx + (game->symbolsize.x + 1) * (yy + 1)] != '1')
	{
		game->ash.symbol_location.y += 1; 
		game->ash.pixel_location.y += game->grass.size.y; 
	}
	if ((keypress == D_key || keypress == Right_arrow) && game->map[(xx + 1) + (game->symbolsize.x + 1) * yy] != '1')
	{
		game->ash.pixel_location.x += game->grass.size.x;
		game->ash.symbol_location.x += 1; 
	} 		
	return 0;
}