/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 10:05:20 by abaurens          #+#    #+#             */
/*   Updated: 2019/11/12 22:09:32 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ftmath.h"
#include "ftlib.h"
#include "utils.h"
#include "ftio.h"
#include "vm.h"
#include "op.h"

static void	out(long int pid, t_dir v1, t_dir v2)
{
	write(1, "P     ", ft_max(4.0 - ft_numlen(pid), 0) + 2);
	ft_putlnbr(pid);
	write(1, " | ld ", 6);
	ft_putnbr(v1);
	write(1, " r", 2);
	ft_putnbr(v2);
	write(1, "\n", 1);
}

char	op_ld(t_vm *vm, t_proc *proc)
{
	t_args	av;
	t_ind	off;

	if (!(off = get_arguments(vm, proc, &av)))
		return (proc->carry);
	av.v1 = apply_type(proc, av.t1, 1, av.v1);
	if (vm->verbosity & V_OPERATONS)
		out(proc->pid, av.v1, av.v2);
	move_pc(vm, proc, off);
	return (!(proc->regs[av.v2 - 1] = av.v1));
}
