/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_termcaps_select.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:13 by qdequele          #+#    #+#             */
/*   Updated: 2016/03/03 13:19:51 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	ft_set_selected(t_env *env)
{
	int		i;
	t_list	*tmp_lst;

	tmp_lst = env->list;
	i = 0;
	while (tmp_lst && tmp_lst->content)
	{
		if (i == (env->current_col * env->wins.ws_row) + env->current_line)
		{
			if (((t_item *)tmp_lst->content)->selected == 0)
			{
				((t_item *)tmp_lst->content)->selected = 1;
				env->count_select++;
			}
			else
			{
				((t_item *)tmp_lst->content)->selected = 0;
				env->count_select--;
			}
		}
		i++;
		tmp_lst = tmp_lst->next;
	}
}

void	ft_select(void)
{
	t_env	*env;
	int	tmp_current_col;
	int tmp_current_line;

	env = ft_get_static_env();
	tmp_current_line = env->current_line;
	tmp_current_col = env->current_col;
	ft_set_selected(env);
	ft_show_list();
	env->current_line = tmp_current_line;
	env->current_col = tmp_current_col;
	ft_termcaps_move_bottom();
}