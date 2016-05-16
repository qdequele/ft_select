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

static void		ft_print_error_size(t_env *env)
{
	ft_print_n_time('*', env->wins.ws_col);
	ft_putchar('\n');
	ft_print_n_time('*', (env->wins.ws_col - 11) / 2);
	ft_putstr(" ft_select ");
	ft_print_n_time('*', (env->wins.ws_col - 11) / 2);
	ft_putchar('\n');
	ft_print_n_time('*', env->wins.ws_col);
	ft_putchar('\n');
	ft_print_n_time(' ', (env->wins.ws_col - 43) / 2);
	ft_putstr(" Your screen is too small, please resize it! ");
	ft_print_n_time(' ', (env->wins.ws_col - 43) / 2);
	ft_putchar('\n');
}

void			ft_event_resize_screen(int i)
{
	t_env	*env;

	(void)i;
	env = ft_get_static_env();
	if (ioctl(0, TIOCGWINSZ, &(env->wins)) != -1)
	{
		tputs(CLSTR, 0, ft_tputs);
		env->current_col = 0;
		env->current_line = 0;
		ft_get_col_li();
		if ((env->nb_col * env->col_width) > env->wins.ws_col)
			ft_print_error_size(env);
		else
		{
			ft_termcaps_move_start();
			ft_show_list();
		}
	}
}

void			ft_event_exit(int i)
{
	t_env	*env;

	(void)i;
	env = ft_get_static_env();
	ft_reset_term(env);
	exit (0);
}