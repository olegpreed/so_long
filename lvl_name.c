/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lvl_name.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preed <preed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 17:55:32 by oleg              #+#    #+#             */
/*   Updated: 2022/02/15 18:21:49 by preed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*level_name2(int lvl)
{
	if (lvl == 12)
		return ("12 - Gladiator");
	if (lvl == 13)
		return ("13 - Hard level");
	if (lvl == 14)
		return ("14 - Twins");
	else
		return ("dwdw");
}

char	*level_name(int lvl)
{
	if (lvl == 1)
		return ("01 - First time in the club");
	if (lvl == 2)
		return ("02 - You wanna fight?");
	if (lvl == 3)
		return ("03 - Hide'n'seek");
	if (lvl == 4)
		return ("04 - President's daughter");
	if (lvl == 5)
		return ("05 - Minotaur's labyrinth");
	if (lvl == 6)
		return ("06 - Buy me a cocktail");
	if (lvl == 7)
		return ("07 - Enemies everywhere!");
	if (lvl == 8)
		return ("08 - Bonus level");
	if (lvl == 9)
		return ("09 - Iphone version");
	if (lvl == 10)
		return ("10 - Ipad version");
	if (lvl == 11)
		return ("11 - Bomberman");
	else
		return (level_name2(lvl));
}
