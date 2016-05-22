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

#include <ft_select.h>

void			ft_event_resize_screen(int i)
{
	t_env		*env;
	static int	index;

	(void)i;
	env = ft_get_static_env();
	if ((env->nb_col * env->col_width) <= env->wins.ws_col)
		index = (env->current_col * env->wins.ws_row) + env->current_line;
	if (ioctl(0, TIOCGWINSZ, &(env->wins)) != -1)
	{
		tputs(CLSTR, 0, ft_tputs);
		ft_get_col_li();
		if ((env->nb_col * env->col_width) > env->wins.ws_col)
		{
			ft_print_error_size(env);
		}
		else
		{
			ft_show_list();
			env->current_col = index / env->wins.ws_row;
			env->current_line = index % env->wins.ws_row;
			ft_termcaps_move_stay();
			ft_hover(ft_termcaps_move_stay);
		}
	}
}

void			ft_event_exit(int i)
{
	t_env	*env;

	(void)i;
	printf("exit\n");
	env = ft_get_static_env();
	ft_reset_term(env);
	signal(SIGQUIT, SIG_DFL);
	exit(0);
}

void			ft_event_background(int i)
{
	t_env	*env;
	char	cp[2];

	(void)i;
	cp[0] = ft_get_static_env()->term.c_cc[VSUSP];
	cp[1] = '\0';
	env = ft_get_static_env();
	ft_reset_term(env);
	signal(SIGCONT, ft_signal_handler);
	signal(SIGTSTP, SIG_DFL);
	ioctl(0, TIOCSTI, cp);
}

void			ft_event_foreground(int i)
{
	t_env		*env;
	static int	index;

	(void)i;
	signal(SIGTSTP, ft_signal_handler);
	signal(SIGQUIT, ft_signal_handler);
	env = ft_get_static_env();
	ft_init_term(env);
	index = (env->current_col * env->wins.ws_row) + env->current_line;
	ft_show_list();
	ft_get_col_li();
	env->current_col = index / env->wins.ws_row;
	env->current_line = index % env->wins.ws_row;
	ft_termcaps_move_stay();
	ft_hover(ft_termcaps_move_stay);
}
