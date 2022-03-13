/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   less_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocapers <ocapers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 15:23:25 by ocapers           #+#    #+#             */
/*   Updated: 2022/02/02 15:23:25 by ocapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_three_and_less_elements(t_stack **a, int argc)
{
	int	i;

	i = 0;
	if (argc == 3)
		if ((*a)->value > (*a)->next->value)
			swap_a(a, 1);
	if (argc == 4)
		sort_three_elements(a, 1);
}

void	sort_three_elements(t_stack **a, int path)
{
	if ((*a)->value < (*a)->next->value
		&& (*a)->value < (*a)->next->next->value
		&& (*a)->next->value < (*a)->next->next->value)
		return ;
	if ((*a)->value < (*a)->next->value
		&& (*a)->value < (*a)->next->next->value)
		rotate_a(a, 1);
	if ((*a)->value < (*a)->next->value
		&& (*a)->value > (*a)->next->next->value)
		reverse_rotate_a(a, 1);
	if ((*a)->value > (*a)->next->value
		&& (*a)->value > (*a)->next->next->value)
		rotate_a(a, 1);
	if ((*a)->value > (*a)->next->value
		&& (*a)->value < (*a)->next->next->value)
		swap_a(a, 1);
	if (path == 1)
		exit(1);
}

void	sort_five_elements(t_stack **a, t_stack **b, int argc)
{
	int	min;
	int	max;

	min = find_min(a, argc);
	max = find_max(a, argc);
	while ((*a)->next->next->next != NULL)
	{
		if (((*a)->value == max) || ((*a)->value == min))
			push_b(a, b);
		else
			rotate_a(a, 1);
	}
	sort_three_elements(a, 0);
	push_a(a, b);
	push_a(a, b);
	if ((*a)->value == find_max(a, argc))
		rotate_a(a, 1);
	else
	{
		swap_a(a, 1);
		rotate_a(a, 1);
	}
}
