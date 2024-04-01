#ifndef __MONTY_H__
#define __MONTY_H__

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define STACK 0
#define QUEUE 1
#define DELIMS " \n\t\a\b"

/* GLOBAL OPCODE TOKENS */
extern char **op_toks;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
    char *opcode;
    void (*f)(stack_t **stack, unsigned int c_number);
} instruction_t;

/* PRIMARY INTERPRETER FUNCTIONS */
void free_stack(stack_t **stack);
int init_stack(stack_t **stack);
int check_mode(stack_t *stack);
void free_tokens(void);
unsigned int token_arr_len(void);
int run_mimi(FILE *script_fd);
void set_op_tok_err(int err);

/* OPCODE FUNCTIONS */
void mimi_push(stack_t **stack, unsigned int c_number);
void mimi_pall(stack_t **stack, unsigned int c_number);
void mimi_pint(stack_t **stack, unsigned int c_number);
void mimi_pop(stack_t **stack, unsigned int c_number);
void mimi_swap(stack_t **stack, unsigned int c_number);
void mimi_add(stack_t **stack, unsigned int c_number);
void mimi_nop(stack_t **stack, unsigned int c_number);
void mimi_sub(stack_t **stack, unsigned int c_number);
void mimi_div(stack_t **stack, unsigned int c_number);
void mimi_mul(stack_t **stack, unsigned int c_number);
void mimi_mod(stack_t **stack, unsigned int c_number);
void mimi_pchar(stack_t **stack, unsigned int c_number);

/* CUSTOM STANDARD LIBRARY FUNCTIONS */
char **strtow(char *str, char *delims);
char *get_int(int n);

/* ERROR MESSAGES & ERROR CODES */
int usage_err(void);
int malloc_err(void);
int f_open_err(char *filename);
int unknown_op_err(char *opcode, unsigned int c_number);
int no_int_err(unsigned int c_number);
int pop_err(unsigned int c_number);
int pint_err(unsigned int c_number);
int short_stack_err(unsigned int c_number, char *op);
int div_err(unsigned int c_number);
int pchar_err(unsigned int c_number, char *message);

#endif /* __MIMI_H__ */

