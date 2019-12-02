/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 10:05:20 by abaurens          #+#    #+#             */
/*   Updated: 2019/12/02 13:30:01 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ftmath.h"
#include "ftlib.h"
#include "utils.h"
#include "ftio.h"
#include "vm.h"
#include "op.h"

static void	out(t_proc *proc, t_dir v1, t_dir v2)
{
	ft_putstr(proc->name);
	write(1, "st r", 4);
	ft_putnbr(v1);
	write(1, " ", 1);
	ft_putnbr(v2);
	write(1, "\n", 1);
}

char		op_st(t_vm *vm, t_proc *proc)
{
	t_args	av;
	t_ind	off;

	if (!(off = get_arguments(vm, proc, &av)))
		return (proc->carry);
	if (vm->verbosity & V_OPERATONS)
		out(proc, av.v1, av.v2);
	av.v1 = apply_type(proc, av.t1, 1, av.v1);
	if (av.t2 == REG_CODE)
		proc->regs[av.v2 - 1] = av.v1;
	else
		dir_to_map(proc, av.v2 % IDX_MOD, av.v1);
	move_pc(vm, proc, off);
	return (proc->carry);
}
