/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addresses_from_mask.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 20:27:58 by ncolomer          #+#    #+#             */
/*   Updated: 2019/10/18 22:32:20 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "network_utils.h"

/**
 * With the amount of available addresses from a mask
 **/

int	main(int argc, char const *argv[])
{
	unsigned int mask[4] = { 0 };
	unsigned int cidr;
	int	i, j, k;
	unsigned int t;
	int	available_addresses;

	// Mask
	// 255.255.0.0
	if (strchr(argv[1], '.'))
	{
		i = j = 0;
		parse_ip(argv[1], mask);
		cidr = i = j = 0;
		while (i < 4) {
			t = mask[i];
			while (t & 0b10000000)
			{
				cidr++;
				t = t << 1;
			}
			if (t == 0)
				i = 4;
			i++;
		}
	}
	// /25
	else
	{
		cidr = atoi(argv[1]);
		i = cidr;
		k = j = 0;
		while (i > 0)
		{
			mask[j] = (0b10000000 | (mask[j] >> 1));
			if (++k == 8)
			{
				k = 0;
				j++;
			}
			i--;
		}
	}

	// Count available addresses
	available_addresses = pow(2, 32 - cidr);

	// Display informations
	printf("Mask:\t%u.%u.%u.%u (%u)\n\t", mask[0], mask[1], mask[2], mask[3], cidr);
	print_ip_binary(mask);
	printf("\nAvailable addresses:\t%d (without host and broadcast: %d)\n", available_addresses, (available_addresses <= 2) ? available_addresses : available_addresses - 2);

	return 0;
}
