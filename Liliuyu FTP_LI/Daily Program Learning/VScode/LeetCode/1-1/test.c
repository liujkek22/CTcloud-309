#include <stdio.h>

int minNumber(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int i,j,min1=nums1[0],min2=nums2[0],same=nums1[0],k=0,l;
    for(i=0;i<nums1Size;i++)
    {
        for(j=0;j<nums2Size;j++)
        {
            if(nums1[i]==nums2[j])
            {
                if(nums2[j]<=same)
                {
                    same = nums2[j];
                    k=1;
                }
            }
            if(min1>nums1[j])
            {
                min1=nums1[j];
            }
            if(min2>nums2[j])
            {
                min2=nums2[j];
            }
        }//本循环求出两数组的最小值
    }
    if(k==1)
    {
        l= same;
        return l;
    }
    else if(min1>min2)
    {
        l= min2*10+min1;
    }
    else if(min1<min2)
    {
        l= min1*10+min2;
    }
    return l;
}

int main()
{
    int nums1[6]={3,8,4,2,6,1};
    int nums1Size=6;
    int nums2[7]={4,7,8,5,2,3,6};
    int nums2Size=7;
    printf("%d",minNumber(nums1,nums1Size,nums2,nums2Size));
}
