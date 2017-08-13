//Finding second smallest and second largest element using Divide and Conquer
    #include<stdio.h>
    #include<stdlib.h>
    
    #define min(a,b) ((a)<(b)?(a):(b))
    #define max(a,b) ((a)>(b)?(a):(b))
    
    typedef struct pair{
        int m1,    m2;    
    } pair;
    
    pair* sec(int *arr,int l,int u){
        int min1, min2, mid;
        pair *p = (pair *)malloc(sizeof(pair));
        printf("l= %d, u = %d\n", l, u);
        int n = (u - l) + 1; 
        if(n==2){
            if(arr[l] > arr[u]){
                min1 = arr[u];
                min2 = arr[l];
            } else {
                min1 = arr[l];
                min2 = arr[u];
            }

        }
        else if (n == 1){
            min1 = arr[l];
            min2 = 99999999;    

        }
        else {
            pair *pl, *pr;
            mid = (l+u)/2;
            pl = sec(arr, l, mid);
            pr = sec(arr,(mid+1),u);
            if(pl->m1 < pr->m1){
                min1 = pl->m1;
                min2 = min(pl->m2, pr->m1);
            } else {
                min1 = pr->m1;
                min2 = min(pl->m1, pr->m2);
            }
            free(pl);
            free(pr);

        }
        p->m1 = min1;
        p->m2 = min2;
        printf("%d, %d\n", p->m1, p->m2);
        getchar();
        return p;

    }

    int main() {
        int n;
        printf("Enter the size of array\n");
        scanf("%d",&n);
        int A[n]; // creating an array of integers. 
        int i;
        for(i=0;i<n;i++)
            scanf("%d",&A[i]);
        
        
    
        // Calling Sort to sort the array. 
        pair *p = sec(A, 0, n-1);
    
        //printing the smallest & second smallest
         printf("%d %d",p->m1, p->m2);
        return 0;
    }
