PROJ_NAME = Capacitor
TEST_PROJ_NAME = Test_$(PROJ_NAME)


SRC = cap_main.c\
src/capacitor.c\

INC = inc


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
	
clean:
	$(RM) *.$(EXEC)
	