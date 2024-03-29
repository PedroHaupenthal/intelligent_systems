#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

int main()
{
    float E1;
    float E2;
    float E3;
    float E4;

    float w1[5][5];
    float w2[5][5];
    float I[5][5];
    float O[5][5];
    int i = 0, j, l;

    //------------------READ W's-----------------------------
    w1[0][0] = -2.515492;
    w1[1][0] = -9.276765;
    w1[2][0] = 40.226723;
    w1[3][0] = -0.862213;
    w1[4][0] = -4.569996;
    w1[0][1] = 16.134884;
    w1[1][1] = 15.894007;
    w1[2][1] = 6.712958;
    w1[3][1] = 2.934447;
    w1[4][1] = -16.679596;
    w1[0][2] = -1.821116;
    w1[1][2] = 10.510577;
    w1[2][2] = 16.242886;
    w1[3][2] = 0.061660;
    w1[4][2] = -7.887495;
    w2[0][0] = 25.171635;
    w2[1][0] = -25.274929;
    w2[2][0] = 6.058901;
    w2[3][0] = -12.152349;
    w2[0][1] = -16.542976;
    w2[1][1] = 20.872499;
    w2[2][1] = -19.808025;
    w2[3][1] = -5.257579;
    //-----------------------------------------------------

    //-----propagation-------------------------------------
    printf("\n BOV =");
    scanf("%f", &E1);
    printf("\n nasdaq=");
    scanf("%f", &E2);
    printf("\n FTSE=");
    scanf("%f", &E3);
    printf("\n JPY =");
    scanf("%f", &E4);

    E1 = (E1 - 96429.6) / 7941.31;
    E2 = (E2 - 94.36) / 9.9;
    E3 = (E3 - 7067) / 619.6;
    E4 = (E4 - 20261.04) / 1783.41;

    I[0][0] = E1;
    I[0][1] = E2;
    I[0][2] = E3;
    I[0][3] = E4;
    I[0][4] = 1.0;

    O[0][0] = I[0][0];
    O[0][1] = I[0][1];
    O[0][2] = I[0][2];
    O[0][3] = I[0][3];
    O[0][4] = I[0][4];

    for (j = 0; j < 3; j++)
    {
        I[1][j] = 0.0;
        for (i = 0; i < 5; i++)
        {
            I[1][j] += w1[i][j] * O[0][i];
        }
        O[1][j] = 1.0 / (1.0 + exp(-I[1][j]));
    }

    I[1][3] = 1.0;
    O[1][3] = I[1][3];

    for (l = 0; l < 2; l++)
    {
        I[2][l] = 0.0;
        for (j = 0; j < 4; j++)
        {
            I[2][l] += w2[j][l] * O[1][j];
        }
        O[2][l] = 1.0 / (1.0 + exp(-I[2][l]));
        printf(" ===> %f", O[2][l]);
    }
    //-----backpropagation----------------------
}
