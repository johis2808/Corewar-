/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 10:05:20 by abaurens          #+#    #+#             */
/*   Updated: 2019/10/22 17:40:58 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process.h"
#include "config.h"
#include "vm.h"
#include "op.h"
#include "ftio.h"

char	op_sub(t_vm *vm, t_proc *proc)
{
	(void)vm;
	(void)proc;
	ft_printf("code: %u - sub\n", OP_SUB);
	return (0);
}