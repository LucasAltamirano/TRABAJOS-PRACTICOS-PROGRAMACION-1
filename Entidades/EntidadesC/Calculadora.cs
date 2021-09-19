using System;

namespace Entidades
{
    public class Calculadora
    {
       /// <summary>
       /// Validara el operador ingresado.
       /// </summary>
       /// <param name="operador">valor del tipo char .operador a validar </param>
       /// <returns>valor del tipo char,operador</returns>
        private static char ValidarOperador(char operador)
        {
            if (operador == '+' || operador == '-' || operador == '*' || operador == '/')
            {
                return operador;
            }
            return operador;
        }
        /// <summary>
        /// validará y realizará la operación pedida entre ambos números.
        /// </summary>
        /// <param name="num1">Valor del tipo Operando(1er numero para operar)</param>
        /// <param name="num2">Valor del tipo Operando(2do numero para operar)</param>
        /// <param name="operador">Valor del tipo char(operador )</param>
        /// <returns>Valor del tipo double; resultado de dicha operacion.
        /// </returns>
        public static double Operar(Operando num1, Operando num2, char operador)
        {
            double result = 0;
            switch (ValidarOperador(operador))
            {
                case '+':
                    result= num1 + num2;
                    break;
                case '-':
                     result = num1 - num2;
                    break;
                case '*':
                    result = num1 * num2;
                    break;
                case '/':
                    result = num1 / num2;
                    break;
            }
            return result;
        }   
    }

}


