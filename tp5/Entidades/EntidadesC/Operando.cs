using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades
{
    public class Operando
    {
        //Miembro :atributos
        /// <summary>
        /// Variable private del tipo Double .Clase Operando
        /// </summary>
        private double numero;

        //Miembro :constructores y sus sobrecargas;

        /// <summary>
        /// Contructor por defecto ,sin parametrizar. asigna valor 0 al atributo numero de la clase operando
        /// </summary>
        /// 
        public Operando()
        {
            this.numero = 0;
        }
        /// <summary>
        /// Constructor con sobrecarga ,asigna el valor recibido por parametro previa validacion del mismo.
        /// </summary>
        /// <param name="strNumero">
        /// parametro del tipo string (+sobrecarga) utilizado a posteriori por la propiedad Numero.
        /// </param>
        public Operando(string strNumero)
        {
           Numero = strNumero;
        }
        /// <summary>
        /// Constructor con sobrecarga ,asigna el valor recibido por parametro previa validacion del mismo.
        /// quien a su vez invoca al constructor Operando.(string). Reutilizacion de codigo.
        /// </summary>
        /// <param name="numero">
        /// parametro del tipo Double (+sobrecarga)
        /// </param>
        public Operando(double numero):this(numero.ToString()) 
        {
   
        }

        //Miembro: Metodo /funcion de la clase

        /// <summary>
        /// Comprobará que el valor recibido sea numérico, y lo retornará en formato double. Caso contrario, retornará 0.
        /// </summary>
        /// <param name="strNumero"> de tipo string </param>
        /// <returns>
        /// Retorna un valor del tipo double si es numero ,caso contrario ,retorna cero.
        /// </returns>
        /// 
        private double ValidarOperando(string strNumero)
        {
            if (double.TryParse(strNumero, out double result))
            {
                return result;
            }
            else
            {
                return 0;
            }

        }

        //Miembro: propiedades

        /// <summary>
        /// asignará un valor al atributo número, previa validación.
        /// </summary>
        private string Numero 
        {
            set { this.numero = ValidarOperando(value); }
        }

        //Miembro: Metodos/funciones relacionadas pasaje decimal a binario y viceversa

        /// <summary>
        /// validará que la cadena de caracteres esté compuesto SOLAMENTE por caracteres '0' o '1'
        /// </summary>
        /// <param name="binario">valor de tipo string a validar</param>
        /// <returns>
        /// retornara un valor bool;true si es binario ,caso contrario false.
        /// </returns>
        private static bool EsBinario(string binario)
        {
            int largo = binario.Length;
 
            for (int i = 0; i < largo-1; i++)
            {
                if (!(binario[i] == '0' || binario[i] == '1')) 
                {
                    return false;
                }
            }
            return true;
        }
        /// <summary>
        /// Convertirá ese número binario a decimal, 
        /// </summary>
        /// <param name="binario">valor de tipo string a convertir </param>
        /// <returns>
        ///Retorna un valor del tipo string si pudo realizar la conversion,en caso contrario retornará "Valor inválido".
        /// </returns>
        public static string BinarioDecimal(string binario)
        {
            string decimalConvertido;
            bool convert = EsBinario(binario);
            if (convert )
            {
                int aDecimal = 0;
                char[] arrayBin = binario.ToCharArray();
                Array.Reverse(arrayBin);

                for (int i = 0; i <arrayBin.Length; i++)
                {
                    if (arrayBin[i] == '1')
                    {
                        aDecimal = aDecimal + (int)Math.Pow(2, i);
                    }
                }
                  decimalConvertido= aDecimal.ToString();
                return decimalConvertido;
            }
            else
            {
                return "Valor inválido";
            }
        }
        /// <summary>
        /// Convertirá ese número decimal a binario, 
        /// </summary>
        /// <param name="numero">valor del tipo double a convertir</param>
        /// <returns>
        /// Retorna un valor del tipo string si pudo realizar la conversion,en caso contrario retornará "Valor inválido".
        /// </returns>
        public static string DecimalBinario(double  numero)
        {
            int numeroInt = (int)numero;
            string resto = "";
            string binario = "";

            if (!(numeroInt > 0))
            {
                return "Valor inválido";
            }
            while ((numeroInt >= 2))
            {
                resto = resto + (numeroInt % 2).ToString();

               numeroInt = numeroInt / 2;
            }
            resto = resto + numeroInt.ToString();

            for (int i = resto.Length; i >= 1; i += -1)

            {
                binario = binario + resto.Substring(i - 1, 1);
            }
            return binario;
        }
        /// <summary>
        /// Convertirá ese número decimal a binario, 
        /// </summary>
        /// <param name="numero">valor del tipo double a convertir </param>
        /// <returns>
        /// Retorna un valor del tipo string si pudo realizar la conversion,en caso contrario retornará "Valor inválido".
        /// </returns>
        public static string DecimalBinario(string numero)
        {

            if (int.TryParse(numero, out int numeroInt))
            {
               return DecimalBinario(numeroInt);
            }
            else
            {
                return "Valor inválido";
            }
           
        }

        //Miembro:Operadores

        /// <summary>
        /// Realiza una suma entre dos numeros
        /// </summary>
        /// <param name="n1">valor del tipo Operando , (1er numero para operar)</param>
        /// <param name="n2">valor del tipo Operando , (2do numero para operar)</param>
        /// <returns>retorna un valor Double,resultado de la operacion </returns>
        public static double operator +(Operando n1,Operando n2)
        {
            return n1.numero + n2.numero;
        }
        /// <summary>
        /// Realiza una resta entre dos numeros
        /// </summary>
        /// <param name="n1">valor del tipo Operando , (1er numero para operar)</param>
        /// <param name="n2">valor del tipo Operando , (2do numero para operar)</param>
        /// <returns>retorna un valor Double,resultado de la operacion </returns>
        public static double operator -(Operando n1, Operando n2)
        {

            return n1.numero - n2.numero;
        }
        /// <summary>
        /// Realiza una multiplicacion entre dos numeros
        /// </summary>
        /// <param name="n1">valor del tipo Operando , (1er numero para operar)</param>
        /// <param name="n2">valor del tipo Operando , (2do numero para operar)</param>
        /// <returns>retorna un valor Double,resultado de la operacion </returns>
        public static double operator *(Operando n1, Operando n2)
        {

            return n1.numero * n2.numero;
        }
        /// <summary>
        /// Realiza una division entre dos numeros
        /// </summary>
        /// <param name="n1">valor del tipo Operando , (1er numero para operar)</param>
        /// <param name="n2">valor del tipo Operando , (2do numero para operar)</param>
        /// <returns>retorna un valor Double,resultado de la operacion </returns>
        public static double operator /(Operando n1, Operando n2)
        {
            if (n2.numero == 0)
            {
                return double.MinValue;
            }
            return n1.numero / n2.numero;
        }
    }
}
