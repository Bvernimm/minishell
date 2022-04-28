/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrogiste <vrogiste@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 09:52:21 by bvernimm          #+#    #+#             */
/*   Updated: 2022/04/28 11:28:43 by vrogiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	bi_echo(char **cmds)
{
	int		i;

	if (!cmds || str_cmp("echo", *cmds))
		return (true);
	i = 1;
	while (cmds[i])
	{
		if (str_cmp(cmds[1], "-n") || i > 1)
			printf("%s", cmds[i]);
		i++;
	}
	if (str_cmp(cmds[1], "-n"))
		printf("\n");
	return (false);
}
