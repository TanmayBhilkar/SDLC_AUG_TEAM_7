# Name of the project
PROJECT_NAME = oscillator

# Output directory
BUILD = build

# All source code files
SRC = ./project_main.c\
src/oscillator.c

INC = -I inc\
-I unity\

#Library Inlcudes
#if working with CUnit 
#INCLUDE_LIBS = -lcunit
#INCLUDE_LIBS =
TEST= test/test_oscillator.c\
unity/unity.c\

# All test source files
TEST_SRC = test/test_oscillator.c\
src/oscillator.c\
unity/unity.c\

# Project Output name
PROJECT_OUTPUT = $(BUILD)/$(PROJECT_NAME)


TEST_OUTPUT = $(BUILD)/Test_$(PROJECT_NAME)

# Document files
DOCUMENTATION_OUTPUT = documentation/html

# Default target built
$(PROJECT_NAME):all



#To check if the OS is Windows or Linux and set the executable file extension and delete command accordingly
ifdef OS
   RM = del /q
   FixPath = $(subst /,\,$1)
   EXEC = exe
else
   ifeq ($(shell uname), Linux)
      RM = rm -rf
      FixPath = $1
	  EXEC = out
   endif
endif
 #Run the target even if the matching name exists
# Makefile will not run target command if the name with file already exists. To override, use .PHONY
.PHONY: run clean test doc all

# -lm to link the maath library
all: $(SRC) $(BUILD)
	gcc $(SRC) $(INC) -o $(call FixPath,$(PROJ_OUTPUT).$(EXEC)) -lm

# Call `make run` to run the application
run: $(PROJECT_NAME)
	$(call FixPath,$(PROJ_OUTPUT).$(EXEC))

# Document the code using Doxygen
#doc:
#	make -C ./documentation

# Build and run the unit tests
# -lm to link the maath library
test: $(TEST_SRC) $(BUILD)
	gcc $(TEST_SRC) $(INC) -o $(call FixPath,$(TEST_OUTPUT).$(EXEC)) -lm
	./$(call FixPath,$(TEST_OUTPUT).$(EXEC))

#Coverage
# -lm to link the maath library
coverage:
	gcc -fprofile-arcs -ftest-coverage -fPIC -O0 $(TEST_SRC) $(INC) -o $(PROJECT_NAME) -lm
	./$(PROJECT_NAME)
	gcovr -r .

# Remove all the built files, invoke by `make clean`
clean:
	rm -rf $(BUILD) $(DOCUMENTATION_OUTPUT)

#Valgrind
valgrind:
	valgrind ./$(TEST_OUTPUT).$(EXEC)

# Create new build folder if not present
$(BUILD):
	mkdir build

