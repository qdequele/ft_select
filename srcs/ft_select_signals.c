/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sigmal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:13 by qdequele          #+#    #+#             */
/*   Updated: 2016/03/03 13:19:51 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void	ft_signal_handler(int i)
{
	if (i == SIGINT || i == SIGQUIT || i == SIGKILL || i == SIGSTOP)
		ft_event_exit(i);
	else if (i == SIGTSTP)
		ft_event_background(i);
	else if (i == SIGCONT)
		ft_event_foreground(i);
	else if (i == SIGWINCH)
		ft_event_resize_screen(i);
	i = 0;
}

void	ft_signals(void)
{
	signal(SIGINT, ft_signal_handler);
	signal(SIGTSTP, ft_signal_handler);
	signal(SIGCONT, ft_signal_handler);
	signal(SIGQUIT, ft_signal_handler);
	signal(SIGKILL, ft_signal_handler);
	signal(SIGSTOP, ft_signal_handler);
	signal(SIGWINCH, ft_signal_handler);
}