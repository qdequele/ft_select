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
# include <signal.h>
# include <sys/ioctl.h>

# define TOP ((buf[0] == 27 && buf[1] == 91 && buf[2] == 65))
# define BOTTOM ((buf[0] == 27 && buf[1] == 91 && buf[2] == 66))
# define RIGHT ((buf[0] == 27 && buf[1] == 91 && buf[2] == 67))
# define LEFT ((buf[0] == 27 && buf[1] == 91 && buf[2] == 68))
# define SPACE ((buf[0] == 32 && buf[1] == 0 && buf[2] == 0))
# define BACK_SPACE ((buf[0] == 127 && buf[1] == 0 && buf[2] == 0))
# define DELETE ((buf[0] == 27 && buf[1] == 91 && buf[2] == 51))
# define ENTER ((buf[0] == 10 && buf[1] == 0 && buf[2] == 0))
# define ECHAP ((buf[0] == 27 && buf[1] == 0 && buf[2] == 0))

# define CLSTR (tgetstr("cl", NULL))
# define HOSTR (tgetstr("ho", NULL))
# define USSTR (tgetstr("us", NULL))
# define MRSTR (tgetstr("mr", NULL))
# define TESTR (tgetstr("te", NULL))
# define CMSTR (tgetstr("cm", NULL))
# define MESTR (tgetstr("me", NULL))
# define VESTR (tgetstr("ve", NULL))
# define VISTR (tgetstr("vi", NULL))
# define UESTR (tgetstr("ue", NULL))

typedef struct termios	t_termios;
typedef struct winsize	t_winsize;

typedef struct			s_item
{
	char				*name;
	int					selected;
}						t_item;

typedef struct			s_env
{
	t_list				*list;
	t_termios			term;
	t_termios			old_term;
	t_winsize			wins;
	char				*term_name;
	int					current_col;
	int					current_line;
	int					col_width;
	int					nb_col;
	int					last_col;
	int					count_select;
}						t_env;
/*
**	TERMCAPS
*/
void					ft_hover(void (*f)(void));
void					ft_termcaps_catch_key(void);
void					ft_termcaps_remove(void);
void					ft_select(void);
void					ft_get_col_li(void);
int						ft_tputs(int c);
/*
**	TERMCAPS MOVE
*/
void					ft_termcaps_move_start(void);
void					ft_termcaps_move_bottom(void);
void					ft_termcaps_move_top(void);
void					ft_termcaps_move_left(void);
void					ft_termcaps_move_right(void);
void					ft_termcaps_move_stay(void);
/*
**	EVENTS
*/
void					ft_event_exit(int i);
void					ft_event_resize_screen(int i);
void					ft_event_background(int i);
void					ft_event_foreground(int i);
void					ft_signal_handler(int i);
void					ft_signals(void);
/*
**	ENV
*/
t_env					*ft_get_static_env(void);
int						ft_init_term(t_env *env);
int						ft_reset_term(t_env *env);
int						ft_init_env(t_env *env, int argc, char **argv);
/*
**	ERRORS
*/
void					ft_show_empty_list(void);
void					ft_print_error_size(t_env *env);
/*
**	SHOW
*/
void					ft_show_list(void);
void					ft_show_list_selected(void);
#endif
