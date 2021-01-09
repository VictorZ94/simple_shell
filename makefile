#
# Makefile for shell
#

CC = gcc
SRC = *.c

all: $(SRC) *.h
	$(CC) $(SRC) -o hsh
