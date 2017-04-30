#include<stdio.h>
#include<stdlib.h>

int in[8][8],trans[8][8];
int it1[8],it2[6],it3[4],it4[2],groupa_i1[4],groupb_i1[4];
int *iteration1();
int *iteration2();
int *iteration3();
int *iteration4();
int *group_iteration1();
int *group_iteration2();
int *group_iteration3();
int *group_iteration4();
void printing_iteration1();
void printing_iteration2();
void printing_iteration3();
void printing_iteration4();
int max_array(int a[], int num_elements);
int groupa_i2[3],groupb_i2[3];
int groupa_i3[2],groupb_i3[2];
int groupa_i4,groupb_i4;

int main(int argc,char **argv)
{
	FILE *k_l_inputs;
	int k=2;
        int n=8;
	int x,i,j,iter,gain,max_ga,max_gb,gaini2,gaini3,gaini4,max;
	int max_gain[4];
	k_l_inputs=fopen("inputs.txt","r");
	printf("\n");
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
       		{
	    		fscanf(k_l_inputs,"%d",&x);
            		in[i][j]=x;
	    		
		}  
      }
printf("\t\tinput matrix is\n\n");
printf(" v1 v4 v5 v8 v2 v3 v6 v7\n");
  for(i=0;i<n;i++)
       {
        for(j=0;j<n;j++)
         printf("%3d",in[i][j]);
         
         printf("\n");
       }
/////////////////THE FIRST PASS
printf("\n\n\t\tTHE FIRST PASS : \n\n");

////////////////////////////////////////////////////////////
//////////     ITERATION 1//////////////////////////////////
iteration1();                // Function to find the iteration 1
group_iteration1();			// Function groups the iteration 1 results
max_ga=max_array(groupa_i1,4);  // finds the maximum of group a
max_gb=max_array(groupb_i1,4);  // finds the maximum of group b
gain=max_ga+max_gb-k*in[0][4];  // finds the gain of the iteration along with the cut size
max_gain[0]=gain;
printing_iteration1();		//PRINTING RESULTS
printf("%d\n\n",gain);  

/////////////////////////////////////////////////////////////////////
////////////////////   ITERATION 2   ////////////////////////////
iteration2();    			  //Function to find the Iteration2
group_iteration2();			// Function groups the iteration 2 results
max_ga=max_array(groupa_i2,3);	 // finds the maximum of group a
max_gb=max_array(groupb_i2,3);	 // finds the maximum of group B
gaini2=max_ga+max_gb-k*in[3][5];// finds the gain of the iteration along with the cut size
max_gain[1]=gaini2;
printing_iteration2();		//PRINTING RESULTS
printf("%d\n\n",gaini2);

//////////////////////////////////////////////////////////////////////
///////////    ITERATION 3 ///////////////////////////////////////
iteration3();				//Function to find the Iteration3
group_iteration3();			// Function groups the iteration 3 results
max_ga=max_array(groupa_i3,2); // finds the maximum of group a
max_gb=max_array(groupb_i3,2); // finds the maximum of group B
gaini3=max_ga+max_gb-k*in[2][6];// finds the gain of the iteration along with the cut size
max_gain[2]=gaini3;
printing_iteration3();			//PRINTING RESULTS
printf("%d\n\n",gaini3);

//////////////////////////////////////////////////////////////////////
///////////    ITERATION 4 ///////////////////////////////////////

iteration4();//Function to find the Iteration4
//group_iteration4();			// Function groups the iteration 4 results
gaini4=it4[0]+it4[1]-k*in[1][7];// finds the gain of the iteration along with the cut size
max_gain[3]=gaini4;
printing_iteration4();			//PRINTING RESULTS
printf("%d\n\n",gaini4);
//trans=in;

///////////////////////////////////////////////////////////////////////////
//////////////////    FINDING THE POSSIBILITY FOR NEXT PASS AND MAKING A DESCISION///////////////////
//////////////////////////////////////////////////////////////////////////////////////
printf("\t\tThe Transformed Matrix After the first Pass is : \n");
  for(i=0;i<n;i++)
       {
        for(j=0;j<n;j++)
         trans[i][j]=in[i][j];
       }
 for(i=0;i<n;i++)
       {
        for(j=0;j<n;j++)
         printf("%3d",trans[i][j]);
         
         printf("\n");
       }
max=max_array(max_gain,4);
printf("\n\n\t\tThe maximum Gain obtained is at Iteration 4 with gain :\t%d\n\n",max);
printf("\t\tThe locked elements up till i=4 are swapped and the new groups formed as follows:\n ");
printf("\n\t\tGroupa :: v2,v3,v6,v7\n");
printf("\n\t\tGroupb :: v1,v4,v5,v8\n");
printf("\n\n\t\tNO FURTHER PARTITIONING POSSIBLE\n\n\n\n\n");
}
int *iteration1()
{  
	int i;
	int n=8;
	for(i=0;i<n;i++)
   {
	if(i<4)
	{
           it1[i]=in[i][4]+in[i][5]+in[i][6]+in[i][7]-in[i][3]-in[i][2]-in[i][1]-in[i][0];
	}
	if(i>=4)
	{
	   it1[i]=in[i][0]+in[i][1]+in[i][2]+in[i][3]-in[i][4]-in[i][5]-in[i][6]-in[i][7];
	}
   }
	return it1;
}
int *group_iteration1()
{
	int i;
	for(i=0;i<4;i++)
	{
		groupa_i1[i]=it1[i];
	}
	for(i=0;i<4;i++)
	{
		groupb_i1[i]=it1[i+4];
	}
	return groupa_i1;
	return groupb_i1;
}
int max_array(int a[], int num_elements)
{
   int i, max=-32000;
   for (i=0; i<num_elements; i++)
   {
	 if (a[i]>max)
	 {
	    max=a[i];
	 }
   }
   return(max);
}
void printing_iteration1()
{
	int i;
	printf("\tv1\tv4\tv5\tv8\tv2\tv3\tv6\tv7\tgain\n\n");
printf("i=1\t"); 
for(i=0;i<8;i++)
{
printf("%d\t",it1[i]);
}
}
int *iteration2()
{   int i;
	for(i=0;i<6;i++)
	{
		if(i<3)
		{
		it2[i]=in[i+1][0]+in[i+1][5]+in[i+1][6]+in[i+1][7]-in[i+1][3]-in[i+1][2]-in[i+1][1]-in[i+1][4];	
		}
		if(i>=3)
		{
		 it2[i]=in[i+2][1]+in[i+2][2]+in[i+2][3]+in[i+2][4]-in[i+2][5]-in[i+2][6]-in[i+2][7]-in[i+2][0];	
		}
}
	   
return it2;
}
int *group_iteration2()
{
	int i;
	for(i=0;i<3;i++)
{
	groupa_i2[i]=it2[i];
	groupb_i2[i]=it2[i+3];
}
}
void printing_iteration2()
{
	int i;
printf("i=2\t\t");
	for(i=0;i<3;i++)
	{
		printf("%d\t",it2[i]);
	}
	printf(" \t");
	for(i=0;i<3;i++)
	{
		printf("%d\t",it2[i+3]);
	}

}
int *iteration3()
{ int i;
		for(i=0;i<4;i++)
		{
			if(i<2)
			{
				it3[i]=in[i+1][0]+in[i+1][6]+in[i+1][7]+in[i+1][3]-in[i+1][5]-in[i+1][2]-in[i+1][1]-in[i+1][4];
	
			}
			if(i>=2)
			{
				it3[i]=in[i+4][0]+in[i+4][6]+in[i+4][7]+in[i+4][3]-in[i+4][5]-in[i+4][2]-in[i+4][1]-in[i+4][4];
			}
			
		}
}
int *group_iteration3()
{ 
	int i;
	for(i=0;i<2;i++)
	{
		groupa_i3[i]=it2[i];
		groupb_i3[i]=it2[i+2];
	}
	
}
void printing_iteration3()
{ 
int i;
	printf("i=3\t\t");
for(i=0;i<2;i++)
{
printf("%d\t",it3[i]);
}
printf("\t\t\t");
for(i=0;i<2;i++)
{
printf("%d\t",it3[i+2]);
}
}
int *iteration4()
{
	
			it4[0]=in[1][0]+in[1][2]+in[1][7]+in[1][3]-in[1][5]-in[1][6]-in[1][1]-in[1][4];
			it4[1]=in[7][5]+in[7][6]+in[7][1]+in[7][4]-in[7][0]-in[7][2]-in[7][7]-in[7][3];
		
	
}
int *group_iteration4()
{
	groupa_i4=it4[0];
	groupb_i4=it4[1];
}
void printing_iteration4()
{
printf("i=4\t\t");
printf("%d\t",it4[0]);
printf("\t\t\t\t\t");
printf("%d\t",it4[1]);
}