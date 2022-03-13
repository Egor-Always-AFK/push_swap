/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocapers <ocapers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 15:21:20 by ocapers           #+#    #+#             */
/*   Updated: 2022/03/05 13:27:37 by ocapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_a(t_stack **a, int output_choise)
{
	t_stack	*tmp;

	if (!(*a) || !((*a)->next))
		return ;
	tmp = *a;
	while ((*a)->next != NULL)
		*a = (*a)->next;
	(*a)->next = tmp;
	*a = tmp->next;
	tmp->next = NULL;
	if (output_choise == 1)
		write (1, "ra\n", 3);
}

void	rotate_b(t_stack **b, int output_choise)
{
	t_stack	*tmp;

	if (!(*b) || !((*b)->next))
		return ;
	tmp = *b;
	while ((*b)-> next != NULL)
		(*b) = (*b)->next;
	(*b)->next = tmp;
	*b = tmp->next;
	tmp->next = NULL;
	if (output_choise == 1)
		write(1, "rb\n", 3);
}

void	rotate_all(t_stack **a, t_stack **b)
{
	rotate_a(a, 0);
	rotate_b(b, 0);
	write(1, "rr\n", 3);
}
