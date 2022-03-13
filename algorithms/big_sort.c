/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocapers <ocapers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 18:00:08 by ocapers           #+#    #+#             */
/*   Updated: 2022/03/10 18:56:32 by ocapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	big_sort(t_stack **a, t_stack **b, int argc)
{
	int	min;
	int	max;
	int	mid;

	min = find_min(a, argc);
	max = find_max(a, argc);
	mid = find_mid(a, argc);
	while (count_of_elements(a) > 2)
	{
		if ((*a)->value != min && (*a)->value != max)
		{
			push_b(a, b);
			if ((*b)->value > mid)
				rotate_b(b, 1);
		}
		else
			rotate_a(a, 1);
	}
	if ((*a)->value < (*a)->next->value)
		swap_a(a, 1);
	push_a(a, b);
	first_part_of_sort(a, b, argc, min);
}

void	first_part_of_sort(t_stack **a, t_stack **b, int argc, int min)
{
	t_steps	*head;

	head = (t_steps *)malloc(sizeof(t_steps));
	while (count_of_elements(b) != 0)
	{
		head->count_a = -1;
		head->count_b = -1;
		head->a_step = 0;
		head->b_step = 0;
		mark_steps_all_elements(a, count_of_elements(a));
		mark_steps_all_elements(b, count_of_elements(b));
		min_action(a, b, head);
		action_manager(a, b, head);
	}
	if (steps_to_min(a, min) > count_of_elements(a) / 2)
		while ((*a)->value != min)
			reverse_rotate_a(a, 1);
	else
		while ((*a)->value != min)
			rotate_a(a, 1);
	free(head);
}

void	mark_steps_all_elements(t_stack **stack, int count)
{
	int		i;
	int		iter;
	t_stack	*buff;

	i = -1;
	iter = count / 2;
	buff = (*stack);
	while (++i <= iter)
	{
		buff->step = i;
		buff->rotate = 1;
		buff = buff->next;
	}
	if (count % 2 == 0)
		i--;
	while (--i > 0)
	{
		buff->step = i;
		buff->rotate = -1;
		buff = buff->next;
	}
}

void	min_action(t_stack **a, t_stack **b, t_steps *steps)
{
	int		min_action;
	t_stack	*head_b;
	t_stack	*head_a;

	min_action = -1;
	head_a = (*a);
	head_b = (*b);
	while ((*b))
	{
		min_action = find_good_place(a, b, steps, min_action);
		(*a) = head_a;
		(*b) = (*b)->next;
	}
	(*b) = head_b;
}

void	action_manager(t_stack **a, t_stack **b, t_steps *steps)
{
	while (steps->count_a > 0)
	{
		if (steps->a_step == 1)
			rotate_a(a, 1);
		else
			reverse_rotate_a(a, 1);
		steps->count_a--;
	}
	while (steps->count_b > 0)
	{
		if (steps->b_step == 1)
			rotate_b(b, 1);
		else
			reverse_rotate_b(b, 1);
		steps->count_b--;
	}
	push_a(a, b);
}
