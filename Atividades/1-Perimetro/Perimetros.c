/*
/*Autor: Lucas Costa Bezerra (20180000247)
/*Programa para calcular perímetro de circunferência, triângulo e quadrado.
*/

//Prototipo
float perimetro_circunferencia(float); //Calcula perímetro de uma circunferência baseada no raio
float perimetro_triangulo(float); //Calcula perímetro do triângulo equilátero baseado em um lado
float perimetro_quadrado(float); //Calcula perímetro de quadrado baseado em um lado


int main(void){
float circunferencia = perimetro_circunferencia(1);
float triangulo = perimetro_triangulo(1);
float quadrado= perimetro_quadrado(1);
printf("Circunferencia %f\n",circunferencia);
printf("Triangulo %f\n",triangulo);
printf("Quadrado %f\n",quadrado);
return 0;
}

//Funções
float perimetro_circunferencia(float raio){
    float perimetro = raio*3.14*4;
    return perimetro;
}
float perimetro_quadrado(float lado){
    float perimetro = lado*4;
    return perimetro;
}
float perimetro_triangulo(float lado){
    float perimetro = lado*3;
    return perimetro;
}




