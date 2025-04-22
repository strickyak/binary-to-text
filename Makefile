all: bin2hhc hhc2bin

test: all
	./bin2hhc < /bin/bash > _1
	(dd if=/bin/bash count=7 ; date ; dd if=/bin/bash skip=7) | ./bin2hhc > _2
	-diff _1 _2
	./hhc2bin < _1 > _11
	cmp /bin/bash _11

clean:
	rm -f bin2hhc hhc2bin _[0-9]*
