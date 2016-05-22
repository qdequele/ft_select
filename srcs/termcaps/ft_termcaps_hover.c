/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_termcaps_mhover.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:13 by qdequele          #+#    #+#             */
/*   Updated: 2016/03/03 13:19:51 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

static t_item	*ft_get_name_at_index(t_env *env, int index)
{
	t_list	*tmp_lst;
	int		i;

	i = 0;
	tmp_lst = env->list;
	while (tmp_lst && tmp_lst->content)
	{
		if (i == index)
			return (((t_item *)tmp_lst->content));
		i++;
		tmp_lst = tmp_lst->next;
	}
	return (NULL);
}

static void	ft_hover_item(t_item *item)
{
	if (item != NULL)
	{
		tputs(USSTR, 0, ft_tputs);
		if (item->selected == 1)
		{
			tputs(MRSTR, 0, ft_tputs);
			ft_putstr(item->name);
			tputs(MESTR, 0, ft_tputs);
		}
		else
			ft_putstr(item->name);
		tputs(UESTR, 0, ft_tputs);
	}
}

static void	ft_unhover_item(t_item *item)
{
	if (item != NULL)
	{
		tputs(UESTR, 0, ft_tputs);
		if (item->selected == 1)
		{
			tputs(MRSTR, 0, ft_tputs);
			ft_putstr(item->name);
			tputs(MESTR, 0, ft_tputs);
		}
		else
			ft_putstr(item->name);
	}
}

void	ft_hover(void (*f)(void))
{
	t_env	*env;
	int		index;

	env = ft_get_static_env();
	index = (env->current_col * env->wins.ws_row) + env->current_line;
	ft_unhover_item(ft_get_name_at_index(env, index));
	f();
	index = (env->current_col * env->wins.ws_row) + env->current_line;
	ft_hover_item(ft_get_name_at_index(env, index));
	ft_get_col_li();
	tputs(tgoto(CMSTR, (env->current_col * env->col_width), env->current_line), 1, ft_tputs);
}
