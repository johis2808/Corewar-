/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_or.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 10:05:20 by abaurens          #+#    #+#             */
/*   Updated: 2019/12/03 02:24:32 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ftmath.h"
#include "output.h"
#include "ftlib.h"
#include "utils.h"
#include "ftio.h"
#include "vm.h"
#include "op.h"

static void	out(t_proc *proc, t_dir v1, t_dir v2, t_dir v3)
{
	corewar_putstr(1, proc->name);
	corewar_write(1, "or ", 3);
	corewar_putnbr(1, v1);
	corewar_write(1, " ", 1);
	corewar_putnbr(1, v2);
	corewar_write(1, " r", 2);
	corewar_putnbr(1, v3);
	corewar_write(1, "\n", 1);
}

char		op_or(t_vm *vm, t_proc *proc)
{
	t_args	av;
	t_ind	off;

	if (!(off = get_arguments(vm, proc, &av)))
		return (proc->carry);
	av.v1 = apply_type(proc, av.t1, 1, av.v1);
	av.v2 = apply_type(proc, av.t2, 1, av.v2);
	if (vm->verbosity & V_OPERATONS)
		out(proc, av.v1, av.v2, av.v3);
	move_pc(vm, proc, off);
	return (!(proc->regs[av.v3 - 1] = (av.v1 | av.v2)));
}
