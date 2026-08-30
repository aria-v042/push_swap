*This project has been created as part of the 42 curriculum by frodrig2, nd-abreu.*

# push_swap

> Sorting data with two stacks, a handful of moves, and a strong opinion about what "fast" means.

## Description

`push_swap` sorts a list of integers using only two stacks (`a` and `b`) and a
restricted set of eleven operations (`sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`,
`rr`, `rra`, `rrb`, `rrr`). The numbers start on stack `a`, stack `b` starts
empty, and the program's only job is to print, to standard output, the
shortest reasonable sequence of moves that leaves `a` sorted in ascending
order.

The real point of the project isn't the sorting itself — it's algorithmic
complexity, made concrete. Instead of reasoning about Big-O over array
comparisons, everything here is measured in the number of stack operations
generated. To force that comparison, `push_swap` doesn't implement one
algorithm: it implements **four**, spanning O(n²), O(n√n), O(n log n), and an
adaptive strategy that picks between them based on how disordered the input
is. A `--bench` mode exposes the chosen strategy, the measured disorder, and
the full operation breakdown, so the trade-offs aren't just theoretical.

A `checker` (bonus) is also included: it replays a list of operations against
a stack and reports whether they actually sort it.

## Instructions

### Compilation

```bash
git clone <this-repo-url>
cd push_swap
make        # builds libft, then push_swap
```

Standard rules are all supported:

```bash
make        # compile push_swap
make bonus  # compile the checker (in _bonus files)
make clean  # remove object files
make fclean # remove object files and binaries
make re     # fclean + all
```

Compiled with `cc`, `-Wall -Wextra -Werror`, no unnecessary relinking.

### Usage

```bash
./push_swap [--simple|--medium|--complex|--adaptive] [--bench] N [N ...]
```

- Numbers are passed as arguments, the first argument being the top of stack
  `a`. They can also be passed as a single space-separated string.
- With no arguments, the program prints nothing and returns.
- Invalid input (non-integers, duplicates, out-of-range values) prints
  `Error` to standard error.
- If no strategy flag is given, `--adaptive` is used.

```bash
$ ./push_swap 2 1 3 6 5 8
ra
pb
rra
...

$ ./push_swap --simple 5 4 3 2 1 | wc -l
14

$ ARG="4 67 3 87 23"; ./push_swap --complex $ARG | ./checker_linux $ARG
OK
```

`--bench` sends its output to `stderr`, so it can be inspected without
disturbing the operation stream on `stdout`:

```bash
$ ARG="4 67 3 87 23"; ./push_swap --bench --adaptive $ARG 2> bench.txt | ./checker_linux $ARG
OK
$ cat bench.txt
[bench] disorder:   40.00%
[bench] strategy:   Adaptive / O(n√n)
[bench] total_ops:  13
[bench] sa: 0  sb: 0  ss: 0  pa: 5  pb: 5
[bench] ra: 2  rb: 1  rr: 0  rra: 0  rrb: 0  rrr: 0
```

### Checker (bonus)

```bash
$ ./checker 3 2 1 0
rra
pb
sa
rra
pa
OK
```

It reads operations from standard input (one per line, terminated with
Ctrl+D or EOF), applies them to the stack given as arguments, and reports
`OK` if `a` ends up sorted and `b` empty, `KO` otherwise. `Error` is printed
to `stderr` for malformed arguments or malformed/unknown instructions.

## Algorithms

Disorder is computed once, before any move, as the fraction of inversions
among all pairs of the input: 0 means already sorted, 1 means reverse-sorted.
All four strategies fall back to a dedicated **small-stack routine** for
`size <= 5`, since these tiny, fixed-shape cases are trivial to solve
optimally by hand and are explicitly exercised during evaluation — 2 and 3
elements are resolved by direct comparisons, and 4–5 elements by pushing the
extras to `b` in ascending order, sorting the remaining 3, then pushing back.

### `--simple` — O(n²): optimized insertion sort

Repeatedly finds the position of the next value from `a` relative to what's
already ordered, rotates it to the top with the shorter of `ra`/`rra`, and
inserts it. Cost grows quadratically with size because each of the n
insertions can cost up to O(n) rotations, but for small inputs the constant
factors are low and the implementation is simple and predictable — which is
exactly what makes it the right baseline for low-disorder stacks, where
there's little left to fix.

### `--medium` — O(n√n): chunk-based sort

The stack is divided into chunks of roughly `√n` values each, and each
chunk is pushed onto `b` in turn by repeatedly locating the element that
falls within the chunk's range and rotating it to the top of `a` (via the
shorter rotation direction) before pushing. Once every chunk has been moved
to `b`, values are pushed back onto `a` in descending order of their max,
which — combined with each push landing them already close to sorted
position — reassembles a sorted stack.

The chunk size is not a fixed `√n`: `get_chunk_size()` divides the stack
size by 5 for `size <= 100` and by 11 for larger stacks. This isn't
arbitrary — it's a tuning of the number-of-chunks vs. cost-per-chunk
trade-off for the sizes this project is actually benchmarked against (100
and 500 elements). A literal `√n` gives ~10 chunks of ~10 elements at
n = 100 and ~22 chunks of ~22 elements at n = 500; empirically, dividing by 5
(≈20 elements/chunk at n = 100) and by 11 (≈45 elements/chunk at n = 500)
produces fewer total rotations for the search-and-push step in each regime,
while still keeping the number of chunks — and therefore the pass over
`b` — small enough that the overall move count stays within the O(n√n)
class. In short: same complexity class, better constants for the sizes that
matter here.

### `--complex` — O(n log n): radix sort (LSD)

Each value is mapped to its rank (0..n-1) among the input, so the sort works
on the bit representation of a position rather than the raw integer. For
each bit from the least significant up to `⌈log2(n)⌉`, every element of `a`
is inspected: if the bit is 0 it's pushed to `b`, otherwise it's rotated to
the back of `a` with `ra`; once the whole stack has been processed, `b` is
pushed back onto `a`. After `⌈log2(n)⌉` such passes the stack is sorted. Each
pass touches every element exactly once (O(n) operations), and there are
O(log n) passes, giving O(n log n) total operations — the same shape as a
classical LSD radix sort, just executed as stack moves instead of array
writes.

### `--adaptive` — picks a strategy from measured disorder

No flag (or `--adaptive` explicitly) measures disorder before doing
anything, then delegates:

| Disorder | Strategy used | Complexity |
|---|---|---|
| `< 0.20` | Simple (insertion) | O(n²) |
| `0.20 – 0.49` | Medium (chunk-based) | O(n√n) |
| `>= 0.50` | Complex (radix) | O(n log n) |

The thresholds reflect where each algorithm's overhead stops paying for
itself: a near-sorted stack has few inversions to fix, so the low constant
factor of insertion sort beats the bookkeeping overhead of chunking or
radix passes; a stack in the middle regime has enough disorder that O(n²)
becomes expensive but not so much that the extra setup of radix sort (rank
assignment, bit passes) is worth it; a heavily disordered stack has so many
inversions that only the O(n log n) strategy keeps the operation count
under control. Space stays O(n) throughout — the input is duplicated at
most into the two stacks plus rank bookkeeping, with no algorithm ever
allocating more than that.

## Resources

- [push_swap – the least amount of moves with two stacks](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a) — the single most useful write-up while designing the medium/complex strategies.
- [ft_ps_visu](https://github.com/italoalmeida0/ft_ps_visu) — visualizer used to sanity-check operation sequences by eye during development.
- [ft_ps_tester](https://github.com/italoalmeida0/ft_ps_tester) and [push_swap_tester](https://github.com/mdfpva/push_swap_tester) — used for automated correctness/performance testing across many random seeds.
- Big-O explainers: [video 1](https://youtu.be/rv_ZacJYRFA), [video 2](https://youtu.be/g2o22C3CRfU)
- Additional algorithm walkthroughs: [video 3](https://youtu.be/4hJAqspcubU), [video 4](https://youtu.be/Q1JdRUh1_98), [video 5](https://youtu.be/Ze2l9OS7r78), [video 6](https://youtu.be/mTNC0ERo-ZI)

**AI use:** Claude was used as a research aid to compare different classical
sorting algorithms' behavior when adapted to a two-stack model, and to talk
through the trade-offs between candidate implementations (e.g. radix vs.
merge-based approaches for the O(n log n) requirement, and how to size
chunks for the O(n√n) strategy) before we implemented them ourselves. It was
also used in the final stage to suggest micro-optimizations (reducing
redundant rotations, tightening the small-stack routine) once the core
algorithms were already written and understood. No code was generated
wholesale by AI and pasted in — every function was written and is
explainable by both of us.

## Contributions

- **frodrig2** — main loop, argument parsing, error handling, benchmark mode,
  final optimization pass across all sorting strategies.
- **nd-abreu** — theoretical research into candidate algorithms and their
  initial implementations, the stack operation/move primitives, disorder
  calculation, bug hunting, and general project upkeep.
- **Both** — overall design decisions and the final round of optimizations.
