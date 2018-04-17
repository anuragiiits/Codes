#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int right=0;
int class_number(int *array, int len){
    int index=0,max = array[0];
    for (int i = 0; i < len; ++i){
        if(max<=array[i]){
            max=array[i];
            index = i;
        }
    }
    return index;
}

void BayesTheorm(float ***prob_mat, int *test, int features){
    int i=0, index, j=0, max;
    int *each_class_probab = (int*)malloc(10*sizeof(int));
    for(i=0;i<features-1;i++){
        for(j=0;j<10;j++){
            each_class_probab[j]+=prob_mat[i][j][test[i]];
        }
    } 
    if(class_number(each_class_probab,10)==test[192])
        right++;
}

void beginTest(float ***prob_mat){
    printf("Reading test file and Calculating their class... ");
    FILE *test = fopen("pp_tes.dat","r");
    int i=0, j=0, k=0, row=3333, col=193;
    int **test_set = (int**)malloc(row*sizeof(int*));
    for(i=0;i<row;i++){
        test_set[i] = (int*)malloc(col*sizeof(int));
    }

    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            fscanf(test,"%d",&test_set[i][j]);
        }
        BayesTheorm(prob_mat, test_set[i], col);
    }
    printf("Done\n");
    printf("Total correct classes: %d\n", right);
    printf("Accuracy in Percentage: %f\n",(right/3333.0)*100.0);
}


void NaiveBayes(int **training_set, float* class_prob, float *feature_mat, int row, int col){
    int i=0, j=0, k=0;
    float ***prob_mat = (float***)malloc((col-1)*sizeof(float**));  //for each columns or features
    for(i=0;i<col-1;i++){
        prob_mat[i] = (float**)malloc(10*sizeof(float*));           //for each classes
        for(j=0;j<10;j++){
            prob_mat[i][j] = (float*)malloc(5*sizeof(float));       //for each value of classes
        }
    }

    printf("Calculating the probability matrix... ");
    for(i=0;i<row;i++){
        for(j=0;j<col-1;j++){
            prob_mat[j][training_set[i][192]][training_set[i][j]]++;
        }
    }

    for(i=0;i<col-1;i++){
        for(j=0;j<10;j++){
            for(k=0;k<5;k++){
                prob_mat[i][j][k]=log(prob_mat[i][j][k]/class_prob[j])+log(feature_mat[j]);
            }
        }
    }
    printf("Done\n\nTesting Started\n");
    beginTest(prob_mat);
}

int main(){
    FILE* train = fopen("shuffled.dat","r");
    int i=0, j=0, cls=10, feature=5, row=6670, col=193;
    int **training_set;
    float *class_prob, *feature_mat;
    
    training_set = (int**)malloc(row*sizeof(int*));
    class_prob = (float*)malloc(cls*sizeof(float));
    feature_mat = (float*)malloc(cls*sizeof(float));
    
    printf("Reading training set... ");
    for(i=0;i<row;i++){
        training_set[i] = (int*)malloc(col*sizeof(int));
        j=0;
        while(j!=col){
            fscanf(train,"%d",&training_set[i][j]);
            j++;
        }
        class_prob[training_set[i][192]]++;
    }
    printf("Done\n");
    printf("Training Started\n");
    for(i=0;i<cls;i++)
        feature_mat[i] = class_prob[i]/6670.0;
    NaiveBayes(training_set, class_prob, feature_mat, row, col);
    return 0;
}
