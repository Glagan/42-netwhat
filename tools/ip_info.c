/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ip_info.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 20:27:58 by ncolomer          #+#    #+#             */
/*   Updated: 2019/10/22 16:53:29 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "network_utils.h"

/**
 * With an IP address and a mask, return the range of the subnet
 **/

int	main(int argc, char const *argv[])
{
	unsigned int ip[4] = { 0 };
	unsigned int mask[4] = { 0 };
	unsigned int subnet[4] = { 0 };
	unsigned int host[4] = { 0 };
	unsigned int range[4] = { 0 };
	unsigned int cidr;
	int	i, j, k;
	unsigned int t;
	int	available_addresses;

	// Get the IP
	parse_ip(argv[1], ip);

	// Mask
	// 255.255.0.0
	if (strchr(argv[2], '.'))
	{
		i = j = 0;
		parse_ip(argv[2], mask);
		// Get the cidr from the mask, count the number of 1 from the left
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
		cidr = atoi(argv[2]);
		// Get the mask from the cidr, add cidr nbr of bytes from the left
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

	// Subnet: & the IP and the mask
	i = 0;
	while (i < 4)
	{
		subnet[i] = ip[i] & mask[i];
		range[i] = subnet[i];
		i++;
	}

	// Host: Keep only the opposite on mask and & with the IP
	i = 0;
	while (i < 4)
	{
		host[i] = ip[i] & ~mask[i];
		i++;
	}

	// Range
	range[3] += (available_addresses - 1);
	if (available_addresses > 255)
		range[3] -= (available_addresses % 256);
	i = 3;
	while (i > 0)
	{
		while (range[i] > 255)
		{
			range[i - 1]++;
			range[i] -= 256;
		}
		i--;
	}

	// Display informations
	printf("IP:\t\t\t%u.%u.%u.%u/%u\n\t\t\t", ip[0], ip[1], ip[2], ip[3], cidr);
	print_ip_binary(ip);
	printf("\nMask:\t\t\t%u.%u.%u.%u\n\t\t\t", mask[0], mask[1], mask[2], mask[3]);
	print_ip_binary(mask);
	printf("\nHost:\t\t\t%u.%u.%u.%u/%u\n\t\t\t", subnet[0], subnet[1], subnet[2], subnet[3], cidr);
	print_ip_binary(subnet);
	printf("\nIP (No Host):\t\t%u.%u.%u.%u\n\t\t\t", host[0], host[1], host[2], host[3]);
	print_ip_binary(host);
	printf("\nAvailable addresses:\t%d (without host and broadcast: %d)", available_addresses, (available_addresses <= 2) ? available_addresses : available_addresses - 2);
	printf("\nIP Range:\t\t%u.%u.%u.%u - %u.%u.%u.%u\n", subnet[0], subnet[1], subnet[2], subnet[3], range[0], range[1], range[2], range[3]);

	return 0;
}
