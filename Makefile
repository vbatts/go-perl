

#interp: interp.c
#	$(CC) -O2 -Dbool=char -DHAS_BOOL -I$(shell perl -MConfig -e 'print $$Config{archlib}')/CORE -o $@ $^ -lperl -lm

.PHONY: run
run: go-perl farts.pl
	./go-perl farts.pl

go-perl: interp.go interp.c alloc.c
	go build -o $@ .

.PHONY: clean
clean:
	rm -rf go-perl
