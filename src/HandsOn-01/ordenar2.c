#include <stdio.h>
#include <stdlib.h>



int main()
{
    int num_elements;
    printf("Ingrese la cantidad de números: ");
    scanf("%d", &num_elements);
    int nums[num_elements];
    printf("Ingrese los números uno por uno:\n");
    for (int i = 0; i < num_elements; i++) {
        scanf("%d", &nums[i]);
    }
int trobat=0;
int temp =0;


while (trobat == 0)
 {
    trobat = 1;
    for (int i = 0; i < num_elements ; i++)
     {
        if ( i<num_elements-1&&nums[i] > nums[i + 1]) {
            temp = nums[i];
            nums[i] = nums[i + 1];
            nums[i + 1] = temp;
            trobat = 0;
        }
    }
}
for(int i=0; i<num_elements;i++)
{
    printf("%d",nums[i]);
}
printf("\n");
return 0;
}

