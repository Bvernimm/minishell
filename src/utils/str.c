/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrogiste <vrogiste@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 22:21:22 by vrogiste          #+#    #+#             */
/*   Updated: 2022/04/21 10:43:39 by vrogiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	str_len(char *str)
{
	if (str && *str)
		return (1 + str_len(str + 1));
	return (0);
}

void	str_n_cpy(char *dst, char *src, size_t len)
{
	size_t	i;

	i = 0;
	if (dst && src)
	{
		while (src[i] && i < len)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
}

char	to_upper(char c)
{
	if (c >= 'a' && c <= 'z')
		c += 'A' - 'a';
	return (c);
}
