#include <stdio.h>
#include <sys/types.h>
#include <time.h>

double funkcja(double x){
    return 4*x-6*x+5;
}

double licz(double a, double b, double ile){
    double h = (b-a)/ile;
    double wynik = funkcja(a)/2;
    wynik += funkcja(b)/2;
    for(double i = 1; i < ile-1; i+=1){
        wynik += funkcja(a+(i/ile)*(b-a));
    }
    wynik = wynik*h;
    return wynik;
}

void forker(int ile){
pid_t pid;

if(ile > 0){
    pid = fork();
    if(pid < 0)
    {
        perror("fork");
    }
    else if(pid == 0){
    srand(time(NULL)^getpid());
    double randa = rand()%100;
    double randb = rand()%100;
    randb += randa;
    int trapezy = rand()%500;

    printf("Proces %d a = %.1f, b = %.1f, ilosc trapezow = %d, wynik = %f\n"
    , ile, randa, randb, trapezy, licz(randa, randb, trapezy));

    }
    else{
        forker(ile-1);
    }
}
}

int main(){
int P = 18;
forker(P);

return 0;
}

