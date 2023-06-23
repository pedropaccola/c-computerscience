# Use make 1.1 / make 1.2 / make 2.1 etc...

# Set the C++ compiler and compilation flags
CC=g++
CFLAGS=-pipe -O2 -std=c++11 -lm

# Set the output file
OUTPUT := bin/file.o
RESULT := bin/result

# Set the paths to the assignments 1.1 == 11_PATH
11_PATH := week1_basic_data_structures/1_brackets_in_code
12_PATH := week1_basic_data_structures/2_tree_height
13_PATH := week1_basic_data_structures/3_network_simulation
14_PATH := week1_basic_data_structures/4_stack_with_max
15_PATH := week1_basic_data_structures/5_max_sliding_window

# Pattern rule to compile and test assignment (prints only STDERR)
%:
	# Compilation:
	$(CC) $(CFLAGS) $($(subst .,,$@)_PATH)/*.cpp -o $(OUTPUT) 
	# Test (prompt if failed) 
	@for file in $$(find $($(subst .,,$@)_PATH)/tests -type f ! -name "*.*"); do \
		echo "Testing against: $$file"; \
		if ! ./$(OUTPUT) < $$file 1> $(RESULT); then \
			echo "ERROR: $$file"; \
		else \
			diff -y --suppress-common-lines $(RESULT) $${file}.a; \
		fi; \
	done
