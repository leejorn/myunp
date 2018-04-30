objects = timeget_ser.o timeget_cli.o tr_ser.o tr_cli.o timeudp_ser.o timeudp_cli.o
all: $(objects)

timeget_ser.o: timeget_ser.c
	gcc timeget_ser.c -o timeget_ser.o

timeget_cli.o: timeget_cli.c
	gcc timeget_cli.c -o timeget_cli.o

tr_ser.o: tr_ser.c
	gcc tr_ser.c -o tr_ser.o

tr_cli.o: tr_cli.c
	gcc tr_cli.c -o tr_cli.o

timeudp_ser.o: timeudp_ser.c
	gcc timeudp_ser.c -o timeudp_ser.o

timeudp_cli.o: timeudp_cli.c
	gcc timeudp_cli.c -o timeudp_cli.o

clean:
	rm $(objects)
