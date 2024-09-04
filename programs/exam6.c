#include <stdio.h>
#include <stdlib.h>
//Η συνάρτηση collatz.c δέχεται έναν αριθμό από το χρήστη και επιστρέφει το μέγιστο μήκος της ακολουθίας του 
int collatz (long long n) {
    int count = 1;
    while ( n != 1 ) {
        if ( n % 2 == 0 ) {
        n /= 2;
        count++;
    }
        else {
            n = ( ( 3 * n ) + 1 );
            count++;
        }
    }
        return count;
}


int main ( int argc, char * argv[]) {
    if ( argc != 3 ) {
        return 0;
    }
    // ο πρώτος αριθμός του πίνακα argv είναι το όνομα του προγράμματος και θέτουμε ως δεύτερο αριθμό του πίνακα τη τιμή του lower_limit 
    long long low = atoll (argv[1]);
    // θέτουμε ως τρίτο αριθμό του πίνακα argv την τιμή του upper_limit
    long long up = atoll (argv[2]);
    // έλεγχος τιμών εισόδου
    if ( low < 1 || up < 1 || up >= 100000001 ) {
    printf ( "%d\n" , 0 );
    return 0;
}
// μεγαλύτερο δυνατό μήκος ακολουθίας
int max = 0;
for (long long i=low ; i<=up ; i++){
    int length=collatz(i);
    if (length > max ) {
        max=length;
    }
}
printf ("%d\n" , max);
return 0;
}




