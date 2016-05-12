/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:13 by qdequele          #+#    #+#             */
/*   Updated: 2016/03/03 13:19:51 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static t_item	*ft_create_item(char *name)
{
	t_item	*item;

	item = (t_item *)malloc(sizeof(t_item));
	item->name = ft_strdup(name);
	item->selected = 0;
	return (item);
}

int				ft_init_term(t_env *env)
{
	if ((env->term_name = getenv("TERM")) == NULL)
		return (-1);
	if (tgetent(NULL, env->term_name) == 0)
		return (-1);
	if (tcgetattr(0, env->term) == -1)
		return (0);
	env->term->c_lflag &= ~(ICANON);
	env->term->c_lflag &= ~(ECHO);
	env->term->c_cc[VMIN] = 1;
	env->term->c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSANOW, env->term) == -1)
		return (-1);
	tputs(tgetstr("cl", NULL), 0, ft_tputs);
	return (1);
}

int				ft_reset_term(t_env *env)
{
	if (tcgetattr(0, env->term) == -1)
		return (-1);
	env->term->c_lflag = (ICANON | ECHO);
	if (tcsetattr(0, 0, env->term) == -1)
		return (-1);
	tputs(CLSTR, 0, ft_tputs);
	return (1);
}

int				ft_init_env(t_env *env, int argc, char **argv)
{
	int		i;

	i = 1;
	env->list = NULL;
	env->current_col = 0;
	env->current_line = 0;
	env->col_width = 0;
	while (i < argc)
	{
		if (ft_strlen(argv[i]) > env->col_width)
			env->col_width = ft_strlen(argv[i]);
		ft_lstaddend(&env->list, ft_lstnew(ft_create_item(argv[i]), sizeof(t_item)));
		i++;
	}
	if (ft_lstcount(env->list) == 0)
		return (0);
	else
		return (1);
}

void			ft_init_sig(void)
{
	signal(SIGWINCH, ft_event_resize_screen);
}