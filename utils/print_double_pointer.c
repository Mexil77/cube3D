/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_double_pointer.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 15:39:06 by emgarcia          #+#    #+#             */
/*   Updated: 2022/08/21 03:36:59 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void	print_double_pointer(char **double_pointer)
{
	size_t	i;

	i = -1;
	while (double_pointer && double_pointer[++i])
		printf("%s\n", double_pointer[i]);
}
