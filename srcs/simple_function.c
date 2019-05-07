/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 14:24:20 by pcredibl          #+#    #+#             */
/*   Updated: 2019/03/20 16:08:25 by pcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_header.h"

int		min(int num1, int num2)
{
	if (num1 <= num2)
		return (num1);
	return (num2);
}

int		max(int num1, int num2)
{
	if (num1 >= num2)
		return (num1);
	return (num2);
}
