/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_termcaps_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:13 by qdequele          #+#    #+#             */
/*   Updated: 2016/03/03 13:19:51 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

int		ft_tputs(int c)
{
	c = (char)c;
	write(1, &c, 1);
	return (1);
}

void	ft_termcaps_move_stay(void)
{
	t_env	*env;

	env = ft_get_static_env();
	tputs(tgoto(CMSTR, (env->current_col * env->col_width),
		env->current_line), 1, ft_tputs);
}

void	ft_get_col_li(void)
{
	t_env	*env;

	env = ft_get_static_env();
	env->nb_col = 0;
	env->last_col = 0;
	env->nb_col = (ft_lstcount(env->list) / env->wins.ws_row);
	env->last_col = ft_lstcount(env->list) % env->wins.ws_row;
	if (env->last_col != 0)
		env->nb_col++;
	else
		env->last_col = env->wins.ws_row;
}
