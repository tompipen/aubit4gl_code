
A4GL_FUNCTION int main (int n)
{
  int a;
  int b[10]={10,11,12,13,14,15,16,17,18,19,20};

  int d[3][3]={
	  	{10,11,12},
		{11,12,13},
		{12,13,14}
	};

  
  for (a = 0; a < 10; a++) {
      printf ("%d Hello World\n", a);
  }

  for (a = 0; a < 10; a++) {
	printf("Bibble\n");
  }


  printf("b[0]=%d\n",b[0]);

  
  for (a = 0; a < 10; a++) {
	  	int c;
		c=a+10;
	  	printf("b[%d]=%d (should be %d) \n",a,b[a],c);
 }
  
   for (a=0;a<3;a++) {
   	for (b=0;b<3;b++) {
		printf("%d + %d = %d\n",a,b,d[a][b]);
	}
   }
   

}
