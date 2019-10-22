/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   network_utils.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 22:08:29 by ncolomer          #+#    #+#             */
/*   Updated: 2019/10/18 22:34:22 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NETWORK_UTILS_H
# define NETWORK_UTILS_H

void byte_to_binary(unsigned int n);

void print_ip_binary(unsigned int ip[4]);

void parse_ip(char const *str, unsigned int ip[4]);

#endif
