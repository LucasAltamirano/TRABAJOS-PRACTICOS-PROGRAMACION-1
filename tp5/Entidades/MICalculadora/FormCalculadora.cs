using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Entidades;

namespace MICalculadora
{
    public partial class FormCalculadora : Form
    {

        
        public FormCalculadora()
        {
            InitializeComponent();
        }
        
        private void FormCalculadora_Load(object sender, EventArgs e)
        {
            Limpiar();
        }

        /// <summary>
        /// Boton operar: realizara la operacion indicada por el usuario.
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void btnOperar_Click(object sender, EventArgs e)
        {
            if(!(String.IsNullOrEmpty(cmbOperador.Text)))
            {
                double resultado = Operar(txtNumero1.Text, txtNumero2.Text, cmbOperador.Text);

                lblResultado.Text = resultado.ToString();

                string operaciones = $"{txtNumero1.Text} {cmbOperador.Text} {txtNumero2.Text} = {lblResultado.Text}";
                
                lstOperaciones.Items.Insert(0, operaciones);
                

            }
            else
            {
                string tleVentana = "Error";
                string msgEmergente = " Ingrese un operador valido + - * / ";
                MessageBox.Show(msgEmergente, tleVentana, MessageBoxButtons.OK, MessageBoxIcon.Error);
            }

        }
        /// <summary>
        /// Boton Limpiar: presionando 1 vez limpiara los campos text1,text2,operador.
        /// presionando 2 veces limpiara incluso la lista de operaciones.
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void btnLimpiar_Click(object sender, EventArgs e)
        {
            Limpiar();
        }
        /// <summary>
        /// Boton cerrar:finalizará la ejecucion del programa,previo a una confirmacion por parte del usuario.
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void btnCerrar_Click(object sender, EventArgs e)
        {

            string tleVentana = "Salir";
            string msgEmergente = "¿Está seguro de querer salir ? ";
            DialogResult close = MessageBox.Show(msgEmergente, tleVentana, MessageBoxButtons.YesNo, MessageBoxIcon.Question);

            if (close == DialogResult.Yes)
            {
                
                this.Close();
            }        
        }
        /// <summary>
        /// Boton convertir a binario: invocara al metodo necesario para la conversion.
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void btnConvertirABinario_Click(object sender, EventArgs e)
        {   
            
            string strBinario =Operando.DecimalBinario( lblResultado.Text);
            lblResultado.Text = strBinario;

            lstOperaciones.Items.Insert(0, strBinario);
        }
        /// <summary>
        /// Boton convertir a decimal: invocara al metodo necesario para la conversion.
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void btnConvertirADecimal_Click(object sender, EventArgs e)
        {
            string strBinarioDecimal = Operando.BinarioDecimal(lblResultado.Text);
            lblResultado.Text = strBinarioDecimal;

            lstOperaciones.Items.Insert(0, strBinarioDecimal);
        }
        /// <summary>
        /// Metodo que limpia los valores de los campos de dicho formulario.
        /// </summary>
        private void Limpiar()
        {
            if (String.IsNullOrEmpty(txtNumero1.Text) && String.IsNullOrEmpty(txtNumero2.Text) && String.IsNullOrEmpty(lblResultado.Text))
            {
                lstOperaciones.Items.Clear();
            }

            txtNumero1.Text = "";
            txtNumero2.Text = "";
            cmbOperador.ResetText();
            lblResultado.Text = "";
            
        }
        /// <summary>
        /// Ejecutara la operacion matematica correspondiente
        /// </summary>
        /// <param name="num1">Valor del tipo string(1er numero para operar)</param>
        /// <param name="num2">Valor del tipo string(2do numero para operar)</param>
        /// <param name="operador">Valor del tipo string(operador matematico)</param>
        /// <returns>valor del tipo double :Resultado de dicha operacion matematica </returns>
        private static double Operar(string num1, string num2, string operador) 
        {
            Operando numero1 = new Operando(num1);
            Operando numero2 = new Operando(num2);
       
            double result =Calculadora.Operar(numero1, numero2, Convert.ToChar(operador));
             
            return result;
            
        }    
    }
}
