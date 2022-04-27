/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrogiste <vrogiste@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 14:43:11 by vrogiste          #+#    #+#             */
/*   Updated: 2022/04/27 09:54:18 by vrogiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	child(t_cmd *cmd, int i_pipe[2], int o_pipe[2], t_list **alst)
{
	char	**cmds;

	if (dup_stdin(cmd, i_pipe) || dup_stdout(cmd, o_pipe))
	{
		lst_clear(alst, del_cmd);
		exit(EXIT_FAILURE);
	}
	if (is_tok((char *)cmd->args->content, "env:echo:pwd", ':'))
	{
		exec_builtin(cmd);
		lst_clear(alst, del_cmd);
		exit(EXIT_SUCCESS);
	}
	cmds = lst_to_str_arr(cmd->args);
	exec(cmds);
}
