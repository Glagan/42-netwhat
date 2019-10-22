/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   network_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 22:08:50 by ncolomer          #+#    #+#             */
/*   Updated: 2019/10/18 22:33:52 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void byte_to_binary(unsigned int n)
{
	int	c, k, j;

	j = 0;
	for (c = 7; c >= 0; c--)
	{
		k = n >> c;
		if (k & 1)
			printf("%c", '1');
		else
			printf("%c", '0');
	}
}

void print_ip_binary(unsigned int ip[4])
{
	byte_to_binary(ip[0]); printf("."); byte_to_binary(ip[1]); printf(".");
	byte_to_binary(ip[2]); printf("."); byte_to_binary(ip[3]);
}

void parse_ip(char const *str, unsigned int ip[4])
{
	int i,j ;

	i = j = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			ip[j] = (ip[j] * 10) + (str[i] - '0');
		else
			j++;
		i++;
	}
}
