CC=gcc

CFLAGS=-Wall -Iinclude `pkg-config --cflags glib-2.0` -g
LDFLAGS=`pkg-config --libs glib-2.0` -lm -lncurses

programa-principal : src/structs.o src/main.o src/hash.o src/parserDrivers.o src/parserRides.o src/parserUsers.o src/city.o src/queries.o src/query1.o src/interactive_mode.o src/querie2.o src/querie3.o src/querie4.o src/query5.o src/query6.o src/query7.o src/query8.o src/query9.o src/city_driver.o src/date.o src/avaliacao_driver.o src/dist_user.o src/loadGeral.o  src/drivers.o src/users.o src/rides.o 
	@mkdir -p Resultados
	$(CC) $(CFLAGS)  $^ $(LDFLAGS) -o $@
	
programa-testes : src/structs.o src/mainTestes.o src/hash.o src/parserDrivers.o src/parserRides.o src/parserUsers.o src/city.o src/queries.o src/query1.o src/interactive_mode.o src/querie2.o src/querie3.o src/querie4.o src/query5.o src/query6.o src/query7.o src/query8.o src/query9.o src/city_driver.o src/date.o src/avaliacao_driver.o src/dist_user.o src/loadGeral.o  src/drivers.o src/users.o src/rides.o 
	@mkdir -p Resultados
	$(CC) $(CFLAGS)  $^ $(LDFLAGS) -o $@
	 
src/main.o: src/main.c
	$(CC) $(CFLAGS) -c $< -o $@
	
src/mainTestes.o: src/mainTestes.c
	$(CC) $(CFLAGS) -c $< -o $@

src/hash.o: src/hash.c 
	$(CC) $(CFLAGS) -c $< -o $@

src/parserDrivers.o: src/parserDrivers.c 
	$(CC) $(CFLAGS) -c $< -o $@

src/parserRides.o: src/parserRides.c 
	$(CC) $(CFLAGS) -c $< -o $@

src/parserUsers.o: src/parserUsers.c
	$(CC) $(CFLAGS) -c $< -o $@

src/structs.o: src/structs.c 
	$(CC) $(CFLAGS) -c $< -o $@

src/queries.o: src/queries.c
	$(CC) $(CFLAGS) -c $< -o $@

src/query1.o: src/query1.c
	$(CC) $(CFLAGS) -c $< -o $@	

src/querie2.o: src/querie2.c 
	$(CC) $(CFLAGS) -c $< -o $@

src/querie3.o: src/querie3.c 
	$(CC) $(CFLAGS) -c $< -o $@

src/querie4.o: src/querie4.c
	$(CC) $(CFLAGS) -c $< -o $@

src/querie5.o: src/query5.c
	$(CC) $(CFLAGS) -c $< -o $@

src/querie6.o: src/query6.c
	$(CC) $(CFLAGS) -c $< -o $@

src/querie7.o: src/query7.c
	$(CC) $(CFLAGS) -c $< -o $@

src/query9.o: src/query9.c
	$(CC) $(CFLAGS) -c $< -o $@		

src/query8.o: src/query8.c
	$(CC) $(CFLAGS) -c $< -o $@	

src/date.o: src/date.c
	$(CC) $(CFLAGS) -c $< -o $@

src/loadGeral.o: src/loadGeral.c
	$(CC) $(CFLAGS) -c $< -o $@

src/avaliacao_driver.o: src/avaliacao_driver.c
	$(CC) $(CFLAGS) -c $< -o $@	

src/city_driver.o: src/city_driver.c
	$(CC) $(CFLAGS) -c $< -o $@	

src/dist_user.o: src/dist_user.c
	$(CC) $(CFLAGS) -c $< -o $@

src/drivers.o: src/drivers.c
	$(CC) $(CFLAGS) -c $< -o $@	

src/users.o: src/users.c
	$(CC) $(CFLAGS) -c $< -o $@	

src/rides.o: src/rides.c
	$(CC) $(CFLAGS) -c $< -o $@		

src/city.o: src/city.c
	$(CC) $(CFLAGS) -c $< -o $@

src/interactive_mode.o: src/interactive_mode.c
	$(CC) $(CFLAGS) -c $< -o $@							

clean : 
	rm -f programa-principal src/*.o
	rm -f programa-testes src/*.o
	rm -r Resultados
