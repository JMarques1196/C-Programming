# Configuration Variables
CC = gcc
CFLAGS = -Wall -Wextra -Iinclude

# Production files (for the main program)
SRC_MODULES = src/data.c src/plants.c src/watering.c src/tasks.c

# Main program
all: program

program:
	$(CC) $(CFLAGS) src/main.c $(SRC_MODULES) -o program

# Tests
test:
	@echo "========================================="
	@echo "Compiling unit tests..."
	@echo "========================================="
	
	# Plants Module: independent, only needs itself
	$(CC) $(CFLAGS) tests/plants_test.c src/plants.c -o tests/plants_test
	
	# Watering Module: depends on plants.c for existence and update validations
	$(CC) $(CFLAGS) tests/watering_test.c src/watering.c src/plants.c -o tests/watering_test
	
	# Tasks Module: independent, only needs itself
	$(CC) $(CFLAGS) tests/tasks_test.c src/tasks.c -o tests/tasks_test

	# Integration Module: depends on all other modules
	$(CC) $(CFLAGS) tests/integration_test.c src/data.c src/plants.c src/watering.c src/tasks.c -o tests/integration_test

	@echo ""
	@echo "========================================="
	@echo "Running tests..."
	@echo "========================================="

	@./tests/plants_test
	@./tests/watering_test
	@./tests/tasks_test
	@./tests/integration_test	

	@echo "========================================="
	@echo "All test modules executed!"
	@echo "========================================="

# Clean up
clean:
	rm -f program
	rm -f tests/plants_test
	rm -f tests/watering_test
	rm -f tests/tasks_test
	rm -f tests/integration_test