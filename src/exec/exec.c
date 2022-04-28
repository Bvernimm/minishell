/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrogiste <vrogiste@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 12:45:34 by vrogiste          #+#    #+#             */
/*   Updated: 2022/04/28 13:26:16 by vrogiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_bin(char **cmds, t_shell *shell)
{
	char	**paths;
	char	*cmd;

	paths = split(((t_var *)table_find(shell->table, "PATH")->content)->data, ':');
	while (*paths)
	{
		cmd = str_dup(*cmds);
		str_n_insert(&cmd, "/", 0, 1);
		str_n_insert(&cmd, *paths, 0, str_len(*paths));
		execve(cmd, cmds, NULL);
		paths++;
	}
	exit(EXIT_FAILURE);
}

bool	exec_builtin(t_cmd *cmd, t_shell *shell)
{
	char	**cmds;
	bool	err;

	err = false;
	if (!str_cmp((char *)cmd->args->content, "exit"))
		bi_exit(shell);
	if (!str_cmp((char *)cmd->args->content, "pwd") && bi_pwd())
		return (bi_pwd());
	else if (!str_cmp((char *)cmd->args->content, "env"))
		return (bi_env(shell));
	cmds = lst_to_str_arr(cmd->args);
	if (!cmds)
		return (exec_error("exec_builtin", NULL, NULL, NULL));
	if (!str_cmp((char *)cmd->args->content, "echo"))
		err = bi_echo(cmds);
	else if (!str_cmp((char *)cmd->args->content, "cd"))
		err = bi_cd(cmds, shell);
	else if (!str_cmp((char *)cmd->args->content, "export"))
		err = bi_export(cmds, shell);
	else if (!str_cmp((char *)cmd->args->content, "unset"))
		err = bi_unset(cmds, shell);
	str_arr_free(cmds);
	return (err);
}
