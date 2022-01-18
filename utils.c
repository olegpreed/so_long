/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preed <preed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 14:31:28 by preed             #+#    #+#             */
/*   Updated: 2022/01/18 16:56:18 by preed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	pxl_to_symbol_loc(int x, int y, int line)
{
	return (x / 100 + (y / 100) * (line + 1));
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
// void	my_mlx_pixel_put(t_root *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }