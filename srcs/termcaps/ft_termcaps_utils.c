/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcaps_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:13 by qdequele          #+#    #+#             */
/*   Updated: 2016/03/03 13:19:51 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		ft_tputs(int c)
{
	c = (char)c;
	write(1, &c, 1);
	return (1);
}

int		ft_termcaps_move_to(t_env *env, int x, int y)
{
	if (((env->current_col + x) * env->col_width) > env->win_width)
		env->current_col = 0;
	else
		env->current_col += x;
	if ((env->current_line + y) > env->win_height)
		env->current_line = 0;
	else
		env->current_line += y;
	tputs(tgoto(CMSTR, (env->current_col * env->col_width), env->current_line), 1, ft_tputs);
	return (1);
}