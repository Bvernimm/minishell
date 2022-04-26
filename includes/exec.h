/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrogiste <vrogiste@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 10:33:26 by vrogiste          #+#    #+#             */
/*   Updated: 2022/04/26 12:50:13 by vrogiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "minishell.h"

# define PIPE_READ 0
# define PIPE_WRITE 1

/*launcher*/
void	launcher(t_list *lst, int z, t_list **alst);

/*pipex*/
void	close_pipe(int fds[2]);
void	pipex(t_list *lst, t_list **alst, int fds[2]);

/*error_pipex*/
void	error_pipex(char *str, int i_pipe[2], int o_pipe[2]);

/*exec*/
void	exec(char **cmds);
void	exec_builtin(t_cmd *cmd, int o_pipe[2]);

#endif