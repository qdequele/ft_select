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

#include "ft_select.h"

static char	*ft_get_name_at_index(t_env *env, int index)
{
	t_list	*tmp_lst;
	int		i;

	i = 0;
	tmp_lst = env->list;
	while (tmp_lst && tmp_lst->content)
	{
		if (i == index)
			return ((((t_item *)tmp_lst->content)->name));
		i++;
		tmp_lst = tmp_lst->next;
	}
	return (NULL);
}

void	ft_hover(void (*f)(void))
{
	t_env	*env;
	int		index;

	env = ft_get_static_env();
	index = (env->current_col * env->wins.ws_row) + env->current_line;

}