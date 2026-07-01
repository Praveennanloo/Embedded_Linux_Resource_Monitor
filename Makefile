CC=gcc
TARGET=monitor

# Explicitly track all module source files
SRC=src/main.c \
    src/cpu.c \
    src/memory.c \
    src/disk.c \
    src/uptime.c \
    src/loadavg.c \
    src/process.c \
    src/system.c\
     src/datetime.c
all:
	$(CC) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)
