#!/bin/bash

# ==========================================
# Push_swap Input Validation Test Script
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
	local expected_exit_code="$1"
	local expected_output="$2"
	shift 2
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
	if [ ${#args[@]} -eq 0 ]; then
		output=$(${PUSH_SWAP} 2>&1)
		exit_code=$?
	else
		output=$(${PUSH_SWAP} "${args[@]}" 2>&1)
		exit_code=$?
	fi

	# Check exit code and output
	local test_passed=0
	if [ "$exit_code" -eq "$expected_exit_code" ]; then
		if [ "$expected_output" = "EMPTY" ]; then
			if [ -z "$output" ]; then
				test_passed=1
			fi
		elif [ "$expected_output" = "Error" ]; then
			if echo "$output" | grep -q "^Error$"; then
				test_passed=1
			fi
		else
			test_passed=1
		fi
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
		if [ -n "$output" ]; then
			echo -e "${RED}>${RESET} ${output}"
		else
			echo -e "${RED}>${RESET} (no output)"
		fi
		FAILED=$((FAILED + 1))
	fi
	echo ""
}

echo "=========================================="
echo "  Input Validation Tests"
echo "=========================================="
echo ""

# ==========================================
# Multiple numerical arguments
# ==========================================
echo -e "${YELLOW}[Multiple numerical arguments]${RESET}"
run_test 0 "EMPTY" 1 3 5 +9 20 -4 50 60 04 08

# ==========================================
# Single character list as parameter
# ==========================================
echo ""
echo -e "${YELLOW}[Single character list]${RESET}"
run_test 0 "EMPTY" "3 4 6 8 9 74 -56 +495"

# ==========================================
# Invalid characters
# ==========================================
echo ""
echo -e "${YELLOW}[Invalid characters - should return Error]${RESET}"
run_test 1 "Error" 1 3 dog 35 80 -3
run_test 1 "Error" a
run_test 1 "Error" 1 2 3 5 67b778 947
run_test 1 "Error" "12 4 6 8 54fhd 4354"
run_test 1 "Error" 1 -- 45 32

# ==========================================
# Duplicate numbers
# ==========================================
echo ""
echo -e "${YELLOW}[Duplicate numbers - should return Error]${RESET}"
run_test 1 "Error" 1 3 58 9 3
run_test 1 "Error" 3 03
run_test 1 "Error" "49 128  50 38  49"

# ==========================================
# Not duplicate (special case)
# ==========================================
echo ""
echo -e "${YELLOW}[Not duplicate - should work]${RESET}"
run_test 0 "EMPTY" "95 99 -9 10 9"

# ==========================================
# INT_MAX & INT_MIN
# ==========================================
echo ""
echo -e "${YELLOW}[INT_MAX & INT_MIN - should work]${RESET}"
run_test 0 "EMPTY" 2147483647 2 4 7
run_test 0 "EMPTY" 99 -2147483648 23 545
run_test 0 "EMPTY" "2147483647 843 56544 24394"

echo ""
echo -e "${YELLOW}[Overflow - should return Error]${RESET}"
run_test 1 "Error" 54867543867438 3
run_test 1 "Error" -214748364776 4 5
run_test 1 "Error" "214748364748385 28 47 29"

# ==========================================
# No arguments
# ==========================================
echo ""
echo -e "${YELLOW}[No arguments]${RESET}"
run_test 0 "EMPTY"

# ==========================================
# Whitespace only
# ==========================================
echo ""
echo -e "${YELLOW}[Whitespace only]${RESET}"
run_test 0 "EMPTY" " "
run_test 0 "EMPTY" "  "

# ==========================================
# Sign only
# ==========================================
echo ""
echo -e "${YELLOW}[Sign only - should return Error]${RESET}"
run_test 1 "Error" +
run_test 1 "Error" -

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