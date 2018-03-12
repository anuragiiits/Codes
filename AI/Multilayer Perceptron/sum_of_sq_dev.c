#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef struct node{
	int n;
	double bias, wts[20];
}node;


// Global Vars
int tr_data[2000][17] = {0};
double bias_inp, bias_hid;
	// arr of 8-neuron-input, hidden and output
node in[16], hidden[8], out[10];


double sigmoid(double x){
	return (double)((1.0)/(1+exp(-1*x)));
}

double derivativefun(double x){
	return (double)(sigmoid(x)*(1-sigmoid(x)));
}

double randomWeights(){
	// return ((((double)(rand()) / (double)(RAND_MAX))*6)-3)/100.0;
	// return ((float)(rand()) / (float)(RAND_MAX)) * (0.5+0.5) -0.5;
	return ((float)(rand()) / (float)(RAND_MAX))/100.0;				
}

void loadTrainData(){
	FILE *train_csv = fopen("train.csv", "r");

	// int tr_data[2000][16] = {0};
	for (int i = 0; i < 2000; ++i)
	{
		fscanf(train_csv, "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d", &tr_data[i][0], &tr_data[i][1], &tr_data[i][2], &tr_data[i][3], &tr_data[i][4], &tr_data[i][5], &tr_data[i][6], &tr_data[i][7], &tr_data[i][8], &tr_data[i][9], &tr_data[i][10], &tr_data[i][11], &tr_data[i][12], &tr_data[i][13], &tr_data[i][14], &tr_data[i][15], &tr_data[i][16]);
	}
	fclose(train_csv);
	
}

double dotproduct(node ne, double *x){	//x the input
	double ans=0;
	for (int i = 0; i < ne.n; ++i)
	{
		ans += ne.wts[i]*x[i];
	}
	return ans+ne.bias;
}

void init(){
	for (int i = 0; i < 16; ++i)
	{
		in[i].n = 1;
		for (int j = 0; j < in[i].n; ++j)			//not required
		{
			in[i].wts[j] = 1;		

		}
		in[i].bias = 1;		
	}

	for (int i = 0; i < 8; ++i)
	{
		hidden[i].n = 16;
		for (int j = 0; j < hidden[i].n; ++j)
		{
			hidden[i].wts[j] = randomWeights();
		}
		hidden[i].bias = 1;		
	}

	for (int i = 0; i < 10; ++i)
	{
		out[i].n = 8;
		for (int j = 0; j < out[i].n; ++j)
		{
			out[i].wts[j] = randomWeights();		
		}
		out[i].bias = 1;		
	}
	bias_inp = randomWeights();
	bias_hid = randomWeights();	
}



int main(){
	srand((unsigned int)time(NULL));
	loadTrainData();
	init();
	double fderv,sum,delta[20],eta = 0.01;
	int tk=0;
	double netk[20], netj[20], dif=0.1;
	int count=0;
	//multiply the first layer 
	float sum_delta=0.1;
	while((float)(sum_delta)>(0.00001*eta)){
		// printf("in %f\n", sum_delta);
		sum_delta=0;
		count=0;
		for (int i = 0; i < 2200; ++i){
			double in_out[16]={0}; 			//in_out will be the input of hidden layer.

			for (int j = 0; j < 16; ++j){
				in_out[j] = (tr_data[i][j+1])*1.0;
			}

			double hidden_out[8] = {0};
			for (int j = 0; j < 8; ++j){
				netj[j] = dotproduct(hidden[j], in_out)+bias_inp;
				hidden_out[j] = sigmoid(netj[j]);
			}

			double out_out[10] = {0};
			for (int j = 0; j < 10; ++j){
				netk[j] = dotproduct(out[j], hidden_out)+bias_hid;
				out_out[j] = sigmoid(netk[j]); 				
				// printf("output %llf\n", out_out[j]);
			}
			
			for(int k = 0; k < 10; ++k){					//back propogation
				tk = 0;
				if((k+1) == tr_data[i][0])
				{
					tk = 1;
				}
				fderv = derivativefun(netk[k]);
				delta[k] = ((double)tk-out_out[k])*(float)fderv;
				for(int j=0; j<8; j++)
				{
					dif = delta[k]*hidden_out[j]*eta;
					out[k].wts[j] += dif;
				}
				dif = delta[k]*bias_hid*eta;
				sum_delta=sum_delta+dif*dif;
				count++;
				bias_hid += dif;
			}

			for(int j=0;j<8;j++)
			{
				fderv = derivativefun(netj[j]);
				for (int _i = 0; _i < 16; ++_i)
				{
					sum = 0;
					for(int r=0; r<10; r++)
					{
						sum += delta[r] * out[r].wts[j];
					}
					dif = sum * eta * fderv * in_out[_i];
					hidden[j].wts[_i] += dif;
					// printf("%llf, %llf, %llf\n", dif, sum, eta);
				}
				dif = sum * eta * fderv * bias_inp;
				sum_delta=sum_delta+dif*dif;
				count++;
				bias_inp+=dif;
			}

		}
		sum_delta = sqrt(dif/count);
	}
	// printf("%d\n", count);
	int cnt=count;
	FILE *train_csv = fopen("test.csv", "r");
	count =0;int p;
	double max;
	double in_out[16]={0}; //in_out will be the input of hidden layer.
	for (int i = 0; i < 900; ++i){
		fscanf(train_csv, "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d", &tr_data[i][0], &tr_data[i][1], &tr_data[i][2], &tr_data[i][3], &tr_data[i][4], &tr_data[i][5], &tr_data[i][6], &tr_data[i][7], &tr_data[i][8], &tr_data[i][9], &tr_data[i][10], &tr_data[i][11], &tr_data[i][12], &tr_data[i][13], &tr_data[i][14], &tr_data[i][15], &tr_data[i][16]);
			for (int j = 0; j < 16; ++j)
			{
				in_out[j] = (in[j].wts[0]*tr_data[i][j+1]);
			}

			double hidden_out[8] = {0};
			for (int j = 0; j < 8; ++j){
				netj[j] = dotproduct(hidden[j], in_out)+bias_inp;
				hidden_out[j] = sigmoid(netj[j]);
			}

			double out_out[10] = {0};
			max = out_out[0];
			p=0;
			for (int j = 0; j < 10; ++j)
			{
				netk[j] = dotproduct(out[j], hidden_out)+bias_hid;
				out_out[j] = sigmoid(netk[j]); 
				if(out_out[j] > max){
					max = out_out[j];
					p=j;
				}
				// printf("%llf\n", out_out[j]);
			}
			if((p+1) == (int)tr_data[i][0]){
				count++;
			}
			

	}
	fclose(train_csv);
	printf("Method Type: Sum of Squared Deviation\n");
	printf("Stopping Condition: Value of delta weight\n");
	printf("Number of neurons in hidden layer = 8\n");
	printf("Value of eta = %f\n", eta);
	printf("Accuracy = %f\n", count/900.0*100.0);
	return 0;
}
