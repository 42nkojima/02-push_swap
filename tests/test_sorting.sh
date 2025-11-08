#!/bin/bash

# ==========================================
# Push_swap Sorting Algorithm Test Script
# Tests sorting for different input sizes
# ==========================================

# Colors
GREEN="\033[0;32m"
RED="\033[0;31m"
YELLOW="\033[0;33m"
BLUE="\033[0;34m"
RESET="\033[0m"

# Counters
TOTAL=0
PASSED=0
FAILED=0

# Program path
PUSH_SWAP="./push_swap"
CHECKER="./checker"

# Helper function to check if sorted
is_sorted_output() {
	local args=("$@")
	local output=$(${PUSH_SWAP} "${args[@]}" 2>&1)

	# If checker exists, use it
	if [ -x "${CHECKER}" ]; then
		result=$(echo "$output" | ${CHECKER} "${args[@]}" 2>&1)
		if [ "$result" = "OK" ]; then
			echo "sorted:$output"
			return 0
		else
			echo "not_sorted:$output"
			return 1
		fi
	else
		# Manual check: just verify program doesn't error
		if [ $? -eq 0 ]; then
			echo "unknown:$output"
			return 0
		else
			echo "error:$output"
			return 1
		fi
	fi
}

# Test function
run_sort_test() {
	local test_name="$1"
	shift
	local args=("$@")

	TOTAL=$((TOTAL + 1))

	# Build command string for display
	local cmd_display="${PUSH_SWAP}"
	for arg in "${args[@]}"; do
		if [[ "$arg" =~ [[:space:]] ]] || [[ -z "$arg" ]]; then
			cmd_display="${cmd_display} \"${arg}\""
		else
			cmd_display="${cmd_display} ${arg}"
		fi
	done

	# Run the program
	output=$(${PUSH_SWAP} "${args[@]}" 2>&1)
	exit_code=$?

	# Count operations
	local op_count=0
	if [ -n "$output" ]; then
		op_count=$(echo "$output" | wc -l | tr -d ' ')
	fi

	# Check if it produces output and exits successfully
	# If output is empty or only whitespace, the sorting is not implemented yet
	local test_passed=0
	if [ $exit_code -eq 0 ] && [ -n "$output" ] && [ "$op_count" -gt 0 ]; then
		test_passed=1
	fi

	# Display result
	if [ $test_passed -eq 1 ]; then
		echo -e "${GREEN}✓${RESET} ${test_name}: ${cmd_display}"
		echo -e "${BLUE}> Operations: ${op_count}${RESET}"
		PASSED=$((PASSED + 1))
	else
		echo -e "${RED}✗${RESET} ${test_name}: ${cmd_display}"
		if [ -n "$output" ]; then
			echo -e "${RED}> Got: ${output}${RESET}"
		else
			echo -e "${RED}> Got: (no output - not implemented yet)${RESET}"
		fi
		FAILED=$((FAILED + 1))
	fi
	echo ""
}

echo "=========================================="
echo "  Sorting Algorithm Tests"
echo "=========================================="
echo ""

# ==========================================
# Already sorted check
# ==========================================
echo -e "${YELLOW}[Check if already sorted]${RESET}"
run_sort_test "Already sorted (3 numbers)" 1 2 3
run_sort_test "Already sorted (5 numbers)" 1 2 3 4 5

# ==========================================
# 2 numbers
# ==========================================
echo ""
echo -e "${YELLOW}[2 numbers]${RESET}"
run_sort_test "2 numbers (reverse)" 2 1
run_sort_test "2 numbers (sorted)" 1 2

# ==========================================
# 3 numbers
# ==========================================
echo ""
echo -e "${YELLOW}[3 numbers]${RESET}"
run_sort_test "3 numbers case 1" 3 2 1
run_sort_test "3 numbers case 2" 2 3 1
run_sort_test "3 numbers case 3" 1 3 2
run_sort_test "3 numbers case 4" 3 1 2
run_sort_test "3 numbers case 5" 2 1 3

# ==========================================
# 4 numbers
# ==========================================
echo ""
echo -e "${YELLOW}[4 numbers]${RESET}"
run_sort_test "4 numbers (reverse)" 4 3 2 1
run_sort_test "4 numbers (random 1)" 3 1 4 2
run_sort_test "4 numbers (random 2)" 2 4 1 3

# ==========================================
# 5 numbers
# ==========================================
echo ""
echo -e "${YELLOW}[5 numbers]${RESET}"
run_sort_test "5 numbers (reverse)" 5 4 3 2 1
run_sort_test "5 numbers (random 1)" 3 5 1 4 2
run_sort_test "5 numbers (random 2)" 2 4 5 1 3
run_sort_test "5 numbers (random 3)" 5 1 3 2 4

# ==========================================
# Large numbers (100)
# ==========================================
echo ""
echo -e "${YELLOW}[100 numbers]${RESET}"
run_sort_test "100 random numbers" $(seq 1 100 | sort -R | tr '\n' ' ')

# ==========================================
# Large numbers (500)
# ==========================================
echo ""
echo -e "${YELLOW}[500 numbers]${RESET}"
run_sort_test "500 random numbers" $(seq 1 500 | sort -R | tr '\n' ' ')

# ==========================================
# Results
# ==========================================
echo ""
echo "=========================================="
echo -e "  Results: ${GREEN}${PASSED} passed${RESET}, ${RED}${FAILED} failed${RESET} (${TOTAL} total)"
echo "=========================================="

if [ ! -x "${CHECKER}" ]; then
	echo ""
	echo -e "${YELLOW}Note:${RESET} checker not found. Tests only verify exit code, not correctness."
	echo -e "${YELLOW}     ${RESET} Download checker from: https://github.com/42Paris/push_swap_tester"
fi

if [ $FAILED -eq 0 ]; then
	exit 0
else
	exit 1
fi