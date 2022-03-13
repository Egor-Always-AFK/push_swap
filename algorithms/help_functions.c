/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocapers <ocapers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 16:31:21 by ocapers           #+#    #+#             */
/*   Updated: 2022/03/10 18:59:55 by ocapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	count_of_elements(t_stack **stack)
{
	t_stack	*tmp;
	int		count;

	count = 0;
	tmp = (*stack);
	while (tmp != NULL)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}

int	steps_to_min(t_stack **a, int min)
{
	t_stack	*tmp;
	int		steps;

	tmp = (*a);
	steps = 0;
	while (tmp->value != min)
	{
		steps++;
		tmp = tmp->next;
	}
	return (steps);
}

int	find_good_place(t_stack **a, t_stack **b, t_steps *steps, int min_action)
{
	int	action;
	int	res;
	int	buff;

	action = 0;
	buff = 0;
	subfinder(a, b, &action, &buff);
	if ((*a)->rotate == -1)
		action = count_of_elements(a) - action;
	if (min_action == -1 || (action + (*b)->step) < min_action)
	{
		steps->a_step = (*a)->rotate;
		steps->b_step = (*b)->rotate;
		steps->count_a = action;
		steps->count_b = (*b)->step;
		res = action + (*b)->step;
	}
	else
		res = min_action;
	return (res);
}

void	subfinder(t_stack **a, t_stack **b, int *action, int *buff)
{
	t_stack	*head_a;
	int		out;

	out = 0;
	head_a = (*a);
	while (out == 0 && (*a))
	{
		*buff = (*a)->value;
		if ((*b)->value > (*a)->value)
		{
			*action += 1;
			if ((*b)->value < (*a)->next->value)
				out = 1;
			(*a) = (*a)->next;
		}
		else
			out = 1;
	}
	subfinder_part_two(a, b, buff, action);
	(*a) = head_a;
}

void	subfinder_part_two(t_stack **a, t_stack **b, int *buff, int *action)
{
	int	out;

	out = 0;
	if (smaller_element_finder(a, *buff, (*b)->value) == 1)
	{
		while (out == 0 && (*a))
		{
			if ((*a)->value < *buff && (*a)->value > (*b)->value)
				out = 1;
			else
			{
				*action += 1;
				(*a) = (*a)->next;
			}
		}
	}
}
