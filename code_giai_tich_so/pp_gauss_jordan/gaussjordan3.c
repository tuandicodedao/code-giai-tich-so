#include <conio.h>

#include <stdio.h>

#include <math.h>

#include <stdlib.h>

#include <ctype.h>

 

void main()

  {

          float a[100][100];

          float b[100];

          int i,j,k,n,m,t;

          float max,c;
          char t1;

          printf("Cho so phuong trinh n = ");

          scanf("%d",&n);

          printf("Cho cac phan tu cua ma tran a :\n");

          for (i=1;i<=n;i++)

            for (j=1;j<=n;j++)

                   {

                     printf("a[%d][%d] = ",i,j);

                     scanf("%f",&a[i][j]);

                   }

          printf("\n");

          printf("Ma tran a ma ban da nhap");

          printf("\n");

          for (i=1;i<=n;i++)

            {

                   for (j=1;j<=n;j++)

                     printf("%15.5f",a[i][j]);

                   printf("\n");

            }
          printf("\n");

          printf("Cho cac phan tu cua ma tran b : \n");

          for (i=1;i<=n;i++)

            {

                   printf("b[%d] = ",i);

                   scanf("%f",&b[i]);

            }

          printf("\n");

          printf("Ma tran b ma ban da nhap\n");

          printf("\n");

          for (i=1;i<=n;i++)

            printf("b[%d] = %15.5f\n",i,b[i]);

          printf("\n");

          while (t)

            {

                   if (a[i][i]==0)

                     {

                             max=0;

                             m=i;

                             for (k=i+1;k<=n;k++)

                               if (max<fabs(a[k][i]))

                                      {

                                        m=k;

                                        max=fabs(a[i][i]);

                                      }

                               if (m!=i)

                                      {

                                        for (j=i;j<=n;j++)

                                                {

                                                  c=a[i][j];

                                                  a[i][j]=a[m][j];

                                                  a[m][j]=c;

                                                }

                                        c=b[i];

                                        b[i]=b[m];

                                        b[m]=c;

                                      }

                               if (m==i)

                                      {

                                        t=0;

                                        printf("MA TRAN SUY BIEN");

                                      }

                     }

                   if (a[i][i]!=0)

                     {

                             c=1/a[i][i];

                             for (j=i;j<=n;j++)

                               a[i][j]=a[i][j]*c;

                             b[i]=b[i]*c;

                             for (k=1;k<=n;k++)

                               if (k!=i)

                                      {

                                        c=a[k][i];

                                        for (j=i;j<=n;j++)

                                                a[k][j]=a[k][j]-a[i][j]*c;

                                        b[k]=b[k]-b[i]*c;

                                      }

                      }

                   i=i+1;

                   if (i==(n+1))

                     t=0;

            }

          if (i==(n+1))

            {

                   printf("NGHIEM CUA HE");

                   printf("\n");

                   for (i=1;i<=n;i++)

                     printf("x[%d] = %15.5f\n",i,b[i]);

            }


  }
