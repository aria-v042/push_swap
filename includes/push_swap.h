/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frodrig2 <frodrig2@students.42porto.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 12:42:26 by frodrig2          #+#    #+#             */
/*   Updated: 2026/08/25 12:52:02 by frodrig2         ###   ########.fr       */
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

typedef struct s_ops;
{
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
}	t_ops;

typedef struct s_data
{
	t_stack **a;
	t_stack **b;
	t_strat *strat;
	int		bench;
	float	disorder;
	t_ops	*operations;
	
}	t_data;

/* ==== MAIN (srcs/main/) ==== */

// TODO

/* ==== UTILS (srcs/utils/) ==== */

// TODO

/* ==== PARSING (srcs/parse/) ==== */

// TODO

/* ==== OPERATIONS (srcs/ops/) ==== */

// TODO

/* ==== SORTING STRATEGIES (srcs/sort/) ==== */

// TODO

/* tiny */
/* simple - O(n^2) */
/* medium - O(n sqrt(n)) */
/* complex - O(n log n) */

/* ==== BENCHMARKS (srcs/bench/) ==== */

// TODO

#endif
