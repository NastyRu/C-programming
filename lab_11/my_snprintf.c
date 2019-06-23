#include "string.h"

/*
Запись size символов в строку str
@param str [out]
@param size [in]
@param format [in]

@return Возвращает количество элементов
*/
int my_snprintf(char *restrict str, size_t size, const char *restrict format, ...)
{
    va_list va;
    char num[20];
    int kol = 0;
    char *str_copy = calloc(1000, sizeof(char));

    int i = 0;
    do
    {
        str_copy[i] = format[i];
        i++;
    }
    while (format[i - 1] != '\0');
    str_copy[i] = '\0';

    va_start(va, format);

    for (int i = 0; i < my_sizeof(str_copy); i++)
    {
        if (str_copy[i] == '%' && (i + 1) < my_sizeof(str_copy))
        {
            i++;
            char c = str_copy[i];
            switch (c)
            {
                case 'o': 
		    sprintf(num, "%o", va_arg(va, int)); 
		    replace(str_copy, num, i - 1, 2); 
		    i = i - 2 + my_sizeof(num); 
		    break;
                case 'd': 
		    int_to_str(num, va_arg(va, int)); 
		    replace(str_copy, num, i - 1, 2); 
		    i = i - 2 + my_sizeof(num); 
		    break;
                case 'c': 
		    num[0] = va_arg(va, int); 
		    num[1] = '\0'; 
		    replace(str_copy, num, i - 1, 2); 
		    i = i - 2 + my_sizeof(num); 
		    break;
                case 'l':
                    i++;
                    if (i < my_sizeof(str_copy))
                    {
                        char cd = str_copy[i];
                        switch (cd)
                        {
                            case 'o': 
				sprintf(num, "%lo", va_arg(va, long int)); 
				replace(str_copy, num, i - 2, 3); 
				i = i - 3 + my_sizeof(num); 
				break;
                            case 'd': 
				int_to_str(num, va_arg(va, long int)); 
				replace(str_copy, num, i - 2, 3); 
				i = i - 3 + my_sizeof(num); 
				break;
                            default: 
				free(str_copy); 
				return FAILED;
                        }
                    }
                    break;
                default: 
		    free(str_copy); 
		    return FAILED;
            }
        }
    }

    va_end(va);

    kol = my_sizeof(str_copy);
    if (size >= kol)
        size = kol;
    else if (size != 0)
        size--;

    if (NULL == str)
    {
	free(str_copy);
        return kol;
    }

    for (int i = 0; i < size; i++)
        str[i] = str_copy[i];
    str[size] = '\0';

    free(str_copy);

    return kol;
}
