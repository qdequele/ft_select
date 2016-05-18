/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_termcaps_remove.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:13 by qdequele          #+#    #+#             */
/*   Updated: 2016/03/03 13:19:51 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	ft_remove_at_index(t_list **head, int index)
{
	t_list	*temp;
	t_list	*prev;
	int		i;

	temp = *head;
	i = 0;
	if (temp != NULL && index == 0)
	{
		*head = temp->next;
		free(temp);
		return ;
	}
	while (temp != NULL && i != index)
	{
		prev = temp;
		temp = temp->next;
		i++;
	}
	if (temp == NULL)
		return ;
	prev->next = temp->next;
	free(temp);
}

void	ft_termcaps_remove(void)
{
	t_env	*env;
	int		tmp_current_col;
	int		tmp_current_line;
	int		index;

	env = ft_get_static_env();
	tmp_current_line = env->current_line;
	tmp_current_col = env->current_col;
	index = (env->current_col * env->wins.ws_row) + env->current_line;
	ft_remove_at_index(&env->list, index);
	ft_show_list();
	env->current_line = tmp_current_line;
	env->current_col = tmp_current_col;
	if (index >= ft_lstcount(env->list))
		ft_hover(ft_termcaps_move_top);
	ft_termcaps_move_stay();
	ft_hover(ft_termcaps_move_stay);
	ft_get_col_li();
}