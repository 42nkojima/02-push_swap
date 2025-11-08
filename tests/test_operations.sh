#!/bin/bash

# ==========================================
# Push_swap Operations Test Script
# Tests all 11 stack operations
# ==========================================

# Colors
GREEN="\033[0;32m"
RED="\033[0;31m"
YELLOW="\033[0;33m"
RESET="\033[0m"

# Counters
TOTAL=0
PASSED=0
FAILED=0

# Program path
PUSH_SWAP="./push_swap"

# Test function
run_test() {
	local expected_output="$1"
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

	# Check if output matches expected
	local test_passed=0
	if [ "$output" = "$expected_output" ] && [ $exit_code -eq 0 ]; then
		test_passed=1
	fi

	# Display result
	if [ $test_passed -eq 1 ]; then
		echo -e "${GREEN}✓${RESET} ${cmd_display}"
		if [ -n "$output" ]; then
			echo -e "${GREEN}>${RESET} ${output}"
		fi
		PASSED=$((PASSED + 1))
	else
		echo -e "${RED}✗${RESET} ${cmd_display}"
		echo -e "${RED}> Expected:${RESET}"
		echo "$expected_output" | while IFS= read -r line; do
			echo -e "${RED}>   ${line}${RESET}"
		done
		echo -e "${RED}> Got:${RESET}"
		if [ -n "$output" ]; then
			echo "$output" | while IFS= read -r line; do
				echo -e "${RED}>   ${line}${RESET}"
			done
		else
			echo -e "${RED}>   (no output)${RESET}"
		fi
		FAILED=$((FAILED + 1))
	fi
	echo ""
}

echo "=========================================="
echo "  Stack Operations Tests"
echo "=========================================="
echo ""

# ==========================================
# sa (swap a)
# ==========================================
echo -e "${YELLOW}[sa - swap first 2 elements of stack a]${RESET}"
run_test "sa" 2 1
run_test "sa" 3 2 1

# ==========================================
# sb (swap b)
# ==========================================
echo ""
echo -e "${YELLOW}[sb - swap first 2 elements of stack b]${RESET}"
# Note: This will require more complex setup once pb is implemented
# For now, we can't test sb alone without pb

# ==========================================
# ss (sa and sb at the same time)
# ==========================================
echo ""
echo -e "${YELLOW}[ss - sa and sb simultaneously]${RESET}"
# Note: This will require both stacks to have elements

# ==========================================
# pa (push a)
# ==========================================
echo ""
echo -e "${YELLOW}[pa - push top of b to a]${RESET}"
# Note: Requires elements in stack b first

# ==========================================
# pb (push b)
# ==========================================
echo ""
echo -e "${YELLOW}[pb - push top of a to b]${RESET}"
run_test "pb" 3 2 1

# ==========================================
# ra (rotate a)
# ==========================================
echo ""
echo -e "${YELLOW}[ra - rotate stack a up]${RESET}"
run_test "ra" 3 2 1

# ==========================================
# rb (rotate b)
# ==========================================
echo ""
echo -e "${YELLOW}[rb - rotate stack b up]${RESET}"
# Note: Requires elements in stack b first

# ==========================================
# rr (ra and rb at the same time)
# ==========================================
echo ""
echo -e "${YELLOW}[rr - ra and rb simultaneously]${RESET}"
# Note: Requires both stacks to have elements

# ==========================================
# rra (reverse rotate a)
# ==========================================
echo ""
echo -e "${YELLOW}[rra - reverse rotate stack a]${RESET}"
run_test "rra" 3 2 1

# ==========================================
# rrb (reverse rotate b)
# ==========================================
echo ""
echo -e "${YELLOW}[rrb - reverse rotate stack b]${RESET}"
# Note: Requires elements in stack b first

# ==========================================
# rrr (rra and rrb at the same time)
# ==========================================
echo ""
echo -e "${YELLOW}[rrr - rra and rrb simultaneously]${RESET}"
# Note: Requires both stacks to have elements

# ==========================================
# Complex operation sequences
# ==========================================
echo ""
echo -e "${YELLOW}[Complex sequences]${RESET}"
run_test "pb
pb
sa
pa
pa" 5 4 3 2 1

run_test "ra
ra
sa" 5 4 3 2 1

# ==========================================
# Results
# ==========================================
echo ""
echo "=========================================="
echo -e "  Results: ${GREEN}${PASSED} passed${RESET}, ${RED}${FAILED} failed${RESET} (${TOTAL} total)"
echo "=========================================="

if [ $FAILED -eq 0 ]; then
	exit 0
else
	exit 1
fi