/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nd-abreu <nd-abreu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 12:42:26 by frodrig2          #+#    #+#             */
/*   Updated: 2026/08/30 01:42:06 by nd-abreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <limits.h>

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;

typedef enum e_strat
{
	ADAPTIVE,
	SIMPLE,
	MEDIUM,
	COMPLEX
}	t_strat;

typedef enum e_ops
{
	OP_SA,
	OP_SB,
	OP_SS,
	OP_PA,
	OP_PB,
	OP_RA,
	OP_RB,
	OP_RR,
	OP_RRA,
	OP_RRB,
	OP_RRR
}	t_ops;

typedef struct s_data
{
	t_stack	*a;
	t_stack	*b;
	t_strat	strat;
	int		bench_mode;
	float	disorder;
	int		ops_count[11];
}	t_data;

/* ==== MAIN (srcs/main/) ==== */

void	error_exit(t_data *data);

/* ==== UTILS (srcs/utils/) ==== */

t_stack	*stack_new_node(int value);
void	stack_add_bottom(t_stack **stack_p, t_stack *new_node);
void	stack_free(t_stack **stack_p);
t_stack	*stack_get_bottom(t_stack *node);
int		stack_size(t_stack *stack);

/* ==== PARSING (srcs/parse/) ==== */

int		parser(t_data *data, int argc, char **argv);
int		parse_flag(t_data *data, char *arg);
int		parse_numbers(t_data *data, char *arg);

/* ==== OPERATIONS (srcs/ops/) ==== */

void	sa(t_data *data);
void	sb(t_data *data);
void	ss(t_data *data);
void	pa(t_data *data);
void	pb(t_data *data);
void	ra(t_data *data);
void	rb(t_data *data);
void	rr(t_data *data);
void	rra(t_data *data);
void	rrb(t_data *data);
void	rrr(t_data *data);

/* ==== SORTING STRATEGIES (srcs/sort/) ==== */

void	set_disorder(t_data *data);

/* simple - O(n^2) */
void	simple_sort(t_data *data);
/* medium - O(n sqrt(n)) */
void	medium_sort(t_data *data);
/* complex - O(n log n) */
void	complex_sort(t_data *data);

/* ==== BENCHMARKS (srcs/bench/) ==== */

#endif
