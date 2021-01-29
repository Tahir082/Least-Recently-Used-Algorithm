#include<iostream>
#include<math.h>
#include<conio.h>
#include<stdlib.h>
#define n 2000

using namespace std;

int main()
{
    int s, i, input_s, input_i, ram_block[n], timecount=1, a, b, j, k, p, q, steps=1;
    cout<<"\n\n\n\t\t\t ****REPLACEMENT ALGORITHM (LRU)**** \t\t\t\n\n\n";
    cout<<" ---------------------------------------------------------------------------------\n\n";
    cout<<" How many Sets?: ";
    cin>>s;
    cout<<"\n\n";
    cout<<" How many way Set Associative (How many indexes in a set?:";
    cin>>i;
    cout<<"\n\n\n";
    int cache[s][i];
    int time[s][i];
    for(a=0; a<s ; a++)
    {
        for(b=0; b<i; b++)
        {
            cache[a][b]=-1;
            time[a][b]=0;
        }
    }
    cout<<" <NOTE> Empty Cells are denoted with (-1).Consider the following figure as initial state. <NOTE>\n";

    for(a=0; a<s ; a++)
    {
        cout<<"\n\n";
        for(b=0; b<i; b++)
        {
            cout<<cache[a][b]<<"  ";
        }
    }


        cout<<"\n\n Enter Some Ram blocks (positive integer) ";
        cout<<"\n\n -> You must put -1 at the end input: \n ";
        for(a=0; a<n; a++)
        {
            cin>>ram_block[a];
            if(ram_block[a]==-1)
                {
                    break;
                }
        }

        for(a=0; a<n; a++)
        {
            if(ram_block[a]==-1)
            {
                break;
            }
            input_s= ram_block[a]%s;


                for(k=0; k<i; k++)
                {
                    if(cache[input_s][k]==-1)
                    {
                        input_i=k;
                        cout<<"\n MISS ";
                        cache[input_s][input_i]=ram_block[a];
                        time[input_s][input_i]=timecount;
                        goto a;

                    }
                }

                for(k=0; k<i; k++)
                {
                    if(cache[input_s][k]!=-1)
                    {

                        if(cache[input_s][k]== ram_block[a])
                        {
                        cout<<"\n HIT";
                        time[input_s][k]=timecount;
                        goto a;
                        }
                        else
                        {
                            int maximum= time[input_s][0];
                            if(time[input_s][k]>maximum)
                            {   input_i=k;}
                        }


                    }
                }
            cout<<"\n MISS";
            cache[input_s][input_i]= ram_block[a];
            time[input_s][input_i]= timecount;
            timecount++;
            a:
            cout<<"\n Cache State "<<steps<<" :\n";
            for(p=0; p<s ; p++)
                {
                    cout<<"\n\n";
                    for(q=0; q<i; q++)
                        {
                            cout<<cache[p][q]<<"  ";
                        }
                }
            steps++;



        }

    return 0;

}
