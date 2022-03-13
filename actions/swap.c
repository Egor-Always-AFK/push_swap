/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocapers <ocapers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 15:21:26 by ocapers           #+#    #+#             */
/*   Updated: 2022/03/05 13:27:40 by ocapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_a(t_stack **a, int output_choise)
{
	int		i;

	if (!(*a) || !((*a)->next))
		return ;
	i = (*a)->value;
	(*a)->value = (*a)->next->value;
	(*a)->next->value = i;
	if (output_choise == 1)
		write(1, "sa\n", 3);
}

void	swap_b(t_stack **b, int output_choise)
{
	int		i;

	if (!(*b) || !((*b)->next))
		return ;
	i = (*b)->value;
	(*b)->value = (*b)->next->value;
	(*b)->next->value = i;
	if (output_choise == 1)
		write(1, "sb\n", 3);
}

void	swap_all(t_stack **a, t_stack **b)
{
	swap_a(a, 0);
	swap_b(b, 0);
	write(1, "ss\n", 3);
}
