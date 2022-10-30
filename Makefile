CC := g++
SRCDIR := src
BUILDDIR := build
TARGET := main.out
CFLAGS := -g -Wall -O3 -std=c++11 -I include/

all: main
intruso:
	$(CC) $(CFLAGS) -c $(SRCDIR)/intruso.cpp -o $(BUILDDIR)/intruso.o 

main:intruso
	$(CC) $(CFLAGS) $(BUILDDIR)/*.o $(SRCDIR)/main.cpp -o main.out

clean:
	$(RM) -r $(BUILDDIR)/* $(TARGET)
