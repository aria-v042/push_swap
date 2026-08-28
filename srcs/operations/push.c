/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nd-abreu <nd-abreu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 22:05:05 by nd-abreu          #+#    #+#             */
/*   Updated: 2026/08/28 23:44:52 by nd-abreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack *source, t_stack *dest)
{
	// ...
}

// pa
void	pa(t_data *data)
{
	push(data->b, data->a);
	ft_printf("pa\n");
	data->ops_count[pa]++;
}

// pb
void	pb(t_data *data)
{
	push(data->a, data->b);
	ft_printf("pa\n");
	data->ops_count[pb]++;
}

//sa
void	sa(t_data *data)
{
	push(data->b, data->a);
	ft_printf("sa\n");
	data->ops_count[sa]++;
}


//sb
void	sb(t_data *data)
{
	push(data->a, data->b);
	ft_printf("sb\n");
	data->ops_count[sb]++;
}


//ss
void	ss(t_data *data)
{
	push(data->a, data->b);
	ft_printf("sb\n");
	data->ops_count[sb]++;
}

//ra
void	ra(t_data *data)
{
	push(data->b, data->a);
	ft_printf("ra\n");
	data->ops_count[ra]++;
}

//rb
void	rb(t_data *data)
{
	push(data->a, data->b);
	ft_printf("rb\n");
	data->ops_count[sb]++;
}

//rr
void	rr(t_data *data)
{
	push(data->a, data->b);
	ft_printf("sb\n");
	data->ops_count[sb]++;
}

//rra
void	rra(t_data *data)
{
	push(data->b, data->a);
	ft_printf("rra\n");
	data->ops_count[rra]++;
}

//rrb
void	rrb(t_data *data)
{
	push(data->a, data->b);
	ft_printf("sb\n");
	data->ops_count[rrb]++;
}

//rrr
void	sb(t_data *data)
{
	push(data->a, data->b);
	ft_printf("sb\n");
	data->ops_count[sb]++;
}