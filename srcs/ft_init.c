/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:13 by qdequele          #+#    #+#             */
/*   Updated: 2016/03/03 13:19:51 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static t_item	*create_item(char *name)
{
	t_item	*item;

	item = (t_item *)malloc(sizeof(t_item));
	item->name = ft_strdup(name);
	item->selected = 0;
	return (item);
}

int			ft_init_term(t_env *env, int argc, char **argv)
{
	if (tcgetattr(0, env->term) == -1)
		return (0);
	
}

int			ft_init_env(t_env *env, int argc, char **argv)
{
	int		i;

	i = 1;
	env->list = NULL;
	while (i < argc)
	{
		ft_lstaddend(&env->list, ft_lstnew(create_item(argv[i]), sizeof(t_item)));
		i++;
	}
	if (ft_lstcount(env->list) == 0)
		return (0);
	else
		return (1);
}
