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

#include <ft_select.h>

int			main(int argc, char **argv)
{
	t_env	*env;

	env = ft_get_static_env();
	if (argc == 1)
	{
		ft_putendl("ft_select need arguments");
		return (1);
	}
	ft_init_env(env, argc, argv);
	if (ft_init_term(env) == -1)
	{
		ft_putendl("ft_select cannot be launch without termcaps");
		ft_reset_term(env);
		return (1);
	}
	ft_event_resize_screen(0);
	ft_signals();
	ft_termcaps_catch_key();
	ft_reset_term(env);
	return (0);
}
