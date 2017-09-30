#!/bin/bash

# FATAL=t

NAME=avm
DATA_DIR=files

CLR_GREEN="\033[32;01m"
CLR_RED="\033[31;01m"
CLR_RESET="\033[0m"

TEST_LOG_FILE=/tmp/test_abstract-vm.log
CTRL_LOG_FILE=/tmp/ctrl_abstract-vm.log

TYPES="int8
int16
int32
float
double"

OP="add
substract
divide
multiply"

FLOW="overflow
downflow"

function success_msg() {
	echo -ne "$CLR_GREEN$1$CLR_RESET"
}

function error_msg() {
    echo -e "$CLR_RED$1$CLR_RESET"
}

function fail() {
	input="$1"
    exit_status="$2"

    error_msg "\nInput:"
    echo "$input"

    if test "$exit_status"; then
        error_msg "\nExit-status:"
        echo "$exit_status"
    else
        error_msg "\nTest:"
        cat $TEST_LOG_FILE

        error_msg "\nControl:"
        cat $CTRL_LOG_FILE

        error_msg "\nDiff:"
        diff $TEST_LOG_FILE $CTRL_LOG_FILE
    fi

    test $FATAL && exit 1
}

function test_vm() {
	input="$1"
	ctrl="$2"

	echo -n "$ctrl" > $CTRL_LOG_FILE

    ./$NAME << EOF > $TEST_LOG_FILE 2>&1
$input
EOF

    # ret=$?
    # test $ret == 0 || fail "$input" "$ret"
    diff $TEST_LOG_FILE $CTRL_LOG_FILE > /dev/null || fail "$input"

    success_msg "."
}



test_vm "$(< $DATA_DIR/bobo.avm)" "20.2
"

test_vm "$(< $DATA_DIR/example.avm)" "42
42.42
3341.25
"

test_vm "$(< $DATA_DIR/zero_divide_error.avm)" "Error : Runtime : Division by 0
"

for f in $FLOW; do
    for t in $TYPES; do
        test_vm "$(< $DATA_DIR/"$f"_error_"$t".avm)" "Error : Runtime : ${f^}
"

        for o in $OP; do
            if test "$o" == "divide" && echo $t | grep -q int; then
                continue
            fi
            test_vm "$(< $DATA_DIR/"$f"_error_"$t"_"$o".avm)" "Error : Runtime : ${f^}
"
        done
    done
done

test_vm "$(< $DATA_DIR/syntax_error.avm)" "Error : Lexical error : push int16(32 ;)
Error : Lexical error : pu int(32))
"

test_vm "$(< $DATA_DIR/empty_stack_error.avm)" "Error : Runtime : Empty stack
"

test_vm "$(< $DATA_DIR/assert_error.avm)" "Error : Runtime : Assert not true
"

test_vm "$(< $DATA_DIR/missing_operand_error.avm)" "Error : Runtime : Too few operand
"

test_vm "$(< $DATA_DIR/plop.avm)" "plop!"

# TODO: Testez un programme de votre invention. Par exemple, faites des operations avec croisement de types avec de tres grands et de tres petits nombres (hors overflow/underflow).

# TODO: Essayez de tester un programme difficile de votre invention (genre vicieux quoi)

# TODO: test stdin vs file

# TODO: no exit instruction

# TODO: modulo zero error





# \n after dots
echo
