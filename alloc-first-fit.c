#include<stdio.h>
//mendefinisikan nilai variabel array maksimum sejumlah 20
#define max 20
void main()
{
 //set setiap variabel yang dibutuhkan
    int frag[max],ukuranBlok[max],ukuranProses[max],i,j,
    jmlBlok,jmlProses,temp;
    static int alokasiBlok[max],flags[max];
    //input dari pengguna
    printf("\nTeknik Alokasi Memori - First Fit");
    printf("\nMasukkan jumlah blok memori:");
    scanf("%d",&jmlBlok);
    printf("Masukkan jumlah proses:");
    scanf("%d",&jmlProses);
    printf("\nMasukkan ukuran blok memori:-\n");
    for(i=1;i<=jmlBlok;i++)
    {
        printf("Blok %d:",i);
        scanf("%d",&ukuranBlok[i]);
    }
    printf("Masukkan ukuran proses :-\n");
    for(i=1;i<=jmlProses;i++)
    {
        printf("Proses %d:",i);
        scanf("%d",&ukuranProses[i]);
    }
    //mengambil setiap proses satu persatu
    for(i=1;i<=jmlProses;i++)
    {
        for(j=1;j<=jmlBlok;j++)
        {
            //melakukan proses alokasi dengan mengurangi ukuran blok dengan ukuran proses
            if(alokasiBlok[j]!=1)
            {
                temp=ukuranBlok[j]-ukuranProses[i];
                if(temp>=0)
                {
                    flags[i]=j;
                    break;
                }
            }
        }
        //alokasi first-fit berdasarkan informasi alokasi blok memori
        frag[i]=temp;
        alokasiBlok[flags[i]]=1;
    }
    //tampilan output
    printf("\nNo. Proses:\tUkuran Proses :\tAlokasi Blok:\tUkuran Blok:\tFragment");
    for(i=1;i<=jmlProses;i++){
        printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d",i,ukuranProses[i],flags[i],ukuranBlok[flags[i]],frag[i]);
    }
}