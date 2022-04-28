/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrogiste <vrogiste@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 10:23:51 by bvernimm          #+#    #+#             */
/*   Updated: 2022/04/28 12:44:16 by vrogiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	bi_pwd(void)
{
	char	*path;

	path = NULL;
	path = getcwd(NULL, 0);
	if (!path)
		return (exec_error("pwd", NULL, NULL, NULL));
	printf("%s\n", path);
	free (path);
	return (false);
}
