CC=gcc

TARGET=monitor

SRC=src/main.c src/cpu.c src/memory.c src/disk.c src/uptime.c src/loadavg.c src/process.c 

all:
	$(CC) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)
