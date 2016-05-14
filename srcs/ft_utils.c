/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:13 by qdequele          #+#    #+#             */
/*   Updated: 2016/03/03 13:19:51 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_get_col_li(void)
{
	t_env	*env;

	env = ft_get_static_env();
	env->nb_col = (ft_lstcount(env->list) / env->wins.ws_row);
	env->last_col = ft_lstcount(env->list) % env->wins.ws_row;
	if (env->last_col != 0)
		env->nb_col++;
}

void	ft_show_list(void)
{
	t_list	*elem;
	t_item	*item;
	t_env	*env;

	env = ft_get_static_env();
	elem = env->list;
	tputs(CLSTR, 0, ft_tputs);
	ft_termcaps_move_start();
	if (elem && elem->content)
	{
		while (elem)
		{
			item = (t_item *)elem->content;
			if (item->selected == 1)
			{
				tputs(MRSTR, 0, ft_tputs);
				ft_putstr(item->name);
				tputs(MESTR, 0, ft_tputs);
			}
			else
				ft_putstr(item->name);
			ft_termcaps_move_bottom();
			elem = elem->next;
		}
	}
}

void	ft_show_list_selected(void)
{
	t_list	*elem;
	t_item	*item;
	t_env	*env;

	env = ft_get_static_env();
	elem = env->list;
	ft_reset_term(env);
	if (elem && elem->content)
	{
		while (elem)
		{
			item = (t_item *)elem->content;
			if (item->selected == 1)
			{
				ft_putstr(item->name);
				env->count_select--;
				if (env->count_select != 0)
					ft_putstr(" ");
			}
			elem = elem->next;
		}
	}
	exit(0);
}
