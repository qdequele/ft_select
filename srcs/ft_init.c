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

#include <ft_select.h>

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
	char	buff_env[4096];

	if ((env->term_name = getenv("TERM")) == NULL)
		return (-1);
	if (tgetent(buff_env, env->term_name) != 1)
		return (-1);
	if (tcgetattr(0, &(env->term)) == -1)
		return (0);
	env->term.c_lflag &= ~(ICANON);
	env->term.c_lflag &= ~(ECHO);
	env->term.c_cc[VMIN] = 1;
	env->term.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSANOW, &(env->term)) == -1)
		return (-1);
	tputs(CLSTR, 0, ft_tputs);
	tputs(VISTR, 0, ft_tputs);
	return (1);
}

int				ft_reset_term(t_env *env)
{
	if (tcgetattr(0, &(env->term)) == -1)
		return (-1);
	env->term.c_lflag = (ICANON | ECHO);
	if (tcsetattr(0, 0, &(env->term)) == -1)
		return (-1);
	tputs(CLSTR, 0, ft_tputs);
	tputs(VESTR, 0, ft_tputs);
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
	env->nb_col = 0;
	env->last_col = 0;
	env->count_select = 0;
	while (i < argc)
	{
		if ((int)ft_strlen(argv[i]) + 1 > env->col_width)
			env->col_width = ft_strlen(argv[i]) + 1;
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
	ft_check_signal(0);
	signal(SIGWINCH, ft_check_signal);
	signal(SIGINT, ft_check_signal);
	signal(SIGTSTP, ft_check_signal);
	signal(SIGCONT, ft_check_signal);
	signal(SIGQUIT, ft_check_signal);
}