#include "../include/list.h"

int my_printf(char *format, ...)
{
    int i;
    unsigned int u;
    char *string;
    int index;
    void *ptr = NULL;
    int count = 0;

    va_list arg;
    va_start(arg, format);

    for (index = 0; format[index] != '\0'; index++)
    {

        if (format[index] != '%') //print string until argument parameter encountered
        {
            count += my_putchar(format[index]);
        }

        else
        {
            index++; //increment to letter after % then check
            if (format[index] == 's')
            {
                string = va_arg(arg, char *); //case for string
                if (string == (char *)NULL || NULL)
                    count += my_putstr("(null)");
                else
                    count += my_putstr(string);
            }

            if (format[index] == 'c')
            {
                i = va_arg(arg, int); //case for char
                count += my_putchar(i);
            }

            if (format[index] == 'd')
            {
                i = va_arg(arg, int); //case for decimal
                char buffer[12];
                count += my_putstr(my_itoa(i, buffer, 10));
            }

            if (format[index] == 'o')
            {
                u = va_arg(arg, unsigned int); //case for octal
                char buffer[12];
                count += my_putstr(my_utoa(u, buffer, 8));
            }

            if (format[index] == 'u')
            {
                u = va_arg(arg, unsigned int); //case for unsigned dec
                char buffer[12];
                count += my_putstr(my_utoa(u, buffer, 10));
            }

            if (format[index] == 'x')
            {
                u = va_arg(arg, unsigned int); //case for unsigned hexadecimal
                char buffer[12];
                count += my_putstr(my_utoa(u, buffer, 16));
            }

            if (format[index] == 'p')
            {
                ptr = va_arg(arg, void *); //case for void* pointer in hex
                unsigned long addr = (unsigned long)ptr;
                char buffer[2 + (sizeof(addr) * 8)];
                count += my_putstr("0x");
                count += my_putstr(to_hex(addr, buffer));
            }
        }
    }
    va_end(arg);
    return count;
}

char my_putchar(char c)
{
    return write(1, &c, 1);
}

int my_putstr(char *string)
{
    int i = strlen(string);
    for (int i = 0; string[i] != '\0'; i++)
    {
        my_putchar(string[i]);
    }
    return i;
}

void my_reverse(char str[], int len)
{
    int start, end;
    char temp;
    for (start = 0, end = len - 1; start < end; start++, end--)
    {
        temp = *(str + start);
        *(str + start) = *(str + end);
        *(str + end) = temp;
    }
}

char *my_itoa(int number, char *string, int base) //to convert my signed decimal to string
{
    int i = 0;
    int negative_num = 0;

    //if 0, print "0" string
    if (number == 0)
    {
        string[i] = '0';
        string[i + 1] = '\0';
        return string;
    }

    //if base decimal and negative, otherwise ignore sign.
    if (number < 0 && base == 10)
    {
        negative_num = 1;
        number = -number;
    }

    while (number != 0)
    {
        unsigned int remainder = number % base;
        if (remainder > 9)
        {
            string[i++] = (remainder - 10) + 'a';
        }
        else
        {
            string[i++] = remainder + '0';
        }
        number = number / base;
    }

    /* Append negative sign for negative numbers */
    if (negative_num)
    {
        string[i++] = '-';
    }

    string[i] = '\0';

    my_reverse(string, i);

    return string;
}

char *my_utoa(unsigned int number, char *string, int base) //conversion for different unsigned inputs in base 8/10/16
{
    int i = 0;

    //if 0, print "0" string
    if (number == 0)
    {
        string[i] = '0';
        string[i + 1] = '\0';
        return string;
    }

    while (number > 0)
    {
        unsigned int remainder = number % base;
        if (remainder >= 10)
        {
            string[i] = (remainder - 10) + 'a';
        }
        else
        {
            string[i] = remainder + '0';
        }
        number = number / base;
        i++;
    }

    string[i] = '\0';

    my_reverse(string, i);

    return string;
}

char *to_hex(unsigned long number, char *string) //needed unsigned long for %p case addresses
{
    int i = 0;

    while (number > 0)
    {
        unsigned int remainder = number % 16;
        if (remainder >= 10)
        {
            string[i] = (remainder - 10) + 'a';
        }
        else
        {
            string[i] = remainder + '0';
        }
        number = number / 16;
        i++;
    }

    string[i] = '\0';

    my_reverse(string, i);

    return string;
}