# 1. Compiler and Flags
CC = gcc
CFLAGS = -Wall -Wextra -g -MMD -MP
LDFLAGS = -lm

# 2. Directories
SRC_DIR = src
INCLUDE_DIR = include
BUILD_DIR = build
BIN_DIR = bin

# 3. Output Executable
# FIX: The target must include the filename (e.g., /calc), not just the folder.
TARGET = $(BIN_DIR)/calc

# 4. Include paths
INCLUDES = -I$(INCLUDE_DIR)

# 5. Find all .c files
SOURCES := $(shell find $(SRC_DIR) -name '*.c')

# 6. Generate object file paths
OBJECTS := $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SOURCES))

# 7. Auto-generated dependency files
DEPS := $(OBJECTS:.o=.d)

# 8. Phony targets
.PHONY: all clean

# Default target
all: $(TARGET)

# 9. Link Rule: Build the executable
$(TARGET): $(OBJECTS)
	@mkdir -p $(BIN_DIR)
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@
	@echo "Built executable: $@"

# 10. Compile Rule: .c to .o
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# 11. Clean Rule
clean:
	@rm -rf $(BUILD_DIR) $(BIN_DIR)
	@echo "Cleaned build and bin directories"

# 12. Include dependencies
-include $(DEPS)
