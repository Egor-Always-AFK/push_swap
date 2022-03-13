/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_functions_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocapers <ocapers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 20:04:04 by ocapers           #+#    #+#             */
/*   Updated: 2022/03/10 20:13:27 by ocapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

long long	atoi_for_check_range(char *str)
{
	long long		n;
	int		mn;
	int		i;
	long	check_maxmin;

	i = 0;
	n = 0;
	mn = 1;
	check_maxmin = 0;
	while (check_space(str[i]))
		i++;
	if ((str[i] == '-') || (str[i] == '+'))
		if (str[i++] == '-')
			mn = -1;
	while (ft_isdigit(str[i]) && *str)
	{
		if (mn == 1 && check_maxmin > 10)
			return (-1);
		else if (mn == -1 && check_maxmin > 10)
			return (0);
		n = (n * 10) + (str[i] - '0');
		i++;
		check_maxmin++;
	}
	return (n * mn);
}