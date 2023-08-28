#include <stdio.h>
#include <stdarg.h>

void custom_printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);
    // int x;

    for (const char *c = format; *c != '\0'; c++)
    {
        if (*c == '%')
        {
            c++;
            switch (*c)
            {
            case 'd':
            {
                int x = va_arg(args, int);
                fprintf(stdout, "%d", x);
                break;
            }
            case 'f':
            {
                double x_d = va_arg(args, double);
                fprintf(stdout, "%f", x_d);
                break;
            }
            case 's':
            {
                char *x_c = va_arg(args, char *);
                fprintf(stdout, "%s", x_c);
                break;
            }
            default:
                putchar(*c);
                break;
            }

            // if (*c == 'd')
            // {
            //     int num = va_arg(args, int);
            //     printf("%d", num);
            // }
            // else if (*c == 'f')
            // {
            //     double num = va_arg(args, double);
            //     printf("%.2f", num);
            // }
            // else if (*c == 's')
            // {
            //     char *str = va_arg(args, char *);
            //     printf("%s", str);
            // }
            // else
            // {
            //     putchar(*c);
            // }
        }
        else
        {
            putchar(*c);
        }
    }

    va_end(args);
}

int main()
{
    int integer_val = 42;
    double float_val = 3.14159;
    char *string_val = "Hello, custom printf!";

    custom_printf("Integer: %d\n", integer_val);
    custom_printf("Float: %f\n", float_val);
    custom_printf("String: %s\n", string_val);
    // custom_printf("Hello world\n");
    // custom_printf("%d",100);

    return 0;
}
