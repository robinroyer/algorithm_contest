# Declaration of variables
CC = g++ 
CC_FLAGS = -w

# File names
EXEC = run
SRCDIR = ./src/
SOURCES = $(wildcard ./src/*.cpp)
OBJECTS = $(SOURCES:.cpp=.o)
DATA = mkdir -p data && ./gen.sh
CLEAN_DATA = rm -f ./data/* && rm -rf  data
GREEN='\033[0;32m'
NC='\033[0m'

# Main target
$(EXEC): $(OBJECTS)
	@$(CC) $(OBJECTS) -o $(EXEC) -O6
	@echo ${GREEN}... Building your stuff !${NC}  🏋🏽 

# To obtain object files
%.o: %.cpp
	@$(CC) -c $(CC_FLAGS) $< -o $@

# To remove generated files
clean:
	@rm -f $(EXEC) $(OBJECTS)
	@$(CLEAN_DATA)
	@echo ${GREEN}... Your directory is now clean !${NC} 💪

data:
	@$(DATA)
	@echo ${GREEN}... Building your data!${NC} 🏋🏽

