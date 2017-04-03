/*
 * Author : Pawel Gniewek (UC Berkeley)
 * Email  : pawel.gniewek@berkeley.edu
 * License: BSD
 */

#include <math.h>      /* log, sqrt */
#include <iostream>    /* cout, cin */
#include <stdlib.h>
#include <steinhardt.h>  /* */

double calcWl(double arr[20][3], int nk, int i_param)
{
    
    double qss = 0.0;
    double *x, *y, *z;
    double *qlRe, *qlIm;
    x = (double*) malloc (nk * sizeof (double));
    y = (double*) malloc (nk * sizeof (double));
    z = (double*) malloc (nk * sizeof (double));

    for (int i = 0; i < nk ; i++)
    {
        x[i] = arr[i][0];
        y[i] = arr[i][1];
        z[i] = arr[i][2];
    }

    qlRe = (double*) malloc ((i_param + 1) * sizeof (double));
    qlIm = (double*) malloc ((i_param + 1) * sizeof (double));
    
    qlm(i_param, nk, 0.0, 0.0, 0.0, x, y, z, qlRe, qlIm);
    qss = qsum(i_param, qlRe, qlIm);

    double wlval = 0.0;

    if (qss > 1e-4)
    {
        wlval = Wl (i_param, qlRe, qlIm) / (qss * qss * qss);
    }

    free (qlRe);
    free (qlIm);
    free (x);
    free (y);
    free (z);
    return wlval;
}

double calcQl(double arr[20][3], int nk, int i_param)
{
    
    double qss = 0.0;
    double *x, *y, *z;
    double *qlRe, *qlIm;
    x = (double*) malloc (nk * sizeof (double));
    y = (double*) malloc (nk * sizeof (double));
    z = (double*) malloc (nk * sizeof (double));

    for (int i = 0; i < nk ; i++)
    {
        x[i] = arr[i][0];
        y[i] = arr[i][1];
        z[i] = arr[i][2];
    }
    
    qlRe = (double*) malloc ((i_param + 1) * sizeof (double));
    qlIm = (double*) malloc ((i_param + 1) * sizeof (double));
    
    qlm(i_param, nk, 0.0, 0.0, 0.0, x, y, z, qlRe, qlIm);
    qss = qsum(i_param, qlRe, qlIm);

    double qlval = 0.0;

    if (qss > 1e-4)
    {
        qlval = Ql(i_param, nk, qlRe, qlIm);
    }

    free (qlRe);
    free (qlIm);
    free (x);
    free (y);
    free (z);
    return qlval;
}

int main(int argc, char** argv)
{
    int idx[5] = {2,4,6,8,10};
        
    double fcc[12][3] = 
    {
        { 1,0, 1},
        { 1,0,-1},
        {-1,0, 1},
        {-1,0,-1},
        
        { 1, 1, 0},
        {-1, 1, 0},
        { 0, 1, 1},
        { 0, 1,-1},
        
        { 1,-1, 0},
        {-1,-1, 0},
        { 0,-1, 1},
        { 0,-1,-1},
    };
    
    std::cout << "FCC:";
    for (int i = 0; i < 5; i++)
    {
        std::cout << "Q(" << idx[i] << ")=" <<  calcQl(fcc, 12, idx[i]) << " ";//std::endl;
    }
        for (int i = 0; i < 5; i++)
    {
        std::cout << "W(" << idx[i] << ")=" <<  calcWl(fcc, 12, idx[i]) << " ";//std::endl;
    }
    std::cout <<  std::endl;
  
    
    double sc[8][3] = 
    {
        {1,0,0},
        {-1,0,0},
        {0,1,0},
        {0,-1,0},
        {0,0,1},
        {0,0,-1}
    };
    
    std::cout << "SC: ";
    for (int i = 0; i < 5; i++)
    {
        std::cout << "Q(" << idx[i] << ")=" <<  calcQl(sc, 6, idx[i]) << " ";//std::endl;
    }
        for (int i = 0; i < 5; i++)
    {
        std::cout << "W(" << idx[i] << ")=" <<  calcWl(sc, 6, idx[i]) << " ";//std::endl;
    }
    std::cout <<  std::endl;
    
    
    double bcc[8][3] = 
    {
        { 1, 1, 1},
        { 1, 1,-1},
        {-1,-1,-1},
        { 1,-1,-1},
        {-1, 1,-1},
        {-1,-1, 1},
        { 1,-1, 1},
        {-1, 1, 1}
    };
        
    std::cout << "BCC:";
    for (int i = 0; i < 5; i++)
    {
        std::cout << "Q(" << idx[i] << ")=" <<  calcQl(bcc, 8, idx[i]) << " ";//std::endl;
    }
        for (int i = 0; i < 5; i++)
    {
        std::cout << "W(" << idx[i] << ")=" <<  calcWl(bcc, 8, idx[i]) << " ";//std::endl;
    }
    std::cout <<  std::endl;

    
    double phi = (1.0 + sqrt(5.0)) / 2.0;
    double ico[20][3] = 
    {
        {0, 1.0, phi},
        {0, 1.0,-phi},
        {0,-1.0, phi},
        {0,-1.0,-phi},
        
        { 1.0, phi, 0.0},
        { 1.0,-phi, 0.0},
        {-1.0, phi, 0.0},
        {-1.0,-phi, 0.0},
        
        { phi, 0.0, 1.0},
        { phi, 0.0,-1.0},
        {-phi, 0.0, 1.0},
        {-phi, 0.0,-1.0}
    };
    
    std::cout << "ICO:";
    for (int i = 0; i < 5; i++)
    {
        std::cout << "Q(" << idx[i] << ")=" <<  calcQl(ico, 12, idx[i]) << " ";//std::endl;
    }
        for (int i = 0; i < 5; i++)
    {
        std::cout << "W(" << idx[i] << ")=" <<  calcWl(ico, 12, idx[i]) << " ";//std::endl;
    }
    std::cout <<  std::endl;  
    
    
    double dod[20][3] = 
    {
        { 1, 1, 1},
        { 1, 1,-1},
        { 1,-1, 1},
        {-1, 1, 1},
        { 1,-1,-1},
        {-1, 1,-1},
        {-1,-1, 1},
        {-1,-1,-1},
      
        { 1.0/phi, phi, 0.0},
        {-1.0/phi, phi, 0.0},
        { 1.0/phi,-phi, 0.0},
        {-1.0/phi,-phi, 0.0},
        
        { phi, 0.0, 1.0/phi},
        {-phi, 0.0, 1.0/phi},
        { phi, 0.0,-1.0/phi},
        {-phi, 0.0,-1.0/phi}, 
        
        { 0.0, 1.0/phi, phi},
        { 0.0,-1.0/phi, phi},
        { 0.0, 1.0/phi,-phi},
        { 0.0,-1.0/phi,-phi}
    };
    
    std::cout << "DOD:";
    for (int i = 0; i < 5; i++)
    {
        std::cout << "Q(" << idx[i] << ")=" <<  calcQl(dod, 20, idx[i]) << " ";//std::endl;
    }
        for (int i = 0; i < 5; i++)
    {
        std::cout << "W(" << idx[i] << ")=" <<  calcWl(dod, 20, idx[i]) << " ";//std::endl;
    }
    std::cout <<  std::endl;
    
    
    double dod_fcts[12][3] = 
    {
        { -1.17082039, -0.72360680,  0.00000000 },
        { 1.17082039,   0.72360680,  0.00000000 },
        { -1.17082039,  0.72360680,  0.00000000 },
        { 1.17082039,  -0.72360680,  0.00000000 },
        { 0.00000000,  -1.17082039, -0.72360680 },
        { 0.00000000,   1.17082039,  0.72360680 },
        { 0.00000000,  -1.17082039,  0.72360680 },
        { 0.00000000,   1.17082039, -0.72360680 },
        { -0.72360680,  0.00000000, -1.17082039 },
        { 0.72360680,   0.00000000,  1.17082039 },
        { 0.72360680,   0.00000000, -1.17082039 },
        { -0.72360680,  0.00000000,  1.17082039 }
    };
    
    std::cout << "FCT:";
    for (int i = 0; i < 5; i++)
    {
        std::cout << "Q(" << idx[i] << ")=" <<  calcQl(dod_fcts, 12, idx[i]) << " ";//std::endl;
    }
        for (int i = 0; i < 5; i++)
    {
        std::cout << "W(" << idx[i] << ")=" <<  calcWl(dod_fcts, 12, idx[i]) << " ";//std::endl;
    }
    std::cout <<  std::endl;   
    
    return 0;
}

