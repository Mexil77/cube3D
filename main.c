/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 12:54:27 by emgarcia          #+#    #+#             */
/*   Updated: 2022/02/15 13:16:06 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	main(int argc, char **argv)
{
	t_general	general;

	if (argc != 2)
	{
		printf("bad arguments.\n");
		return (0);
	}
	printf("mapa : %s\n", argv[1]);
	ft_parsemap(&general, argv[1])
	return (0);
}
