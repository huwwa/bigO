all: main plot

main: main.c
	cc -Wall -Wextra -ggdb -o $@ $<

plot: plot.py
	./main && python $<

clean:
	rm -rf main *.csv *.png

.PHONY:
	all clean
