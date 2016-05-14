/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_termcaps_move.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:13 by qdequele          #+#    #+#             */
/*   Updated: 2016/03/03 13:19:51 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_termcaps_move_start(void)
{
	t_env	*env;

	env = ft_get_static_env();
	env->current_line = 0;
	env->current_col = 0;
	tputs(tgoto(CMSTR, (env->current_col * env->col_width), env->current_line), 1, ft_tputs);
}

void	ft_termcaps_move_bottom(void)
{
	t_env	*env;

	env = ft_get_static_env();
	if (( env->current_col == env->nb_col - 1
		&& env->current_line + 1 >= env->last_col))
	{
		env->current_line = 0;
		env->current_col = 0;
	}
	else if ((env->current_line + 1) >= env->wins.ws_row)
	{
		env->current_line = 0;
		env->current_col++;
	}
	else
		env->current_line++;
	tputs(tgoto(CMSTR, (env->current_col * env->col_width), env->current_line), 1, ft_tputs);
}

void	ft_termcaps_move_top(void)
{
	t_env	*env;

	env = ft_get_static_env();
	if ((env->current_line - 1) < 0)
	{
		if (env->current_col == 0)
		{
			env->current_line = env->last_col - 1;
			env->current_col = env->nb_col - 1;
		}
		else
		{
			env->current_line = env->wins.ws_row;
			env->current_col--;
		}
	}
	else
		env->current_line--;
	tputs(tgoto(CMSTR, (env->current_col * env->col_width), env->current_line), 1, ft_tputs);
}

void	ft_termcaps_move_left(void)
{
	t_env	*env;

	env = ft_get_static_env();
	if ((env->current_col - 1) < 0)
	{
		if (env->current_line >= env->last_col - 1)
		{
			env->current_line = env->last_col - 1;
			env->current_col = env->nb_col - 1;
		}
		else
		{
			env->current_col = env->nb_col - 1;
		}
	}
	else
		env->current_col--;
	tputs(tgoto(CMSTR, (env->current_col * env->col_width), env->current_line), 1, ft_tputs);
}

void	ft_termcaps_move_right(void)
{
	t_env	*env;

	env = ft_get_static_env();
	if ((env->current_col + 1) >= env->nb_col)
		env->current_col = 0;
	else
	{
		if (env->current_col + 1 == env->nb_col - 1
			&& env->current_line >= env->last_col - 1)
		{
			env->current_line = env->last_col - 1;
		}
		env->current_col++;
	}
	tputs(tgoto(CMSTR, (env->current_col * env->col_width), env->current_line), 1, ft_tputs);
}