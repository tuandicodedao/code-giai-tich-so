# include <stdio.h>
# include <math.h>

/**
 * Nhap ma tran
 */
void Nhap(double M[100][100], int *m, int *n);

/**
 * In ma tran
 */
void InMt(double M[100][100], int m, int n);

/**
 * Dua ma tran ve dang bac thang rut gon
 */
void RutGon(double M[100][100], int m, int n);

/**
 * Bien luan nghiem
 */
void BienLuan(double M[100][100], int m, int n);

/**
 * Chuong trinh chinh
 */
int main()
{
    double M[100][100];
    int m, n;
    printf("\n\tCHAO MUNG TAT CA CAC BAN DEN VOI CHUONG TRINH RUT GON MA TRAN");

     Nhap(M, &m, &n);

    // In ma tran ra de kiem tra mang nhap vao
    InMt(M, m, n);


    // Dua ma tran ve dang bac thang rut gon
    RutGon(M, m, n);

    // In ra thoi
    printf("\nMa tran bac thang rut gon la:\n\n");
    InMt(M, m, n);
    
    // Rut ra nghiem tu ma tran bac thang rut gon vua thu duoc sau khi xu li
    BienLuan(M, m, n);
    
    
    // Doi nguoi dung nhan phim bat ky roi thoat
    char ch;
    scanf("%c", &ch);
}


/**
 * Nhap ma tran bo sung M:
 * VD: m = 3, n = 4
 *   a1 x  + b1 y + c1 z = d1
 *   a2 x  + b2 y + c2 z = d2 Hay ben Dai so tuyen tinh Ky hieu la: AX = B
 *   a3 x  + b3 y + c3 z = d3
 *
 * Trong do:
 *           a1  b1  c1  d1                   a1  b1  c1                d1                       x
 * M =  a2  b2  c2  d2  O day A = a1  b1  c1  con B =  d2   Nghiem X = y
 *           a3  b3  c3  d3                   a1  b1  c1                d3                       z
 *
 */
void Nhap(double M[100][100], int *m, int *n)
{
    int i, j;
    double temp;

    printf("\n   Ban hay nhap vao kich thuoc ma tran mo rong cua he phuong trinh tuyen tinh !\n");

    printf("\n\tNhap so dong m = ");
    scanf("%d", m);
    fflush(stdin);

    printf("\tNhap so cot n  = ");
    scanf("%d", n);
    fflush(stdin);

    printf("\n\t* Nhan Tab de nhap tiep so khac:\n");
    printf("\t* Nhan Enter de nhap cac phan tu dong tiep theo:\n");
    printf("\n Bay gio ban hay nhap vao cac phan tu cua ma tran\n");
    for (i = 0; i < *m; i++)
    {
        printf("\n\t");
        for(j = 0; j < *n; j++)
        {
            scanf("%lf", &temp);
            M[i][j] = temp;
            printf("\t");
        }
    }

    printf("\nBan vua nhap xong ma tran.\n\n");
}


/**
 * In ma tran
 */
void InMt(double M[100][100], int m, int n)
{
    int i, j;
    for (i = 0; i < m; i++) 
    {
        for (j = 0; j < n; j++)
        {
                printf("%lf\t", M[i][j]);
        }
        printf("\n\n");
    }
}


/**
 * Dua ma tran ve dang bac thang rut gon
 *
 * Nghia la:
 *   Dua phan tu tren duong cheo chinh thanh so 1
 *   Va dua phan tu khong nam tren duong cheo chinh thanh so 0
 *   Bang cach nhan dong hien tai voi mot so ten HeSoNhan voi dong phu hop.
 */
void RutGon(double M[100][100], int m, int n)
{
    double HeSoNhan, tg;
    int i, j, k,l ,kt, dong;

    /**
     * Chuyen doi ma tran M ve dang bac thang rut gon
     * Dua tung cot ve dang cot cua ma tran don vi I tuong ung
     */
    for (i = 0; i < n-1; i++)
    {
        /*
         * Bien doi theo cot
         *
         * Chao doi dong de dua ma tran ve dang co the bien ve so 1
         * Moi cot chi can chao doi mot lan
         */
        if (M[i][i] == 0)
        {
            // Tim dong co cot i khac 0 de chao doi
            for (k = i+1; k < m; k++)
            {
                if (M[k][i] != 0)
                {
                    // Chao doi dong k chua phan tu != 0 do voi dong i dang xet
                    for (l = 0; l < n; l++)
                    {
                        tg = M[i][l];
                        M[i][l] = M[k][l];
                        M[k][l] = tg;
                    }

                    break;// dung vong for lai khi da chao doi xong
                }
            }
        }// Hoan tat chao doi

        /*
         * Tien hanh bien doi M[j][i] thanh so 1 va so 0
         * Chuyen doi lan luot tung dong theo dung loai
         */
        for (j = 0; j < m; j++)
        {
            /*
             * Xac dinh loai can chuyen ve so 0 hay so 1
             * loai = 2 la truong hop phan tu M[j][i] da o dung vi tri
             * khong can bien doi gi ca.
             */
            int loai = 2;

            // Neu M[j][i] khong nam tren duong cheo chinh va ban than no khac 0
            if ( (j != i) && (M[j][i] != 0) )
            {
                // M[j][i] can chuyen ve zero
                loai = 0;
            }

            // Neu M[j][i] nam tren duong cheo chinh va ban than no khac 1
            if ( (j == i) && (M[j][i] != 1) )
            {
                // M[j][i] can chuyen ve 1 chuan
                loai = 1;
            }

            switch (loai)
            {
                // Truong hop can chuyen M[j][i] ve so 0
                case 0:
                    //Xac dinh he so nhan(HeSoNhan) va dong nhan vao thich hop
                    for (k = 0; k < m; k++) 
                    {
                        if (k != j)
                        {
                            HeSoNhan = 0;
                            kt = 0;
                            for (l = 0; l < i; l++) if (M[k][l] != 0) kt=1;
                            if ((kt == 0) && (M[k][i] != 0))
                            {
                                dong = k;
                                HeSoNhan = (-1) * M[j][i] / M[dong][i];
                                break;
                            }
                        }
                    }
                    //Neu co HeSoNhan thi se chuyen doi neu khong thi giu nguyen
                    if (HeSoNhan != 0)
                    {
                        for (k = 0; k < n; k++)
                        {
                            M[j][k] = M[j][k] + HeSoNhan * M[dong][k];
                        }
                    }

                    break;

                // Truong hop can chuyen M[j][i] ve so 0
                case 1:
                    kt = 0;
                    for (l = 0; l < i; l++)
                    {
                        if (M[j][l] != 0)
                        {
                            kt = 1;
                        }
                    }

                    HeSoNhan = M[j][i];
                    if ( (HeSoNhan != 0) && (kt == 0))
                    {
                        for (l = 0; l < n; l++)
                        {
                            M[j][l] = M[j][l] / HeSoNhan;
                        }
                    }
                    
                    break;
            }
        }
    }
}

/**
 * Bien luan nghiem tu ma tran bac thang rut gon
 *
 * so phuong trinh bang so dong m
 * so an bang so cot n tru 1
 */
void BienLuan(double M[100][100], int m, int n)
{

    printf("\nBien luan nghiem tu ma tran bac thang rut gon thu duoc:");
    int i,j;

    // Tim hang cua ma tran he so A
    int rA = 0;
    int tangHangA;
    for (i = 0; i < m; i++)
    {
        // Mac dinh la khong tang hang
        tangHangA = 0;
        for (j = 0; j < n - 1; j++)
        {
            // Chi can mot phan tu trong hang khac 0 la tang hang ngay
            if (M[i][j] != 0)
            {
                tangHangA = 1;
                break;
            }                
        }

        rA += tangHangA;
    }
    printf("\n - Hang cua ma tran he so A la rA = %d", rA);

    // Tim hang cua ma tran bo sung M
    int rM = 0;
    int tangHangM;
    for (i = 0; i < m; i++)
    {
        // Mac dinh la khong tang hang
        tangHangM = 0;
        for (j = 0; j < n; j++)
        {
            // Chi can mot phan tu trong hang khac 0 la tang hang ngay
            if ( (int)M[i][j] != 0)
            {
                tangHangM = 1;
                break;
            }                
        }
        
        rM += tangHangM;
    }
    printf("\n - Hang cua ma tran bo sung M la rM = %d", rM);

    printf("\n - So an (n-1) la: %d", n-1);

    // TH1 HPTTT co nghiem duy nhat Khi rA == rM == n-1(so an):
    if (rA == rM && rA == n - 1)
    {
        printf("\n-> He phuong trinh co nghiem duy nhat la:");
        for (i = 0; i < n - 1; i++)
        {
            printf("\n X%d = %lf", i + 1, M[i][n - 1]);
        }

        printf("\n");
    }

    // TH2 HPTTT co vo so nghiem Khi rA == rM < 3(so an):
    if (rA == rM && rA < n - 1)
    {
        printf("\n-> He phuong trinh co vo so nghiem.\n");
    }

    // TH2 HPTTT vo nghiem Khi rA < rM:
    if (rA < rM)
    {
        printf("\n-> He phuong trinh vo nghiem.\n");
    }

} 
