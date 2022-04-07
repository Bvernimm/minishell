/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrogiste <vrogiste@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 19:15:14 by vrogiste          #+#    #+#             */
/*   Updated: 2022/04/07 22:11:37 by vrogiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	cmd_parse_loop(t_cmd *cmd, char *cmd_line)
{
	char	*arg;

	arg = str_tok_simple(cmd_line, ' ', QUOTES);
	if (arg)
	{
		if (redirection(cmd, arg))
		{
			str_tok_simple(NULL, '\0', NULL);
			return (true);
		}
		return (cmd_parse_loop(cmd, cmd_line));
	}
	str_tok_simple(NULL, '\0', NULL);
}

bool	parse_cmd(t_cmd *cmd, char *cmd_line, char *con)
{
	char	*cmd_line_cpy;

	if (cmd)
	{
		cmd_line_cpy = str_n_dup(cmd_line, str_len(cmd_line));
		if (!cmd_line_cpy)
			return (true);
		cmd->connector = con;
		format(&cmd_line_cpy);
		if (!cmd_line_cpy)
			return (true);
		if (cmd_parse_loop(cmd, cmd_line_cpy))
		{
			free(cmd_line_cpy);
			return (true);
		}
		free(cmd_line_cpy);
		return (false);
	}
}