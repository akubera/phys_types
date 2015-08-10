#
# test/Makefile
#

CXX ?= g++
CFLAGS = -Wall -std=c++11 -I. -I.. -Ibandit

all: run_tests

run_tests: main.cc *.h
	${CXX} ${CFLAGS} $< -o $@
