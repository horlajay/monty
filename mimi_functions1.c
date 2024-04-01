#include "monty.h"

void mimi_push(stack_t **stack, unsigned int c_number);
void mimi_pall(stack_t **stack, unsigned int c_number);
void mimi_pint(stack_t **stack, unsigned int c_number);
void mimi_pop(stack_t **stack, unsigned int c_number);
void mimi_swap(stack_t **stack, unsigned int c_number);

/**
 * mimi_push - Pushes a value to a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @c_number: The current working line number of a Mimi bytecodes file.
 */
void mimi_push(stack_t **stack, unsigned int c_number)
{
    stack_t *tmp, *new;
    int i;

    new = malloc(sizeof(stack_t));
    if (new == NULL)
    {
        set_op_tok_err(malloc_err());
        return;
    }

    if (op_toks[1] == NULL)
    {
        set_op_tok_err(no_int_err(c_number));
        return;
    }

    for (i = 0; op_toks[1][i]; i++)
    {
        if (op_toks[1][i] == '-' && i == 0)
            continue;
        if (op_toks[1][i] < '0' || op_toks[1][i] > '9')
        {
            set_op_tok_err(no_int_err(c_number));
            return;
        }
    }
    new->n = atoi(op_toks[1]);

    if (check_mode(*stack) == STACK) /* STACK mode insert at front */
    {
        tmp = (*stack)->next;
        new->prev = *stack;
        new->next = tmp;
        if (tmp)
            tmp->prev = new;
        (*stack)->next = new;
    }
    else /* QUEUE mode insert at end */
    {
        tmp = *stack;
        while (tmp->next)
            tmp = tmp->next;
        new->prev = tmp;
        new->next = NULL;
        tmp->next = new;
    }
}

/**
 * mimi_pall - Prints the values of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @c_number: The current working line number of a Mimi bytecodes file.
 */
void mimi_pall(stack_t **stack, unsigned int c_number)
{
    stack_t *tmp = (*stack)->next;

    while (tmp)
    {
        printf("%d\n", tmp->n);
        tmp = tmp->next;
    }
    (void)c_number;
}

/**
 * mimi_pint - Prints the top value of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @c_number: The current working line number of a Mimi bytecodes file.
 */
void mimi_pint(stack_t **stack, unsigned int c_number)
{
    if ((*stack)->next == NULL)
    {
        set_op_tok_err(pint_err(c_number));
        return;
    }

    printf("%d\n", (*stack)->next->n);
}


/**
 * mimi_pop - Removes the top value element of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @c_number: The current working line number of a Mimi bytecodes file.
 */
void mimi_pop(stack_t **stack, unsigned int c_number)
{
    stack_t *next = NULL;

    if ((*stack)->next == NULL)
    {
        set_op_tok_err(pop_err(c_number));
        return;
    }

    next = (*stack)->next->next;
    free((*stack)->next);
    if (next)
        next->prev = *stack;
    (*stack)->next = next;
}

/**
 * mimi_swap - Swaps the top two value elements of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @c_number: The current working line number of a Mimi bytecodes file.
 */
void mimi_swap(stack_t **stack, unsigned int c_number)
{
    stack_t *tmp;

    if ((*stack)->next == NULL || (*stack)->next->next == NULL)
    {
        set_op_tok_err(short_stack_err(c_number, "swap"));
        return;
    }

    tmp = (*stack)->next->next;
    (*stack)->next->next = tmp->next;
    (*stack)->next->prev = tmp;
    if (tmp->next)
        tmp->next->prev = (*stack)->next;
    tmp->next = (*stack)->next;
    tmp->prev = *stack;
    (*stack)->next = tmp;
}

