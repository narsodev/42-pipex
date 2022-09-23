/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narso </var/spool/mail/narso>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 14:19:14 by narso             #+#    #+#             */
/*   Updated: 2022/09/23 19:06:23 by ngonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_check_args(int argc, char **argv)
{
	if (argc < 5)
	{
		ft_printf("Error: minimum four args required\n");
		exit(EXIT_FAILURE);
	}
	if (!ft_strncmp("here_doc", argv[1], ft_strlen(argv[1])))
	{
		if (argc != 6)
		{
			ft_printf("Error: five args required in order to use here_doc\n");
			exit(EXIT_FAILURE);
		}
		return (argv[2]);
	}
	return (NULL);
}
