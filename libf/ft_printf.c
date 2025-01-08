/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogueir <enogueir@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:59:36 by enogueir          #+#    #+#             */
/*   Updated: 2024/11/07 16:54:02 by enogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_var_opt(va_list args, const char format)
{
	int	len;

	len = 0;
	if (format == 'c')
		len += ft_putchar_fd(va_arg(args, int), 1);
	else if (format == 's')
		len += ft_putstr_fd(va_arg(args, char *), 1);
	else if (format == 'p')
		len += ft_putptr((size_t)va_arg(args, void *));
	else if (format == 'd' || format == 'i')
		len += ft_putnbr_fd(va_arg(args, int), 1);
	else if (format == 'u')
		len += ft_putnbr_fd(va_arg(args, unsigned int), 1);
	else if (format == 'x')
		len += ft_putnbr_hex(va_arg(args, unsigned int), 0);
	else if (format == 'X')
		len += ft_putnbr_hex(va_arg(args, unsigned int), 1);
	else if (format == '%')
		len += ft_putchar_fd('%', 1);
	return (len);
}

int	ft_printf(char const *str, ...)
{
	int		i;
	int		len;
	va_list	args;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			len += ft_var_opt(args, str[i + 1]);
			i++;
		}
		else
			len += ft_putchar_fd(str[i], 1);
		i++;
	}
	va_end(args);
	return (len);
}

#include <stdio.h>

/* int	main(void)
{
	int original_print_return;
	int fake_print_return;
	
	//close(STDOUT_FILENO);

	fake_print_return = ft_printf("Esto es un caracter: %c\n", 'W');
	ft_putnbr_fd(fake_print_return, 2);
	ft_putchar_fd('\n', 2);
	original_print_return = printf("Esto es un caracter: %c\n", 'W');
	ft_putnbr_fd(original_print_return, 2);
	ft_putchar_fd('\n', 2);
	ft_putchar_fd('\n', 2);

	if (original_print_return != fake_print_return)
		ft_putstr_fd("ALERTA, ALERTA!\n\n", STDERR_FILENO);

	fake_print_return = ft_printf("Esto es un string: %s\n", "Hola que tal?");
	ft_putnbr_fd(fake_print_return, 2);
	ft_putchar_fd('\n', 2);
	original_print_return = printf("Esto es un string: %s\n", "Hola que tal?");
	ft_putnbr_fd(original_print_return, 2);
	ft_putchar_fd('\n', 2);
	ft_putchar_fd('\n', 2);

	if (original_print_return != fake_print_return)
		ft_putstr_fd("ALERTA, ALERTA!\n\n", STDERR_FILENO);

	fake_print_return = ft_printf("Esto es un string NULL: %s\n", (char *)NULL);
	ft_putnbr_fd(fake_print_return, 2);
	ft_putchar_fd('\n', 2);
	original_print_return = printf("Esto es un string NULL: %s\n", (char *)NULL);
	ft_putnbr_fd(original_print_return, 2);
	ft_putchar_fd('\n', 2);
	ft_putchar_fd('\n', 2);

	if (original_print_return != fake_print_return)
		ft_putstr_fd("ALERTA, ALERTA!\n\n", STDERR_FILENO);

	fake_print_return = ft_printf("Esto es un entero negativo: %d\n", -42);
	ft_putnbr_fd(fake_print_return, 2);
	ft_putchar_fd('\n', 2);
	original_print_return = printf("Esto es un entero negativo: %d\n", -42);
	ft_putnbr_fd(original_print_return, 2);
	ft_putchar_fd('\n', 2);
	ft_putchar_fd('\n', 2);

	if (original_print_return != fake_print_return)
		ft_putstr_fd("ALERTA, ALERTA!\n\n", STDERR_FILENO);

	fake_print_return = ft_printf("Esto es un unsigned int: %u\n", 42);
	ft_putnbr_fd(fake_print_return, 2);
	ft_putchar_fd('\n', 2);
	original_print_return = printf("Esto es un unsigned int: %u\n", 42);
	ft_putnbr_fd(original_print_return, 2);
	ft_putchar_fd('\n', 2);
	ft_putchar_fd('\n', 2);

	if (original_print_return != fake_print_return)
		ft_putstr_fd("ALERTA, ALERTA!\n\n", STDERR_FILENO);

	fake_print_return = ft_printf("Esto es un hex en minusculas: %x\n", 255);
	ft_putnbr_fd(fake_print_return, 2);
	ft_putchar_fd('\n', 2);
	original_print_return = printf("Esto es un hex en minusculas: %x\n", 255);
	ft_putnbr_fd(original_print_return, 2);
	ft_putchar_fd('\n', 2);
	ft_putchar_fd('\n', 2);

	if (original_print_return != fake_print_return)
		ft_putstr_fd("ALERTA, ALERTA!\n\n", STDERR_FILENO);

	fake_print_return = ft_printf("Esto es un hex 0 en minusculas: %x\n", 0);
	ft_putnbr_fd(fake_print_return, 2);
	ft_putchar_fd('\n', 2);
	original_print_return = printf("Esto es un hex 0 en minusculas: %x\n", 0);
	ft_putnbr_fd(original_print_return, 2);
	ft_putchar_fd('\n', 2);
	ft_putchar_fd('\n', 2);

	if (original_print_return != fake_print_return)
		ft_putstr_fd("ALERTA, ALERTA!\n\n", STDERR_FILENO);

	fake_print_return = ft_printf("Esto es un hex en mayusculas: %X\n", 255);
	ft_putnbr_fd(fake_print_return, 2);
	ft_putchar_fd('\n', 2);
	original_print_return = printf("Esto es un hex en mayusculas: %X\n", 255);
	ft_putnbr_fd(original_print_return, 2);
	ft_putchar_fd('\n', 2);
	ft_putchar_fd('\n', 2);

	if (original_print_return != fake_print_return)
		ft_putstr_fd("ALERTA, ALERTA!\n\n", STDERR_FILENO);

	fake_print_return = ft_printf("Esto es un hex 0 en mayusculas: %X\n", 0);
	ft_putnbr_fd(fake_print_return, 2);
	ft_putchar_fd('\n', 2);
	original_print_return = printf("Esto es un hex 0 en mayusculas: %X\n", 0);
	ft_putnbr_fd(original_print_return, 2);
	ft_putchar_fd('\n', 2);
	ft_putchar_fd('\n', 2);

	if (original_print_return != fake_print_return)
		ft_putstr_fd("ALERTA, ALERTA!\n\n", STDERR_FILENO);

	int	n = 42;
	fake_print_return = ft_printf("Esto es un puntero: %p\n", &n);
	ft_putnbr_fd(fake_print_return, 2);
	ft_putchar_fd('\n', 2);
	original_print_return = printf("Esto es un puntero: %p\n", &n);
	ft_putnbr_fd(original_print_return, 2);
	ft_putchar_fd('\n', 2);
	ft_putchar_fd('\n', 2);

	if (original_print_return != fake_print_return)
		ft_putstr_fd("ALERTA, ALERTA!\n\n", STDERR_FILENO);

	fake_print_return = ft_printf("Esto es un porcentaje: %%\n");
	ft_putnbr_fd(fake_print_return, 2);
	ft_putchar_fd('\n', 2);
	original_print_return = printf("Esto es un porcentaje: %%\n");
	ft_putnbr_fd(original_print_return, 2);
	ft_putchar_fd('\n', 2);
	ft_putchar_fd('\n', 2);

	if (original_print_return != fake_print_return)
		ft_putstr_fd("ALERTA, ALERTA!\n\n", STDERR_FILENO);

	fake_print_return = ft_printf("Esto es un vacío: %p\n", NULL);
	ft_putnbr_fd(fake_print_return, 2);
	ft_putchar_fd('\n', 2);
	original_print_return = printf("Esto es un vacío: %p\n", NULL);
	ft_putnbr_fd(original_print_return, 2);
	ft_putchar_fd('\n', 2);
	
	return (0);
} */