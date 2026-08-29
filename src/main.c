#include <stdarg.h>
#include <stdio.h>

int custoprint(const char *format, ...);

int main(void) {

  custoprint("Printing example for char is %c and %c \n", 'o', 'k');
  custoprint("and for string %s \n", "is like this");
  custoprint("Now then we try integer %i \n", 1);
  custoprint("After 1 comes %f but in float \n", 2.0);

  return 0;
}

int custoprint(const char *format, ...) {
  int len = 0;

  va_list arg_list;
  va_start(arg_list, format);

  for (int i = 0; format[i] != '\0'; i++) {

    if (format[i] == '%') //
    {
      i++;

      switch (format[i]) {

      case 's': //
      {
        char *str;
        str = va_arg(arg_list, char *);
        for (int j = 0; str[j] != '\0'; j++) {
          putchar(str[j]);
          len++;
        }
      } break;
        /////////////////////////////////////////
      case 'i': //
      {
        int num;
        num = va_arg(arg_list, int);
        char buf[12];
        int digits = sprintf(buf, "%i", num);
        for (int j = 0; j < digits; j++) {
          putchar(buf[j]);
          len++;
        }
      } break;
        /////////////////////////////////////////
      case 'c': //
      {
        int num;
        num = va_arg(arg_list, int);
        putchar(num);
        len++;
      } break;
      /////////////////////////////////////////
      case 'f': //
      {
        double num;
        num = va_arg(arg_list, double);
        char buf[12];
        int digits = sprintf(buf, "%f", num);
        for (int j = 0; j < digits; j++) {
          putchar(buf[j]);
          len++;
        }
      } break;
      /////////////////////////////////////////
      default: //
      {
        printf("Its nothing gozaru \n");
      }
      }
      /*ENDSWITCH*/
    }

    /*ENDIF*/

    else //
    {
      putchar(format[i]);
      len++;
    }

    /*ENDFOR*/
  }
  return len;
}
