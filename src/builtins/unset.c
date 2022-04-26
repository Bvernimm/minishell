/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvernimm <bvernimm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 10:20:37 by bvernimm          #+#    #+#             */
/*   Updated: 2022/04/22 10:34:20 by bvernimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_unset(char **cmd, t_list *table[TABLE_SIZE])
{
	char	*var;
	char	*ptr;
	int		i;

	if (str_n_cmp(cmd[0], "unset", str_len(cmd[0])) != 0)
		return ;
	i = 1;
	while (cmd[i])
	{
		ptr = str_chr(cmd[i], '=');
		var = str_n_dup(cmd[i], ptr - cmd[i]);
		if (errno == ENOMEM)
			return ;
		if (table_find(table, var))
			table_remove(table, var);
		free (var);
		i++;
	}
}