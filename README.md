# push_swap

## Project objective
This project will make you sort data on a stack, with a limited set of instructions, using
the lowest possible number of actions. To succeed you'll have to manipulate various
types of algorithms and choose the one (of many) most appropriate solution for an
optimized data sorting.
  
## Allowed instructions

### Rotating instructions:
```
RA - rotate stack A (send top number on stack to bottom)
RB - rotate stack B (send top number on stack to bottom)
RR - rotate both stack A and B at the same time
RRA - counter-rotate stack A (send bottom number of stack to top)
RRB - counter-rotate stack B (send bottom number of stack to top)
RRR - counter-rotate stack A and stack B at the same time
```
### Swapping instructions:
```
SA - swap top two numbers at top of stack A
SB - swap top two numbers at top of stack B
```
### Pushing instructions:
```
PA - push top element from stack A onto stack B
PB - push stack B
```
###  How to run it
```console
git clone https://github.com/ropalev/push_swap.git
cd push_swap
make

If you want run push_swap:
ARG=`ruby -e "puts (0..100).to_a.shuffle.join(' ')"`; ./push_swap $ARG;

If you want run checker:
ARG=`ruby -e "puts (0..100).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker $ARG
```
