#include "monty.h"

void mimi_nop(stack_t **stack, unsigned int c_number);
void mimi_pchar(stack_t **stack, unsigned int c_number);
void mimi_pstr(stack_t **stack, unsigned int c_number);

/**
 * mimi_nop - Does absolutely nothing for the Mimi opcode 'nop'.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @c_number: The current working line number of a Mimi bytecodes file.
 */
void mimi_nop(stack_t **stack, unsigned int c_number)
{
    (void)stack;
    (void)c_number;
}

/**
 * mimi_pchar - Prints the character in the top value
 *               node of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @c_number: The current working line number of a Mimi bytecodes file.
 */
void mimi_pchar(stack_t **stack, unsigned int c_number)
{
    if ((*stack)->next == NULL)
    {
        set_op_tok_err(pchar_err(c_number, "stack empty"));
        return;
    }
    if ((*stack)->next->n < 0 || (*stack)->next->n > 127)
    {
        set_op_tok_err(pchar_err(c_number, "value out of range"));
        return;
    }

    printf("%c\n", (*stack)->next->n);
}

/**
 * mimi_pstr - Prints the string contained in a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @c_number: The current working line number of a Mimi bytecodes file.
 */
void mimi_pstr(stack_t **stack, unsigned int c_number)
{
    stack_t *tmp = (*stack)->next;

    while (tmp && tmp->n != 0 && (tmp->n > 0 && tmp->n <= 127))
    {
        printf("%c", tmp->n);
        tmp = tmp->next;
    }

    printf("\n");

    (void)c_number;
}

