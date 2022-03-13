/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocapers <ocapers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 17:53:53 by ocapers           #+#    #+#             */
/*   Updated: 2022/03/10 19:00:09 by ocapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort(t_stack **a, t_stack **b, int argc)
{
	if ((argc - 1) <= 3)
		sort_three_and_less_elements(a, argc);
	else if ((argc - 1) == 5)
		sort_five_elements(a, b, argc);
	else
		big_sort(a, b, argc);
}

int	find_end(t_stack **a)
{
	t_stack	*end;

	end = (*a);
	while (end->next != NULL)
		end = end->next;
	return (end->value);
}

int	smaller_element_finder(t_stack **a, int a_head_value, int b_head_value)
{
	t_stack	*head;
	int		out;

	head = (*a);
	out = 0;
	while (head && out == 0)
	{
		if (head->value < a_head_value && head->value > b_head_value)
			out = 1;
		head = head->next;
	}
	return (out);
}
