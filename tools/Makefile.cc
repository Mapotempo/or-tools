# OR_ROOT is the minimal prefix to define the root of or-tools, if we
# are compiling in the or-tools root, it is empty. Otherwise, it is
# $(OR_TOOLS_TOP)/ or $(OR_TOOLS_TOP)\\ depending on the platform. It
# contains the trailing separator if not empty.

# Let's discover something about where we run
ifeq "$(SHELL)" "cmd.exe"
	SYSTEM = win
else
	ifeq "$(SHELL)" "sh.exe"
		SYSTEM = win
	else
		SYSTEM = unix
	endif
endif

# Define the OR_ROOT directory.
ifeq ($(OR_TOOLS_TOP),)
	OR_ROOT =
else
	ifeq "$(SYSTEM)" "win"
		OR_ROOT = $(OR_TOOLS_TOP)\\
	else
		OR_ROOT = $(OR_TOOLS_TOP)/
	endif
endif

# Useful directories.
BIN_DIR = $(OR_ROOT)bin
OBJ_DIR = $(OR_ROOT)objs
EX_DIR = $(OR_ROOT)examples$Scpp
INC_EX_DIR = $(OR_ROOT)examples
INC_DIR = $(OR_ROOT)include

# Unix specific part.
ifeq ("$(SYSTEM)","unix")
	OS = $(shell uname -s)
	ifeq ($(OS),Linux)
		CCC = g++ -fPIC -std=c++0x
		LD_FLAGS = -lz -lrt -lpthread
		# Defines OR_TOOLS_TOP if it is not already defined.
		OR_TOOLS_TOP ?= $(shell pwd)
    OR_TOOLS_LIB_PRE = -Wl,-rpath $(OR_TOOLS_TOP)/lib -L$(OR_TOOLS_TOP)/lib
<<<<<<< HEAD
		ORTOOLS_LIB = $(OR_TOOLS_LIB_PRE) -lortools $(OR_TOOLS_LIB_PRE) -lcvrptw_lib $(OR_TOOLS_LIB_PRE) -lfz $(OR_TOOLS_LIB_PRE) -ldimacs
=======
<<<<<<< HEAD
<<<<<<< HEAD
		ORTOOLS_LIB = $(OR_TOOLS_LIB_PRE) -lortools $(OR_TOOLS_LIB_PRE) -lcvrptw_lib $(OR_TOOLS_LIB_PRE) -ldimacs
=======
		ORTOOLS_LIB = $(OR_TOOLS_LIB_PRE) -lortools $(OR_TOOLS_LIB_PRE) -lcvrptw_lib $(OR_TOOLS_LIB_PRE) -lfz $(OR_TOOLS_LIB_PRE) -ldimacs
>>>>>>> 4ea00a8a3aaf87b3831f4a47e31df5fb028eb4d7
=======
		ORTOOLS_LIB = $(OR_TOOLS_LIB_PRE) -lortools $(OR_TOOLS_LIB_PRE) -lcvrptw_lib $(OR_TOOLS_LIB_PRE) -lfz $(OR_TOOLS_LIB_PRE) -ldimacs
>>>>>>> 4ea00a8a3aaf87b3831f4a47e31df5fb028eb4d7
>>>>>>> archives fixes for windows
		LBITS = $(shell getconf LONG_BIT)
		ifeq ($(LBITS),64)
			PORT = Linux64
			ARCH = -DARCH_K8
		else
			PORT = Linux32
		endif
	endif
	ifeq ($(OS),Darwin) # Assume Mac Os X
		CCC = clang++ -fPIC -std=c++11
		LD_FLAGS = -lz
<<<<<<< HEAD
		ORTOOLS_LIB = -L$(OR_ROOT)lib -lortools -L$(OR_ROOT)lib -lcvrptw_lib -L$(OR_ROOT)lib -lfz -L$(OR_ROOT)lib -ldimacs
=======
<<<<<<< HEAD
<<<<<<< HEAD
		ORTOOLS_LIB = -L$(OR_ROOT)lib -lortools -L$(OR_ROOT)lib -lcvrptw_lib -L$(OR_ROOT)lib -ldimacs
=======
		ORTOOLS_LIB = -L$(OR_ROOT)lib -lortools -L$(OR_ROOT)lib -lcvrptw_lib -L$(OR_ROOT)lib -lfz -L$(OR_ROOT)lib -ldimacs
>>>>>>> 4ea00a8a3aaf87b3831f4a47e31df5fb028eb4d7
=======
		ORTOOLS_LIB = -L$(OR_ROOT)lib -lortools -L$(OR_ROOT)lib -lcvrptw_lib -L$(OR_ROOT)lib -lfz -L$(OR_ROOT)lib -ldimacs
>>>>>>> 4ea00a8a3aaf87b3831f4a47e31df5fb028eb4d7
>>>>>>> archives fixes for windows
		ARCH = -DARCH_K8
		PORT = MacOsX64
	endif
	O = o
	E =
	OBJ_OUT = -o #
	EXE_OUT = -o #
	DEL = rm -f
	S = /
	CLP_INC = -DUSE_CLP
	CBC_INC = -DUSE_CBC
	GLOP_INC = -DUSE_GLOP
	BOP_INT = -DUSE_BOP
	DEBUG = -O4 -DNDEBUG
	CFLAGS = $(DEBUG) -I$(INC_DIR) -I$(INC_EX_DIR) $(ARCH) -Wno-deprecated \
			$(CBC_INC) $(CLP_INC) $(GLOP_INC) $(BOP_INC)
endif

# Windows specific part.
ifeq ("$(SYSTEM)","win")
	ifeq ("$(Platform)", "X64")
		PLATFORM = Win64
	endif
	ifeq ("$(Platform)", "x64")
		PLATFORM = Win64
	endif
	ifeq ("$(PLATFORM)", "Win64")
		PORT = VisualStudio$(VISUAL_STUDIO)-64b
	else
		PORT = VisualStudio$(VISUAL_STUDIO)-32b
	endif
	CLP_INC = -DUSE_CLP
	CBC_INC = -DUSE_CBC
	GLOP_INC = -DUSE_GLOP
	BOP_INC = -DUSE_BOP
<<<<<<< HEAD
=======
<<<<<<< HEAD
<<<<<<< HEAD
	CFLAGS= /D_SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS -nologo $(DEBUG) $(CBC_INC) $(CLP_INC)\
			/D__WIN32__ /I$(INC_DIR)\\src\\windows /DGFLAGS_DLL_DECL= \
			/DGFLAGS_DLL_DECLARE_FLAG= /DGFLAGS_DLL_DEFINE_FLAG= \
			/I$(INC_DIR) /I$(INC_EX_DIR) /D $(GLOP_INC) $(BOP_INC)
	LD_FLAGS = psapi.lib ws2_32.lib
	ORTOOLS_LIB = lib\\ortools.lib lib\\cvrptw_lib.lib lib\\dimacs.lib
=======
=======
>>>>>>> 4ea00a8a3aaf87b3831f4a47e31df5fb028eb4d7
>>>>>>> archives fixes for windows
	CFLAGS= -nologo $(DEBUG) $(CBC_INC) $(CLP_INC)\
			/D__WIN32__ /I$(INC_DIR)\\src\\windows /DGFLAGS_DLL_DECL= \
			/DGFLAGS_DLL_DECLARE_FLAG= /DGFLAGS_DLL_DEFINE_FLAG= \
			/I$(INC_DIR) /I$(EX_DIR) /D $(GLOP_INC) $(BOP_INC)
	LD_FLAGS = psapi.lib ws2_32.lib
	ORTOOLS_LIB = lib\\ortools.lib lib\\cvrptw.lib lib\\fz.lib lib\\dimacs.lib
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 4ea00a8a3aaf87b3831f4a47e31df5fb028eb4d7
=======
>>>>>>> 4ea00a8a3aaf87b3831f4a47e31df5fb028eb4d7
>>>>>>> archives fixes for windows
	O=obj
	E=.exe
	OBJ_OUT = /Fo
	EXE_OUT = /Fe
	DEL = del
	S = \\
	DEBUG=/O2 -DNDEBUG
	CCC=cl /EHsc /MD /nologo
endif

.PHONY: all clean

all: \
	$(BIN_DIR)/cpp/costas_array$E\
	$(BIN_DIR)/cpp/cryptarithm$E\
	$(BIN_DIR)/cpp/cvrptw$E\
	$(BIN_DIR)/cpp/dobble_ls$E\
	$(BIN_DIR)/cpp/flexible_jobshop$E\
	$(BIN_DIR)/cpp/golomb$E\
	$(BIN_DIR)/cpp/jobshop$E\
	$(BIN_DIR)/cpp/jobshop_ls$E\
	$(BIN_DIR)/cpp/jobshop_earlytardy$E\
	$(BIN_DIR)/cpp/magic_square$E\
	$(BIN_DIR)/cpp/model_util$E\
	$(BIN_DIR)/cpp/multidim_knapsack$E\
	$(BIN_DIR)/cpp/network_routing$E\
	$(BIN_DIR)/cpp/nqueens$E\
	$(BIN_DIR)/cpp/pdptw$E\
	$(BIN_DIR)/cpp/sports_scheduling$E\
	$(BIN_DIR)/cpp/tsp$E\
	$(BIN_DIR)/cpp/linear_assignment_api$E\
	$(BIN_DIR)/cpp/strawberry_fields_with_column_generation$E\
	$(BIN_DIR)/cpp/linear_programming$E\
	$(BIN_DIR)/cpp/linear_solver_protocol_buffers$E\
	$(BIN_DIR)/cpp/integer_programming$E
  # TODO(dlahlou) $(BIN_DIR)/cpp/flow_api$E


clean:
	$(DEL) $(BIN_DIR)$Scpp$S*
	$(DEL) $(OBJ_DIR)$S*$O

# Constraint Programming and Routing examples.

$(OBJ_DIR)/costas_array.$O: $(EX_DIR)/costas_array.cc $(INC_DIR)/constraint_solver/constraint_solver.h
	$(CCC) $(CFLAGS) -c $(EX_DIR)$Scostas_array.cc $(OBJ_OUT)$(OBJ_DIR)$Scostas_array.$O

$(BIN_DIR)/cpp/costas_array$E: $(OBJ_DIR)/costas_array.$O
	$(CCC) $(CFLAGS) $(OBJ_DIR)/costas_array.$O $(ORTOOLS_LIB) $(LD_FLAGS) $(EXE_OUT)$(BIN_DIR)$Scpp$Scostas_array$E

$(OBJ_DIR)/cryptarithm.$O:$(EX_DIR)/cryptarithm.cc $(INC_DIR)/constraint_solver/constraint_solver.h
	$(CCC) $(CFLAGS) -c $(EX_DIR)$Scryptarithm.cc $(OBJ_OUT)$(OBJ_DIR)$Scryptarithm.$O

$(BIN_DIR)/cpp/cryptarithm$E: $(OBJ_DIR)/cryptarithm.$O
	$(CCC) $(CFLAGS) $(OBJ_DIR)/cryptarithm.$O $(ORTOOLS_LIB) $(LD_FLAGS) $(EXE_OUT)$(BIN_DIR)$Scpp$Scryptarithm$E

$(OBJ_DIR)/cvrptw.$O: $(EX_DIR)/cvrptw.cc $(INC_DIR)/constraint_solver/constraint_solver.h
	$(CCC) $(CFLAGS) -c $(EX_DIR)$Scvrptw.cc $(OBJ_OUT)$(OBJ_DIR)$Scvrptw.$O

$(BIN_DIR)/cpp/cvrptw$E: $(OBJ_DIR)/cvrptw.$O
	$(CCC) $(CFLAGS) $(OBJ_DIR)/cvrptw.$O $(ORTOOLS_LIB) $(LD_FLAGS) $(EXE_OUT)$(BIN_DIR)$Scpp$Scvrptw$E

$(OBJ_DIR)/dobble_ls.$O:$(EX_DIR)/dobble_ls.cc $(INC_DIR)/constraint_solver/constraint_solver.h
	$(CCC) $(CFLAGS) -c $(EX_DIR)$Sdobble_ls.cc $(OBJ_OUT)$(OBJ_DIR)$Sdobble_ls.$O

$(BIN_DIR)/cpp/dobble_ls$E: $(OBJ_DIR)/dobble_ls.$O
	$(CCC) $(CFLAGS) $(OBJ_DIR)/dobble_ls.$O $(ORTOOLS_LIB) $(LD_FLAGS) $(EXE_OUT)$(BIN_DIR)$Scpp$Sdobble_ls$E

$(OBJ_DIR)/flexible_jobshop.$O:$(EX_DIR)/flexible_jobshop.cc $(INC_DIR)/constraint_solver/constraint_solver.h $(EX_DIR)/flexible_jobshop.h
	$(CCC) $(CFLAGS) -c $(EX_DIR)$Sflexible_jobshop.cc $(OBJ_OUT)$(OBJ_DIR)$Sflexible_jobshop.$O

$(BIN_DIR)/cpp/flexible_jobshop$E: $(OBJ_DIR)/flexible_jobshop.$O
	$(CCC) $(CFLAGS) $(OBJ_DIR)/flexible_jobshop.$O $(ORTOOLS_LIB) $(LD_FLAGS) $(EXE_OUT)$(BIN_DIR)$Scpp$Sflexible_jobshop$E

$(OBJ_DIR)/golomb.$O:$(EX_DIR)/golomb.cc $(INC_DIR)/constraint_solver/constraint_solver.h
	$(CCC) $(CFLAGS) -c $(EX_DIR)$Sgolomb.cc $(OBJ_OUT)$(OBJ_DIR)$Sgolomb.$O

$(BIN_DIR)/cpp/golomb$E: $(OBJ_DIR)/golomb.$O
	$(CCC) $(CFLAGS) $(OBJ_DIR)/golomb.$O $(ORTOOLS_LIB) $(LD_FLAGS) $(EXE_OUT)$(BIN_DIR)$Scpp$Sgolomb$E

$(OBJ_DIR)/jobshop.$O:$(EX_DIR)/jobshop.cc $(INC_DIR)/constraint_solver/constraint_solver.h
	$(CCC) $(CFLAGS) -c $(EX_DIR)$Sjobshop.cc $(OBJ_OUT)$(OBJ_DIR)$Sjobshop.$O

$(BIN_DIR)/cpp/jobshop$E: $(OBJ_DIR)/jobshop.$O
	$(CCC) $(CFLAGS) $(OBJ_DIR)/jobshop.$O $(ORTOOLS_LIB) $(LD_FLAGS) $(EXE_OUT)$(BIN_DIR)$Scpp$Sjobshop$E

$(OBJ_DIR)/jobshop_ls.$O:$(EX_DIR)/jobshop_ls.cc $(INC_DIR)/constraint_solver/constraint_solver.h
	$(CCC) $(CFLAGS) -c $(EX_DIR)$Sjobshop_ls.cc $(OBJ_OUT)$(OBJ_DIR)$Sjobshop_ls.$O

$(BIN_DIR)/cpp/jobshop_ls$E: $(OBJ_DIR)/jobshop_ls.$O
	$(CCC) $(CFLAGS) $(OBJ_DIR)/jobshop_ls.$O $(ORTOOLS_LIB) $(LD_FLAGS) $(EXE_OUT)$(BIN_DIR)$Scpp$Sjobshop_ls$E

$(OBJ_DIR)/jobshop_earlytardy.$O:$(EX_DIR)/jobshop_earlytardy.cc $(INC_DIR)/constraint_solver/constraint_solver.h $(EX_DIR)/jobshop_earlytardy.h
	$(CCC) $(CFLAGS) -c $(EX_DIR)$Sjobshop_earlytardy.cc $(OBJ_OUT)$(OBJ_DIR)$Sjobshop_earlytardy.$O

$(BIN_DIR)/cpp/jobshop_earlytardy$E: $(OBJ_DIR)/jobshop_earlytardy.$O
	$(CCC) $(CFLAGS) $(OBJ_DIR)/jobshop_earlytardy.$O $(ORTOOLS_LIB) $(LD_FLAGS) $(EXE_OUT)$(BIN_DIR)$Scpp$Sjobshop_earlytardy$E

$(OBJ_DIR)/magic_square.$O:$(EX_DIR)/magic_square.cc $(INC_DIR)/constraint_solver/constraint_solver.h
	$(CCC) $(CFLAGS) -c $(EX_DIR)$Smagic_square.cc $(OBJ_OUT)$(OBJ_DIR)$Smagic_square.$O

$(BIN_DIR)/cpp/magic_square$E: $(OBJ_DIR)/magic_square.$O
	$(CCC) $(CFLAGS) $(OBJ_DIR)/magic_square.$O $(ORTOOLS_LIB) $(LD_FLAGS) $(EXE_OUT)$(BIN_DIR)$Scpp$Smagic_square$E

$(OBJ_DIR)/model_util.$O:$(EX_DIR)/model_util.cc $(INC_DIR)/constraint_solver/model.pb.h $(INC_DIR)/constraint_solver/constraint_solver.h
	$(CCC) $(CFLAGS) -c $(EX_DIR)$Smodel_util.cc $(OBJ_OUT)$(OBJ_DIR)$Smodel_util.$O

$(BIN_DIR)/cpp/model_util$E: $(OBJ_DIR)/model_util.$O
	$(CCC) $(CFLAGS) $(OBJ_DIR)/model_util.$O $(ORTOOLS_LIB) $(LD_FLAGS) $(EXE_OUT)$(BIN_DIR)$Scpp$Smodel_util$E

$(OBJ_DIR)/multidim_knapsack.$O:$(EX_DIR)/multidim_knapsack.cc $(INC_DIR)/constraint_solver/constraint_solver.h
	$(CCC) $(CFLAGS) -c $(EX_DIR)$Smultidim_knapsack.cc $(OBJ_OUT)$(OBJ_DIR)$Smultidim_knapsack.$O

$(BIN_DIR)/cpp/multidim_knapsack$E: $(OBJ_DIR)/multidim_knapsack.$O
	$(CCC) $(CFLAGS) $(OBJ_DIR)/multidim_knapsack.$O $(ORTOOLS_LIB) $(LD_FLAGS) $(EXE_OUT)$(BIN_DIR)$Scpp$Smultidim_knapsack$E

$(OBJ_DIR)/network_routing.$O:$(EX_DIR)/network_routing.cc $(INC_DIR)/constraint_solver/constraint_solver.h
	$(CCC) $(CFLAGS) -c $(EX_DIR)$Snetwork_routing.cc $(OBJ_OUT)$(OBJ_DIR)$Snetwork_routing.$O

$(BIN_DIR)/cpp/network_routing$E: $(GRAPH_DEPS) $(OBJ_DIR)/network_routing.$O
	$(CCC) $(CFLAGS) $(OBJ_DIR)/network_routing.$O $(ORTOOLS_LIB) $(GRAPH_LNK) $(LD_FLAGS) $(EXE_OUT)$(BIN_DIR)$Scpp$Snetwork_routing$E

$(OBJ_DIR)/nqueens.$O: $(EX_DIR)/nqueens.cc $(INC_DIR)/constraint_solver/constraint_solver.h
	$(CCC) $(CFLAGS) -c $(EX_DIR)$Snqueens.cc $(OBJ_OUT)$(OBJ_DIR)$Snqueens.$O

$(BIN_DIR)/cpp/nqueens$E: $(OBJ_DIR)/nqueens.$O
	$(CCC) $(CFLAGS) $(OBJ_DIR)/nqueens.$O $(ORTOOLS_LIB) $(LD_FLAGS) $(EXE_OUT)$(BIN_DIR)$Scpp$Snqueens$E

$(OBJ_DIR)/pdptw.$O: $(EX_DIR)/pdptw.cc $(INC_DIR)/constraint_solver/constraint_solver.h
	$(CCC) $(CFLAGS) -c $(EX_DIR)$Spdptw.cc $(OBJ_OUT)$(OBJ_DIR)$Spdptw.$O

$(BIN_DIR)/cpp/pdptw$E: $(OBJ_DIR)/pdptw.$O
	$(CCC) $(CFLAGS) $(OBJ_DIR)/pdptw.$O $(ORTOOLS_LIB) $(LD_FLAGS) $(EXE_OUT)$(BIN_DIR)$Scpp$Spdptw$E

$(OBJ_DIR)/sports_scheduling.$O:$(EX_DIR)/sports_scheduling.cc $(INC_DIR)/constraint_solver/constraint_solver.h
	$(CCC) $(CFLAGS) -c $(EX_DIR)$Ssports_scheduling.cc $(OBJ_OUT)$(OBJ_DIR)$Ssports_scheduling.$O

$(BIN_DIR)/cpp/sports_scheduling$E: $(OBJ_DIR)/sports_scheduling.$O
	$(CCC) $(CFLAGS) $(OBJ_DIR)/sports_scheduling.$O $(ORTOOLS_LIB) $(LD_FLAGS) $(EXE_OUT)$(BIN_DIR)$Scpp$Ssports_scheduling$E

$(OBJ_DIR)/tsp.$O: $(EX_DIR)/tsp.cc $(INC_DIR)/constraint_solver/routing.h
	$(CCC) $(CFLAGS) -c $(EX_DIR)$Stsp.cc $(OBJ_OUT)$(OBJ_DIR)$Stsp.$O

$(BIN_DIR)/cpp/tsp$E: $(OBJ_DIR)/tsp.$O
	$(CCC) $(CFLAGS) $(OBJ_DIR)/tsp.$O $(ORTOOLS_LIB) $(LD_FLAGS) $(EXE_OUT)$(BIN_DIR)$Scpp$Stsp$E

# Flow and linear assignment cpp

$(OBJ_DIR)/linear_assignment_api.$O:$(EX_DIR)/linear_assignment_api.cc
	$(CCC) $(CFLAGS) -c $(EX_DIR)$Slinear_assignment_api.cc $(OBJ_OUT)$(OBJ_DIR)$Slinear_assignment_api.$O

$(BIN_DIR)/cpp/linear_assignment_api$E: $(OBJ_DIR)/linear_assignment_api.$O
	$(CCC) $(CFLAGS) $(OBJ_DIR)/linear_assignment_api.$O $(ORTOOLS_LIB) $(LD_FLAGS) $(EXE_OUT)$(BIN_DIR)$Scpp$Slinear_assignment_api$E

#TODO(dlahlou)
#$(OBJ_DIR)/flow_api.$O:$(EX_DIR)/flow_api.cc
#	$(CCC) $(CFLAGS) -c $(EX_DIR)$Sflow_api.cc $(OBJ_OUT)$(OBJ_DIR)$Sflow_api.$O

#$(BIN_DIR)/cpp/flow_api$E: $(OBJ_DIR)/flow_api.$O
#	$(CCC) $(CFLAGS) $(OBJ_DIR)/flow_api.$O $(ORTOOLS_LIB) $(LD_FLAGS) $(EXE_OUT)$(BIN_DIR)$Scpp$Sflow_api$E

# Linear Programming Examples

$(OBJ_DIR)/strawberry_fields_with_column_generation.$O: $(EX_DIR)/strawberry_fields_with_column_generation.cc $(INC_DIR)/linear_solver/linear_solver.h
	$(CCC) $(CFLAGS) -c $(EX_DIR)$Sstrawberry_fields_with_column_generation.cc $(OBJ_OUT)$(OBJ_DIR)$Sstrawberry_fields_with_column_generation.$O

$(BIN_DIR)/cpp/strawberry_fields_with_column_generation$E: $(OBJ_DIR)/strawberry_fields_with_column_generation.$O
	$(CCC) $(CFLAGS) $(OBJ_DIR)/strawberry_fields_with_column_generation.$O $(ORTOOLS_LIB) $(LD_FLAGS) $(EXE_OUT)$(BIN_DIR)$Scpp$Sstrawberry_fields_with_column_generation$E

$(OBJ_DIR)/linear_programming.$O: $(EX_DIR)/linear_programming.cc $(INC_DIR)/linear_solver/linear_solver.h
	$(CCC) $(CFLAGS) -c $(EX_DIR)$Slinear_programming.cc $(OBJ_OUT)$(OBJ_DIR)$Slinear_programming.$O

$(BIN_DIR)/cpp/linear_programming$E: $(OBJ_DIR)/linear_programming.$O
	$(CCC) $(CFLAGS) $(OBJ_DIR)/linear_programming.$O $(ORTOOLS_LIB) $(LD_FLAGS) $(EXE_OUT)$(BIN_DIR)$Scpp$Slinear_programming$E

$(OBJ_DIR)/linear_solver_protocol_buffers.$O: $(EX_DIR)/linear_solver_protocol_buffers.cc $(INC_DIR)/linear_solver/linear_solver.h
	$(CCC) $(CFLAGS) -c $(EX_DIR)$Slinear_solver_protocol_buffers.cc $(OBJ_OUT)$(OBJ_DIR)$Slinear_solver_protocol_buffers.$O

$(BIN_DIR)/cpp/linear_solver_protocol_buffers$E: $(OBJ_DIR)/linear_solver_protocol_buffers.$O
	$(CCC) $(CFLAGS) $(OBJ_DIR)/linear_solver_protocol_buffers.$O $(ORTOOLS_LIB) $(LD_FLAGS) $(EXE_OUT)$(BIN_DIR)$Scpp$Slinear_solver_protocol_buffers$E

$(OBJ_DIR)/integer_programming.$O: $(EX_DIR)/integer_programming.cc $(INC_DIR)/linear_solver/linear_solver.h
	$(CCC) $(CFLAGS) -c $(EX_DIR)$Sinteger_programming.cc $(OBJ_OUT)$(OBJ_DIR)$Sinteger_programming.$O

$(BIN_DIR)/cpp/integer_programming$E: $(OBJ_DIR)/integer_programming.$O
	$(CCC) $(CFLAGS) $(OBJ_DIR)/integer_programming.$O $(ORTOOLS_LIB) $(LD_FLAGS) $(EXE_OUT)$(BIN_DIR)$Scpp$Sinteger_programming$E

# Debug

printport:
	@echo SHELL = $(SHELL)
	@echo SYSTEM = $(SYSTEM)
	@echo PORT = $(PORT)
	@echo OS = $(OS)
	@echo CCC = $(CCC)

# Include user makefile

-include $(OR_ROOT)Makefile.user
