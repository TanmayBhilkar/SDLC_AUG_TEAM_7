PROJ_NAME = Electronics_lab

TEST_PROJ_NAME = Test_$(PROJ_NAME)

BUILD_DIR = Build

SRC = $(wildcard src/*.c)

TEST_SRC = test/test_function.c\
unity/unity.c

TEST_SRC1 = test/test_function.c\
src/addersub.c\
src/capacitor.c\
src/FlipFlop.c\
src/functions.c\
src/logicgates.c\
src/op-amp_B.c\
src/opm.c\
src/oscillator.c\
src/rect.c\
unity/unity.c\

TEST_OUTPUT = $(BUILD)/Test_$(PROJECT_NAME)

INC = -I inc\
-I unity\

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

# Makefile will not run target command if the name with file already exists. To override, use .PHONY
.PHONY : all test run clean doc

all:$(BUILD_DIR)
	gcc main.c $(SRC) $(INC) -o $(call FixPath,$(BUILD_DIR)/$(PROJ_NAME).$(EXEC)) -lm

run: all
	$(call FixPath,$(BUILD_DIR)/$(PROJ_NAME).$(EXEC))

test: $(SRC) $(TEST_SRC)
	gcc $^ $(INC) -o $(call FixPath,$(BUILD_DIR)/$(TEST_PROJ_NAME).$(EXEC)) -lm
	./$(call FixPath,$(BUILD_DIR)/$(TEST_PROJ_NAME).$(EXEC))


doc:
	
$(BUILD_DIR):
	mkdir $(BUILD_DIR)

clean:
	$(RM) $(call FixPath,$(BUILD_DIR)/*)
	
	rmdir $(BUILD_DIR) 

#Valgrind
valgrind:
	valgrind $(TEST_OUTPUT).$(EXEC)

# Create new Build folder if not present
$(BUILD):
	mkdir Build

# Coverage 
coverage:
	gcc -fprofile-arcs -ftest-coverage -fPIC -O0 $(TEST_SRC1) $(INC) -o $(PROJ_NAME) -lm
	./$(PROJ_NAME)
	gcovr -r .