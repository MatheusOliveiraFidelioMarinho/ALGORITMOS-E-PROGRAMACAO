/*Leia os quatro valores correspondentes aos eixos x e y de dois pontos quaisquer no
plano, p1(x1, y1) e p2(x2, y2) e calcule a distância entre eles, mostrando 4 casas decimais
após a vírgula, segundo a fórmula:*/
#include<stdio.h>
#include<math.h>
int main(){

    int x1;
    int x2;
    int y1;
    int y2;
    float distancia;

        printf("Informe 4 valores que correspondem aos eixos, X1, X2, Y1, Y2: ");
        scanf("%d %d %d %d", &x1, &x2, &y1, &y2);

        distancia = sqrt(pow(((float)x2-(float)x1),2)+pow(((float)y2-(float)y1),2)); 

        printf("A distancia é = %.4f", distancia);


    return 0;
}