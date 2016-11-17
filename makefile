
CC=gcc
ROCKET_TYPE=NASA_ROCKET

rocket: rocket.o rocket_type.o
	$(CC) rocket.o rocket_type.o -o rocket

rocket.o: rocket.c
	$(CC) -c rocket.c -DROCKET=$(ROCKET_TYPE)

ifeq ($(ROCKET_TYPE), NASA_ROCKET)
rocket_type.o: nasa_rocket.c nasa_rocket.h
	$(CC) -c nasa_rocket.c -o rocket_type.o
endif
ifeq ($(ROCKET_TYPE), FAT_ROCKET)
rocket_type.o: fat_rocket.c fat_rocket.h
	$(CC) -c fat_rocket.c -o rocket_type.o
endif
ifeq ($(ROCKET_TYPE), LARGE_ROCKET)
rocket_type.o: large_rocket.c large_rocket.h
	$(CC) -c large_rocket.c -o rocket_type.o
endif

clean:
	rm *.o