/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remunder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguttenb <vguttenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 18:22:32 by vguttenb          #+#    #+#             */
/*   Updated: 2023/03/25 18:59:27 by vguttenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

double	remunder(double number, double base)
{
	double	result;

	result = remainder(number, base);
	if (result < 0)
		return (result + base);
	return (result);
}
