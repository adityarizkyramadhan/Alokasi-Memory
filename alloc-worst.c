#include<stdio.h>
//mendefinisikan nilai variabel array maksimum sejumlah 20
#define max 20
void main()
{
    //set setiap variabel yang dibutuhkan
    int frag[max],ukuranBlok[max],ukuranProses[max],i,j,
    jmlBlok,jmlProses,temp,highest=0;
    static int alokasiBlok[max],flags[max];
    //input dari pengguna
    printf("\nTeknik Alokasi Memori - Worst Fit");
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
    for(i=1;i<=jmlProses;i++)
    {
        for(j=1;j<=jmlBlok;j++)
        {
        //melakukan proses alokasi dengan mengurangi ukuran blok dengan ukuran proses
            if(alokasiBlok[j]!=1)
            {
                temp=ukuranBlok[j]-ukuranProses[i];
                if(temp>=0)
                    if(highest<temp)
                    {
                    flags[i]=j;
                    highest=temp;
                    }
            }
        }
        //alokasi worst-fit berdasarkan nilai fragment terbesar
        frag[i]=highest;
        alokasiBlok[flags[i]]=1;
        highest=0;
    }
    //tampilan output
    printf("\nNo. Proses:\tUkuran Proses :\tAlokasi Blok:\tUkuran Blok:\tFragment");
    for(i=1;i<=jmlProses;i++)
    {
        printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d",i,ukuranProses[i],flags[i],ukuranBlok[flags[i]],frag[i]);
    }
}
