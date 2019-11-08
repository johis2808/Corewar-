#
#	here are the corewar's virtual machine specific makefiles variables.
#	each variables declared here has to end with the '_COR' sufix to prevent
#	conflicts with other modules.
#

#	Operators files
OPS_COR	:=	\
			op_or.c		\
			op_ld.c		\
			op_st.c		\
			op_add.c	\
			op_sub.c	\
			op_and.c	\
			op_xor.c	\
			op_ldi.c	\
			op_sti.c	\
			op_lld.c	\
			op_aff.c	\
			op_lldi.c	\
			op_live.c	\
			op_zjmp.c	\
			op_fork.c	\
			op_lfork.c
OPS_COR	:=	$(addprefix ops/,$(OPS_COR))

PARSER	:=	\
			opt_aff.c	\
			opt_num.c	\
			opt_file.c	\
			opt_dump.c	\
			opt_verbosity.c
PARSER	:=	$(addprefix parser/,$(PARSER))

#	general source definitions
SRC_COR	:=	$(PARSER)	\
			$(OPS_COR)	\
			ocp.c		\
			loop.c		\
			utils.c		\
			arena.c		\
			corewar.c	\
			process.c	\
			arguments.c	\
			cmd_parse.c

#
#	vm compilation specific flags
#
override ZAZ ?= FALSE
ifeq ($(ZAZ),TRUE)
override ZAZ_FLAG	:= -DZAZ_OUTPUT
endif

$(COR):	CFLAGS += -I./includes/corewar -ansi -pedantic -DVM $(ZAZ_FLAG)

#
#	vm unit tests
#
TESTER	:=	tester

SPEC	:=	\
			or.c	\
			st.c	\
			ld.c	\
			add.c	\
			sub.c	\
			and.c	\
			xor.c	\
			aff.c	\
			sti.c	\
			ldi.c	\
			lld.c	\
			lldi.c	\
			zjmp.c	\
			live.c	\
			fork.c	\
			lfork.c
SPEC	:=	$(addprefix specific_tests/,$(SPEC))

SRC_TST	:=	\
			$(SPEC)		\
			main.c		\
			random.c	\
			file_gen.c
SRC_TST	:=	$(addprefix $(TESTER)/,$(SRC_TST)) $(SRC_COM)

OBJ_TST	:=	$(addprefix $(OBJD)/,$(SRC_TST:.c=.o))
SRC_TST	:=	$(addprefix $(SRCD)/,$(SRC_TST))
DEP_TST	:=	$(OBJ_TST:.o=.d)

-include $(DEP_TST)

$(TESTER):	CFLAGS += -I./includes/tester -DVM_TEST
$(TESTER): $(OBJ_TST)
	$(LINKER) $(TESTER) $(OBJ_TST) $(LDFLAGS)
