using System;

namespace other
{
    class Program
    {
        static void Main(string[] args)
        {
            string laura = "laura";
            Console.WriteLine("Hello World!");
            Operando constructor = new Operando();

            double valor=constructor.GetNumero();
          
            Console.WriteLine("el valor de imput es {0}", valor);

            Console.WriteLine(laura.Length);
            Console.Read();
        }
    }
}
