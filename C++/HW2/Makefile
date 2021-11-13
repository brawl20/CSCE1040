output: Main.o Customer.o CustomerCollection.o Loan.o LoanCollection.o Movie.o MovieCollection.o
	g++ Main.o Customer.o CustomerCollection.o Loan.o LoanCollection.o Movie.o MovieCollection.o -o output

Main.o: Main.cpp
	g++ -c Main.cpp

Customer.o: Customer.cpp Customer.h
	g++ -c Customer.cpp 

CustomerCollection.o: CustomerCollection.cpp CustomerCollection.h
	g++ -c CustomerCollection.cpp

Loan.o: Loan.cpp Loan.h
	g++ -c Loan.cpp

LoanCollection.o: LoanCollection.cpp LoanCollection.h
	g++ -c LoanCollection.cpp

Movie.o: g++ -c Movie.cpp Movie.h
	g++ -c Movie.cpp

MovieCollection.o: MovieCollection.cpp MovieCollection.h
	g++ -c MovieCollection.cpp

clean:
	rm *.o output