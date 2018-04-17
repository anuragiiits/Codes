#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct node{
    int index,dis;
}featureDist;

void euclideanDistance(int **training_set, featureDist **DistanceMatrix, int row, int col){
    int i,j,k,sum=0;
    for(i=0;i<row;i++){
        // printf("%d\n",i);
        for(j=0;j<row;j++){
            if(i<j){
                sum=k=0;
                while(k!=col-1){
                    sum = sum + (training_set[i][k]-training_set[j][k])*(training_set[i][k]-training_set[j][k]); //no need to find sq. root because comparison of sq values or unsquared values will give same result
                    k++;
                }
                DistanceMatrix[i][j].dis=DistanceMatrix[j][i].dis=sum;
                DistanceMatrix[i][j].index=DistanceMatrix[j][i].index=i;
            }
            else if(i==j){
                DistanceMatrix[i][j].dis=-1;
                DistanceMatrix[i][j].index=i;
            }
        }
    }
}

int error=0, tempErrorMatrix[10]={0}, correct=0, kval=0;
int cmpfunc (const void * a, const void * b) {
   int x = ((const featureDist*)a)->dis;
    int y = ((const featureDist*)b)->dis;
    return x < y ? -1 : x > y;
}

void findKValue(int **ErrorMatrix, int d, int krange){
    printf("Finding value of k... ");
    int i=0, j=0, *kvalue, sum=0;
    kvalue = (int*)malloc(krange*sizeof(int));
    for(i=0;i<krange;i++){
        sum=0;
        for(j=0;j<d;j++){
            sum+=ErrorMatrix[j][i];
        }
        kvalue[i]=sum;
    }

    sum = kvalue[0];
    j=0;
    for(i=0;i<krange;i++){
        // printf("%d ", kvalue[i]);
        if(sum>kvalue[i]){
            sum=kvalue[i];
            j=i;
        }
    }
    kval = j+1;
    printf("Done\nValue of k : %d\n", j+1);
}

void NearestNode(int **training_set, featureDist **DistanceMatrix, int **ErrorMatrix, int krange, int start, int end, int trainingsetnum, int node, int row){
    int i=0, j=0, temp=0, in=0, max;
    featureDist *tempdis = (featureDist*)malloc((row-(end-start))*sizeof(featureDist));
    for(i=0;i<row;i++){
        if(i<start||i>=end){
            tempdis[j].dis = DistanceMatrix[node][i].dis;
            tempdis[j].index = i;
            j++;
        }
    }
    // printf("sort\n");
    qsort(tempdis, (row-(end-start)), sizeof(featureDist), cmpfunc);
    for(i=0;i<10;i++)
        tempErrorMatrix[i]=0;
    for(i=1;i<=krange;i++){
        for(j=0;j<i;j++){
            tempErrorMatrix[training_set[tempdis[j].index][192]]++;
        }
        max=tempErrorMatrix[0];
        in=0;
        for(j=0;j<10;j++){
            if(max<tempErrorMatrix[j]){
                max=tempErrorMatrix[j];
                in=j;
            }
        }
        if(in!=training_set[node][192]){
            ErrorMatrix[trainingsetnum][i-1]++;
        }
        for(j=0;j<10;j++)
            tempErrorMatrix[j]=0;
    }   
}

void CrossValidation(int** training_set, featureDist **DistanceMatrix, int row, int col, int d, int krange){
    int i=0, trainingsetnum=0,j=0;
    int **ErrorMatrix = (int**)malloc(d*sizeof(int*));
    for(i=0;i<d;i++){
        ErrorMatrix[i] = (int*)malloc(krange*sizeof(int));
    }
    i=0;
    printf("1st fold as test set from %d to %d\n",0, row/d-1);
    printf("Finding nearest k-nodes for 1<=k<=25... ");
    for(i=0;i<row/d;i++){
        trainingsetnum=0;
        // printf("%d \n",i);
        NearestNode(training_set, DistanceMatrix, ErrorMatrix, krange, 0, row/d, trainingsetnum, i, row);
    }
    trainingsetnum=1;
    printf("Done\n2nd fold as test set from %d to %d\n", row/d, 2*row/d-1);
    printf("Finding nearest k-nodes for 1<=k<=25... ");
    for(;i<2*row/d;i++){
        trainingsetnum=1;
        
        NearestNode(training_set, DistanceMatrix, ErrorMatrix, krange, row/d, 2*row/d, trainingsetnum, i, row);
        // printf("%d \n",i);
        
    }
    trainingsetnum=2;
    printf("Done\n3rd fold as test set from %d to %d\n",2*row/d, row);
    printf("Finding nearest k-nodes for 1<=k<=25... ");
    for(;i<row;i++){
        trainingsetnum=2;
        
        NearestNode(training_set, DistanceMatrix, ErrorMatrix, krange, 2*row/d, row, trainingsetnum, i, row);
        // printf("%d \n",i);
        
    }
    printf("Done\n");
    // PrintArray(ErrorMatrix, d, krange);
    findKValue(ErrorMatrix, d, krange);
    
}

void KNNC(featureDist *TestDistance, int row, int** training_set, int k, int cls){
    int i=0,j=0,temp, class[10], in;
    
    qsort(TestDistance, row, sizeof(featureDist), cmpfunc);

    for(i=0;i<10;i++)
        class[i]=0;

    for(i=0;i<k;i++){
        class[training_set[TestDistance[i].index][192]]++;
    }
    int max = class[0];
    in=0;
    for(i=0;i<10;i++){
        if(max<class[i]){
            max=class[i];
            in=i;
        }
    }
    // printf("class :%d %d\n",in, cls);
    if(in==cls)
        correct++;
}

void CalDistance(int **testset, int**training_set, int trow, int row, int col, int kv){
    printf("Calculating distances from every sets and perform K-NNC... ");
    int i=0, j=0, k=0,sum =0;
    featureDist *TestDistance;
    TestDistance = (featureDist*)malloc(row*sizeof(featureDist));
    for(k=0;k<trow;k++){
        // printf("%d\n",k);
        for(i=0;i<row;i++){
            j=sum=0;
            while(j!=col-1){
                sum+=(testset[k][j]-training_set[i][j])*(testset[k][j]-training_set[i][j]);
                j++;
            }
            TestDistance[i].dis=sum;
            TestDistance[i].index=i;
        }
        KNNC(TestDistance, row, training_set, kv, testset[k][j]);
    }
    printf("Done\n");
}

void TestClass(int **training_set, int trainrow, int traincol, int k){
    printf("Reading the test set... ");
    int **testset, i, j, count=3333, row=3333, col=193;
    testset = (int**)malloc(row*sizeof(int*));
    for(i=0;i<row;i++)
        testset[i] = (int*)malloc(col*sizeof(int));

    FILE *test = fopen("pp_tes.dat", "r");
    for(i=0;i<count;i++){
        j=0;
        while(j!=col){
            fscanf(test, "%d", &testset[i][j]);
            j++;
        }
    }
    // PrintArray(testset, row, col-1);
    printf("Done\n");
    CalDistance(testset, training_set, row, trainrow, col, k);
}

int main(){
    int **training_set, i,row=6670, col=193, d=3, krange=25;
    training_set = (int**)malloc(row*sizeof(int*));
    for(i=0;i<row;i++){
        training_set[i] = (int*)malloc(col*sizeof(int));
    }
    printf("Initializing... Done\n");
    printf("Reading Training set from File... ");
    FILE *train = fopen("shuffled.dat","r");
    for(i=0;i<row;i++){
        int j=0;
        while(j!=col){
            fscanf(train, "%d", &training_set[i][j]);
            // printf("print %d\n", training_set[i][j]);
            j++;
        }
    }
    fclose(train);
    featureDist **DistanceMatrix = (featureDist**)malloc(row*sizeof(featureDist*));         //declaration of feature distance struct
    for(i=0;i<row;i++)
        DistanceMatrix[i] = (featureDist*)malloc(row*sizeof(featureDist));

    // PrintArray(training_set, row, col);
    // printf("Cross Validation\n");
    printf("Done\nPrecomputing distance between every neighbours... ");
    euclideanDistance(training_set, DistanceMatrix, row, col);      //finding euclidean distance between every points
    printf("Done\n\nCross Validation \n");                          //perform cross validation to find k
    CrossValidation(training_set, DistanceMatrix, row, col, d, krange);
    printf("Training Over\n\n");
    TestClass(training_set, row, col, kval);
    printf("Total correct classes : %d\n",correct);
    printf("Accuraccy in Percentage: %f\n",(correct/3333.0)*100);   
    return 0;
}