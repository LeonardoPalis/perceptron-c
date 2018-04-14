#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include "config.h"
#include <math.h>
using namespace std;
typedef int TRAINING;

void initialize_perceptron();
int activation_function(float *);
void recalculateWeight(TRAINING, TRAINING);
void training();
void setPerceptron(int);
float** alocarMatriz(int);
void andTrainingMatrixGenerator(int);
void orTrainingMatrixGenerator(int);
void xorTrainingMatrixGenerator(int);
float ** learningMatrix; //principal matrix
float * weight; //weight vector of perceptron
float sum;				  //variable designated to register the sum
int current_seasons;			  //variable disignated to count past seasons
int wrong_choice = 1;
int tam;
int main(){
	tam = 0;
	while(1){

		while(wrong_choice){
			cout << "==========================================================================================================================================" << endl;
			cout << "MENU - \n\tType 1 to calculate AND function - Type 2 to calculate OR function - Type 3 to calculate XOR function - Type 4 to clear console" << endl;
			cout << "==========================================================================================================================================" << endl;
			int menu;
			cout << ">> ";
			cin >> menu;			
			setPerceptron(menu);
		}
		initialize_perceptron(); 
		training();
		cout << endl << "Trained! Lets test!" << endl;
		
		string x;
		
		float in[tam];
		cout << "In >> ";
		
		for (int i = 0; i < tam; ++i)
		{
			cin >> in[i];
		}
		int response = activation_function(&in[0]);
		cout << "----------------------------" << endl;
		cout << "\t  Response" << endl;
		cout << "\t  <<  " << response << "  >>" << endl;
		cout << "----------------------------" << endl;
		wrong_choice = 1;
	}
}

float** alocarMatriz(int tam){ //Recebe a quantidade de Linhas e Colunas como Parâmetro

  float aux = pow(2.0, tam);
  MATRIX_i = (int)floor(aux + 0.5);
  MATRIX_j = tam + 1;
  int Linhas = MATRIX_i, Colunas = MATRIX_j;
  int i,j; //Variáveis Auxiliares

  weight = (float*) malloc(tam * sizeof(float));
  NUM_WEIGHT = tam + 1;
  float **m = (float**)malloc(Linhas * sizeof(float*)); //Aloca um Vetor de Ponteiros

  for (i = 0; i < Linhas; i++){ //Percorre as linhas do Vetor de Ponteiros
       m[i] = (float*) malloc(Colunas * sizeof(float)); //Aloca um Vetor de Inteiros para cada posição do Vetor de Ponteiros.
       for (j = 0; j < Colunas; j++){ //Percorre o Vetor de Inteiros atual.
            m[i][j] = 0; //Inicializa com 0.
       }
  }
return m; //Retorna o Ponteiro para a Matriz Alocada
}

void andTrainingMatrixGenerator(int size) {


		if (size == 2) {

			float aux[4][3] = {{0,0,0},{0,1,0},{1,0,0},{1,1,1}};

				for (int i = 0; i < MATRIX_i; i++)
		{	
			cout << endl;
			for (int j = 0; j < MATRIX_j; j++)
			{
				cout << aux[i][j] << " ";
				learningMatrix[i][j] = aux[i][j];
			}
		}

		} else if (size == 3) {
			float aux[8][4] = {
			{0,0,0,0},
			{0,0,1,0},
			{0,1,0,0},
			{0,1,1,0},
			{1,0,0,0},
			{1,0,1,0},
			{1,1,0,0},
			{1,1,1,1}};
				for (int i = 0; i < MATRIX_i; i++)
		{	
			cout << endl;
			for (int j = 0; j < MATRIX_j; j++)
			{
				cout << aux[i][j] << " ";
				learningMatrix[i][j] = aux[i][j];
			}
		}

		} else {
			float aux[16][5] = {
				{0,0,0,0,0},
				{0,0,0,1,0},
				{0,0,1,0,0},
				{0,0,1,1,0},
				{0,1,0,0,0},
				{0,1,0,1,0},
				{0,1,1,0,0},
				{0,1,1,1,0},
				{1,0,0,0,0},
				{1,0,0,1,0},
				{1,0,1,0,0},
				{1,0,1,1,0},
				{1,1,0,0,0},
				{1,1,0,1,0},
				{1,1,1,0,0},
				{1,1,1,1,1}};

					for (int i = 0; i < MATRIX_i; i++)
		{	
			cout << endl;
			for (int j = 0; j < MATRIX_j; j++)
			{
				cout << aux[i][j] << " ";
				learningMatrix[i][j] = aux[i][j];
			}
		}
		}

	




}

void orTrainingMatrixGenerator(int size) {
		if (size == 2) {

			float aux[4][3] = {{0,0,0},{0,1,1},{1,0,1},{1,1,1}};

				for (int i = 0; i < MATRIX_i; i++)
		{	
			cout << endl;
			for (int j = 0; j < MATRIX_j; j++)
			{
				cout << aux[i][j] << " ";
				learningMatrix[i][j] = aux[i][j];
			}
		}

		} else if (size == 3) {
			float aux[8][4] = {
			{0,0,0,0},
			{0,0,1,1},
			{0,1,0,1},
			{0,1,1,1},
			{1,0,0,1},
			{1,0,1,1},
			{1,1,0,1},
			{1,1,1,1}};

				for (int i = 0; i < MATRIX_i; i++)
		{	
			cout << endl;
			for (int j = 0; j < MATRIX_j; j++)
			{
				cout << aux[i][j] << " ";
				learningMatrix[i][j] = aux[i][j];
			}
		}

		} else {
			float aux[16][5] = {
				{0,0,0,0,0},
				{0,0,0,1,1},
				{0,0,1,0,1},
				{0,0,1,1,1},
				{0,1,0,0,1},
				{0,1,0,1,1},
				{0,1,1,0,1},
				{0,1,1,1,1},
				{1,0,0,0,1},
				{1,0,0,1,1},
				{1,0,1,0,1},
				{1,0,1,1,1},
				{1,1,0,0,1},
				{1,1,0,1,1},
				{1,1,1,0,1},
				{1,1,1,1,1}};

					for (int i = 0; i < MATRIX_i; i++)
		{	
			cout << endl;
			for (int j = 0; j < MATRIX_j; j++)
			{
				cout << aux[i][j] << " ";
				learningMatrix[i][j] = aux[i][j];
			}
		}
		}


}

void xorTrainingMatrixGenerator(int size) {
		if (size == 2) {

			float aux[4][3] = {{0,0,0},{0,1,1},{1,0,1},{1,1,0}};

				for (int i = 0; i < MATRIX_i; i++)
		{	
			cout << endl;
			for (int j = 0; j < MATRIX_j; j++)
			{
				cout << aux[i][j] << " ";
				learningMatrix[i][j] = aux[i][j];
			}
		}

		} else if (size == 3) {
			float aux[8][4] = {
			{0,0,0,0},
			{0,0,1,1},
			{0,1,0,1},
			{0,1,1,0},
			{1,0,0,1},
			{1,0,1,0},
			{1,1,0,0},
			{1,1,1,0}};

				for (int i = 0; i < MATRIX_i; i++)
		{	
			cout << endl;
			for (int j = 0; j < MATRIX_j; j++)
			{
				cout << aux[i][j] << " ";
				learningMatrix[i][j] = aux[i][j];
			}
		}

		} else {
			float aux[16][5] = {
				{0,0,0,0,0},
				{0,0,0,1,1},
				{0,0,1,0,1},
				{0,0,1,1,0},
				{0,1,0,0,1},
				{0,1,0,1,0},
				{0,1,1,0,0},
				{0,1,1,1,0},
				{1,0,0,0,1},
				{1,0,0,1,0},
				{1,0,1,0,0},
				{1,0,1,1,0},
				{1,1,0,0,0},
				{1,1,0,1,0},
				{1,1,1,0,0},
				{1,1,1,1,0}};

					for (int i = 0; i < MATRIX_i; i++)
		{	
			cout << endl;
			for (int j = 0; j < MATRIX_j; j++)
			{
				cout << aux[i][j] << " ";
				learningMatrix[i][j] = aux[i][j];
			}
		}
		}

}

void setPerceptron(int choice){	
	
	if(choice == 1){
		wrong_choice = 0;
		cout << "You choice AND: " << endl;
		cout << "Type lenght of input (less than 5) >> ";
		cin >> tam;
		learningMatrix = alocarMatriz(tam);
		andTrainingMatrixGenerator(tam);
	}else if(choice == 2){
		wrong_choice = 0;
		cout << "Type lenght of input (less than 5) >> ";
		cin >> tam;
		learningMatrix = alocarMatriz(tam);
		orTrainingMatrixGenerator(tam);
	}else if(choice == 3){
		wrong_choice = 0;
		cout << "Type lenght of input (less than 5) >> ";
		cin >> tam;
		learningMatrix = alocarMatriz(tam);
		xorTrainingMatrixGenerator(tam);
	}else if(choice == 4){
		wrong_choice = 1;
		system("clear");
	}else{
		wrong_choice = 1;
		system("clear");
		cout << endl << "(COMMAND " << choice << " NOT EXISTS)" << endl;
	}
}


void training(){

	TRAINING isTrained = 1; //bool variable
	TRAINING out = 0;
	for(TRAINING i = 0; i < MATRIX_i; i++){
		out = activation_function(&learningMatrix[i][0]);
		if(out != learningMatrix[i][MATRIX_j-1]){
			//cout << "FIND ERROR" << endl;
			recalculateWeight(i,out);
			isTrained = 0;	//find error
		}
		current_seasons++;	//change of season
		if(!isTrained && (current_seasons < SEASONS)){
			training();
		}

	}

}

int activation_function(float * vector){
	sum = 0;

	for (int i = 0; i < MATRIX_j - 1; i++) {
		sum += vector[i]*weight[i];
	}

	sum +=  ((-1)*weight[MATRIX_j-1]);
	
	int response = (sum >= 0) ?  1 : 0;
	//cout << "X: " << x << " Y: " << y << " SUM: " << sum << " BEFORE AF: " << response << " WEIGHT 1: " <<  weight[0] 
		// << " WEIGHT 2: " <<  weight[1]  << " WEIGHT 3: " <<  weight[2] << endl;
	return response;
}

void recalculateWeight(TRAINING position, TRAINING out){
	int i;
	for (i = 0; i < MATRIX_j - 1; i++) {
		weight[i] = weight[i] + (N * (learningMatrix[position][MATRIX_j-1] - out) * learningMatrix[position][i]);
	}

    weight[i] = weight[i] + (N * (learningMatrix[position][MATRIX_j-1] - out) * (-1));

}

//function created to initialize the params of perceptron
void initialize_perceptron(){
	sum = 0;
	current_seasons = 0;
	for(int i = 0; i < NUM_WEIGHT; i++){
		weight[i] = 0.1;
	}
}