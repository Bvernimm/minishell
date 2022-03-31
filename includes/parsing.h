/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrogiste <vrogiste@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 10:48:35 by vrogiste          #+#    #+#             */
/*   Updated: 2022/03/31 10:03:59 by vrogiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "minishell.h"

typedef struct s_cmd
{
	char	**exec_args;
	char	*infile;
	char	*outfile;
	bool	append;
	char	*limiter;
	bool	pipe;
}	t_cmd;

/*parsing*/
bool	parse(t_list **alst, char *line);

/*new_cmd*/
t_cmd	*new_cmd(void);
void	init_cmd(t_cmd *cmd);

#endif
