/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:17 by qdequele          #+#    #+#             */
/*   Updated: 2016/03/03 13:32:52 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H
# include <libft.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <termios.h>
# include <term.h>
# include <stdio.h>
# include <sys/ioctl.h>

# define TOP ((buf[0] == 27 && buf[1] == 91 && buf[2] == 65))
# define BOTTOM ((buf[0] == 27 && buf[1] == 91 && buf[2] == 66))
# define RIGHT ((buf[0] == 27 && buf[1] == 91 && buf[2] == 67))
# define LEFT ((buf[0] == 27 && buf[1] == 91 && buf[2] == 68))
# define SPACE ((buf[0] == 32 && buf[1] == 10 && buf[2] == 0))
# define BACK_SPACE ((buf[0] == 127 && buf[1] == 0 && buf[2] == 0))
# define DELETE ((buf[0] == 27 && buf[1] == 91 && buf[2] == 51))
# define ENTER ((buf[0] == 10 && buf[1] == 0 && buf[2] == 0))
# define ECHAP ((buf[0] == 27 && buf[1] == 10 && buf[2] == 0))

# define CLSTR (tgetstr("cl", NULL)) //Clear the screen
# define HOSTR (tgetstr("ho", NULL)) //Home cursor
# define USSTR (tgetstr("us", NULL)) //Begin underline mode
# define MRSTR (tgetstr("mr", NULL)) //Turn on reverse video mode
# define TESTR (tgetstr("te", NULL)) //Strings to end programs using cup
# define CMSTR (tgetstr("cm", NULL)) //Move to row #1 columns #2
# define MESTR (tgetstr("me", NULL)) //Turn off all attributes
# define VESTR (tgetstr("ve", NULL)) //Make cursor appear normal


typedef struct termios t_termios;
typedef struct winsize	t_winsize;

typedef struct	s_item
{
	char		*name;
	int			selected;
}				t_item;

typedef struct	s_env
{
	t_list		*list;
	t_termios	*term;
	t_winsize	*wins;
	char		*term_name;
	size_t		current_col;
	size_t		current_line;
	size_t		col_width;
	size_t		win_width;
	size_t		win_height;
}				t_env;
/*
**	termcaps.c
*/
int			ft_tputs(int c);
int			ft_termcaps_catch_key(t_env *env);
int			ft_termcaps_move_to(t_env *env, int x, int y);
/*
**	ft_init.c
*/
int			ft_init_term(t_env *env);
int			ft_reset_term(t_env *env);
int			ft_init_env(t_env *env, int argc, char **argv);
t_env		*ft_get_static_env(void);
void		ft_init_sig(void);
void		ft_event_resize_screen(int i);
#endif
