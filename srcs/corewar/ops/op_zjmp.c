/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 10:05:20 by abaurens          #+#    #+#             */
/*   Updated: 2019/12/02 13:29:50 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ftmath.h"
#include "ftlib.h"
#include "utils.h"
#include "ftio.h"
#include "vm.h"
#include "op.h"

static void	out(t_proc *proc, t_dir v1, char jmp)
{
	ft_putstr(proc->name);
	write(1, "zjmp ", 5);
	ft_putnbr(v1);
	write(1, (jmp ? " OK\n" : " FAILED\n"), jmp ? 4 : 8);
}

char		op_zjmp(t_vm *vm, t_proc *proc)
{
	t_ind	off;
	t_dir	val;
	t_dir	pc;

	off = 1;
	get_dir4(proc, &off, &val);
	if (vm->verbosity & V_OPERATONS)
		out(proc, val, proc->carry);
	if (!proc->carry)
		move_pc(vm, proc, off);
	else
	{
		pc = proc->pc;
		pc += (val % IDX_MOD);
		pc %= MEM_SIZE;
		if (pc < 0)
			pc += MEM_SIZE;
		proc->pc = pc;
	}
	return (proc->carry);
}
