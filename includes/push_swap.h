/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nd-abreu <nd-abreu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 12:42:26 by frodrig2          #+#    #+#             */
/*   Updated: 2026/08/30 12:05:08 by frodrig2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <limits.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	int				rank;
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

void	small_sort(t_data *data);
void	simple_sort(t_data *data);
void	medium_sort(t_data *data);
void	complex_sort(t_data *data);

/* ==== BENCHMARKS (srcs/bench/) ==== */

void	display_benchmarks(t_data *data);

/* ==== UTILS (srcs/utils/) ==== */

// error
void	error_exit(t_data *data);

// disorder
void	set_disorder(t_data *data);

// stack
t_stack	*stack_new_node(int value);
void	stack_add_bottom(t_stack **stack_p, t_stack *new_node);
void	stack_free(t_stack **stack_p);
t_stack	*stack_get_bottom(t_stack *node);
int		stack_size(t_stack *stack);

// sort
int		get_min_index(t_stack *node, int n);
int		get_max_index(t_stack *node, int size);
void	rotate_to_top_a(t_data *data, int index, int size);
void	rotate_to_top_b(t_data *data, int index, int size);
int		find_insert_index_b(t_stack *stack, int count_in_b, int value);
void	insert_into_b(t_data *data, int idx);
void	assign_ranks(t_stack *a);
int		is_sorted(t_stack *stack);

#endif
