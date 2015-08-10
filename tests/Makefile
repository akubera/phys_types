#
# test/Makefile
#

BANDIT_DIR ?= bandit

CXX ?= g++
CFLAGS = -Wall -std=c++11 -I. -I.. -I${BANDIT_DIR}

RM = rm -rf

.PHONY: clean all

all: run_tests

run_tests: main.cc *.h
	${CXX} ${CFLAGS} $< -o $@

clean:
	${RM} run_tests
