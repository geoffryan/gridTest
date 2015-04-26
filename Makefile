APP = gridTest

default: $(APP)

$(APP): main.c discoStyle.c discoStatStyle.c oneDStyle.c
	gcc -Wall -O3 -lm -o $@ $^

clean:
	rm -f $(APP)
