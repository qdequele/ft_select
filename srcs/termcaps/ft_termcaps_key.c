/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_termcaps_key.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:13 by qdequele          #+#    #+#             */
/*   Updated: 2016/03/03 13:19:51 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void	ft_termcaps_catch_key(void)
{
	char	buf[3];
	int		ret;

	ft_show_empty_list();
	ft_bzero(buf, 3);
	while ((ret = read(0, buf, 3)) != -1)
	{
		if (TOP)
			ft_hover(ft_termcaps_move_top);
		else if (BOTTOM)
			ft_hover(ft_termcaps_move_bottom);
		else if (RIGHT)
			ft_hover(ft_termcaps_move_right);
		else if (LEFT)
			ft_hover(ft_termcaps_move_left);
		else if (SPACE)
			ft_select();
		else if (BACK_SPACE || DELETE)
			ft_termcaps_remove();
		else if (ENTER)
			ft_show_list_selected();
		else if (ECHAP)
			ft_event_exit(0);
		ft_bzero(buf, 3);
	}
}
