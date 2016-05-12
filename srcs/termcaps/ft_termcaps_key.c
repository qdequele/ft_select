/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcaps_key.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:13 by qdequele          #+#    #+#             */
/*   Updated: 2016/03/03 13:19:51 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		ft_termcaps_catch_key(t_env *env)
{
	char	buf[3];

	ft_bzero(buf, 3);
	read(0, buf, 3);
	// printf("%d - %d - %d\n", buf[0], buf[1], buf[2]);
	if (TOP)
		ft_termcaps_move_to(env, 0, -1);
	else if (BOTTOM)
		ft_termcaps_move_to(env, 0, 1);
	else if (RIGHT)
		ft_termcaps_move_to(env, 1, 0);
	else if (LEFT)
		ft_termcaps_move_to(env, -1, 0);
	else if (SPACE)
		printf("SPACE\n");
	else if (BACK_SPACE)
		printf("BACK_SPACE\n");
	else if (DELETE)
		printf("DELETE\n");
	else if (ENTER)
		printf("ENTER\n");
	else if (ECHAP)
		ft_reset_term(env);
	return (1);
}