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
            Matfile matFile = Matfile.Open("Test.mat", MatfileMode.WriteHDF5);

            CellArray cellArray = new CellArray(3, 3);

            cellArray.Add(true, 1, 1);

            //matFile.Add("Test", cellArray);

            matFile.Add("test", 53253453.45345);

            matFile.Close();
            matFile.Dispose();

            string F = "";
        }
    }
}