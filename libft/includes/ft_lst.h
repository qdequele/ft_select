/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 11:19:04 by qdequele          #+#    #+#             */
/*   Updated: 2016/02/19 17:18:24 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LST_H
# define FT_LST_H

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstaddend(t_list **alst, t_list *new);
int					ft_lstcount(t_list *lst);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstiter(t_list *lst, void (*f)(t_list *node));
void				ft_lstiter_plus(t_list *lst, void const *info,
	void (*f)(void const *info, t_list *node));
void				ft_lstiter_if(t_list *lst, void (*f)(t_list *node),
	int (*c)(t_list *node));
void				ft_lstiter_if_plus(t_list *lst, void const *info,
	void (*f)(void const *info, t_list *node), int (*c)(t_list *node));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *node));
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lst_bubble_sort(t_list *node, int (*c)(t_list *node));
void				ft_lst_swap(t_list *node1, t_list *node2);
t_list				*ft_lst_reverse(t_list *root);
void				ft_lstcpy(t_list **dest, t_list *src);
#endif
