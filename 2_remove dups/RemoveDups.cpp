#include <iostream>


void RemoveDups(char* str)
{
	
	if ((str == nullptr) || (*str == '\0'))
	{
		return;
	}

    int i = 1;
    int j = 1;

    while (*(str + i++)) {   // пока не дойдём до конца строки

        // если текущий символ не равен предыдущему, запоминаем его
        if (*(str + i) != *(str + i - 1)) {
            *(str + j++) = *(str + i);
        }
    }
	
}

int main() {
    char data[] = "AAA  BBB AAA";
    printf("%s\n", data);
    RemoveDups(data);
    printf("%s\n", data); // “A B A”
    return 0;
}