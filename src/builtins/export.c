/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrogiste <vrogiste@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 15:49:40 by bvernimm          #+#    #+#             */
/*   Updated: 2022/04/28 10:04:31 by vrogiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	bi_export(char **cmd, t_shell *shell)
{
	t_var	*new_var;
	int		i;

	if (str_n_cmp(cmd[0], "export", str_len(cmd[0])) != 0)
		return ;
	i = 1;
	while (cmd[i])
	{
		new_var = str_to_var(cmd[i]);
		if (errno == ENOMEM)
			return ;
		if (table_find(shell->table, new_var->key))
			table_remove(shell->table, new_var->key);
		table_add(shell->table, new_var);
		if (errno == ENOMEM)
			return ;
		i++;
	}
}
