#include "monty.h"

void mimi_add(stack_t **stack, unsigned int c_number);
void mimi_sub(stack_t **stack, unsigned int c_number);
void mimi_div(stack_t **stack, unsigned int c_number);
void mimi_mul(stack_t **stack, unsigned int c_number);
void mimi_mod(stack_t **stack, unsigned int c_number);

/**
 * mimi_add - Adds the top two values of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @c_number: The current working line number of a Monty bytecodes file.
 *
 * Description: The result is stored in the second value node
 *              from the top and the top value  is removed.
 */
void mimi_add(stack_t **stack, unsigned int c_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_err(short_stack_err(c_number, "add"));
		return;
	}

	(*stack)->next->next->n += (*stack)->next->n;
	mimi_pop(stack, c_number);
}

/**
 * mimi_sub - Subtracts the second value from the top of
 *             a stack_t linked list by the top value.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @c_number: The current working line number of a Monty bytecodes file.
 *
 * Description: The result is stored in the second value node
 *              from the top and the top value is removed.
 */
void mimi_sub(stack_t **stack, unsigned int c_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_err(short_stack_err(c_number, "sub"));
		return;
	}

	(*stack)->next->next->n -= (*stack)->next->n;
	mimi_pop(stack, c_number);
}

/**
 * mimi_div - Divides the second value from the top of
 *             a stack_t linked list by the top value.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @c_number: The current working line number of a Monty bytecodes file.
 *
 * Description: The result is stored in the second value node
 *              from the top and the top value is removed.
 */
void mimi_div(stack_t **stack, unsigned int c_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_err(short_stack_err(c_number, "div"));
		return;
	}

	if ((*stack)->next->n == 0)
	{
		set_op_tok_err(div_err(c_number));
		return;
	}

	(*stack)->next->next->n /= (*stack)->next->n;
	mimi_pop(stack, c_number);
}

/**
 * mimi_mul - Multiplies the second value from the top of
 *             a stack_t linked list by the top value.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @c_number: The current working line number of a Monty bytecodes file.
 *
 * Description: The result is stored in the second value node
 *              from the top and the top value is removed.
 */
void mimi_mul(stack_t **stack, unsigned int c_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_err(short_stack_err(c_number, "mul"));
		return;
	}

	(*stack)->next->next->n *= (*stack)->next->n;
	mimi_pop(stack, c_number);
}

/**
 * mimi_mod - Computes the modulus of the second value from the
 *             top of a stack_t linked list  by the top value.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @c_number: The current working line number of a Monty bytecodes file.
 *
 * Description: The result is stored in the second value node
 *              from the top and the top value is removed.
 */
void mimi_mod(stack_t **stack, unsigned int c_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_err(short_stack_err(c_number, "mod"));
		return;
	}

	if ((*stack)->next->n == 0)
	{
		set_op_tok_err(div_err(c_number));
		return;
	}

	(*stack)->next->next->n %= (*stack)->next->n;
	mimi_pop(stack, c_number);
}

