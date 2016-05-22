/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:13 by qdequele          #+#    #+#             */
/*   Updated: 2016/03/03 13:19:51 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void	ft_show_empty_list(void)
{
	t_env	*env;

	env = ft_get_static_env();
	if (ft_lstcount(env->list) == 0)
	{
		ft_reset_term(env);
		exit(0);
	}
}

void	ft_print_error_size(t_env *env)
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
