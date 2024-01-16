# Copy and adapt the contents of a makefile here.
# Use separate compilation, support "make clean", and name your 
# executable "fans" as per the specification

COURSE = cs240
SEMESTER = spring2022
CP_NUMBER = 4
LASTNAME = Dossie
GITUSERID = ddossie1
EXE = fans

REPODIR = ../$(COURSE)-$(SEMESTER)-cp$(CP_NUMBER)-$(GITUSERID)
TARFILE = CP$(CP_NUMBER)_$(LASTNAME)_$(USER)_$(GITUSERID).tar

FLAGS = -Wall -Wextra -g
FLAGS = -Wall -O3
CC = g++
BIN = bin
OBJ = obj

all: $(BIN)/$(EXE)

$(BIN)/$(EXE): $(OBJ)/Fan.o $(OBJ)/Email.o $(OBJ)/Phone.o $(OBJ)/LL.o $(OBJ)/BSTTemp.o $(OBJ)/Fans.o
	$(CC) $(FLAGS) $(OBJ)/Fan.o $(OBJ)/Email.o $(OBJ)/Phone.o $(OBJ)/LL.o $(OBJ)/BSTTemp.o $(OBJ)/Fans.o -o $@

$(OBJ)/Fans.o: Fans.cpp Fan.h Email.h Phone.h LL.h BSTTemp.h
	$(CC) $(FLAGS) -c Fans.cpp -o $@

$(OBJ)/Fan.o: Fan.cpp Fan.h Email.h Phone.h
	$(CC) $(FLAGS) -c Fan.cpp -o $@

$(OBJ)/Email.o: Email.cpp Email.h
	$(CC) $(FLAGS) -c Email.cpp -o $@

$(OBJ)/Phone.o: Phone.cpp Phone.h
	$(CC) $(FLAGS) -c Phone.cpp -o $@

$(OBJ)/LL.o: LL.cpp LL.h
	$(CC) $(FLAGS) -c LL.cpp -o $@

$(OBJ)/BSTTemp.o: BSTTemp.cpp BSTTemp.h
	$(CC) $(FLAGS) -c BSTTemp.cpp -o $@

tar:	clean
	tar cvvf $(TARFILE) $(REPODIR)
	gzip $(TARFILE)

clean:
	rm -f $(OBJ)/*.o $(BIN)/$(EXE) *.tar.gz
