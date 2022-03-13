/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocapers <ocapers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 15:21:15 by ocapers           #+#    #+#             */
/*   Updated: 2022/03/05 13:27:34 by ocapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	reverse_rotate_a(t_stack **a, int output_choise)
{
	t_stack	*tmp;

	if (!(*a) || !((*a)->next))
		return ;
	tmp = *a;
	while ((*a)->next->next)
		*a = (*a)->next;
	(*a)->next->next = tmp;
	tmp = (*a)->next;
	(*a)->next = NULL;
	*a = tmp;
	if (output_choise == 1)
		write (1, "rra\n", 4);
}

void	reverse_rotate_b(t_stack **b, int output_choise)
{
	t_stack	*tmp;

	if (!(*b) || !((*b)->next))
		return ;
	tmp = *b;
	while ((*b)->next->next)
		*b = (*b)->next;
	(*b)->next->next = tmp;
	tmp = (*b)->next;
	(*b)->next = NULL;
	*b = tmp;
	if (output_choise == 1)
		write (1, "rrb\n", 4);
}

void	reverse_rotate_all(t_stack **a, t_stack **b)
{
	reverse_rotate_a(a, 0);
	reverse_rotate_b(b, 0);
	write (1, "rrr\n", 4);
}
