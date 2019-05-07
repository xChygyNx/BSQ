/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 17:49:52 by pcredibl          #+#    #+#             */
/*   Updated: 2019/03/04 18:03:27 by pcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(char *str)
{
	int res;
	int sign;

	sign = 1;
	res = 0;
	while ((*str == '\t') || (*str == '\v') || (*str == '\n')
			|| (*str == '\f') || (*str == '\r') || (*str == ' '))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str)
	{
		if ((*str >= '0') && (*str <= '9'))
			res = res * 10 + (((int)*str) - 48);
		else
			return (res * sign);
		str++;
	}
	return (res * sign);
}
