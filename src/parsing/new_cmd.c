/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrogiste <vrogiste@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 09:57:45 by vrogiste          #+#    #+#             */
/*   Updated: 2022/04/07 19:55:27 by vrogiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_cmd(t_cmd *cmd)
{
	if (cmd)
	{
		cmd->exec_args = NULL;
		cmd->infile = NULL;
		cmd->outfile = NULL;
		cmd->append = false;
		cmd->limiter = NULL;
		cmd->connector = NULL;
		cmd->z_index = 0;
	}
}

void	del_cmd(void *args)
{
	t_cmd	*cmd;

	cmd = (t_cmd *) args;
	if (cmd)
	{
		if (cmd->exec_args)
			str_arr_free(cmd->exec_args);
		if (cmd->infile)
			free(cmd->infile);
		if (cmd->outfile)
			free(cmd->outfile);
		if (cmd->limiter)
			free(cmd->limiter);
		if (cmd->connector)
			free(cmd->connector);
		free(cmd);
	}
}
