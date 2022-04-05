/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrogiste <vrogiste@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 18:07:43 by vrogiste          #+#    #+#             */
/*   Updated: 2022/04/05 16:21:45 by vrogiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "minishell.h"

typedef struct s_list
{
	void			*content;
	struct s_list	*prev;
	struct s_list	*next;
}	t_list;

/*str*/
size_t	ft_strlen(const char *str);
bool	is_in_str(const char *str, char c);
bool	is_in_quote(char *str, char *quote, size_t index);
void	ft_strncpy(char *dst, char *src, size_t len);

/*str_alloc*/
char	*ft_strndup(const char *str, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
bool	str_append_buff(char **astr, char *buff, size_t size);
void	str_insert(char **astr, char *str, size_t index);

/*lst*/
int		lst_size(t_list *lst);
t_list	*lst_last(t_list *lst);
void	lst_add_front(t_list **alst, t_list *new_node);
void	lst_add_back(t_list **alst, t_list *new_node);

/*lst_alloc*/
t_list	*lst_new(void *content);
void	lst_clear(t_list **lst, void (*del)(void*));

/*get_next_line*/
char	*get_next_line(int fd);

/*get_next_word*/
void	skip_charset(char **ptr, char *charset);
void	skip_next_word(char **ptr, char *charset, char *quotes);
void	erase_next_word(const char *str, char *charset, char *quotes);
char	*get_next_word(const char *str, char *charset, char *quotes);

/*split*/
void	free_split(char **arr);

#endif
