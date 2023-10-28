# define variable
a := test
bb := makefile
$(aa)$(bb):= hello "makefile test" var


.PHONY : all intro

all : 1_intro

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