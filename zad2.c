#include <stdio.h>
#include <sys/types.h>
#include <time.h>
#include <math.h>

double licz(int ile){
    double wynik = 0;
    for(int i=1; i< ile; i++){
        wynik +=(pow(-1, i-1))/(2*i-1);
    }
    return wynik*4;
}

void forker(int ile){
pid_t pid;

if(ile > 0){
    pid = fork();
    if(pid < 0){
        perror("fork");
    }else if(pid == 0){
        srand(time(NULL)^getpid());
        int n = 100+rand()%4901;
        printf("Dla n = %d wartość PI = %f\n", n, licz(n));
    }
    else{
        forker(ile-1);
    }
    }
}


int main(){
int P = 50;
forker(P);

return 0;
}

