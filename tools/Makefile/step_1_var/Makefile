# define variable
a := test
bb := makefile
$(aa)$(bb):= hello "makefile test" var
COLOR_GREEN = \033[32m
COLOR_RESET = \033[0m

.PHONY : all 1_intro 2_use_var

all : 
	@clear
	@make 1_intro 
	@make 2_use_var

# getting started variable 
1_intro :
	$(info $$a := test)
	$(info $$bb := makefile)
	$(info $$a$$bb := hello "makefile test" var)
	$(info )

	$(info $$(a)$$(bb))
	$(info $(a)$(bb))
	$(info )

	$(info ($$(a)$$(bb)))
	$(info ($(a)$(bb)))
	$(info )

	$(info literal)
	$(info testmakefile)
	$(info )

	@echo "$(COLOR_GREEN)1_intro done\n$(COLOR_RESET)"

# using variable
# charater variable not use bracket but string variable must need bracket
2_use_var :
	$(info $$a := test)
	$(info $$bb := makefile)
	$(info $$aa$$bb := hello "makefile test" var)
	$(info )
	
	$(info $$(a)$$(bb))
	$(info $a$(bb))
	$(info )

	$(info $$a)
	$(info $a is char variable)
	$(info )

	$(info $$bb)
	$(info $(bb) is str variable)
	$(info )

	@echo "$(COLOR_GREEN)2_use_var done\n$(COLOR_RESET)"