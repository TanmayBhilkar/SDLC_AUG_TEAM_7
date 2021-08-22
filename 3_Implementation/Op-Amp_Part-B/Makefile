PROJ_NAME = op-amp_B
TEST_PROJ_NAME = Test_$(PROJ_NAME)


SRC = main.c\
src/op-amp_B.c\

TEST_SRC = test/test.c\
unity/unity.c 

INC = inc
INC_T = unity


#To check if the OS is Windows or Linux and set the executable file extension and delete command accordingly
ifdef OS
   RM = del /q
   FixPath = $(subst /,\,$1)
   EXEC = exe
   editor = notepad
else
   ifeq ($(shell uname), Linux)
      RM = rm -rf
      FixPath = $1
	  EXEC = out
	  editor = cat
   endif
endif



all:  
	gcc $(SRC) -I$(INC) -o $(call FixPath,$(PROJ_NAME).$(EXEC))

run :
	$(call FixPath,$(PROJ_NAME).$(EXEC))
	

test:
	gcc -I $(INC) -I $(INC_T) $(TEST_SRC) $(SRC) -o $(call FixPath,$(TEST_PROJ_NAME).$(EXEC))
	./$(call FixPath,$(TEST_PROJ_NAME).$(EXEC))

clean:
	$(RM) *.$(EXEC)
	