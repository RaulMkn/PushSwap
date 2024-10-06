/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakende <rmakende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:19:36 by rmakende          #+#    #+#             */
/*   Updated: 2024/09/20 17:17:50 by rmakende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_c(va_list args, char c)
{
	if (c == 'c')
		return (ft_putchar_fd_printf(va_arg(args, int), 1));
	else if (c == 's')
		return (ft_putstr_fd_printf(va_arg(args, char *), 1));
	else if (c == 'p')
		return (ft_putpointer_fd_printf(va_arg(args, void *), 1));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr_fd_printf(va_arg(args, int), 1));
	else if (c == 'u')
		return (ft_putunsigned_fd_printf(va_arg(args, unsigned int), 1));
	else if (c == 'x' || c == 'X')
		return (ft_putexa_fd_printf(va_arg(args, unsigned int), 1, c));
	else if (c == '%')
		return (ft_putchar_fd_printf('%', 1));
	else
	{
		return (0);
	}
}

int	ft_printf(char const *c, ...)
{
	int			i;
	int			count;
	va_list		args;

	i = 0;
	count = 0;
	va_start(args, c);
	while (c[i])
	{
		if (c[i] == '%')
		{
			count += handle_c(args, c[i + 1]);
			i++;
		}
		else
			count += ft_putchar_fd_printf(c[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}
/*
int main()
{
    int entero = 985632;
    char caracter = 'B';
    char *cadena = NULL;
    char *cadena_larga = "Este es un string largo";
    char *cadena_vacia = "";
    void *puntero = &entero;
    void *puntero_null = NULL;
    int num_negativo = -42;
    int int_max = 2147483647;
    int int_min = -2147483648;
    unsigned int uint_max = 4294967295;

    int original_ret, mi_ret;
    //PRUEBA DE CARACTERES
    printf("%s\n", "Prueba de impresión de caracteres");
    printf("Original printf:\n");
    original_ret = printf("Caracter: %c\n", caracter);
    printf("Return: %d\n", original_ret);
    original_ret = printf("%c\n", caracter);
    printf("Return: %d\n", original_ret);

    printf("Mi ft_printf:\n");
    mi_ret = ft_printf("Caracter: %c\n", caracter);
    printf("Return: %d\n", mi_ret);
    mi_ret = ft_printf("%c\n", caracter);
    printf("Return: %d\n\n", mi_ret);
    
    //PRUEBA CON CADENAS
    printf("%s\n", "Prueba de impresión de cadenas");
    printf("Original printf:\n");
    original_ret = printf("Cadena: %s\n", cadena);
    printf("Return: %d\n", original_ret);

    printf("Mi ft_printf:\n");
    mi_ret = ft_printf("Cadena: %s\n", cadena);
    printf("Return: %d\n\n", mi_ret);

    //PRUEBA CON CADENAS LARGAS
    printf("%s\n", "Prueba de impresión de cadenas largas");
    printf("Original printf:\n");
    original_ret = printf("Cadena larga: %s\n", cadena_larga);
    printf("Return: %d\n", original_ret);

    printf("Mi ft_printf:\n");
    mi_ret = ft_printf("Cadena larga: %s\n", cadena_larga);
    printf("Return: %d\n\n", mi_ret);

    //PRUEBA DE CADENAS VACIAS
    printf("%s\n", "Prueba de impresión de cadenas vacías");
    printf("Original printf:\n");
    original_ret = printf("Cadena vacía: %s\n", cadena_vacia);
    printf("Return: %d\n", original_ret);

    printf("Mi ft_printf:\n");
    mi_ret = ft_printf("Cadena vacía: %s\n", cadena_vacia);
    printf("Return: %d\n\n", mi_ret);

    //PRUEBA DE PUNTEROS
    printf("%s\n", "Prueba de impresión de punteros");
    printf("Original printf:\n");
    original_ret = printf("Puntero: %p\n", puntero);
    printf("Return: %d\n", original_ret);

    printf("Mi ft_printf:\n");
    mi_ret = ft_printf("Puntero: %p\n", puntero);
    printf("Return: %d\n\n", mi_ret);

    //PRUEBA DE PUNTERO NULL
    printf("%s\n", "Prueba de impresión de puntero NULL");
    printf("Original printf:\n");
    original_ret = printf("Puntero NULL: %p\n", puntero_null);
    printf("Return: %d\n", original_ret);

    printf("Mi ft_printf:\n");
    mi_ret = ft_printf("Puntero NULL: %p\n", puntero_null);
    printf("Return: %d\n\n", mi_ret);

    //PRUEBA NUMEROS DECIMALES
    printf("%s\n", "Prueba de impresión de números decimales (base 10)");
    printf("Original printf:\n");
    original_ret = printf("Entero: %d\n", entero);
    printf("Return: %d\n", original_ret);

    printf("Mi ft_printf:\n");
    mi_ret = ft_printf("Entero: %d\n", entero);
    printf("Return: %d\n\n", mi_ret);

    //PRUEBA ENTEROS
    printf("%s\n", "Prueba de impresión de enteros (base 10)");
    printf("Original printf:\n");
    original_ret = printf("Entero: %i\n", entero);
    printf("Return: %d\n", original_ret);

    printf("Mi ft_printf:\n");
    mi_ret = ft_printf("Entero: %i\n", entero);
    printf("Return: %d\n\n", mi_ret);

    //PRUEBA DECIMALES LARGOS
    printf("%s\n", "Prueba de impresión de números decimales negativos");
    printf("Original printf:\n");
    original_ret = printf("Número negativo: %d\n", num_negativo);
    printf("Return: %d\n", original_ret);

    printf("Mi ft_printf:\n");
    mi_ret = ft_printf("Número negativo: %d\n", num_negativo);
    printf("Return: %d\n\n", mi_ret);

    //PRUEBA NUMEROS SIN SIGNO
    printf("%s\n", "Prueba de impresión de números sin signo (base 10)");
    printf("Original printf:\n");
    original_ret = printf("Unsigned Entero: %u\n", uint_max);
    printf("Return: %d\n", original_ret);

    printf("Mi ft_printf:\n");
    mi_ret = ft_printf("Unsigned Entero: %u\n", uint_max);
    printf("Return: %d\n\n", mi_ret);

    //PRUEBA INT MAX, INT MIN UINT MAX
    printf("%s\n", "Prueba de impresión de enteros máximos y mínimos");
    printf("Original printf:\n");
    original_ret = printf("Entero máximo: %d\n", int_max);
    printf("Return: %d\n", original_ret);
    original_ret = printf("Entero mínimo: %d\n", int_min);
    printf("Return: %d\n", original_ret);
    original_ret = printf("Unsigned Entero máximo: %u\n", uint_max);
    printf("Return: %d\n", original_ret);

    printf("Mi ft_printf:\n");
    mi_ret = ft_printf("Entero máximo: %d\n", int_max);
    printf("Return: %d\n", mi_ret);
    mi_ret = ft_printf("Entero mínimo: %d\n", int_min);
    printf("Return: %d\n", mi_ret);
    mi_ret = ft_printf("Unsigned Entero máximo: %u\n", uint_max);
    printf("Return: %d\n\n", mi_ret);

    //PRUEBA HEXADECIMALES MINUSCULA
    printf("%s\n", "Prueba de impresión de números hexadecimales en minúsculas");
    printf("Original printf:\n");
    original_ret = printf("Hexadecimal (minúsculas): %x\n", entero);
    printf("Return: %d\n", original_ret);

    printf("Mi ft_printf:\n");
    mi_ret = ft_printf("Hexadecimal (minúsculas): %x\n", entero);
    printf("Return: %d\n\n", mi_ret);

    //PRUEBA HEXADECIMALES MAYUSCULA
    printf("%s\n", "Prueba de impresión de números hexadecimales en mayúsculas");
    printf("Original printf:\n");
    original_ret = printf("Hexadecimal (mayúsculas): %X\n", entero);
    printf("Return: %d\n", original_ret);

    printf("Mi ft_printf:\n");
    mi_ret = ft_printf("Hexadecimal (mayúsculas): %X\n", entero);
    printf("Return: %d\n\n", mi_ret);

    //PRUEBA HEXADECIMALES 0
    printf("%s\n", "Prueba de impresión de números hexadecimales para 0");
    printf("Original printf:\n");original_ret = 
    printf("Hexadecimal (mayúsculas): 
    %X\nHexadecimal (minusculas): %x\n", 0, 0);
    printf("Return: %d\n", original_ret);

    printf("Mi ft_printf:\n");mi_ret = ft_printf("Hexadecimal (mayúsculas): 
    %X\nHexadecimal (minusculas): %x\n", 0, 0);
    printf("Return: %d\n\n", mi_ret);

    //PRUEBA PORCENTAJE
    printf("%s\n", "Prueba de impresión de porcentaje");
    printf("Original printf:\n");
    original_ret = printf("Porcentaje: %%\n");
    printf("Return: %d\n", original_ret);

    printf("Mi ft_printf:\n");
    mi_ret = ft_printf("Porcentaje: %%\n");
    printf("Return: %d\n\n", mi_ret);

    //PRUEBA MULTIPLES PARAMETROS
    printf("%s\n", "Prueba de impresión de multiples parametros");
    printf("Original printf:\n");
    original_ret = printf("Hola mi nombre es %s, tengo %d años, 
    estudio en %s y este es mi printf:\n", "Raul", 22, "42 Madrid")
    ;printf("Return: %d\n", original_ret);

    printf("Mi ft_printf:\n");
    mi_ret = ft_printf("Hola mi nombre es %s, tengo %d años, 
    estudio en %s y este es mi printf:\n", "Raul", 22, "42 Madrid");
     printf("Return: %d\n\n", mi_ret);

    return 0;
}
*/