/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:13 by qdequele          #+#    #+#             */
/*   Updated: 2016/03/03 13:19:51 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_env	*ft_get_static_env(void)
{
	static t_env	env;
	return (&env);
}

void	ft_show_list(t_list *list)
{
	t_list	*elem;
	t_item	*item;
	int		i;

	elem = list;
	i = 0;
	if (elem && elem->content)
	{
		while (elem)
		{
			item = (t_item *)elem->content;
			ft_putstr(item->name);
			ft_putstr(" : ");
			ft_putendl(ft_itoa(item->selected));
			elem = elem->next;
			i++;
		}
	}
}

int			main(int argc, char **argv)
{
	t_env	*env;

	env = ft_get_static_env();
	ft_init_env(env, argc, argv);
	ft_init_term(env);
	ft_init_sig();
	ft_event_resize_screen(0);
	while (1)
	{
		tputs(CLSTR, 0, ft_tputs);
		ft_termcaps_catch_key(env);
	}
	ft_reset_term(env);
	return (0);
}
