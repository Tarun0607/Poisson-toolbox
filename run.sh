rm *.o *.so *.lib test

export R_HOME=/usr/lib/R
gcc $(R CMD config --cppflags) -fPIC -c r_ppois.c $(R CMD config --ldflags)
gcc $(R CMD config --cppflags) -shared -o libr_ppois.so r_ppois.o $(R CMD config --ldflags)
gcc $(R CMD config --cppflags) -L$(pwd) -Wl,-rpath=$(pwd) -o test main.c -lr_ppois -g $(R CMD config --ldflags)
./test

cp r_ppois.h thirdparty/linux/include/
cp libr_ppois.so thirdparty/linux/lib/x64/

cp r_ppois.h thirdparty/Mac/include/
cp libr_ppois.so thirdparty/Mac/lib/x64/
