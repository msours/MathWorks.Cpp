using System;
using System.Collections.Generic;
using System.Linq;
using MathWorks.NET;

namespace MathWorks.Tests
{
    class Program
    {
        static void Main(string[] args)
        {
            Matfile matFile = Matfile.Open("Test.mat", MatfileMode.OverwriteHDF5);

            double[,] F = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };

            double[,,] F0 = new double[3, 4, 3];
            int t = 0;
            for (int p = 0; p < 3; p++)
            {
                for (int k = 0; k < 3; k++)
                {
                    for (int j = 0; j < 4; j++)
                    {
                        F0[k, j, p] = t++;
                    }
                }
            }
            
            matFile.Add("F", F);
            matFile.Add("F0", F0);

            matFile.Close();
            matFile.Dispose();

            string F_ = "";
        }
    }
}