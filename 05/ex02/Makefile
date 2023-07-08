# NAME file
NAME := AForm

# Compiler and flags
CC := c++
# CC := g++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -MMD
CFLAGS += -Wshadow
# CFLAGS += -g
# CFLAGS += -fsanitize=address
# CFLAGS += -W-no-shadow

# Folders
BUILD_DIR := build
SRC_DIR := .
INCLUDE_DIR := .

# List of source files
VPATH := $(SRC_DIR)
SOURCES := main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp
# List of header files
HEADERS := Bureaucrat.hpp AForm.hpp ShrubberyCreationForm.hpp RobotomyRequestForm.hpp PresidentialPardonForm.hpp

# Object files
OBJ_F := $(patsubst %.cpp,$(BUILD_DIR)/%.o,$(notdir $(SOURCES)))
DEP_F := $(patsubst %.cpp,$(BUILD_DIR)/%.d,$(notdir $(SOURCES)))

# Default rule
all: $(NAME)

# Rule to build the NAME
$(NAME): $(OBJ_F)
	$(CC) $(CFLAGS) $^ -o $@

# Rule to compile source files
$(BUILD_DIR)/%.o: %.cpp $(HEADERS) | $(BUILD_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

# Create build directory if it doesn't exist
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Clean rule
clean:
	rm -rf $(BUILD_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean
