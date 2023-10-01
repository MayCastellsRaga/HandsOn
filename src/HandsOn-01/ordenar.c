#include <stdio.h>
#include <stdlib.h>



int main()
{

    
int nums[]= {4,2,8,1,5};
int trobat=0;
int temp =0;
int num_elemens =sizeof(nums)/sizeof(nums[0]);

while (trobat == 0)
 {
    trobat = 1;
    for (int i = 0; i < num_elemens ; i++)
     {
        if ( i<num_elemens-1&&nums[i] > nums[i + 1]) {
            temp = nums[i];
            nums[i] = nums[i + 1];
            nums[i + 1] = temp;
            trobat = 0;
        }
    }
}
for(int i=0; i<(sizeof(nums)/sizeof(nums[0]));i++)
{
    printf("%d",nums[i]);
}
printf("\n");
return 0;
}

