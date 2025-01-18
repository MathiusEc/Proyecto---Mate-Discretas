
/*Modificar el Color del texto dentro de la termina*/


#define BLACK   "\x1B[30m"                          // El código define macros en C para aplicar colores y estilos al texto en la consola usando códigos de escape ANSI. 
#define RED     "\x1b[31m"                          // Cada macro representa un color (como RED para rojo o GREEN para verde)
#define GREEN   "\x1b[32m"                          // o combinaciones personalizadas usando valores RGB (como ORANGE o ROSE).
#define YELLOW  "\x1b[33m"                          // También incluye el macro RESET para restablecer los colores al valor predeterminado de la consola.
#define BLUE    "\x1b[34m"                          // Estas macros facilitan imprimir texto de colores de forma sencilla en programas.
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define WHITE   "\x1B[37m"
#define ORANGE  "\x1B[38;2;255;128;0m"
#define ROSE    "\x1B[38;2;255;151;203m"
#define LBLUE   "\x1B[38;2;53;149;240m"
#define LGREEN  "\x1B[38;2;17;245;120m"
#define GRAY    "\x1B[38;2;176;174;174m"
#define RESET   "\x1b[0m"




/*Modificar el Fondo del texto dentro de la termina*/

#define BG_BLACK   "\x1B[40m"                      // Define macros en C para cambiar el color de fondo del texto en la consola usando códigos de escape ANSI.
#define BG_RED     "\x1B[41m"                      // Cada macro comienza con BG_ (para "Background") y representa un color específico, utilizando los códigos correspondientes.
#define BG_GREEN   "\x1B[42m"                      // Usa códigos ANSI estándar para definir colores de fondo básicos y avanzados (con valores RGB) 
#define BG_YELLOW  "\x1B[43m"                      // que pueden ser aplicados al texto en la consola.
#define BG_BLUE    "\x1B[44m"                      // Las macros facilitan la personalización de la apariencia visual del texto
#define BG_MAGENTA "\x1B[45m"                      // y pueden ser usadas en programas para destacar información.
#define BG_CYAN    "\x1B[46m"
#define BG_WHITE   "\x1B[47m"
#define BG_ORANGE  "\x1B[48;2;255;128;0m"
#define BG_LBLUE   "\x1B[48;2;53;149;240m"
#define BG_LGREEN  "\x1B[48;2;17;245;120m"
#define BG_GRAY    "\x1B[48;2;176;174;174m"
#define BG_ROSE    "\x1B[48;2;255;151;203m"



//La libreria se basa en códigos de colores a través de ANSI Códigos de escape,
//los cuales son secuencias de caracteres que se utilizan para controlar la salida de texto en la terminal.