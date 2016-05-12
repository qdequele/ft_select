/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:13 by qdequele          #+#    #+#             */
/*   Updated: 2016/03/03 13:19:51 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void			ft_event_resize_screen(int i)
{
	t_env	*env;

	(void)i;
	env = ft_get_static_env();
	if (ioctl(0, TIOCGWINSZ, env->wins) != -1)
	{
		env->win_width = tgetnum("co");
		env->win_height = tgetnum("li");
		printf("size %zu - %zu\n", env->win_width, env->win_height);
	}
}