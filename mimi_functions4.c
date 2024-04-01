#include "monty.h"


void mimi_rotl(stack_t **stack, unsigned int c_number);
void mimi_rotr(stack_t **stack, unsigned int c_number);
void mimi_stack(stack_t **stack, unsigned int c_number);
void mimi_queue(stack_t **stack, unsigned int c_number);

/**
 * mimi_rotl - Rotates the top value of a stack_t linked list to the bottom.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @c_number: The current working line number of a Mimi bytecodes file.
 */
void mimi_rotl(stack_t **stack, unsigned int c_number)
{
    stack_t *top, *bottom;

    if ((*stack)->next == NULL || (*stack)->next->next == NULL)
        return;

    top = (*stack)->next;
    bottom = (*stack)->next;
    while (bottom->next != NULL)
        bottom = bottom->next;

    top->next->prev = *stack;
    (*stack)->next = top->next;
    bottom->next = top;
    top->next = NULL;
    top->prev = bottom;

    (void)c_number;
}

/**
 * mimi_rotr - Rotates the bottom value of a stack_t linked list to the top.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @c_number: The current working line number of a Mimi bytecodes file.
 */
void mimi_rotr(stack_t **stack, unsigned int c_number)
{
    stack_t *top, *bottom;

    if ((*stack)->next == NULL || (*stack)->next->next == NULL)
        return;

    top = (*stack)->next;
    bottom = (*stack)->next;
    while (bottom->next != NULL)
        bottom = bottom->next;

    bottom->prev->next = NULL;
    (*stack)->next = bottom;
    bottom->prev = *stack;
    bottom->next = top;
    top->prev = bottom;

    (void)c_number;
}

/**
 * mimi_stack - Converts a queue to a stack.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @c_number: The current working line number of a Mimi bytecodes file.
 */
void mimi_stack(stack_t **stack, unsigned int c_number)
{
    (*stack)->n = STACK;
    (void)c_number;
}

/**
 * mimi_queue - Converts a stack to a queue.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @c_number: The current working line number of a Mimi bytecodes file.
 */
void mimi_queue(stack_t **stack, unsigned int c_number)
{
    (*stack)->n = QUEUE;
    (void)c_number;
}

