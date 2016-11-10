default: signals

signals: signals.c
	gcc -o signals signals.c

run: signals
	./signals

clean:
	-rm *~
	-rm log
	-rm signals
